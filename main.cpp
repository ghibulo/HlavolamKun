#include <iostream>
#include "Global.h"
#include "Chessboard.h"
#include "Field.h"

using namespace std;
using namespace Constants;

//pokus o naivní rekurzi
bool recursiveJumping(Chessboard board, int tolerance, Chessboard &result) {
    Fields options;

    if (board.nNomarkFieldsLessThan(tolerance)) {
        result = board;
        return true;
    }
    board.getNeighb(options);
    board.filterOccupied(options);
    while (options.isNotEmpty()) { //vyzkousej vsechny moznosti do hloubky
        Field mv = options.pop();
        board.moveHorse(mv);
        #ifdef DEBUG
        cout << "moveHorse: " << mv.toString() << endl;
        #endif
        if (recursiveJumping(board,tolerance, result)) {
        //predavam board hodnotou -> implicitní copy construktor objektu
            return true;
        } else {
            board.unMoveHorse();
        }
    }
    return false;
}


int main()
{
    //pokus = 10;
    //tiskniPokus();
    cout << "Hrajeme si s konem na sachovnici velikosti: " << sizeBoard <<  endl;

    Chessboard board, reseno;
    board.startAt(0,0);

 /*
    Fields kamJdeSkocit;
    board.getNeighb(kamJdeSkocit);
    kamJdeSkocit.debugPrint();
    board.markField(5,2,1); //oznacene pole se neobjevi ve vypisu
    cout << "oznaceno pole (5,2)..." << endl;
    board.filterOccupied(kamJdeSkocit);
    kamJdeSkocit.debugPrint();
    board.debugChessboardPrint();

    Chessboard reseno = board;
    reseno.debugChessboardPrint();
    board.markField(5,2,0);
*/

    if (recursiveJumping(board,4, reseno)) {
        reseno.debugChessboardPrint();
    } else {
        cout << "nenasel!"<< endl;
    }


    return 0;
}
