# aisd_wyklad

kopiec jest przykładem drzewa AVL wyważonego

drzewo wyważone - h ~ log2 (n); AVL - |h1-h2|<=1

drzewo ściśle wyważone - |n1-n2|<=1

kopiec zapisany w formie wektora:
dla pola o indeksie i, jego dzieci mają indeksy 2i+1 oraz 2i+2

kolejka priorytetowa jako abstrakcyjny typ danych
(wiemy jak działa, ale nie znamy dokładnej implementacji):  
posiada metody push i pop, gdzie push dodaje na koniec, a pop zdejmuje
z początku (o najwyższym priorytecie)  

Tablica - push O(1) i pop O(n)  
Kopiec - push O(log n) i pop O(log n)

analiza kosztu zamortyzowanego:  
dla n operacji tablica wykonuje O(n^2) + O(n) operacji, a kopiec wykonuje
2 * O(n log(n))

drzewo wyważone: h~log(2)n