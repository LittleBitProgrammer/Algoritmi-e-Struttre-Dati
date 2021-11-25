#include "SetGenerator.h"
using std::cin;

int main()
{
    short menu; /* Variabile per la scelta della voce nel menu */
    string filename; /* Nome del file da cui vogliamo leggere i valori numerici che comporranno gli insiemi */

    /* Richiesta del nome del file */
    cout << "Inserire il nome del file per la popolazione degli insiemi:" << endl;
    cin >> filename;

    do
    {
        /* Stampa del menu */
        cout << "Seleziona:" << endl;
        cout << "[0] Uscita dal programma" << endl;
        cout << "[1] Visualizzare tutti gli insiemi con lettura inorder" << endl;
        cout << "[2] Visualizzare tutti gli insiemi con lettura preorder" << endl;
        cout << "[3] Visualizzare tutti gli insiemi con lettura postorder" << endl;
        cout << "[4] Visualizzare un dato insieme come albero red-black" << endl;
        cout << "[5] Eseguire operazione canonica di unione tra due insieme scelti" << endl;
        cout << "[6] Eseguire operazione canonica di intersezione tra due insiemi scelti" << endl;
        cout << "[7] Eseguire operazione canonica di differenza tra due insiemi scelti" << endl;
        cout << "[8] Aggiungere un valore numerico ad un dato insieme" << endl;
        cout << "[9] Rimuovere un valore da un dato insieme" << endl;

        /* Resettiamo lo stream associato allo standard input */
        cin.clear();
        /* Richiediamo all'utente di scegliere una delle voci nel menu */
        cout << "\nScelta: ";
        cin >> menu;

        switch(menu)
        {
            case 0:
                exit(0);
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            default:
                cout << "Scelta non presente, riprovare.";
                /* Break non necessario */
        }
    } while (menu != 0);

    SetGenerator setGenerator{"input1_1_0.txt"};

    vector<NumSet> sets = setGenerator.generate_sets();


    return 0;
}