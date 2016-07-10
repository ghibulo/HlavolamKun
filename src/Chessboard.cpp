#include "Chessboard.h"
#include "Global.h"
#include "iterator"
Chessboard::Chessboard()
{

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
