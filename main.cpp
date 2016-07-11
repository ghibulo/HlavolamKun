#include <iostream>
#include "Global.h"
#include "Chessboard.h"
#include "Field.h"

using namespace std;
using namespace Constants;

int main()
{
    pokus = 10;
    tiskniPokus();
    cout << "Hello world! " << sizeBoard <<  endl;

    Chessboard board;
    board.horse.x = 4;
    board.horse.y = 3;
    Fields kamJdeSkocit;
    board.getNeighb(kamJdeSkocit);
    kamJdeSkocit.debugPrint();

    return 0;
}
