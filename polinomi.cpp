#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main()
{
	char carattere;
	cout << "\x1b[33m";
	cout << " ____  ____   ___   ____ _____ _____ _____ ___    ____   ___  _     ___ _   _  ___  __  __ ___ " << endl;
	cout << "|  _ \\|  _ \\ / _ \\ / ___| ____|_   _|_   _/ _ \\  |  _ \\ / _ \\| |   |_ _| \\ | |/ _ \\|  \\/  |_ _| " << endl;
	cout << "| |_) | |_) | | | | |  _|  _|   | |   | || | | | | |_) | | | | |    | ||  \\| | | | | |\\/| || |  " << endl;
	cout << "|  __/|  _ <| |_| | |_| | |___  | |   | || |_| | |  __/| |_| | |___ | || |\\  | |_| | |  | || |  " << endl;
	cout << "|_|   |_| \\_\\\\___/ \\____|_____| |_|   |_| \\___/  |_|    \\___/|_____|___|_| \\_|\\___/|_|  |_|___| " << endl;
	cout << "\n\n\x1b[0m-ROTA MICHAEL\n-COLOMBO FRANCESCO\n-SPINELLI FILIPPO\n\n\n\033[4m\033[1m\033[3mPremi un tasto per continuare\033[0m . . . ";
	carattere = getch();
	bool primo = true;

	system("cls");
	int pol1[4]{0};
	int pol2[4]{0};
	int numeri;
	int numeri2;

	while (true)
	{
		if (primo == true)
		{
			cout << "\x1b[33m0) INSERIMENTO POLINOMI\x1b[0m\n\n";
			cout << "\033[1m\033[3mQuale grado vuoi inserire nel primo polinomio : \033[0m";
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
			cout << "\n\n\nPRIMO : ";

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
			cout << "\nSECONDO : ";

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

		cout << "\x1b[33m";
		cout << " __  __ _____ _   _ _   _ " << endl;
		cout << "|  \\/  | ____| \\ | | | | |" << endl;
		cout << "| |\\/| |  _| |  \\| | | | |" << endl;
		cout << "| |  | | |___| |\\  | |_| |" << endl;
		cout << "|_|  |_|_____|_| \\_|\\___/ " << endl;
		cout << "\x1b[0m";
		char opz;
		int polfine[7]{0};
		cout << "\n\n\033[1m\033[3m0 ( inserimento polinomi ) \n1 ( somma ) \n2 ( differenza ) \n3 ( prodotto ) \n4 ( ricerca degli zeri solo per primo e secondo grado ) \n5 ( ricerca punti di intersezione ) \n6 ( grafico ) \n\n9 ( esci )\033[0m";
		opz = getch();
		system("cls");

		if (opz == '0')
		{
			primo = true;
			continue;
		}
		else if (opz == '1')
		{
			for (int i = 3; i >= 0; i--)
			{
				polfine[i] = pol1[i] + pol2[i];
			}

			cout << "\n\n\nsomma : ";
			for (int i = 3; i >= 0; i--)
			{
				if (polfine[i] != 0)
				{

					if (i != 0)
					{
						cout << polfine[i] << "x^" << i << "  ";
					}
					else
					{
						cout << polfine[i] << "\n\n";
					}
				}
			}
			cout << "Premi un tasto per continuare . . . ";
			carattere = getch();
			system("cls");
		}
		else if (opz == '2')
		{
			for (int i = 3; i >= 0; i--)
			{
				polfine[i] = pol1[i] - pol2[i];
			}

			cout << "\n\n\ndifferenza : ";
			for (int i = 3; i >= 0; i--)
			{
				if (polfine[i] != 0)
				{

					if (i != 0)
					{
						cout << polfine[i] << "x^" << i << "  ";
					}
					else
					{
						cout << polfine[i] << "\n\n";
					}
				}
			}
			cout << "Premi un tasto per continuare . . . ";
			carattere = getch();
			system("cls");
		}
		if (opz == '3')
		{
			for (int i = 3; i >= 0; i--)
			{
				for (int j = 3; j >= 0; j--)
				{
					polfine[i + j] += pol1[i] * pol2[j];
				}
			}

			cout << "\n\n\nprodotto : ";
			for (int i = 6; i >= 0; i--)
			{
				if (polfine[i] != 0)
				{

					if (i != 0)
					{
						cout << polfine[i] << "x^" << i << "  ";
					}
					else
					{
						cout << polfine[i] << "\n\n";
					}
				}
			}
		}
		else if (opz == '4')
		{

			if (pol1[3] != 0)
			{
				cout << "Polinomio di terzo grado";
			}
			else if (pol1[3] == 0)
			{
				if (pol1[2] == 0)
				{
					cout << " X : " << pol1[0] * -1 << "/" << pol1[1];
				}
				else if (pol1[2] == 0 && pol1[1] == 0)
				{
					cout << "non ci sono x";
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
							cout << "x1 : " << ((pol1[1] * -1) + sqrt(delta)) / (pol1[2] * 2);
							cout << "\nx2 : " << ((pol1[1] * -1) - sqrt(delta)) / (pol1[2] * 2);
						}
					}
					else if (pol1[0] == 0 && pol1[1] != 0 && pol1[2] != 0)
					{
						cout << "x1 : 0";
						cout << "\nx2 : " << pol1[1] * -1 << "/" << pol1[2];
					}
					else if (pol1[0] != 0 && pol1[1] == 0 && pol1[2] != 0)
					{
						if (pol1[0] * -1 < 0)
						{
							cout << "Impossibile";
						}
						else if (pol1[0] * -1 > 0)
						{
							cout << "x1 : -" << sqrt((pol1[0] * -1) / pol1[2]);
							cout << "\nx1 : +" << sqrt((pol1[0] * -1) / pol1[2]);
						}
					}
				}
			}

			cout << "\n\n";
			if (pol2[3] != 0)
			{
				cout << "Polinomio di terzo grado";
			}
			else if (pol2[2] == 0 && pol2[1] == 0)
			{
				cout << "non ci sono x";
			}
			else if (pol2[3] == 0)
			{
				if (pol2[2] == 0)
				{
					cout << " X : " << pol2[0] * -1 << "/" << pol2[1];
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
							cout << "x1 : " << ((pol2[1] * -1) + sqrt(delta)) / (pol2[2] * 2);
							cout << "\nx2 : " << ((pol2[1] * -1) - sqrt(delta)) / (pol2[2] * 2);
						}
					}
					else if (pol2[0] == 0 && pol2[1] != 0 && pol2[2] != 0)
					{
						cout << "x1 : 0";
						cout << "\nx2 : " << pol2[1] * -1 << "/" << pol2[2];
					}
					else if (pol2[0] != 0 && pol2[1] == 0 && pol2[2] != 0)
					{
						if (pol2[0] * -1 < 0)
						{
							cout << "Impossibile";
						}
						else if (pol2[0] * -1 > 0)
						{
							cout << "x1 : -" << sqrt((pol2[0] * -1) / pol2[2]);
							cout << "x1 : +" << sqrt((pol2[0] * -1) / pol2[2]);
						}
					}
				}
			}
			cout << "\n\nPremi un tasto per continuare . . . ";
			carattere = getch();
			system("cls");
		}
		else if (opz == '5')
		{

			int x1 = 0;
			int x2 = 0;
			int y1;
			int y2;

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
						cout << "X : " << x1 << " Y : " << y1;
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

							cout << "X : " << x1 << " Y : " << y1;
							cout << "\nX2 : " << x2 << " Y2 : " << y2;
						}
					}

					else if (polfine[0] == 0 && polfine[1] != 0 && polfine[2] != 0)
					{
						x1 = 0;
						x2 = (polfine[1] * -1) / polfine[2];

						y1 = (pol1[2] * pow(x1, 2)) + (pol1[1] * x1) + pol1[0];
						y2 = (pol1[2] * pow(x2, 2)) + (pol1[1] * x2) + pol1[0];

						cout << "X : " << x1 << " Y : " << y1;
						cout << "\nX2 : " << x2 << " Y2 : " << y2;
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

							cout << "X : " << x1 << " Y : " << y1;
							cout << "\nX2 : " << x2 << " Y2 : " << y2;
						}
					}
				}
			}

			cout << "\n\nPremi un tasto per continuare . . . ";
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
	cout << "\x1b[33m";
	cout << " _____ ___ _   _ _____ " << endl;
	cout << "|  ___|_ _| \\ | | ____|" << endl;
	cout << "| |_   | ||  \\| |  _|  " << endl;
	cout << "|  _|  | || |\\  | |___ " << endl;
	cout << "|__|  |___|_| \\_|_____|" << endl;
	cout << "\x1b[0m";
	return 0;
}
