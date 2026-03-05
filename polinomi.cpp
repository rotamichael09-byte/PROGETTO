#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main()
{
	char carattere;
	cout << "\x1b[33mPROGETTO POLINOMI\n\n\x1b[0mROTA MICHAEL\nCOLOMBO FRANCESCO\nSPINELLI FILIPPO\n\n\nPremi un tasto per continuare . . . ";
	carattere = getch();
	bool primo = true;

	system("cls");
	int pol1[4]{0};
	int pol2[4]{0};
	int numeri;

	while (true)
	{
		if (primo == true)
		{
			cout << "Quale grado vuoi inserire : ";
			cin >> numeri;

			cout << "Primo polinomio\n\n";

			for (int i = numeri; i >= 0; i--)
			{
				if (i != 0)
				{
					cout << "Valore alla " << i << "^ : ";
				}
				else
				{
					cout << "Termine noto : ";
				}
				cin >> pol1[i];
			}

			cout << "\n\n";
			cout << "secondo polinomio\n\n";

			for (int i = numeri; i >= 0; i--)
			{
				if (i != 0)
				{
					cout << "Valore alla " << i << "^ : ";
				}
				else
				{
					cout << "Termine noto : ";
				}
				cin >> pol2[i];
			}
			cout << "\n\nprimo  ";

			for (int i = numeri; i >= 0; i--)
			{
				if (pol1[i] != 0)
				{

					if (i != 0)
					{
						cout << pol1[i] << "x^" << i << "  ";
					}
					else
					{
						cout << pol1[i] << "\n\n";
					}
				}
			}
			cout << "\nsecondo  ";

			for (int i = numeri; i >= 0; i--)
			{
				if (pol2[i] != 0)
				{

					if (i != 0)
					{
						cout << pol2[i] << "x^" << i << "  ";
					}
					else
					{
						cout << pol2[i] << "\n\n";
					}
				}
			}
			primo = false;
			cout << "Premi un tasto per continuare . . . ";
			carattere = getch();
			system("cls");
		}

		char opz;
		int polfine[7]{0};
		cout << "0 ( inserimento polinomi ) \n1 ( somma ) \n2 ( differenza ) \n3 ( prodotto ) \n4 ( ricerca degli zeri solo per primo e secondo grado ) \n5 ( ricerca punti di intersezione ) \n6 ( grafico ) \n\n9 ( esci )";
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
	}
	return 0;
}
