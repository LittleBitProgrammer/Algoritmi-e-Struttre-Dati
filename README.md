## Traccia 1
Seguendo i principi di progettazione object oriented, progettare ed implementare in c++ i seguenti punti:

### 1) Insiemi implementati con Alberi Red Black
Si vuole realizzare una struttura dati per insiemi generici basata su *alberi Red Black*. La struttura dati deve consentire di eseguire le operazioni canoniche di *unione*, *intersezione* e *differenza* tra due insiemi. Progettare ed implementare una struttura dati basata su alberi Red Black in cui ogni albero rappresenta un inesieme che consenta di effettuare le seguenti operazioni:

- UNION()
- INTERSECT()
- DIFFERENCE()

Gli elementi degli insiemi (*numeri interi*) sono memorizzati all'interno del *file di testo*. Gli elementi appartenenti ad uno stesso insieme si trovano su una stessa riga separati da uno spazio (righe successive corrispondono ai diversi insiemi). Dotare il programma di un menu da cui sia possibile richiamare le suddette operazioni.

### 2) Percorsi nell'Arcipelago
Dopo il terribile terremoto del Dicembre 2019, a seguito di ingenti investimenti economici, la regina dell'arcipelago di Grapha-Nui è riuscita a ripristinare i collegamenti tra le isole. È ora necessario incentivare il turismo nell'arcipelago per rimpinguare le casse del governo ed a tal fine il Primo Ministro vuole sapere quali collegamenti tra le isole pubblicizzare maggiormente. Viene nuovamente convocata la famosa consulente informatica Ros Walker con il compito di calcolare i percorsi che massimizzano la soddisfazione dei turisti, partendo da una generica isola verso tutte le altre isole. Ros ha a disposizione la piantina dell'arcipelago con la rete di collegamenti tra le isole. Per ogni collegamento la piantina specifica la *direzione* ed un *valore (anche negativo)* che misura la qualità del collegamento. I collegamenti tra le isole non danno origine a cicli.

#### Dati di input
È assegnato un file di testo contenente nel primo rigo due interi separati da uno spazio: il numero *N* delle isole (numerate da 0 a N-1) ed il numero *P* dei ponti. I successivi P righi contengono ciascuno tre numeri *I1*, *I2* e *Q* per indicare che è possibile raggiungere l'isola I2 dall'isola I1 dove Q rappresenta la qualità del collegamento

#### Dati di output
Determinare i percorsi con la massima qualità totale tra l'isola sorgente e tutte le altre isole

#### Assunzioni
- 2 <= N <= 1000  (numero isole tra 2 e 1000)
- 1 <= P <= 10000 (numero ponti tra 1 e 10000)
- Q_i in Z per ogni collegamento

#### Esempio
input.txt | Output (partendo dall'isola 1)
--------- | ------------------------------
6 10 | 1->0 -infty
0 1 5 | 1->1 0
0 2 3 | 1->2 2
1 3 6 | 1->3 9
1 2 2 | 1->4 8
2 4 4 | 1->5 10
2 5 2 |
2 3 7 |
3 5 1 |
3 4 -1|
4 5 -2|

![Grafo esempio](/images/Grafo.png)

ToDo List:
- [ ] Implementare Alberi Red Black
- [ ] Implementare Insiemi con Alberi Red Black
- [ ] Implementare Unione tra alberi Red Black
- [ ] Implementare Intersezione tra alberi Red Black
- [ ] Implementare Differenza tra alberi Red Black
- [ ] Implementare operation Overloading per le operazioni canoniche degli insiemi
- [ ] Implementare lettura da file per costruzione degli insiemi
- [ ] Implementare un menu per effettuare operazioni canoniche sull'insieme
- [X] Implementare un Max Heap per simulare una max priority queue
- [ ] Implementare un grafo orientato pesato con funzione peso w:E->Z
- [ ] Implementare lettura da file per generazione grafo
- [ ] Implementare algoritmo per massima qualità totale tra le isole
- [X] Implementare Heap Sort
