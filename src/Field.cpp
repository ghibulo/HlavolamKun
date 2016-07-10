#include "Field.h"
#include <vector>


//abych mohl ve Fields použít množinu
bool operator< (Field f1, Field f2) {
    return (f1.x+f1.y)<(f2.x+f2.y);
}

Field::Field()
{x = 'x';y = 'x';}


Field::Field(char x1, char y1)
{x = x1;y = y1;}


Fields::Fields()
{

    //ctor
}

Fields::~Fields()
{
    //dtor
}

void Fields::add(Field f) {
    if ((f.x>=0)&&(f.y>=0)) { //jen na Boardu
        fs.insert(f);
    }

}
void Fields::del(Field f) {
    fs.erase(f);
}
void Fields::delAll() {
    fs.clear();
}
