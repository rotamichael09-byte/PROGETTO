/*
 * ============================================================
 *  PROGRAMMA GRAFICO PER LA GESTIONE DI POLINOMI
 * ============================================================
 *  Autori : ROTA MICHAEL, COLOMBO FRANCESCO, SPINELLI FILIPPO
 *
 *  Descrizione:
 *    Il programma permette all'utente di inserire due polinomi
 *    di grado massimo 3 (cubici) e di eseguire su di essi le
 *    seguenti operazioni:
 *      1. Somma
 *      2. Differenza
 *      3. Prodotto
 *      4. Calcolo degli zeri (radici)
 *      5. Calcolo dei punti di intersezione
 *      6. Visualizzazione grafica con finestra dedicata
 *
 *  Librerie utilizzate:
 *    - iostream   : input/output standard
 *    - cmath      : funzioni matematiche (sqrt, pow)
 *    - conio.h    : lettura di tasti senza invio (getch)
 *    - cctype     : classificazione/conversione caratteri
 *    - graphics2.h: grafica (libreria personalizzata BGI)
 *    - windows.h  : gestione della finestra console (Win32 API)
 * ============================================================
 */

#include <iostream>
#include <cmath>
#include <conio.h>
#include <cctype>                      //librerie occorrenti
#include "graphics2.h"
#include <windows.h>
using namespace std;

int main()
{
    // Pulisce lo schermo della console all'avvio del programma
    system("cls");

    // Imposta il titolo della finestra console
    SetConsoleTitleA("Programma grafico polinomi");

    // Variabile usata per catturare l'input di "premi un tasto per continuare"
    char carattere;

    // Stampa il banner di benvenuto in ASCII art con colore giallo ANSI
    cout << "\033[1;33m";
    cout << " ____  ____   ___   ____ _____ _____ _____ ___    ____   ___  _     ___ _   _  ___  __  __ ___ " << endl;
    cout << "|  _ \\|  _ \\ / _ \\ / ___| ____|_   _|_   _/ _ \\  |  _ \\ / _ \\| |   |_ _| \\ | |/ _ \\|  \\/  |_ _| " << endl;
    cout << "| |_) | |_) | | | | |  _|  _|   | |   | || | | | | |_) | | | | |    | ||  \\| | | | | |\\/| || |  " << endl;
    cout << "|  __/|  _ <| |_| | |_| | |___  | |   | || |_| | |  __/| |_| | |___ | || |\\  | |_| | |  | || |  " << endl;
    cout << "|_|   |_| \\_\\\\___/ \\____|_____| |_|   |_| \\___/  |_|    \\___/|_____|___|_| \\_|\\___/|_|  |_|___| " << endl;
    cout << "\n\033[0m========================================================================================================================";
    cout << "\n\n";

    // Stampa il messaggio di benvenuto e il menu delle funzionalità disponibili
    cout << "\n";
    cout << "|\033[0m                                   |          \n";
    cout << "|  \033[1;33mBENVENUTO NEL NOSTRO PROGRAMMA   \033[0m|\n";
    cout << "|                                   |\n\n";

    cout << "\033[3mCon questo software puoi:\033[0m\n\n";

    cout << "  \033[1;32m[1]\033[0m Sommare due polinomi\n";
    cout << "  \033[1;32m[2]\033[0m Calcolare la differenza\n";
    cout << "  \033[1;32m[3]\033[0m Fare il prodotto\n";
    cout << "  \033[1;32m[4]\033[0m Trovare gli zeri\n";
    cout << "  \033[1;32m[5]\033[0m Calcolare l'intersezione tra polinomi\n";
    cout << "  \033[1;32m[6]\033[0m Visualizzare il grafico\n\n";

    // Crediti: nomi dei componenti del gruppo
    cout << "\033[1;35mMembri del gruppo:\033[0m\n\n";

    cout << "  \033[37mROTA MICHAEL\033[0m\n";
    cout << "  \033[37mCOLOMBO FRANCESCO\033[0m\n";
    cout << "  \033[37mSPINELLI FILIPPO\033[0m\n\n";
    cout << "\033[1;3;4m\nPremi un tasto per continuare\033[0m . . .";

    // Attende la pressione di un qualsiasi tasto per procedere
    carattere = getch();

    // Flag che indica se è necessario re-inserire i polinomi (true = primo avvio o reset)
    bool primo = true;

    system("cls");

    /*
     * Rappresentazione dei polinomi come array di coefficienti:
     *   pol[0] = termine noto        (coefficiente di x^0)
     *   pol[1] = coefficiente di x^1
     *   pol[2] = coefficiente di x^2
     *   pol[3] = coefficiente di x^3
     * Il grado massimo supportato è 3 (polinomio cubico).
     */
    double pol1[4];   // Coefficienti del primo polinomio  P(x)
    double pol2[4];   // Coefficienti del secondo polinomio R(x)

    // Inizializzazione a zero di tutti i coefficienti
    for (int i = 3; i >= 0; i--)
    {
        pol1[i] = 0;
        pol2[i] = 0;
    }

    int numeri;    // Grado del primo polinomio inserito dall'utente
    int numeri2;   // Grado del secondo polinomio inserito dall'utente
    bool uguali = true;  // Flag: true se i due polinomi sono identici (usato per ottimizzare alcune operazioni)

    // Imposta la precisione di stampa a 2 cifre decimali per i double
    cout.precision(2);

    // ============================================================
    // CICLO PRINCIPALE DEL PROGRAMMA
    // Rimane attivo finché l'utente non sceglie di uscire (opz == '9')
    // ============================================================
    while (true)
    {
        // Blocco di inserimento polinomi: viene eseguito all'avvio
        // e ogni volta che l'utente sceglie l'opzione '0' (reinserimento)
        if (primo == true)
        {
            // Reset del flag di uguaglianza e azzeramento dei coefficienti
            uguali = true;
            for (int i = 3; i >= 0; i--)
            {
                pol1[i] = 0;
                pol2[i] = 0;
            }

            // Stampa del titolo della sezione "INSERIMENTO" in ASCII art
            cout << "\033[1;33m";
            cout << " ___ _   _ ____  _____ ____  ___ __  __ _____ _   _ _____ ___  " << endl;
            cout << "|_ _| \\ | / ___|| ____|  _ \\|_ _|  \\/  | ____| \\ | |_   _/ _ \\ " << endl;
            cout << " | ||  \\| \\___ \\|  _| | |_) || || |\\/| |  _| |  \\| | | || | | |" << endl;
            cout << " | || |\\  |___) | |___|  _ < | || |  | | |___| |\\  | | || |_| |" << endl;
            cout << "|___|_| \\_|____/|_____|_| \\_\\___|_|  |_|_____|_| \\_| |_| \\___/ " << endl;
            cout << "\033[0m" << endl;

            // Acquisizione del grado del PRIMO polinomio con validazione
            // Vengono accettati solo valori interi compresi tra 0 e 3

            do
            {
                cout << "\n\033[1m\033[3mQuale grado vuoi inserire nel primo polinomio : \033[0m";
                cin >> numeri;

                if (cin.fail())
                {
                    // Input non numerico: pulisce il buffer e richiede nuovamente
                    cout << "\033[31mAttenzione accetto solo numeri :( \033[0m\n\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else if (numeri > 3 || numeri < 0)
                {
                    // Grado fuori dal range consentito
                    cout << "\033[33mAttenzione il mio numero massimo e' 3 :|\033[0m\n\n";
                }
                else
                {
                    break; // Input valido: esce dal ciclo di validazione
                }

            } while (true);

            cout << "\n\n\033[1m\033[3m";

            // Acquisizione dei coefficienti del PRIMO polinomio
            // Vengono richiesti dal grado più alto fino al termine noto

            for (int i = numeri; i >= 0; i--)
            {
                while (true)
                {
                    // Messaggio differenziato per il termine noto rispetto agli altri coefficienti
                    if (i != 0)
                    {
                        cout << "Valore alla " << i << "^ :\t";
                    }
                    else
                    {
                        cout << "Termine noto :\t\t";
                    }

                    cin >> pol1[i];

                    if (cin.fail())
                    {
                        // Gestione input non valido
                        cout << "\033[31mAttenzione! Inserisci solo numeri.\033[0m\n\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                    {
                        break; // Coefficiente acquisito correttamente
                    }
                }
            }

            cout << "\n\n\n\n";

            // Acquisizione del grado del SECONDO polinomio con validazione

            do
            {
                cout << "\n\033[1m\033[3mQuale grado vuoi inserire nel secondo polinomio : \033[0m";
                cin >> numeri2;

                if (cin.fail())
                {
                    cout << "\033[31mAttenzione accetto solo numeri :( \033[0m\n\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                else if (numeri2 > 3 || numeri2 < 0)
                {
                    cout << "\033[33mAttenzione il mio numero massimo e' 3 :|\033[0m\n\n";
                }
                else
                {
                    break;
                }

            } while (true);

            cout << "\n";

            // Acquisizione dei coefficienti del SECONDO polinomio

            for (int i = numeri2; i >= 0; i--)
            {
                while (true)
                {
                    if (i != 0)
                    {
                        cout << "Valore alla " << i << "^ :\t";
                    }
                    else
                    {
                        cout << "Termine noto :\t\t";
                    }

                    cin >> pol2[i];

                    if (cin.fail())
                    {
                        cout << "\033[31mAttenzione! Inserisci solo numeri.\033[0m\n\n";
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                    else
                    {
                        break;
                    }
                }
            }

            // Verifica se i due polinomi sono identici confrontando
            // tutti i coefficienti uno per uno

            for (int i = 3; i >= 0; i--)
            {
                if (pol1[i] != pol2[i])
                {
                    uguali = false; // Almeno un coefficiente differisce
                }
            }

            // Stampa riepilogativa dei due polinomi inseriti
            // Vengono omessi i termini con coefficiente nullo
            // Il segno '+' viene aggiunto esplicitamente per i positivi

            cout << "\n\n\n\033[31mP(x) \033[0m: ";

            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0) // Salta i termini con coefficiente zero
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0)
                        {
                            cout << " +" << pol1[i] << "x^" << i;
                        }
                        else
                        {
                            cout << " " << pol1[i] << "x^" << i;
                        }
                    }
                    else
                    {
                        if (pol1[i] > 0)
                        {
                            cout << " +" << pol1[i] << "\n";
                        }
                        else
                        {
                            cout << " " << pol1[i] << "\n";
                        }
                    }
                }
            }
            cout << "\n\033[33mR(x)\033[0m : ";

            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0)
                        {
                            cout << " +" << pol2[i] << "x^" << i;
                        }
                        else
                        {
                            cout << " " << pol2[i] << "x^" << i;
                        }
                    }
                    else
                    {
                        if (pol2[i] > 0)
                        {
                            cout << " +" << pol2[i];
                        }
                        else
                        {
                            cout << " " << pol2[i];
                        }
                    }
                }
            }

            primo = false; // L'inserimento è completato: non rieseguire questo blocco
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // MENU PRINCIPALE DELLE OPERAZIONI
        // ============================================================
        cout << "\033[1;33m";
        cout << " __  __ _____ _   _ _   _ " << endl;
        cout << "|  \\/  | ____| \\ | | | | |" << endl;
        cout << "| |\\/| |  _| |  \\| | | | |" << endl;
        cout << "| |  | | |___| |\\  | |_| |" << endl;
        cout << "|_|  |_|_____|_| \\_|\\___/ " << endl;
        cout << "\x1b[0m";

        char opz;  // Carattere che identifica l'operazione scelta dall'utente

        // Array per il risultato delle operazioni (somma, differenza, prodotto).
        // Ha dimensione 7 perché il prodotto di due polinomi di grado 3 può arrivare a grado 6.
        double polfine[7];
        for (int i = 6; i >= 0; i--)
        {
            polfine[i] = 0;
        }

        cout << "\n\n\033[1m\033[3mCosa vuoi fare oggi con i tuoi polinomi?\033[0m\n\n";
        cout << "  \033[1;32m[1]\033[0m SOMMA \t\t-> somma tra P(x) + R(x)\n";
        cout << "  \033[1;32m[2]\033[0m DIFFERENZA \t-> Differenza tra P(x) - R(x)\n";
        cout << "  \033[1;32m[3]\033[0m PRODOTTO \t\t-> Prodotto tra P(x) * R(x)\n";
        cout << "  \033[1;32m[4]\033[0m ZERI \t\t-> Trova i valori di x\n";
        cout << "  \033[1;32m[5]\033[0m INTERSEZIONI \t-> Trova i punti di intersezione tra P(x) e R(x)\n";
        cout << "  \033[1;32m[6]\033[0m GRAFICO \t\t-> Visualizza il grafico\n\n";
        cout << "  \033[1;32m[9]\033[0m ESCI \t\t-> Chiude il programma\n\n\n";

        // Ciclo di validazione per l'input dell'operazione (accetta solo '0'-'6' e '9')
        do
        {
            cout << "\033[1m\033[3mInserisci operazione : ";
            opz = getch();

            if ((opz >= '0' && opz <= '6') || opz == '9')
            {
                cout << opz;
                break; // Input valido
            }

            cout << "  \033[31mInput non valido! Usa solo 1-6 oppure 9.\033[0m\n\n";

        } while (true);

        system("cls");

        // ============================================================
        // OPZIONE 0 : Reinserimento dei polinomi
        // ============================================================
        if (opz == '0')
        {
            primo = true; // Forza il rientro nel blocco di inserimento
            continue;
        }

        // ============================================================
        // OPZIONE 1 : SOMMA  P(x) + R(x)
        // I coefficienti vengono sommati termine per termine (stessa potenza)
        // ============================================================
        else if (opz == '1')
        {
            cout << "\033[1;33m";
            cout << " ____   ___  __  __ __  __    _ " << endl;
            cout << "/ ___| / _ \\|  \\/  |  \\/  |  / \\ " << endl;
            cout << "\\___ \\| | | | |\\/| | |\\/| | / _ \\ " << endl;
            cout << " ___) | |_| | |  | | |  | |/ ___ \\ " << endl;
            cout << "|____/ \\___/|_|  |_|_|  |_/_/   \\_\\" << endl;
            cout << "\n\033[0m=====================================\n\n";

            // Somma coefficiente per coefficiente (a[i] + b[i])
            for (int i = 3; i >= 0; i--)
            {
                polfine[i] = pol1[i] + pol2[i];
            }

            // Stampa P(x)
            cout << "Polinomio \033[31mP(x)\033[32m\n";
            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i] << "x^" << i;
                        else             cout << " "  << pol1[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i];
                        else             cout << " "  << pol1[i];
                    }
                }
            }

            // Stampa R(x)
            cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";
            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i] << "x^" << i;
                        else             cout << " "  << pol2[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i];
                        else             cout << " "  << pol2[i];
                    }
                }
            }

            // Stampa il risultato: se tutti i coefficienti sono zero il risultato è il polinomio nullo
            if (polfine[1] == 0 && polfine[0] == 0 && polfine[2] == 0 && polfine[3] == 0)
            {
                cout << "\n\n\033[0m------------------------------------\n\033[32m0";
            }
            else
            {
                cout << "\n\n\033[0m------------------------------------\nPolinomio \033[31mP(x)\033[0m + \033[33mR(x)\033[32m\n";
                for (int i = 3; i >= 0; i--)
                {
                    if (polfine[i] != 0)
                    {
                        if (i != 0)
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i] << "x^" << i;
                            else                cout << " "  << polfine[i] << "x^" << i;
                        }
                        else
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i];
                            else                cout << " "  << polfine[i];
                        }
                    }
                }
            }
            cout << "\n\033[0m------------------------------------\n\n";
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // OPZIONE 2 : DIFFERENZA  P(x) - R(x)
        // Analoga alla somma ma sottrae i coefficienti di R(x) da quelli di P(x)
        // ============================================================
        else if (opz == '2')
        {
            cout << "\033[1;33m";
            cout << " ___  ___ _____ _____ _____ ____  _____ _   _ _____  _ \n";
            cout << "|  _ \\|_ _|  ___|  ___| ____|  _ \\| ____| \\ | |__  / / \\ \n";
            cout << "| | | || || |_  | |_  |  _| | |_) |  _| |  \\| |  / / / _ \\ \n";
            cout << "| |_| || ||  _| |  _| | |___|  _ <| |___| |\\  | / /_/ ___ \\ \n";
            cout << "|____/|___|_|   |_|   |_____|_| \\_\\_____|_| \\_|/____/_/   \\_\\\n";
            cout << "\n\033[0m=================================================================\n\n";

            // Differenza coefficiente per coefficiente (a[i] - b[i])
            for (int i = 3; i >= 0; i--)
            {
                polfine[i] = pol1[i] - pol2[i];
            }

            // Stampa P(x)
            cout << "Polinomio \033[31mP(x)\033[32m\n";
            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i] << "x^" << i;
                        else             cout << " "  << pol1[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i];
                        else             cout << " "  << pol1[i];
                    }
                }
            }

            // Stampa R(x)
            cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";
            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i] << "x^" << i;
                        else             cout << " "  << pol2[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i];
                        else             cout << " "  << pol2[i];
                    }
                }
            }

            // Stampa risultato
            if (polfine[1] == 0 && polfine[0] == 0 && polfine[2] == 0 && polfine[3] == 0)
            {
                cout << "\n\n\033[0m------------------------------------\n\033[32m0";
            }
            else
            {
                cout << "\n\n\033[0m------------------------------------\nPolinomio \033[31mP(x)\033[0m - \033[33mR(x)\033[32m\n";
                for (int i = 3; i >= 0; i--)
                {
                    if (polfine[i] != 0)
                    {
                        if (i != 0)
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i] << "x^" << i;
                            else                cout << " "  << polfine[i] << "x^" << i;
                        }
                        else
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i];
                            else                cout << " "  << polfine[i];
                        }
                    }
                }
            }
            cout << "\n\033[0m------------------------------------\n\n";
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // OPZIONE 3 : PRODOTTO  P(x) * R(x)
        // Implementa la moltiplicazione polinomiale tramite doppio ciclo:
        // ogni coppia di monomi (pol1[i], pol2[j]) contribuisce al termine
        // di grado i+j del risultato con il prodotto dei rispettivi coefficienti.
        // ============================================================
        if (opz == '3')
        {
            cout << "\033[1;33m";
            cout << " ____  ____   ___  ____   ___ _____ _____ ___  " << endl;
            cout << "|  _ \\|  _ \\ / _ \\|  _ \\ / _ \\_   _|_   _/ _ \\ " << endl;
            cout << "| |_) | |_) | | | | | | | | | || |   | || | | |" << endl;
            cout << "|  __/|  _ <| |_| | |_| | |_| || |   | || |_| |" << endl;
            cout << "|_|   |_| \\_\\\\___/|____/ \\___/ |_|   |_| \\___/ " << endl;
            cout << "\n\033[0m=================================================\n\n";

            // Moltiplicazione polinomiale: polfine[i+j] += pol1[i] * pol2[j]
            // Il grado risultante può arrivare a 3+3 = 6, da cui la dimensione 7 di polfine
            for (int i = 3; i >= 0; i--)
            {
                for (int j = 3; j >= 0; j--)
                {
                    polfine[i + j] += pol1[i] * pol2[j];
                }
            }

            // Stampa P(x)
            cout << "Polinomio \033[31mP(x)\033[32m\n";
            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i] << "x^" << i;
                        else             cout << " "  << pol1[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i];
                        else             cout << " "  << pol1[i];
                    }
                }
            }

            // Stampa R(x)
            cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";
            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i] << "x^" << i;
                        else             cout << " "  << pol2[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i];
                        else             cout << " "  << pol2[i];
                    }
                }
            }

            // Stampa risultato (fino al grado 6)
            if (polfine[1] == 0 && polfine[0] == 0 && polfine[2] == 0 && polfine[3] == 0)
            {
                cout << "\n\n\033[0m------------------------------------\n\033[32m0";
            }
            else
            {
                cout << "\n\n\033[0m------------------------------------\nPolinomio \033[31mP(x)\033[0m * \033[33mR(x)\033[32m\n";
                for (int i = 6; i >= 0; i--)
                {
                    if (polfine[i] != 0)
                    {
                        if (i != 0)
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i] << "x^" << i;
                            else                cout << " "  << polfine[i] << "x^" << i;
                        }
                        else
                        {
                            if (polfine[i] > 0) cout << " +" << polfine[i];
                            else                cout << " "  << polfine[i];
                        }
                    }
                }
            }
            cout << "\n\033[0m------------------------------------\n\n";
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // OPZIONE 4 : ZERI (RADICI) dei due polinomi
        //
        // Algoritmo utilizzato in base al grado:
        //   Grado 1 : x = -termine_noto / coefficiente_x
        //   Grado 2 : formula quadratica  x = (-b ± √Δ) / (2a)
        //             con Δ = b² - 4ac
        //             Δ < 0  → nessuna soluzione reale
        //             Δ >= 0 → due soluzioni reali (coincidenti se Δ=0)
        //   Grado 3 : riconosciuto ma non risolto analiticamente
        // ============================================================
        else if (opz == '4')
        {
            cout << "\033[1;33m";
            cout << " ____  ___ ____   ___  _    _   _ _____ ___ ___  _   _ _____ " << endl;
            cout << "|  _ \\|_ _/ ___| / _ \\| |  | | | |__  /|_ _/ _ \\| \\ | | ____|" << endl;
            cout << "| |_) || |\\___ \\| | | | |  | | | | / /  | | | | |  \\| |  _|  " << endl;
            cout << "|  _ < | | ___) | |_| | |__| |_| |/ /_  | | |_| | |\\  | |___ " << endl;
            cout << "|_| \\_\\___|____/ \\___/|_____\\___//____|___\\___/|_| \\_|_____|" << endl;
            cout << "\n\033[0m=============================================================\n\n";

            // Stampa i polinomi inseriti come riferimento
            cout << "Polinomi inseriti :\n\n\033[31mP(x) \033[0m= \033[32m";
            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i] << "x^" << i;
                        else             cout << " "  << pol1[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i];
                        else             cout << " "  << pol1[i];
                    }
                }
            }

            cout << "\n\n\033[33mR(x) \033[0m= \033[32m";
            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i] << "x^" << i;
                        else             cout << " "  << pol2[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i];
                        else             cout << " "  << pol2[i];
                    }
                }
            }

            cout << "\n\n\033[0m------------------------------------\n\nZeri di \033[31mP(x)\033[0m:\n\033[32m";

            // --- Calcolo zeri di P(x) ---
            if (pol1[3] != 0)
            {
                // Il programma non gestisce analiticamente il caso cubico
                cout << "Polinomio di terzo grado";
            }
            else if (pol1[3] == 0)
            {
                if (pol1[2] == 0)
                {
                    // Grado ≤ 1
                    if (pol1[1] == 0)
                    {
                        // Polinomio costante: nessuna incognita
                        cout << "Non ci sono X";
                    }
                    else if (pol1[1] != 0 && pol1[0] == 0)
                    {
                        // Forma: a*x = 0  →  x = 0
                        cout << "X : \033[32m0\033[0m";
                    }
                    else
                    {
                        // Forma: a*x + b = 0  →  x = -b/a
                        cout << " X : " << (pol1[0] * -1) / pol1[1];
                    }
                }
                else if (pol1[2] != 0)
                {
                    // Grado 2: equazione di secondo grado  ax² + bx + c = 0
                    if (pol1[0] != 0 && pol1[1] != 0 && pol1[2] != 0)
                    {
                        // Caso generale: tutti e tre i coefficienti sono non nulli
                        int delta;
                        delta = pow(pol1[1], 2) - (4 * pol1[0] * pol1[2]); // Δ = b² - 4ac
                        if (delta < 0)
                        {
                            cout << "Non ci sono soluzioni"; // Discriminante negativo → no soluzioni reali
                        }
                        else if (delta >= 0)
                        {
                            // Formula quadratica: x = (-b ± √Δ) / (2a)
                            cout << "X1 : " << ((pol1[1] * -1) + sqrt(delta)) / (pol1[2] * 2);
                            cout << "\nX2 : " << ((pol1[1] * -1) - sqrt(delta)) / (pol1[2] * 2);
                        }
                    }
                    else if (pol1[0] == 0 && pol1[1] != 0 && pol1[2] != 0)
                    {
                        // Forma: ax² + bx = 0  →  x(ax + b) = 0  →  x=0 oppure x=-b/a
                        cout << "X1 : 0";
                        cout << "\nX2 : " << (pol1[1] * -1) / pol1[2];
                    }
                    else if (pol1[0] != 0 && pol1[1] == 0 && pol1[2] != 0)
                    {
                        // Forma: ax² + c = 0  →  x² = -c/a
                        if (pol1[0] * -1 < 0)
                        {
                            cout << "Impossibile"; // -c/a < 0: radice di numero negativo
                        }
                        else if (pol1[0] * -1 > 0)
                        {
                            // x = ± √(-c/a)
                            cout << "X1 : -" << sqrt((pol1[0] * -1) / pol1[2]);
                            cout << "\nX2 : +" << sqrt((pol1[0] * -1) / pol1[2]);
                        }
                    }
                    else if (pol1[0] == 0 && pol1[1] == 0 && pol1[2] != 0)
                    {
                        // Forma: ax² = 0  →  x = 0 (radice doppia)
                        cout << "X : \033[32m0\033[0m";
                    }
                }
            }

            // Se i polinomi sono uguali non ricalcola gli zeri di R(x)
            if (uguali)
            {
                cout << "\033[0m\n\nLe X di \033[33mR(x) \033[0msono le stesse essendo i due polinomi uguali";
            }
            else
            {
                // --- Calcolo zeri di R(x) con la stessa logica usata per P(x) ---
                cout << "\n\n\033[0mZeri di \033[33mR(x)\033[0m:\n\033[32m";

                if (pol2[3] != 0)
                {
                    cout << "Polinomio di terzo grado";
                }
                else if (pol2[3] == 0)
                {
                    if (pol2[2] == 0)
                    {
                        if (pol2[1] == 0)
                        {
                            cout << "Non ci sono X";
                        }
                        else if (pol2[1] != 0 && pol2[0] == 0)
                        {
                            cout << "X : \033[32m0\033[0m";
                        }
                        else
                        {
                            cout << " X : " << (pol2[0] * -1) / pol2[1];
                        }
                    }
                    else if (pol2[2] != 0)
                    {
                        if (pol2[0] != 0 && pol2[1] != 0 && pol2[2] != 0)
                        {
                            int delta;
                            delta = pow(pol2[1], 2) - (4 * pol2[0] * pol2[2]);
                            if (delta < 0)
                            {
                                cout << "Non ci sono soluzioni";
                            }
                            else if (delta >= 0)
                            {
                                cout << "X1 : " << ((pol2[1] * -1) + sqrt(delta)) / (pol2[2] * 2);
                                cout << "\nX2 : " << ((pol2[1] * -1) - sqrt(delta)) / (pol2[2] * 2);
                            }
                        }
                        else if (pol2[0] == 0 && pol2[1] != 0 && pol2[2] != 0)
                        {
                            cout << "X1 : 0";
                            cout << "\nX2 : " << (pol2[1] * -1) / pol2[2];
                        }
                        else if (pol2[0] != 0 && pol2[1] == 0 && pol2[2] != 0)
                        {
                            if (pol2[0] * -1 < 0)
                            {
                                cout << "Impossibile";
                            }
                            else if (pol2[0] * -1 > 0)
                            {
                                cout << "X1 : -" << sqrt((pol2[0] * -1) / pol2[2]);
                                cout << "\nX2 : +" << sqrt((pol2[0] * -1) / pol2[2]);
                            }
                        }
                        else if (pol1[0] == 0 && pol1[1] == 0 && pol1[2] != 0)
                        {
                            cout << "X : \033[32m0\033[0m";
                        }
                    }
                }
            }
            cout << "\n\n\033[0m------------------------------------\n\n";
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // OPZIONE 5 : INTERSEZIONI tra P(x) e R(x)
        //
        // I punti di intersezione si trovano risolvendo P(x) = R(x),
        // ovvero calcolando gli zeri di D(x) = P(x) - R(x).
        // Una volta trovate le ascisse x, le ordinate y si ricavano
        // sostituendo x in P(x).
        // ============================================================
        else if (opz == '5')
        {
            cout << "\033[1;33m";
            cout << " ___ _   _ _____ _____ ____  ____  _____ _____ ___ ___  _   _ ___ " << endl;
            cout << "|_ _| \\ | |_   _| ____|  _ \\/ ___|| ____|__  /|_ _/ _ \\| \\ | |_ _|" << endl;
            cout << " | ||  \\| | | | |  _| | |_) \\___ \\|  _|   / /  | | | | |  \\| || | " << endl;
            cout << " | || |\\  | | | | |___|  _ < ___) | |___ / /_  | | |_| | |\\  || | " << endl;
            cout << "|___|_| \\_| |_| |_____|_| \\_\\____/|_____/____|___\\___/|_| \\_|___|" << endl;
            cout << "\n\033[0m==================================================================\n\n";

            // Stampa i polinomi di riferimento
            cout << "Polinomi inseriti :\n\n\033[31mP(x) \033[0m= \033[32m";
            for (int i = numeri; i >= 0; i--)
            {
                if (pol1[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i] << "x^" << i;
                        else             cout << " "  << pol1[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol1[i] > 0) cout << " +" << pol1[i];
                        else             cout << " "  << pol1[i];
                    }
                }
            }

            cout << "\n\n\033[33mR(x) \033[0m= \033[32m";
            for (int i = numeri2; i >= 0; i--)
            {
                if (pol2[i] != 0)
                {
                    if (i != 0)
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i] << "x^" << i;
                        else             cout << " "  << pol2[i] << "x^" << i;
                    }
                    else
                    {
                        if (pol2[i] > 0) cout << " +" << pol2[i];
                        else             cout << " "  << pol2[i];
                    }
                }
            }
            cout << "\n\n\033[0m------------------------------------";
            cout << "\n\n\033[0mCerchiamo i punti in cui i polinomi si incontrano :\n\n";

            if (uguali)
            {
                // Polinomi identici → infiniti punti in comune (coincidenti)
                cout << "\nI due polinomi sono \033[32mcoincidenti \033[0messendo uguali";
            }
            else
            {
                double x1 = 0;
                double x2 = 0;
                double y1;
                double y2;

                // Calcola D(x) = P(x) - R(x): le sue radici sono le ascisse di intersezione
                for (int i = 3; i >= 0; i--)
                {
                    polfine[i] = pol1[i] - pol2[i];
                }

                if (polfine[3] != 0)
                {
                    // Caso cubico: non gestito analiticamente
                    cout << "Polinomio di terzo grado";
                }
                else if (polfine[3] == 0)
                {
                    if (polfine[2] == 0)
                    {
                        // D(x) ha grado ≤ 1
                        if (polfine[1] == 0)
                        {
                            // D(x) è costante non nulla: nessuna intersezione
                            cout << "\033[31mNon ci sono punti di intersezione\033[0m";
                        }
                        else if (polfine[1] != 0 && polfine[0] == 0)
                        {
                            // D(x) = a*x → x = 0
                            x1 = 0;
                            y1 = (pol1[1] * x1) + pol1[0];
                            cout << "( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )";
                        }
                        else
                        {
                            // D(x) = a*x + b → x = -b/a
                            x1 = (polfine[0] * -1) / polfine[1];
                            y1 = (pol1[1] * x1) + pol1[0];
                            cout << "( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )";
                        }
                    }
                    else if (polfine[2] != 0)
                    {
                        // D(x) ha grado 2: si applica la formula quadratica
                        if (polfine[0] != 0 && polfine[1] != 0 && polfine[2] != 0)
                        {
                            // Caso generale quadratico
                            int delta;
                            delta = pow(polfine[1], 2) - (4 * polfine[0] * polfine[2]);

                            if (delta < 0)
                            {
                                cout << "\033[31mNon ci sono punti di intersezione\033[0m";
                            }
                            else
                            {
                                // Due ascisse distinte (o coincidenti se Δ=0)
                                x1 = ((polfine[1] * -1) + sqrt(delta)) / (polfine[2] * 2);
                                x2 = ((polfine[1] * -1) - sqrt(delta)) / (polfine[2] * 2);

                                // Calcola le ordinate sostituendo in P(x)
                                y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
                                y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

                                cout << "1( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )\n";
                                cout << "2( X ; Y ) == ( \033[32m" << x2 << "\033[0m ; \033[32m" << y2 << " \033[0m )";
                            }
                        }
                        else if (polfine[0] == 0 && polfine[1] != 0 && polfine[2] != 0)
                        {
                            // D(x) = ax² + bx → x=0 oppure x=-b/a
                            x1 = 0;
                            x2 = (polfine[1] * -1) / polfine[2];

                            y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
                            y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

                            cout << "1( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )\n";
                            cout << "2( X ; Y ) == ( \033[32m" << x2 << "\033[0m ; \033[32m" << y2 << " \033[0m )";
                        }
                        else if (polfine[0] != 0 && polfine[1] == 0 && polfine[2] != 0)
                        {
                            // D(x) = ax² + c → x = ± √(-c/a)
                            if (polfine[0] * -1 < 0)
                            {
                                cout << "\0033[31mNon ci sono punti di intersezione\033[0m";
                            }
                            else
                            {
                                x1 = sqrt((polfine[0] * -1) / polfine[2]);
                                x2 = -sqrt((polfine[0] * -1) / polfine[2]);

                                y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
                                y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

                                cout << "1( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )\n";
                                cout << "2( X ; Y ) == ( \033[32m" << x2 << "\033[0m ; \033[32m" << y2 << " \033[0m )";
                            }
                        }
                        else if (pol2[2] != 0 && polfine[1] == 0 && polfine[0] == 0)
                        {
                            // D(x) = ax² → x = 0 (tangenza in x=0)
                            x1 = 0;
                            y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
                            cout << "( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )";
                        }
                        else
                        {
                            cout << "\033[31mNon ci sono punti di intersezione\033[0m";
                        }
                    }
                }
            }
            cout << "\n\n\033[0m------------------------------------\n\n";
            cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
            carattere = getch();
            system("cls");
        }

        // ============================================================
        // OPZIONE 6 : GRAFICO
        //
        // Apre una finestra grafica BGI (601×702 pixel) e disegna:
        //   - Assi cartesiani con tacche di scala
        //   - P(x) e R(x) come sequenze di cerchi campionati ogni 0.5 unità
        //     nell'intervallo [-5, 5]
        //   - Legenda colorata in basso
        //
        // Controlli da tastiera nella finestra grafica:
        //   '+' → aumenta la scala di 5 unità (zoom out matematico)
        //   '-' → diminuisce la scala di 5 unità (zoom in matematico)
        //   'i' → accede alla pagina di personalizzazione colori
        //   qualsiasi altro tasto → chiude la finestra e torna al menu
        // ============================================================
        else if (opz == '6')
        {
            bool personalizzazione = true; // true = mostra la pagina di scelta colori
            char funzione;
            bool uni = true;   // true = prima apertura: imposta unita = 20 (valore di default)
            char col1;         // Colore scelto per P(x)
            char col2;         // Colore scelto per R(x)
            int unita;         // Pixel per unità sull'asse (scala del grafico)

            do
            {
                // Se l'utente ha premuto 'i' nella finestra grafica, torna alla personalizzazione
                if (funzione == 'i')
                {
                    personalizzazione = true;
                }

                while (personalizzazione)
                {
                    cout << "Pagina formattazione grafico : \n\n";
                    cout << "  \033[1;31m[r]\033[0m ROSSO\n";
                    cout << "  \033[1;33m[y]\033[0m GIALLO\n";
                    cout << "  \033[1;32m[g]\033[0m VERDE\n";
                    cout << "  \033[1;34m[b]\033[0m BLU\n\n";

                    // Acquisisce il colore del primo polinomio con validazione
                    do
                    {
                        cout << "\033[1m\033[3mInserisci il colore del primo polinomio : ";
                        col1 = getch();
                        cout << col1;

                        if (col1 != 'r' && col1 != 'y' && col1 != 'g' && col1 != 'b')
                        {
                            cout << "  \033[31mErrore: colore non valido!\033[0m" << endl;
                        }
                    } while (col1 != 'r' && col1 != 'y' && col1 != 'g' && col1 != 'b');

                    cout << "\n\n";

                    // Acquisisce il colore del secondo polinomio:
                    // deve essere valido E diverso dal primo per distinguerli visivamente
                    do
                    {
                        cout << "\033[1m\033[3mInserisci il colore del secondo polinomio : ";
                        col2 = getch();
                        cout << col2;

                        if (col2 != 'r' && col2 != 'y' && col2 != 'g' && col2 != 'b')
                        {
                            cout << "  \033[31mErrore: colore non valido!\033[0m" << endl;
                        }
                        else if (col2 == col1)
                        {
                            cout << "  \033[31mErrore: il secondo colore non puo' essere uguale al primo!\033[0m" << endl;
                        }
                    } while ((col2 != 'r' && col2 != 'y' && col2 != 'g' && col2 != 'b') || col2 == col1);

                    // Riepilogo delle scelte colore
                    cout << "\n\n\033[32m\033[1m\033[3mScelte finali\033[0m:" << endl;
                    cout << "Primo polinomio: " << col1 << endl;
                    cout << "Secondo polinomio: " << col2 << endl;

                    cout << "\n\n\033[1m\033[4m\033[3mPremi un tasto per inizializzare la grafica\033[0m . . .";
                    carattere = getch();

                    personalizzazione = false; // Personalizzazione completata
                }

                // Gestione della scala:
                // Prima apertura → valore di default 20 px/unità
                // '+' → +5 px/unità (fino a max 35)
                // '-' → -5 px/unità (fino a min 15, cioè > 10)
                if (uni)
                {
                    unita = 20;
                    uni = false;
                }
                else if (funzione == '+' && unita + 5 <= 35)
                {
                    unita += 5;
                }
                else if (funzione == '-' && unita - 5 > 10)
                {
                    unita -= 5;
                }

                // Nasconde la console mentre è aperta la finestra grafica
                ShowWindow(GetConsoleWindow(), SW_HIDE);

                // Inizializza la finestra grafica BGI (601×702 pixel)
                int GraphDriver = 0, GraphMode = 0;
                initgraph(&GraphDriver, &GraphMode, "", 601, 702);

                // Disegna gli assi cartesiani: asse X (y=301), asse Y (x=301) e bordo inferiore
                line(0, 301, 601, 301);
                line(301, 0, 301, 601);
                line(0, 601, 601, 601); // Linea separatrice per la legenda

                // Disegna le tacche sugli assi a intervalli di 'unita' pixel
                for (int i = unita; i <= 300; i += unita)
                {
                    line(301 + i, 301 - 5, 301 + i, 301 + 5); // Tacche asse X positive
                    line(301 - i, 301 - 5, 301 - i, 301 + 5); // Tacche asse X negative
                    line(301 - 5, 301 + i, 301 + 5, 301 + i); // Tacche asse Y negative
                    line(301 - 5, 301 - i, 301 + 5, 301 - i); // Tacche asse Y positive
                }

                double cy = 0;   // Valore calcolato di P(x) per il punto corrente
                double cy2 = 0;  // Valore calcolato di R(x) per il punto corrente

                // Campionamento e disegno delle curve ogni 0.5 unità nell'intervallo [-5, 5]
                for (double i = -5; i <= 5; i += 0.5)
                {
                    cy = 0;
                    cy2 = 0;

                    // Valutazione di P(x) nel punto i usando lo schema di Horner implicito
                    for (int j = 3; j >= 1; j--)
                    {
                        cy += pol1[j] * pow(i, j);
                    }
                    cy += pol1[0]; // Aggiunge il termine noto

                    // Conversione coordinate matematiche → pixel:
                    // x_pixel = centro_x + x_matematico * scala
                    // y_pixel = centro_y - y_matematico * scala  (asse Y invertito)
                    int x = 301 + (i * unita);
                    int y = 301 - (cy * unita);

                    // Disegna il punto di P(x) solo se rientra nell'area del grafico
                    if (x >= 0 && x <= 601 && y >= 0 && y <= 601)
                    {
                        // Imposta il colore scelto per P(x)
                        if      (col1 == 'r') setcolor(RED);
                        else if (col1 == 'y') setcolor(YELLOW);
                        else if (col1 == 'g') setcolor(GREEN);
                        else if (col1 == 'b') setcolor(BLUE);

                        circle(x, y, 3); // Disegna un cerchietto di raggio 3 pixel
                    }

                    // Valutazione di R(x) nel punto i
                    for (int j = 3; j >= 1; j--)
                    {
                        cy2 += pol2[j] * pow(i, j);
                    }
                    cy2 += pol2[0];

                    x = 301 + (i * unita);
                    y = 301 - (cy2 * unita);

                    // Disegna il punto di R(x) solo se rientra nell'area del grafico
                    if (x >= 0 && x <= 601 && y >= 0 && y <= 601)
                    {
                        // Imposta il colore scelto per R(x)
                        if      (col2 == 'r') setcolor(RED);
                        else if (col2 == 'y') setcolor(YELLOW);
                        else if (col2 == 'g') setcolor(GREEN);
                        else if (col2 == 'b') setcolor(BLUE);

                        circle(x, y, 3);
                    }
                }

                settextstyle(2, 0, 5);

                // Etichetta P(x) con il suo colore
                if      (col1 == 'r') setcolor(RED);
                else if (col1 == 'y') setcolor(YELLOW);
                else if (col1 == 'g') setcolor(GREEN);
                else if (col1 == 'b') setcolor(BLUE);
                outtextxy(21, 651, "P(x) : ");

                setcolor(WHITE);
                outtextxy(61, 651, "Primo polinomio");

                // Etichetta R(x) con il suo colore
                if      (col2 == 'r') setcolor(RED);
                else if (col2 == 'y') setcolor(YELLOW);
                else if (col2 == 'g') setcolor(GREEN);
                else if (col2 == 'b') setcolor(BLUE);
                outtextxy(401, 651, "R(x) : ");

                setcolor(WHITE);
                outtextxy(441, 651, "Secondo polinomio");

                // Attende un tasto nella finestra grafica per decidere l'azione successiva
                funzione = getchg();

                // Pulisce la finestra, ripristina la console e chiude il contesto grafico
                cleardevice();
                ShowWindow(GetConsoleWindow(), SW_SHOW);
                closegraph();
                system("cls");

                // Se il tasto non è un comando riconosciuto ('i', '+', '-'), esce dalla modalità grafica
                if (funzione != 'i' && funzione != '+' && funzione != '-')
                {
                    break;
                }

            } while (true);
        }

        // ============================================================
        // OPZIONE 9 : USCITA DAL PROGRAMMA
        // Chiede conferma prima di terminare
        // ============================================================
        else if (opz == '9')
        {
            char sicuro;
            do
            {
                cout << "Vuoi davvero uscire \033[32m(s)\033[0m / \033[31m(n)\033[0m : ";
                sicuro = getch();

                if (sicuro == 's' || sicuro == 'n')
                {
                    cout << sicuro;
                    break;
                }

                cout << "  \033[33mAttenzione! Premi solo 's' per si oppure 'n' per no.\033[0m\n\n";

            } while (true);

            if (sicuro == 's')
            {
                system("cls");
                break; // Esce dal ciclo principale → fine del programma
            }
            else
            {
                system("cls");
                continue; // Torna al menu senza uscire
            }
        }
    }

    // Stampa il messaggio di chiusura "FINE" in ASCII art
    cout << "\033[1;33m";
    cout << " _____ ___ _   _ _____ " << endl;
    cout << "|  ___|_ _| \\ | | ____|" << endl;
    cout << "| |_   | ||  \\| |  _|  " << endl;
    cout << "|  _|  | || |\\  | |___ " << endl;
    cout << "|__|  |___|_| \\_|_____|" << endl;
    cout << "\x1b[0m";

    return 0; // Terminazione normale del programma
}
