#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main()
{
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
	cout << "\033[1;3;4m\nPremi un tasto per continuare...\033[0m";
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
			cout << "\n\033[1m\033[3mQuale grado vuoi inserire nel primo polinomio : \033[0m";
			cin >> numeri;
			cout << "\n\n\033[1m\033[3m";

			for (int i = numeri; i >= 0; i--)
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
			}

			cout << "\n\n\n\n";
			cout << "\033[1m\033[3mQuale grado vuoi inserire nel secondo polinomio : \033[0m";
			cin >> numeri2;
			cout << "\n\n";

			for (int i = numeri2; i >= 0; i--)
			{
				if (i != 0)
				{
					cout << "Valore alla " << i << "^ : \t";
				}
				else
				{
					cout << "Termine noto : \t\t";
				}
				cin >> pol2[i];
			}
			for (int i = 3; i >= 0; i--)
			{
				if (pol1[i] != pol2[i])
				{
					uguali = false;
				}
			}
			cout << "\n\n\nP(x) : ";

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
			cout << "\nR(x) : ";

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
							cout << " +" << pol2[i] << "\n\n";
						}
						else
						{
							cout << " " << pol2[i] << "\n\n";
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
		cout << "  \033[1;32m[1]\033[0m SOMMAA \t\t-> somma tra P(x) + R(x)\n";
		cout << "  \033[1;32m[2]\033[0m DIFFERENZA \t-> Differenza tra P(x) - R(x)\n";
		cout << "  \033[1;32m[3]\033[0m PRODOTTO \t\t-> Prodotto tra P(x) * R(x)\n";
		cout << "  \033[1;32m[4]\033[0m ZERI \t\t-> Trova i valori di x\n";
		cout << "  \033[1;32m[5]\033[0m INTERSEZIONI \t-> Trova i punti di intersezione tra P(x) e R(x)\n";
		cout << "  \033[1;32m[6]\033[0m GRAFICO \t\t-> Visualizza il grafico\n\n";
		cout << "  \033[1;32m[9]\033[0m ESCI \t\t-> Chiude il programma\n\n\n";
		cout << "\033[1m\033[3mInserisci operazione : ";

		opz = getch();
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
							if (pol2[i] > 0)
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
				if (pol1[i] != 0 && pol2[i] != 0 || pol1[i] != 0 && pol2[i] == 0)
				{
					polfine[i] = pol1[i] - pol2[i];
				}
				else if (pol1[i] == 0 && pol2[i] != 0)
				{
					polfine[i] = pol1[i] + pol2[i];
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
							if (pol2[i] > 0)
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
				if ( pol1[1] == 0 && pol1[2] == 0 ) {
					cout << "Impossibile";
				}

				else if (pol1[2] == 0 && pol1[1] != 0 )
				{
					cout << " X : " << (pol1[0] * -1) / pol1[1];
				}
				else if (pol1[2] != 0 )
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
					 if (pol2[2] == 0 && pol2[1] == 0)
				{
					cout << "Impossibile";
				}
					if (pol2[2] == 0 && pol2[1] != 0 )
					{
						cout << " X : " << (pol2[0] * -1) / pol2[1];
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
				cout << "\nI due polinomi sono \033[32mcoincidenti \033[0messendo uguali\n";
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
							cout << "Non ci sono punti di intersezione";
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
								cout << "Non ci sono punti di intersezione";
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
								cout << "Non ci sono punti di intersezione";
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
					}
				}
			}
			cout << "\n\n\033[0m------------------------------------\n\n";
			cout << "\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
			carattere = getch();
			system("cls");
		}
		else if (opz == '9')
		{
			char sicuro;
			cout << "Vuoi davvero uscire (s) / (n) : ";
			sicuro = getch();
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
