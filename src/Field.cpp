#include "Field.h"
#include "Global.h"
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
    if ((f.x>=0)&&(f.y>=0)&&(f.x<Constants::sizeBoard)&&(f.x<Constants::sizeBoard)) { //jen na Boardu
        fs.insert(f);
    }

}
void Fields::del(Field f) {
    fs.erase(f);
}
void Fields::delAll() {
    fs.clear();
}

Field Fields::pop() {
    std::set<Field>::iterator one = fs.begin();
    fs.erase(one);
    return *one;
}

bool Fields::isLessThan(int n) {
    return fs.size()<n;
}

bool Fields::isNotEmpty() {
    return !(fs.empty());
}

void Fields::debugPrint() {
    for(it=fs.begin();it!=fs.end();it++) {
        Field pole = *it;
        cout << pole.toString();
    }
}
