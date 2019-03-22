#include<iostream>
using namespace std;
int convert(char);//9+5+8+2  1+2+3+4
int main()
{
bas:
	char sayi[100];
	int top = 0, s1;
	cout << "Ýslem gir ..:";
	cin >> sayi;
	s1 = convert(sayi[0]);
	top += s1;

	for (int i = 0; 1; i++)
	{

		if (sayi[i] == '+')
		{

			s1 = convert(sayi[i + 1]);
			top += s1;
			i = i + 1;

		}
		else if (sayi[i] == '-')
		{

			s1 = convert(sayi[i + 1]);
			top -= s1;
			i = i + 1;
		}
		else if (sayi[i] == '\0')
		{
			break;
		}

	}
	cout << "Sonuc ...:" << top << endl;
	goto bas;
}
int convert(char sayi)
{
	int s = (int)sayi - 48;
	return s;
}