
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include <fstream>
#include <windows.h>
#include <direct.h>


using namespace std;
extern char codDat[100], denumire[21], ean13[13];
extern int nean13[13];
extern int c;

	
	


void completaresir(char codDat[])
{
	char sirSapte[9] = ""; // sirul initial este vid
	int lungime = strlen(codDat);

	{if (lungime < 9)
	{
		int  j;
		for (j = 0; j < 9 - lungime; j++)

			sirSapte[j] = '7';
		// Limitez sirSapte la dreapta adaugandu-i un caracter '\0'
		sirSapte[j] = '\0';
	}

	char codRO[4] = "594";

	strcpy_s(ean13, codRO);
	strcat_s(ean13, sirSapte);
	strcat_s(ean13, codDat);

	cout << "The first 12 numbers of the barcode are : " << ean13 << endl;
	}


	int i;
	for (i = 0; i < 12; i++)

	{

		nean13[i] = int(ean13[i] - '0');

	}
	cout << "The final barcode, including control number is  ";

	for (i = 0; i < 12; i++)
	{
		cout << nean13[i];
	}
	
}

	void cifracontrol (int nean13[13])
	{

	int s1, s2, l, c;
	s1 = s2 = 0;
	

	for (l = 0; l < 12; l=l+2)

	{
		s1 = s1 + nean13[l];
		s2 = s2 + nean13[l + 1];
	}

	c = s1 +  3*s2;

	
		nean13[12] = 10 - c % 10; // Cifra de control
	
	cout << nean13[12];
	cout << endl;

}

		void L(int valoare, int bin[], int poz)
		{
			switch (valoare)
			{
			case 0: // 0001101
				bin[poz] = bin[poz + 1] = bin[poz + 2] = bin[poz + 5] = 0;
				bin[poz + 3] = bin[poz + 4] = bin[poz + 6] = 1;
				break;
			case 1: // 0011001
				bin[poz] = bin[poz + 1] = bin[poz + 4] = bin[poz + 5] = 0;
				bin[poz + 2] = bin[poz + 3] = bin[poz + 6] = 1;
				break;
			case 2: // 0010011
				bin[poz] = bin[poz + 1] = bin[poz + 3] = bin[poz + 4] = 0;
				bin[poz + 2] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			case 3: // 0111101
				bin[poz] = bin[poz + 5] = 0;
				bin[poz + 1] = bin[poz + 2] = bin[poz + 3] = bin[poz + 4] = bin[poz + 6] = 1;
				break;
			case 4: // 0100011
				bin[poz] = bin[poz + 2] = bin[poz + 3] = bin[poz + 4] = 0;

				bin[poz + 1] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			case 5: // 0110001
				bin[poz] = bin[poz + 3] = bin[poz + 4] = bin[poz + 5] = 0;
				bin[poz + 1] = bin[poz + 2] = bin[poz + 6] = 1;
				break;
			case 6: // 0101111
				bin[poz] = bin[poz + 2] = 0;
				bin[poz + 1] = bin[poz + 3] = bin[poz + 4] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			case 7: // 0111011
				bin[poz] = bin[poz + 4] = 0;
				bin[poz + 1] = bin[poz + 2] = bin[poz + 3] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			case 8: // 0110111
				bin[poz] = bin[poz + 3] = 0;
				bin[poz + 1] = bin[poz + 2] = bin[poz + 4] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			case 9: // 0001011
				bin[poz] = bin[poz + 1] = bin[poz + 2] = bin[poz + 4] = 0;
				bin[poz + 3] = bin[poz + 5] = bin[poz + 6] = 1;
				break;
			}

	}
	

		void G(int valoare, int bin[], int poz)
		{
			switch (valoare)
			{
			case 0: // 0100111
				bin[poz]  = bin[poz + 2] = bin[poz + 3] = 0;
				bin[poz + 1] = bin[poz + 4] = bin[poz + 5]=bin[poz + 6] = 1;
				break;
			case 1: // 0110011
				bin[poz] = bin[poz + 4] = bin[poz + 5]  = 0;
				bin[poz + 1] = bin[poz + 1] = bin[poz + 5] = bin[poz + 6]= 1;
				break;
			case 2: // 0011011
				bin[poz] = bin[poz + 1] =  bin[poz + 4] = 0;
				bin[poz + 2] = bin[poz + 3] = bin[poz + 4]= bin[poz + 5]= bin[poz + 6] = 1;
				break;
			case 3: // 0100001
				bin[poz] = bin[poz + 1] = bin[poz + 3]= bin[poz + 4]= bin[poz + 5] = 0;
				bin[poz + 1] = bin[poz + 6] = 1;
				break;
			case 4: // 0011101
				bin[poz] = bin[poz + 2] = bin[poz + 5] = 0;

				bin[poz + 2] = bin[poz + 3] = bin[poz + 4] = bin[poz + 6] = 1;
				break;
			case 5: // 0111001
				bin[poz] = bin[poz + 4] = bin[poz + 5]  = 0;
				bin[poz + 1] = bin[poz + 2] = bin[poz + 3]= bin[poz + 6] = 1;
				break;
			case 6: // 0000101
				bin[poz] = bin[poz + 1] = bin[poz + 2] = bin[poz + 3]= bin[poz + 5] = 0;
				bin[poz + 4] = bin[poz + 6]  = 1;
				break;
			case 7: // 0010001
				bin[poz] = bin[poz + 1]=bin[poz + 3]=bin[poz + 4]=bin[poz + 5] = 0;
				bin[poz + 2] = bin[poz + 6] = 1;
				break;
			case 8: // 0001001
				bin[poz] = bin[poz + 1] = bin[poz + 2] = bin[poz + 4] = bin[poz + 5] = 0;
				bin[poz + 3] = bin[poz + 6] = 1;
				break;
			case 9: // 0010111
				bin[poz] = bin[poz + 1] = bin[poz + 3]  = 0;
				bin[poz + 2] = bin[poz + 4]= bin[poz + 5] = bin[poz + 6] = 1;
				break;
			}

		}
		void R(int valoare, int bin[], int poz)
		{
			switch (valoare)
			{
			case 0: // 1110010
				bin[poz+3] = bin[poz +4] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 1] = bin[poz + 2] = bin[poz + 5] = 1;
				break;
			case 1: // 1100110
				bin[poz+2] = bin[poz + 3] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 1] = bin[poz + 4] = bin[poz + 5] = 1;
				break;
			case 2: // 1101100
				bin[poz+2] = bin[poz + 5] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 1] = bin[poz + 3] = bin[poz + 4]  = 1;
				break;
			case 3: // 1000010
				bin[poz+1] = bin[poz + 2] = bin[poz + 3] = bin[poz +4] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 5] = 1;
				break;
			case 4: // 1011100
				bin[poz+1] = bin[poz + 5] = bin[poz + 6] = 0;

				bin[poz] = bin[poz + 2] = bin[poz + 3] = bin[poz + 4]  = 1;
				break;
			case 5: // 1001110
				bin[poz+1] = bin[poz + 2] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 3] = bin[poz + 4] =bin[poz +5] = 1;
				break;
			case 6: // 1010000
				bin[poz+1] = bin[poz + 3]= bin[poz + 4] = bin[poz + 5] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 2]  = 1;
				break;
			case 7: // 1000100
				bin[poz+1] = bin[poz + 2]=bin[poz + 3] = bin[poz + 5] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 4]  = 1;
				break;
			case 8: // 1001000
				bin[poz+1] = bin[poz + 2]= bin[poz + 4] = bin[poz + 5] = bin[poz + 6] = 0;
				bin[poz] = bin[poz + 3]= 1;
				break;
			case 9: // 1110100
				bin[poz+3] = bin[poz + 5] = bin[poz + 6]  = 0;
				bin[poz] = bin[poz + 1] = bin[poz +2] = bin[poz + 4] = 1;
				break;
			}

		}
		
		void desenare(int b[95])
		{
			int i;
			
			strcat_s(denumire, ".html");
			fstream cod;
			cod.open (denumire, ios:: out);
		
			cod << "<!DOCTYPE html>" << endl;
			cod << "<html>" << endl;
			cod << "<body>" << endl;
			cod << "<svg height=\"100\" width=\"200\">" << endl;
			// Doi pixeli pentru fiecare bara
			int pozx = 10; // De la acest x incep trasarea
			for (i = 0; i<3; i++)
			{
				if (b[i] == 1) // Se traseaza o linie
					cod << "<line x1=\"" << pozx << "\" y1=\"20\" x2=\"" << pozx
					<< "\" y2=\"57\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />"
					<< endl;
				pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
			}
			for (i = 3; i <45; i++)
			{
				if (b[i] == 1) // Se traseaza o linie
					cod << "<line x1=\"" << pozx << "\" y1=\"20\" x2=\"" << pozx
					<< "\" y2=\"50\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />"
					<< endl;
				pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
			}
			for (i = 45; i <50; i++)
			{
				if (b[i] == 1) // Se traseaza o linie
					cod << "<line x1=\"" << pozx << "\" y1=\"20\" x2=\"" << pozx
					<< "\" y2=\"57\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />"
					<< endl;
				pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
			}
			for (i = 50; i <92; i++)
			{
				if (b[i] == 1) // Se traseaza o linie
					cod << "<line x1=\"" << pozx << "\" y1=\"20\" x2=\"" << pozx
					<< "\" y2=\"50\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />"
					<< endl;
				pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
			}
			for (i = 92; i <95; i++)
			{
				if (b[i] == 1) // Se traseaza o linie
					cod << "<line x1=\"" << pozx << "\" y1=\"20\" x2=\"" << pozx
					<< "\" y2=\"57\" style=\"stroke:rgb(0,0,0); stroke-width:2\" />"
					<< endl;
				pozx = pozx + 2; // Avans cu 2px, indiferent daca s-a trasat sau nu
			}
			cod << "</svg>" << endl;
			cod << "</body>" << endl;
			cod << "</html>" << endl;
			cod.close();
		}