# ExternalSort
Sortowanie liczb całkowitych w pliku, gdzie liczby mogą być bardzo duże. 

<b>Wejście:</b>
Program otrzymuje na wejściu plik z nieposortowanymi liczbami, gdzie kolejne liczby znajdują się w osobnych wierszach w pliku.

<b>Wyjście:</b>
Posortowane liczby w pliku, podanym na wejściu.

<b>Idea:</b>
Program komunikuje się między 3 plikami: jeden z nich to plik do posortowania, dwa pozostałe są pomocnicze. W każdej iteracji pętli są pobierane bloki
liczb z pliku i sortowane. Następnie bloki z liczbami zostają scalane z plikiem pomocniczym "A"(wcześniej plik pomocniczy "B") do pliku pomocniczego "B". 
