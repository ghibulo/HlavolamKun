#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Global.h"
#include "Field.h"

using namespace Constants;

class Chessboard
{
    public:

        Chessboard();
        virtual ~Chessboard();
        Field horse;
        void getNeighb(Fields &nb);
        void filterOccupied(Fields &nb);
        void markField(int x, int y, int s);
        bool nNomarkFieldsLessThan(int n);
        void moveHorse(Field pl);
        void unMoveHorse(); //vrati posledni tah - pro rekurzi neni potreba nekolikanasobne undo
        void startAt(int x, int y);
        void debugChessboardPrint();

    private:
        char field[sizeBoard][sizeBoard];
        int mark;
        Field lastField;
};

#endif // CHESSBOARD_H
