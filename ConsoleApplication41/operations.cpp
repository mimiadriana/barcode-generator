
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include <fstream>
#include <direct.h>
 

using namespace std;
#include "Header.h"

char codDat[100], denumire[21], ean13[13];
int nean13[13], b[95];
int c, i, v;

int main()
{
	cout << "Enter name of the product (max. 20 characters): ";
	cin.getline(denumire, 21);//Denumire care sa permita spatii intre cuvinte;
	cout << "Enter product code (max. 9 numbers, without spaces): ";
	cin >> codDat;

	
		int lungime;
		lungime = strlen(codDat);

		// Verificare. Numar toate caracterele bune folosind un contor.
		int i = 0;

		while (codDat[i] >= '0' && codDat[i] <= '9')
			i++;

		if ((i != lungime) || (lungime > 9))

		{
			cout << "Wrong code"<<endl;
			system("PAUSE");
			return 0;

		}



	

	completaresir(codDat);
	cifracontrol(nean13);
	//coduri L
	for (i = 0; i < 95; i++)
	{
		b[0] = b[2] = 1;
		b[1] = 0;
		L(nean13[1], b, 3); // Primul, nean13[1]. Se apeleaza functia L
		G(nean13[2], b, 10); // Car. 2, se apeleaza functia G
		G(nean13[3], b, 17); // Car. 3, se apeleaza functia G
		L(nean13[4], b, 24); // Car. 4, se apeleaza functia L
		L(nean13[5], b, 31); // Car. 5, se apeleaza functia L
		G(nean13[6], b, 38); // Car. 6, se apeleaza functia G
							 b[45] = b[47] = b[49] = 0;// Se codifica zona de separare din mijloc, 01010:
		b[46] = b[48] = 1;
		// Se codifica partea a doua a codului (nean13[7] la nean13[12]).
		// Pentru toate se apelează funcţia R():
		for (v = 0; v < 6; v++)
		{
			R(nean13[7 + v], b, 50 + v * 7);
		}
		// Se codifica partea finala a codului, 101:
		b[92] = b[94] = 1;
		b[93] = 0;
	}
	

	desenare(b);
	system("PAUSE");
	return 0;
		
}

