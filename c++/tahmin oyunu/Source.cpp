#include<iostream>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
using namespace std;
int main()
{
	int sayi,tahmin,hak=10;
	char secenek;
	srand(time(NULL));
bas:
	system("cls");
	cout << "Say� atan�yor ... ";
	Sleep(2000);
	sayi = rand() % 101;
	cout << "\t Say� atand�" << endl;
	
	do{
		cout << "  Tahmini gir ....:";
		cin >> tahmin;
		if (hak == 0)
		{
			cout << "\noyun bitti\n"; 
			goto son;
		}
		else if (sayi == tahmin)
		{
			cout << " \nTeprikler bildiniz .. \n" << endl;
			goto son;
		}
		else if (sayi < tahmin)
			cout << "\nk���k\n";	
		else if (sayi>tahmin)
			cout << "\nb�y�k\n";
		hak -= 1;
	} while (hak);
	son:
	cout << "devam etcen mi (e/h)..:";
	cin >> secenek;
	if (secenek == 'e')
		goto bas;
	

}