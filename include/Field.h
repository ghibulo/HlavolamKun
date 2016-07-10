#ifndef FIELD_H
#define FIELD_H

#include <set>

class Field
{
    public:
        Field();
        Field (char x1, char y1);
        char x;
        char y;
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



    //private:
    std::set<Field> fs;
};

#endif // FIELD_H
