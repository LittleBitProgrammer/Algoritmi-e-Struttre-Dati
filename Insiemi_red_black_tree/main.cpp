#include "SetGenerator.h"
using std::cin;

int main()
{
    short menu; /* Variabile per la scelta della voce nel menu */
    string filename; /* Nome del file da cui vogliamo leggere i valori numerici che comporranno gli insiemi */

    /* Richiesta del nome del file */
    cout << "Inserire il nome del file per la popolazione degli insiemi:" << endl;
    cin >> filename;

    /* Generiamo gli insiemi sfruttando il file indicato dall'utente */
    SetGenerator setGenerator{filename};
    vector<NumSet> sets = setGenerator.generate_sets();

    cout << "\n**\t Generazione degli insiemi avvenuta con successo \t**\n" << endl;

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

        /* Resettiamo lo stream associato allo standard input */
        cin.clear();
        /* Richiediamo all'utente di scegliere una delle voci nel menu */
        cout << "\nScelta: ";
        cin >> menu;

        switch(menu)
        {
            case 0:
                cout << "\nProgramma terminato con successo.\n" << endl;
                exit(0);
            case 1:
                if (!sets.empty())
                {
                    int i{0};

                    cout << "\nInorder: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.inorder();
                        cout << endl;
                    }
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 2:
                if (!sets.empty())
                {
                    int i{0};

                    cout << "\nPreorder: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.preorder();
                        cout << endl;
                    }
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 3:
                if (!sets.empty())
                {
                    int i{0};

                    cout << "\nPostorder: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.postorder();
                        cout << endl;
                    }
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 4:
                if (!sets.empty())
                {
                    int set_choice; /* Variabile utile a identificare quale insieme l'utente vuole stampare come RB Tree */

                    cout << "\nDi quale insieme si vuole conoscere la rappresentazione Red-Black Tree?" << endl;

                    int i{0};

                    cout << "\nInsiemi: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.inorder();
                        cout << endl;
                    }
                    cout << "\nScelta insieme: ";
                    cin.clear();
                    cin >> set_choice;

                    if (set_choice == 0 || set_choice > sets.size())
                    {
                        cout << "\nScelta non valida, ravvio il menu." << endl;
                        break;
                    }
                    cout << "Rappresentazione Red-Black Tree dell'insieme [" << set_choice << "]:" << endl;
                    sets.at(set_choice-1).print_tree();
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 5:
                if (!sets.empty())
                {
                    int set1, set2; /* Variabili utili ad identificare gli insiemi su cui eseguire l'operazione di unione */

                    cout << "\nSu quali insiemi si vuole effettuare l'operazione di unione?" << endl;

                    int i{0};

                    cout << "\nInsiemi: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.inorder();
                        cout << endl;
                    }
                    cout << "\nInsieme 1: ";
                    cin.clear();
                    cin >> set1;
                    cout << "\nInsieme 2:";
                    cin.clear();
                    cin >> set2;

                    if (set1 == 0 || set2 == 0 || set1 > sets.size() || set2 > sets.size())
                    {
                        cout << "\nScelta non valida, ravvio il menu." << endl;
                        break;
                    }

                    NumSet *temp_set1 = new NumSet;
                    NumSet *temp_set2 = new NumSet;

                    temp_set1->set_root(sets.at(set1-1).cloning(sets.at(set1-1).get_root(),sets.at(set1-1).get_tnull()));
                    temp_set2->set_root(sets.at(set2-1).cloning(sets.at(set2-1).get_root(),sets.at(set1-1).get_tnull()));

                    NumSet *union_set = temp_set1->set_union(temp_set2);

                    cout << "Unione = ";
                    union_set->inorder();
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 6:
                if (!sets.empty())
                {
                    int set1, set2; /* Variabili utili ad identificare gli insiemi su cui eseguire l'operazione di unione */

                    cout << "\nSu quali insiemi si vuole effettuare l'operazione di unione?" << endl;

                    int i{0};

                    cout << "\nInsiemi: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.inorder();
                        cout << endl;
                    }
                    cout << "\nInsieme 1: ";
                    cin.clear();
                    cin >> set1;
                    cout << "\nInsieme 2:";
                    cin.clear();
                    cin >> set2;

                    if (set1 == 0 || set2 == 0 || set1 > sets.size() || set2 > sets.size())
                    {
                        cout << "\nScelta non valida, ravvio il menu." << endl;
                        break;
                    }

                    NumSet *temp_set1 = new NumSet;
                    NumSet *temp_set2 = new NumSet;

                    temp_set1->set_root(sets.at(set1-1).cloning(sets.at(set1-1).get_root(),sets.at(set1-1).get_tnull()));
                    temp_set2->set_root(sets.at(set2-1).cloning(sets.at(set2-1).get_root(),sets.at(set1-1).get_tnull()));

                    NumSet *intersect_set = temp_set1->set_intersection(temp_set2);

                    cout << "Intersezione = ";
                    intersect_set->inorder();
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            case 7:
                if (!sets.empty())
                {
                    int set1, set2; /* Variabili utili ad identificare gli insiemi su cui eseguire l'operazione di unione */

                    cout << "\nSu quali insiemi si vuole effettuare l'operazione di differenza?" << endl;

                    int i{0};

                    cout << "\nInsiemi: " << endl;
                    for(auto set:sets)
                    {
                        cout << "Insieme [" << ++i << "] = ";
                        set.inorder();
                        cout << endl;
                    }
                    cout << "\nInsieme 1: ";
                    cin.clear();
                    cin >> set1;
                    cout << "\nInsieme 2:";
                    cin.clear();
                    cin >> set2;

                    if (set1 == 0 || set2 == 0 || set1 > sets.size() || set2 > sets.size())
                    {
                        cout << "\nScelta non valida, ravvio il menu." << endl;
                        break;
                    }


                    NumSet *temp_set1 = new NumSet;
                    NumSet *temp_set2 = new NumSet;

                    temp_set1->set_root(sets.at(set1-1).cloning(sets.at(set1-1).get_root(),sets.at(set1-1).get_tnull()));
                    temp_set2->set_root(sets.at(set2-1).cloning(sets.at(set2-1).get_root(),sets.at(set1-1).get_tnull()));

                    NumSet *difference_set = temp_set1->set_difference(temp_set2);

                    cout << "Difference = ";
                    difference_set->inorder();
                    cout << endl;
                }
                else
                {
                    cout << "\nNessun insieme presente in memoria\n" << endl;
                }
                break;
            default:
                cout << "\nScelta non presente, riprovare.\n" << endl;
                /* Break non necessario */
        }
    } while (menu != 0);

    return 0;
}