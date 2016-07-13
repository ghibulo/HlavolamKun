#include <iostream>
#include "Chessboard.h"
#include "Global.h"
#include "iterator"


using namespace std;
Chessboard::Chessboard()
{
    mark=0;
    for (int i=0;i<Constants::sizeBoard;i++) {
        for (int j=0;j<Constants::sizeBoard;j++) {
            field[i][j]=0;
        }
    }
}

Chessboard::~Chessboard()
{

    //dtor
}

//obecne volani pro pole na ktera se da doskocit
void doSomethingAround(int x, int y, void * context, void (*pfce) (char x, char y, void* ct)  ) {
    pfce(x-2,y+1, context);pfce(x-2,y-1, context);pfce(x+2,y-1, context);pfce(x+2,y+1, context);
    pfce(x-1,y+2, context);pfce(x-1,y-2, context);pfce(x+1,y+2, context);pfce(x+1,y-2, context);
}

//konkretni pomocna funkce pro naplneni promenne Fields
void fillBufFields ( char x, char y, void *context ) {
    ((Fields*)context)->add(Field(x,y));
}


void Chessboard::getNeighb(Fields &nb) {
    if (horse.x<0) return;
    doSomethingAround(horse.x, horse.y, &nb, fillBufFields);
}

void sumEmptyNeighb (char x, char y, void *context) {
    if ( (x>=0)&&(x<Constants::sizeBoard)&&(y>=0)&&(y<Constants::sizeBoard)&&(((Chessboard*)context)->field[x][y] == 0))
        (*((char*)context))++;
}

void Chessboard::getAvailability(Field &f) {
        doSomethingAround(f.x,f.y,&(f.availability), sumEmptyNeighb );
}

void Chessboard::appraiseField(Fields &nb) {

    for(std::list<Field>::iterator i=nb.fs.begin(); i!=nb.fs.end();i++)
        getAvailability(*i);
}

/*
//puvodni funkce
void Chessboard::getNeighb(Fields &nb) {
    if (horse.x<0) return;
    nb.add(Field(horse.x-2,horse.y+1));
    nb.add(Field(horse.x-2,horse.y-1));
    nb.add(Field(horse.x+2,horse.y+1));
    nb.add(Field(horse.x+2,horse.y-1));
    nb.add(Field(horse.x-1,horse.y+2));
    nb.add(Field(horse.x-1,horse.y-2));
    nb.add(Field(horse.x+1,horse.y+2));
    nb.add(Field(horse.x+1,horse.y-2));
}
*/

void Chessboard::filterOccupied(Fields &nb) {

    nb.fs.remove_if([&](const Field& f) { return (field[f.x][f.y]!=0); });

/* drive...
    std::list<Field> fs; // sem vyfiltruju...
    for(std::list<Field>::iterator i=nb.fs.begin(); i!=nb.fs.end();i++)
        if (field[(*i).x][(*i).y]==0) fs.insert(*i);



    //std::copy_if(nb.fs.begin(), nb.fs.end(), std::inserter(fs, fs.end()), [](const Field & f){return field[f.x][f.y]==0});
    nb.fs.swap(fs);
*/
}

void Chessboard::markField(int x, int y, int s) {
    #ifdef DEBUG
        if ((x<0)||(x>Constants::sizeBoard)||(y<0)||(y>Constants::sizeBoard)) {
         std::cout << "debug problem markField";
        exit(1);}
    #endif
    field[x][y] = s;

}

bool Chessboard::nNomarkFieldsLessThan(int n) {
    /*
    int sum = 0;
    for (int i=0;i<Constants::sizeBoard;i++) {
        for (int j=0;j<Constants::sizeBoard;j++) {
            sum+=field[i][j]==0 ? 1:0;
            if (sum>=n) return false;
        }
    }
    return true;
    */
    return ((64-mark) <= n);
}

void Chessboard::debugChessboardPrint() {
    cout << "--------------" << endl;
    for (int i=0;i<Constants::sizeBoard;i++) {
        for (int j=0;j<Constants::sizeBoard;j++) {
            printf("%.2d ", field[i][j]);
        }
        cout << endl;
    }
}

void Chessboard::moveHorse(Field pl) {
    lastField = horse;
    horse=pl;
    markField(horse.x,horse.y,++mark);
}

void Chessboard::unMoveHorse() {
    #ifdef DEBUG
    if (lastField.x<0) { cout << "Problem: opakovane undo neni implementovano"; exit(1);}
    #endif
    markField(horse.x, horse.y,0);
    horse=lastField;
    lastField.x=-1;
    mark--;
}

void Chessboard::startAt(int x, int y) {
    horse.x=x;horse.y=y;
    markField(horse.x,horse.y,++mark);
}
