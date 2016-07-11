#include "Field.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//abych mohl ve Fields použít množinu
bool operator< (Field f1, Field f2) {
    return (f1.toString())<(f2.toString());
}

Field::Field()
{x = 'x';y = 'x';}


Field::Field(char x1, char y1)
{x = x1;y = y1;}


string Field::toString() {
    stringstream t;
    t << "Field: x=" << to_string(x) << ", y=" << to_string(y) << endl;
    string vysl = t.str();
    return vysl;
}

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

void Fields::debugPrint() {
    for(it=fs.begin();it!=fs.end();it++) {
        Field pole = *it;
        cout << pole.toString();
    }
}
