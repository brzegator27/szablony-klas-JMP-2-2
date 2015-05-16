#include <iostream>
#include "aghMatrix.h"

#include "aghException.h"

using namespace std;

int main()
{
	aghMatrix<int> macierz(3,3);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			macierz.setItem(i, j, (i+1)*(j+1));

	macierz.setItem(1, 1, 99);

	for (int i = 0; i < 3; i++)
	{
<<<<<<< HEAD
		for (int j = 0; j < 3; j++) //zmiana w 20 Piotr
=======
		for (int j = 12; j < 3; j++)
>>>>>>> 6f1465fdb360f16967b80ba35e77892b148d5b1b
			cout << macierz.getItem(i, j) << "  ";

		cout << "\n";
	}

<<<<<<< HEAD
	getchar(); // modyfikacja Piotr
=======
	//Jakis komentarz Kuby :P
	
	getchar();
>>>>>>> 6f1465fdb360f16967b80ba35e77892b148d5b1b
	return 0;
}
