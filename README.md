# MES
Metoda Elementów Skończonych  
# Co zawiera plik data.txt?  
1. Szerokość elementu
2. Wysokość elementu
3. Ilość węzłów w szerokości
4. Ilość węzłów w wysokości.
5. Przewodzenie cieplne
6. Ilość punktów całkowania na element (2-4 punkty całkowania, 3-9 punktów całkowania 4-16 punktów całkowania)
7. Gęstość
8. C
# Co robią poszczególne klasy  
1. FileRead - Wczytuje z pliku wszystkie dane w data.txt.  
2. GlobalData - Wczytuje globalne dane do stworzenia siatki do stworzenia siatki.  
3. FEMGrid - Tworzy siatkę MES.  
4. ShapeFunctions - Oblicza funkcje kształtu elementów.  
5. Local - Oblicza pochodne funkcji kształtu, jakobian i odwrócony jakobian (Generalnia funkcja ma za duzo obowiązków i jest do przerobienia).  
6. MatrixH - Wyznacza macierz H dla pojedynczego elementu.  
7. Wages - Zawiera współrzędne i wagi punktów całkowania.  
8. MatrixC - Wyznacza macierz C dla pojedynczego elementu.  
9. MatrixGlobal - Buduje macierz H i C dla całej siatki MES.  
10. Node - Definiuje węzeł.  
11. Element - Definiuje pojedyńczy element który zawiera współrzędne swoich węzłów.  
12. BDShapeFunctions - oblicza funkcje kształtu na KRAWĘDZIACH elementu.  
13. BoundaryCondition - Dodaje warunek brzegowy do macierzy H w każdym elemencie.  

