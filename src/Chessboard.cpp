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

void Chessboard::filterOccupied(Fields &nb) {

    std::set<Field> fs; // sem vyfiltruju...
    for(std::set<Field>::iterator i=nb.fs.begin(); i!=nb.fs.end();i++)
        if (field[(*i).x][(*i).y]==0) fs.insert(*i);


    //std::copy_if(nb.fs.begin(), nb.fs.end(), std::inserter(fs, fs.end()), [](const Field & f){return field[f.x][f.y]==0});
    nb.fs.swap(fs);
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
    int sum = 0;
    for (int i=0;i<Constants::sizeBoard;i++) {
        for (int j=0;j<Constants::sizeBoard;j++) {
            sum+=field[i][j]==0 ? 1:0;
            if (sum>=n) return false;
        }
    }
    return true;
}

void Chessboard::debugChessboardPrint() {
    for (int i=0;i<Constants::sizeBoard;i++) {
        for (int j=0;j<Constants::sizeBoard;j++) {
            printf("%d ", field[i][j]);
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
    if (lastField.x<0) cout << "Problem: opakovane undo neni implementovano";
    #endif
    markField(horse.x, horse.y,0);
    horse=lastField;
    lastField.x=-1;
}
