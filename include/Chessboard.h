#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "Global.h"
#include "Field.h"

using namespace Constants;



void fillBufFields  (char x, char y, void *context);
void sumEmptyNeighb (char x, char y, void *context);
void doSomethingAround (int x, int y, void * context, void (*pfce) (char x, char y, void* ct));

class Chessboard
{
    public:
        Chessboard();
        virtual ~Chessboard();
        Field horse;
        void getNeighb(Fields &nb); //fill Fields by neigbours of horse
        void getAvailability(Field &f); //count of available fields
        void appraiseField(Fields &nb);
        void filterOccupied(Fields &nb);
        void markField(int x, int y, int s);
        bool nNomarkFieldsLessThan(int n);
        void moveHorse(Field pl);
        void unMoveHorse(); //vrati posledni tah - pro rekurzi neni potreba nekolikanasobne undo
        void startAt(int x, int y);
        void debugChessboardPrint();
        friend void sumEmptyNeighb (char x, char y, void *context); //abych se vyhnul getterum pro 'field'

    private:
        char field[sizeBoard][sizeBoard];
        int mark, nNeighb;
        Field lastField;

};

#endif // CHESSBOARD_H
