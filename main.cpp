#include <iostream>
#include "Global.h"
#include "Chessboard.h"
#include "Field.h"

using namespace std;
using namespace Constants;

int main()
{
    //pokus = 10;
    //tiskniPokus();
    cout << "Hrajeme si s konem na sachovnici velikosti: " << sizeBoard <<  endl;

    Chessboard board;
    board.horse.x = 4;
    board.horse.y = 0;
    Fields kamJdeSkocit;
    board.getNeighb(kamJdeSkocit);
    kamJdeSkocit.debugPrint();
    board.markField(5,2,1); //oznacene pole se neobjevi ve vypisu
    cout << "oznaceno pole (5,2)..." << endl;
    board.filterOccupied(kamJdeSkocit);
    kamJdeSkocit.debugPrint();


    return 0;
}
