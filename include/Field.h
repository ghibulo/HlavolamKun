#ifndef FIELD_H
#define FIELD_H

#include <set>
#include <list>
#include <string>

class Field
{
    public:
        char x;
        char y;
        Field();
        Field (char x1, char y1);
        char availability; //dostupnost z okolnich prazdnych poli
        std::string toString();

};

bool operator< (Field f1, Field f2);


class Fields
{
    public:
        Fields();
        virtual ~Fields();
        void add(Field f);
        //void del(Field f);
        void sortIt();
        void delAll();
        Field pop();
        bool isLessThan(int n);
        bool isNotEmpty();
        void debugPrint();



    //private:
        // drive: std::set<Field> fs;
        std::list<Field> fs;
    private:
        std::list<Field>::iterator it;

};

#endif // FIELD_H
