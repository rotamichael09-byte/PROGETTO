#include <iostream>
#include <cmath>
#include <conio.h>
#include <cctype>
#include "graphics2.h"
#include <windows.h>
using namespace std;

int main()
{
	system("cls");
	SetConsoleTitleA("Programma grafico polinomi");
	char carattere;
	cout << "\033[1;33m";
	cout << " ____  ____   ___   ____ _____ _____ _____ ___    ____   ___  _     ___ _   _  ___  __  __ ___ " << endl;
	cout << "|  _ \\|  _ \\ / _ \\ / ___| ____|_   _|_   _/ _ \\  |  _ \\ / _ \\| |   |_ _| \\ | |/ _ \\|  \\/  |_ _| " << endl;
	cout << "| |_) | |_) | | | | |  _|  _|   | |   | || | | | | |_) | | | | |    | ||  \\| | | | | |\\/| || |  " << endl;
	cout << "|  __/|  _ <| |_| | |_| | |___  | |   | || |_| | |  __/| |_| | |___ | || |\\  | |_| | |  | || |  " << endl;
	cout << "|_|   |_| \\_\\\\___/ \\____|_____| |_|   |_| \\___/  |_|    \\___/|_____|___|_| \\_|\\___/|_|  |_|___| " << endl;
	cout << "\n\033[0m========================================================================================================================";
	cout << "\n\n";

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

	cout << "\033[1;35mMembri del gruppo:\033[0m\n\n";

	cout << "  \033[37mROTA MICHAEL\033[0m\n";
	cout << "  \033[37mCOLOMBO FRANCESCO\033[0m\n";
	cout << "  \033[37mSPINELLI FILIPPO\033[0m\n\n";
	cout << "\033[1;3;4m\nPremi un tasto per continuare\033[0m . . .";
	carattere = getch();
	bool primo = true;

	system("cls");
	double pol1[4];
	double pol2[4];

	for (int i = 3; i >= 0; i--)
	{
		pol1[i] = 0;
		pol2[i] = 0;
	}

	int numeri;
	int numeri2;
	bool uguali = true;
	cout.precision(2);

	while (true)
	{
		if (primo == true)
		{
			uguali = true;
			for (int i = 3; i >= 0; i--)
			{
				pol1[i] = 0;
				pol2[i] = 0;
			}

			cout << "\033[1;33m";
			cout << " ___ _   _ ____  _____ ____  ___ __  __ _____ _   _ _____ ___  " << endl;
			cout << "|_ _| \\ | / ___|| ____|  _ \\|_ _|  \\/  | ____| \\ | |_   _/ _ \\ " << endl;
			cout << " | ||  \\| \\___ \\|  _| | |_) || || |\\/| |  _| |  \\| | | || | | |" << endl;
			cout << " | || |\\  |___) | |___|  _ < | || |  | | |___| |\\  | | || |_| |" << endl;
			cout << "|___|_| \\_|____/|_____|_| \\_\\___|_|  |_|_____|_| \\_| |_| \\___/ " << endl;
			cout << "\033[0m" << endl;

			do
			{

				cout << "\n\033[1m\033[3mQuale grado vuoi inserire nel primo polinomio : \033[0m";
				cin >> numeri;

				if (cin.fail())
				{
					cout << "\033[31mAttenzione accetto solo numeri :( \033[0m\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
				}

				else if (numeri > 3 || numeri < 0)
				{
					cout << "\033[33mAttenzione il mio numero massimo e' 3 :|\033[0m\n\n";
				}

				else
				{
					break;
				}

			} while (true);
			cout << "\n\n\033[1m\033[3m";

			for (int i = numeri; i >= 0; i--)
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

					cin >> pol1[i];

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

			cout << "\n\n\n\n";
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

			for (int i = 3; i >= 0; i--)
			{
				if (pol1[i] != pol2[i])
				{
					uguali = false;
				}
			}
			cout << "\n\n\n\033[31mP(x) \033[0m: ";

			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
			primo = false;
			cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
			carattere = getch();
			system("cls");
		}

		cout << "\033[1;33m";
		cout << " __  __ _____ _   _ _   _ " << endl;
		cout << "|  \\/  | ____| \\ | | | | |" << endl;
		cout << "| |\\/| |  _| |  \\| | | | |" << endl;
		cout << "| |  | | |___| |\\  | |_| |" << endl;
		cout << "|_|  |_|_____|_| \\_|\\___/ " << endl;
		cout << "\x1b[0m";
		char opz;
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
		do
		{

			cout << "\033[1m\033[3mInserisci operazione : ";

			opz = getch();

			if ((opz >= '0' && opz <= '6') || opz == '9')
			{
				cout << opz;
				break;
			}

			cout << "  \033[31mInput non valido! Usa solo 1-6 oppure 9.\033[0m\n\n";

		} while (true);

		system("cls");

		if (opz == '0')
		{
			primo = true;
			continue;
		}
		else if (opz == '1')
		{
			cout << "\033[1;33m";
			cout << " ____   ___  __  __ __  __    _ " << endl;
			cout << "/ ___| / _ \\|  \\/  |  \\/  |  / \\ " << endl;
			cout << "\\___ \\| | | | |\\/| | |\\/| | / _ \\ " << endl;
			cout << " ___) | |_| | |  | | |  | |/ ___ \\ " << endl;
			cout << "|____/ \\___/|_|  |_|_|  |_/_/   \\_\\" << endl;
			cout << "\n\033[0m=====================================\n\n";

			for (int i = 3; i >= 0; i--)
			{
				polfine[i] = pol1[i] + pol2[i];
			}

			cout << "Polinomio \033[31mP(x)\033[32m\n";
			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
							cout << " +" << pol1[i];
						}
						else
						{
							cout << " " << pol1[i];
						}
					}
				}
			}
			cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";

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
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i] << "x^" << i;
							}
							else
							{
								cout << " " << polfine[i] << "x^" << i;
							}
						}
						else
						{
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i];
							}
							else
							{
								cout << " " << polfine[i];
							}
						}
					}
				}
			}
			cout << "\n\033[0m------------------------------------\n\n";
			cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
			carattere = getch();
			system("cls");
		}
		else if (opz == '2')
		{
			cout << "\033[1;33m";
			cout << " ___  ___ _____ _____ _____ ____  _____ _   _ _____  _ \n";
			cout << "|  _ \\|_ _|  ___|  ___| ____|  _ \\| ____| \\ | |__  / / \\ \n";
			cout << "| | | || || |_  | |_  |  _| | |_) |  _| |  \\| |  / / / _ \\ \n";
			cout << "| |_| || ||  _| |  _| | |___|  _ <| |___| |\\  | / /_/ ___ \\ \n";
			cout << "|____/|___|_|   |_|   |_____|_| \\_\\_____|_| \\_|/____/_/   \\_\\\n";
			cout << "\n\033[0m=================================================================\n\n";
			for (int i = 3; i >= 0; i--)
			{
				polfine[i] = pol1[i] - pol2[i];
			}

			cout << "Polinomio \033[31mP(x)\033[32m\n";
			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
							cout << " +" << pol1[i];
						}
						else
						{
							cout << " " << pol1[i];
						}
					}
				}
			}
			cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";

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
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i] << "x^" << i;
							}
							else
							{
								cout << " " << polfine[i] << "x^" << i;
							}
						}
						else
						{
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i];
							}
							else
							{
								cout << " " << polfine[i];
							}
						}
					}
				}
			}
			cout << "\n\033[0m------------------------------------\n\n";
			cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
			carattere = getch();
			system("cls");
		}
		if (opz == '3')
		{
			cout << "\033[1;33m";
			cout << " ____  ____   ___  ____   ___ _____ _____ ___  " << endl;
			cout << "|  _ \\|  _ \\ / _ \\|  _ \\ / _ \\_   _|_   _/ _ \\ " << endl;
			cout << "| |_) | |_) | | | | | | | | | || |   | || | | |" << endl;
			cout << "|  __/|  _ <| |_| | |_| | |_| || |   | || |_| |" << endl;
			cout << "|_|   |_| \\_\\\\___/|____/ \\___/ |_|   |_| \\___/ " << endl;
			cout << "\n\033[0m=================================================\n\n";
			for (int i = 3; i >= 0; i--)
			{
				for (int j = 3; j >= 0; j--)
				{
					polfine[i + j] += pol1[i] * pol2[j];
				}
			}
			cout << "Polinomio \033[31mP(x)\033[32m\n";
			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
							cout << " +" << pol1[i];
						}
						else
						{
							cout << " " << pol1[i];
						}
					}
				}
			}
			cout << "\n\n\033[0mPolinomio \033[33mR(x)\033[32m\n";

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
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i] << "x^" << i;
							}
							else
							{
								cout << " " << polfine[i] << "x^" << i;
							}
						}
						else
						{
							if (polfine[i] > 0)
							{
								cout << " +" << polfine[i];
							}
							else
							{
								cout << " " << polfine[i];
							}
						}
					}
				}
			}
			cout << "\n\033[0m------------------------------------\n\n";
			cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
			carattere = getch();
			system("cls");
		}
		else if (opz == '4')
		{
			cout << "\033[1;33m";
			cout << " ____  ___ ____   ___  _    _   _ _____ ___ ___  _   _ _____ " << endl;
			cout << "|  _ \\|_ _/ ___| / _ \\| |  | | | |__  /|_ _/ _ \\| \\ | | ____|" << endl;
			cout << "| |_) || |\\___ \\| | | | |  | | | | / /  | | | | |  \\| |  _|  " << endl;
			cout << "|  _ < | | ___) | |_| | |__| |_| |/ /_  | | |_| | |\\  | |___ " << endl;
			cout << "|_| \\_\\___|____/ \\___/|_____\\___//____|___\\___/|_| \\_|_____|" << endl;
			cout << "\n\033[0m=============================================================\n\n";
			cout << "Polinomi inseriti :\n\n\033[31mP(x) \033[0m= \033[32m";

			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
							cout << " +" << pol1[i];
						}
						else
						{
							cout << " " << pol1[i];
						}
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

			cout << "\n\n\033[0m------------------------------------\n\nZeri di \033[31mP(x)\033[0m:\n\033[32m";

			if (pol1[3] != 0)
			{
				cout << "Polinomio di terzo grado";
			}
			else if (pol1[3] == 0)
			{
				if (pol1[2] == 0)
				{
					if (pol1[1] == 0)
					{
						cout << "Non ci sono X";
					}
					else if (pol1[1] != 0 && pol1[0] == 0)
					{
						cout << "X : \033[32m0\033[0m";
					}
					else
					{
						cout << " X : " << (pol1[0] * -1) / pol1[1];
					}
				}
				else if (pol1[2] != 0)
				{
					if (pol1[0] != 0 && pol1[1] != 0 && pol1[2] != 0)
					{
						int delta;
						delta = pow(pol1[1], 2) - (4 * pol1[0] * pol1[2]);
						if (delta < 0)
						{
							cout << "Non ci sono soluzioni";
						}
						else if (delta >= 0)
						{
							cout << "X1 : " << ((pol1[1] * -1) + sqrt(delta)) / (pol1[2] * 2);
							cout << "\nX2 : " << ((pol1[1] * -1) - sqrt(delta)) / (pol1[2] * 2);
						}
					}
					else if (pol1[0] == 0 && pol1[1] != 0 && pol1[2] != 0)
					{
						cout << "X1 : 0";
						cout << "\nX2 : " << (pol1[1] * -1) / pol1[2];
					}
					else if (pol1[0] != 0 && pol1[1] == 0 && pol1[2] != 0)
					{
						if (pol1[0] * -1 < 0)
						{
							cout << "Impossibile";
						}
						else if (pol1[0] * -1 > 0)
						{
							cout << "X1 : -" << sqrt((pol1[0] * -1) / pol1[2]);
							cout << "\nX2 : +" << sqrt((pol1[0] * -1) / pol1[2]);
						}
					}
					else if (pol1[0] == 0 && pol1[1] == 0 && pol1[2] != 0)
					{
						cout << "X : \033[32m0\033[0m";
					}
				}
			}
			if (uguali)
			{
				cout << "\033[0m\n\nLe X di \033[33mR(x) \033[0msono le stesse essendo i due polinomi uguali";
			}
			else
			{
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
		else if (opz == '5')
		{
			cout << "\033[1;33m";
			cout << " ___ _   _ _____ _____ ____  ____  _____ _____ ___ ___  _   _ ___ " << endl;
			cout << "|_ _| \\ | |_   _| ____|  _ \\/ ___|| ____|__  /|_ _/ _ \\| \\ | |_ _|" << endl;
			cout << " | ||  \\| | | | |  _| | |_) \\___ \\|  _|   / /  | | | | |  \\| || | " << endl;
			cout << " | || |\\  | | | | |___|  _ < ___) | |___ / /_  | | |_| | |\\  || | " << endl;
			cout << "|___|_| \\_| |_| |_____|_| \\_\\____/|_____/____|___\\___/|_| \\_|___|" << endl;
			cout << "\n\033[0m==================================================================\n\n";
			cout << "Polinomi inseriti :\n\n\033[31mP(x) \033[0m= \033[32m";

			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
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
							cout << " +" << pol1[i];
						}
						else
						{
							cout << " " << pol1[i];
						}
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
			cout << "\n\n\033[0m------------------------------------";

			cout << "\n\n\033[0mCerchiamo i punti in cui i polinomi si incontrano :\n\n";
			if (uguali)
			{
				cout << "\nI due polinomi sono \033[32mcoincidenti \033[0messendo uguali";
			}
			else
			{

				double x1 = 0;
				double x2 = 0;
				double y1;
				double y2;

				for (int i = 3; i >= 0; i--)
				{
					polfine[i] = pol1[i] - pol2[i];
				}

				if (polfine[3] != 0)
				{
					cout << "Polinomio di terzo grado";
				}

				else if (polfine[3] == 0)
				{
					if (polfine[2] == 0)
					{
						if (polfine[1] == 0)
						{
							cout << "\033[31mNon ci sono punti di intersezione\033[0m";
						}
						else if (polfine[1] != 0 && polfine[0] == 0)
						{
							x1 = 0;
							y1 = (pol1[1] * x1) + pol1[0];
							cout << "( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )";
						}

						else
						{
							x1 = (polfine[0] * -1) / polfine[1];
							y1 = (pol1[1] * x1) + pol1[0];
							cout << "( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )";
						}
					}

					else if (polfine[2] != 0)
					{
						if (polfine[0] != 0 && polfine[1] != 0 && polfine[2] != 0)
						{
							int delta;
							delta = pow(polfine[1], 2) - (4 * polfine[0] * polfine[2]);

							if (delta < 0)
							{
								cout << "\033[31mNon ci sono punti di intersezione\033[0m";
							}

							else
							{
								x1 = ((polfine[1] * -1) + sqrt(delta)) / (polfine[2] * 2);
								x2 = ((polfine[1] * -1) - sqrt(delta)) / (polfine[2] * 2);

								y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
								y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

								cout << "1( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )\n";
								cout << "2( X ; Y ) == ( \033[32m" << x2 << "\033[0m ; \033[32m" << y2 << " \033[0m )";
							}
						}

						else if (polfine[0] == 0 && polfine[1] != 0 && polfine[2] != 0)
						{
							x1 = 0;
							x2 = (polfine[1] * -1) / polfine[2];

							y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
							y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

							cout << "1( X ; Y ) == ( \033[32m" << x1 << "\033[0m ; \033[32m" << y1 << " \033[0m )\n";
							cout << "2( X ; Y ) == ( \033[32m" << x2 << "\033[0m ; \033[32m" << y2 << " \033[0m )";
						}

						else if (polfine[0] != 0 && polfine[1] == 0 && polfine[2] != 0)
						{
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
		else if (opz == '6')
		{
			bool personalizzazione = true;
			char funzione;
			bool uni = true;
			char col1;
			char col2;
			int unita;

			do
			{
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

					cout << "\n\n\033[32m\033[1m\033[3mScelte finali\033[0m:" << endl;
					cout << "Primo polinomio: " << col1 << endl;
					cout << "Secondo polinomio: " << col2 << endl;

					cout << "\n\n\033[1m\033[4m\033[3mPremi un tasto per inizializzare la grafica\033[0m . . .";
					carattere = getch();

					personalizzazione = false;
				}

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

				ShowWindow(GetConsoleWindow(), SW_HIDE);

				int GraphDriver = 0, GraphMode = 0;
				initgraph(&GraphDriver, &GraphMode, "", 601, 702);

				line(0, 301, 601, 301);
				line(301, 0, 301, 601);
				line(0, 601, 601, 601);

				for (int i = unita; i <= 300; i += unita)
				{

					line(301 + i, 301 - 5, 301 + i, 301 + 5);
					line(301 - i, 301 - 5, 301 - i, 301 + 5);

					line(301 - 5, 301 + i, 301 + 5, 301 + i);
					line(301 - 5, 301 - i, 301 + 5, 301 - i);
				}

				double cy = 0;
				double cy2 = 0;

				for (double i = -5; i <= 5; i += 0.5)
				{

					cy = 0;
					cy2 = 0;

					for (int j = 3; j >= 1; j--)
					{
						cy += pol1[j] * pow(i, j);
					}
					cy += pol1[0];

					int x = 301 + (i * unita);
					int y = 301 - (cy * unita);

					if (x >= 0 && x <= 601 && y >= 0 && y <= 601)
					{
						if (col1 == 'r')
						{
							setcolor(RED);
						}
						else if (col1 == 'y')
						{
							setcolor(YELLOW);
						}
						else if (col1 == 'g')
						{
							setcolor(GREEN);
						}
						else if (col1 == 'b')
						{
							setcolor(BLUE);
						}
						circle(x, y, 3);
					}

					for (int j = 3; j >= 1; j--)
					{
						cy2 += pol2[j] * pow(i, j);
					}
					cy2 += pol2[0];

					x = 301 + (i * unita);
					y = 301 - (cy2 * unita);

					if (x >= 0 && x <= 601 && y >= 0 && y <= 601)
					{
						if (col2 == 'r')
						{
							setcolor(RED);
						}
						else if (col2 == 'y')
						{
							setcolor(YELLOW);
						}
						else if (col2 == 'g')
						{
							setcolor(GREEN);
						}
						else if (col2 == 'b')
						{
							setcolor(BLUE);
						}
						circle(x, y, 3);
					}
				}
				settextstyle(2, 0, 5);

				if (col1 == 'r')
				{
					setcolor(RED);
				}
				else if (col1 == 'y')
				{
					setcolor(YELLOW);
				}
				else if (col1 == 'g')
				{
					setcolor(GREEN);
				}
				else if (col1 == 'b')
				{
					setcolor(BLUE);
				}
				outtextxy(21, 651, "P(x) : ");
				setcolor(WHITE);
				outtextxy(61, 651, "Primo polinomio");

				if (col2 == 'r')
				{
					setcolor(RED);
				}
				else if (col2 == 'y')
				{
					setcolor(YELLOW);
				}
				else if (col2 == 'g')
				{
					setcolor(GREEN);
				}
				else if (col2 == 'b')
				{
					setcolor(BLUE);
				}
				outtextxy(401, 651, "R(x) : ");
				setcolor(WHITE);
				outtextxy(441, 651, "Secondo polinomio");

				funzione = getchg();

				cleardevice();
				ShowWindow(GetConsoleWindow(), SW_SHOW);
				closegraph();
				system("cls");
				if (funzione != 'i' && funzione != '+' && funzione != '-')
				{
					break;
				}

			} while (true);
		}
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
				break;
			}
			else
			{
				system("cls");
				continue;
			}
		}
	}
	cout << "\033[1;33m";
	cout << " _____ ___ _   _ _____ " << endl;
	cout << "|  ___|_ _| \\ | | ____|" << endl;
	cout << "| |_   | ||  \\| |  _|  " << endl;
	cout << "|  _|  | || |\\  | |___ " << endl;
	cout << "|__|  |___|_| \\_|_____|" << endl;
	cout << "\x1b[0m";

	return 0;
}
