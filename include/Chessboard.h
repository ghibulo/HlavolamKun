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

    private:
        char field[sizeBoard][sizeBoard];
};

#endif // CHESSBOARD_H