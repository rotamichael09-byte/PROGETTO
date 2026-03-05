#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "PROGETTO POLINOMI\n\n";

	while (true)
	{

		int pol1[4];
		int pol2[4];

		cout << "Primo polinomio\n\n";

		for (int i = 3; i >= 0; i--)
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

		for (int i = 3; i >= 0; i--)
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

		for (int i = 3; i >= 0; i--)
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

		for (int i = 3; i >= 0; i--)
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

		int scelta;
		int polfine[7]{0};

		cout << "\nscegli una delle seguenti opzioni somma(0) , differenza(1) , prodotto(2) : ";
		cin >> scelta;

		if (scelta == 0)
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
		}

		if (scelta == 1)
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
		}

		if (scelta == 2)
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

		bool secondo = true;

		for ( int i = 6 ; i >= 3 ; i-- ) {
			if ( polfine[i] != 0 ) {
				secondo = false;
			}
		}

		if ( secondo ) {
			int x1;
			int x2;
			if ( polfine[2] == 0 ) {
				x1 = (polfine[0] * -1) / polfine[1];
				cout << "X = " << x1;
			}
			else if (polfine[2] != 0 ) {
				x1 = ((polfine[1] * -1) + sqrt( pow(polfine[1] , 2) - (4*polfine[0]*polfine[2] ))) / (polfine[2] *2);
				x2 = ((polfine[1] * -1) - sqrt( pow(polfine[1] , 2) - (4*polfine[0]*polfine[2] ))) / (polfine[2] *2);
				cout << "X1 = " << x1 << "\n\n";
				cout << "X2= " << x2;
			}
		}

		char rip;

		cout << "\n\nVuoi rifare il gioco ( s ) si ( n ) no : ";
		cin >> rip;

		if (rip == 'n')
		{
			break;
		}
		if (rip == 's')
		{
			system("cls");
		}
	}
	return 0;
}


