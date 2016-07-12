#include <iostream>
#include "Global.h"
#include "Chessboard.h"
#include "Field.h"

using namespace std;
using namespace Constants;

//pokus o naivní rekurzi
Chessboard recursiveJumping(Chessboard board, int tolerance) {
    Fields options;

    if (board.nNomarkFieldsLessThan(tolerance)) return board;
    board.getNeighb(options);
    board.filterOccupied(options);
    while (options.isNotEmpty()) { //vyzkousej vsechny moznosti do hloubky
        Field mv = options.pop();
        board.moveHorse(mv);
        recursiveJumping(board,tolerance); //predavam hodnotou -> implicitní copy construktor objektu
        board.unMoveHorse();
    }

}


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
    board.debugChessboardPrint();

    board.markField(5,2,0);
    Chessboard reseno = recursiveJumping(board,60);
    reseno.debugChessboardPrint();

    return 0;
}
