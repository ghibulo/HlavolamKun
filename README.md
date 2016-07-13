#Hlavolam „Jak vyskákat koněm šachovnici“

- cvičná úloha pro zopakování práce s objekty a kontejnery v C++
- zatím hotov jen podklad
  - třída Field představuje pole
  - třída Fields obaluje kontejner množiny a kontroluje, jestli vkládaná pole patří do šachovnice
  - třída Chessboard udržuje stav šachovnice (kde je kůň, sousední políčka z hlediska skoku a obsazenost políček)

na mem dvoujadrovem procesoru nasel reseni za cca 15 minut:
```
01 12 09 06 03 14 17 20 
10 07 02 13 18 21 04 15 
31 28 11 08 05 16 19 22 
64 25 32 29 36 23 48 45 
33 30 27 24 49 46 37 58 
26 63 52 35 40 57 44 47 
53 34 61 50 55 42 59 38 
62 51 54 41 60 39 56 43 
```

## Provedena optimalizace:

- Fields předělán na List, filtrování obsazených polí nahradilo jediné volání pomocí lambda funkce:
```cpp
nb.fs.remove_if([&](const Field& f) { return (field[f.x][f.y]!=0); });
```
- Field rozšířen o parametr dostupnosti ```cpp availability ```

- Dostupné tahy jsou seřazeny podle své ```cpp availability ```

```cpp
/*obecne volani pro pole na ktera se da doskocit
 *používá Chessboard::getNeighb(Fields &nb) a  Chessboard::getAvailability(Field &f)
*/
void doSomethingAround(int x, int y, void * context, void (*pfce) (char x, char y, void* ct)  ) {
    pfce(x-2,y+1, context);pfce(x-2,y-1, context);pfce(x+2,y-1, context);pfce(x+2,y+1, context);
    pfce(x-1,y+2, context);pfce(x-1,y-2, context);pfce(x+1,y+2, context);pfce(x+1,y-2, context);
}

void sumEmptyNeighb (char x, char y, void *context) {
    if ( (x>=0)&&(x<Constants::sizeBoard)&&(y>=0)&&(y<Constants::sizeBoard)&&(((Chessboard*)context)->field[x][y] == 0))
        (*((char*)context))++;
}

void Chessboard::getAvailability(Field &f) {
        doSomethingAround(f.x,f.y,&(f.availability), sumEmptyNeighb );
}
```
## Výsledek: 
- řešení nalezeno za cca 2s
