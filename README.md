#Hlavolam „Jak vyskákat koněm šachovnici“

- cvičná úloha pro zopakování práce s objekty a kontejnery v C++
- zatím hotov jen podklad
  - třída Field představuje pole
  - třída Fields obaluje kontejner množiny a kontroluje, jestli vkládaná pole patří do šachovnice
  - třída Chessboard udržuje stav šachovnice (kde je kůň, sousední políčka z hlediska skoku a obsazenost políček)

na mem dvoujadrovem procesoru nasel reseni za cca 15 minut:
01 12 09 06 03 14 17 20 
10 07 02 13 18 21 04 15 
31 28 11 08 05 16 19 22 
64 25 32 29 36 23 48 45 
33 30 27 24 49 46 37 58 
26 63 52 35 40 57 44 47 
53 34 61 50 55 42 59 38 
62 51 54 41 60 39 56 43 

TODO:
optimalizace seřazením možných tahů podle dostupnosti z okolních volných míst -> upřednostňovat hůře dostupná pole
