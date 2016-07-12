#ifndef FIELD_H
#define FIELD_H

#include <set>
#include <string>

class Field
{
    public:
        char x;
        char y;
        Field();
        Field (char x1, char y1);
        std::string toString();

};

bool operator< (Field f1, Field f2);


class Fields
{
    public:
        Fields();
        virtual ~Fields();
        void add(Field f);
        void del(Field f);
        void delAll();
        Field pop();
        bool isLessThan(int n);
        bool isNotEmpty();
        void debugPrint();



    //private:
        std::set<Field> fs;
    private:
        std::set<Field>::iterator it;
};

#endif // FIELD_H
