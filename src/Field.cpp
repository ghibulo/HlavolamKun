#include "Field.h"
#include "Global.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

bool operator< (Field f1, Field f2) {
    if (f1.availability == f2.availability)
        return (f1.toString())<(f2.toString());
    else
        return (f1.availability>f2.availability);
}

Field::Field()
{x = 'x';y = 'x';availability=0;}


Field::Field(char x1, char y1)
{x = x1;y = y1;availability=0;}


string Field::toString() {
    stringstream t;
    t << "Field: x=" << to_string(x) << ", y=" << to_string(y) << ", av=" << to_string(availability) << endl;
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
    if ((f.x>=0)&&(f.y>=0)&&(f.x<Constants::sizeBoard)&&(f.y<Constants::sizeBoard)) { //jen na Boardu
        fs.push_back(f);
        #ifdef DEBUG
         cout << "Vkladam: " << f.toString() << endl;
         cout << "sizeBoard:" << Constants::sizeBoard << endl;
        #endif
    }
    #ifdef DEBUG
    else { cout << "Odmitam " << f.toString() << endl; }
    #endif

}

void Fields::delAll() {
    fs.clear();
}

Field Fields::pop() {

    Field res = fs.back();
    fs.pop_back();
    return res;
}

bool Fields::isLessThan(int n) {
    return fs.size()<(unsigned)n;
}

bool Fields::isNotEmpty() {
    return !(fs.empty());
}

void Fields::sortIt() {
    fs.sort();
}

void Fields::debugPrint() {
    for(it=fs.begin();it!=fs.end();it++) {
        Field pole = *it;
        cout << pole.toString();
    }
}
