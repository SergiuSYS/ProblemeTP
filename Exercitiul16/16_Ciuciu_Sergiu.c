/*
Se dau N cuvinte (N ≤ 10 000), de lungime maximă L caractere (L ≤ 1 000). Pentru fiecare
cuvânt introdus, creați și afișați pe câte o linie un nou cuvânt format astfel încât să fie:
- Format prin amestecarea literelor cuvântului original.
- Mai mare din punct de vedere lexicografic decât cuvântul original.
- Cel mai mic cuvânt din punct de lexicografic respectând condițiile 1) și 2).
Dacă cel puțin una dintre cele trei condiții nu poate fi respectată, se va afișa -1 pentru
cuvântul respectiv. Complexitate maximă O(N × L) timp și O(L) memorie.

+--------+-----------------+-------------------------------------------------+
| ams.in |    ams.out      |    Explicații                                   |
+--------+-----------------+-------------------------------------------------+
|   4    |                 |    Se citește numărul N, apoi cele N cuvinte,   |
|  lmno  |      lmon       |    câte un cuvânt pe un rând.                   |
|  dcba  |       -1        |    Se vor afișa doar cuvintele transformate, în |
|  abdc  |      acbd       |    ordinea datelor de intrare.                  |
|  abcd  |      abdc       |                                                 |
+--------+-----------------+-------------------------------------------------+
*/