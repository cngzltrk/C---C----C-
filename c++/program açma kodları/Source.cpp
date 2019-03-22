#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	//string is;
	//cout << "BÝLGÝSAYARDA AÇILMAK ÝSTENEN ÝSMÝ YAZIN ..:";
	//cin >> is;
	//cout << is;
	////system("start is");
	//system("shutdown -r"); bilgisayarý resetler
	//system("shutdown -s -t 1");bilgisayarý kapatýr
	//system("shutdown -l -f -t 1");//Özel kod :Uygulamlarý kapat ve bilgisayar oturmunu 1 saniyede kapat :)
	int s,d=1;
	while (d){
		cout << "1- tarayýcý chorome aç\n";
		cout << "2- not defteri aç\n";
		cout << "3- lol  aç\n";
		cout << "0- çýkýþ \n";
		cout << "Secenek gir ..:";
		cin >> s;
		switch (s)
		{///dasdasd
		case 1:
			system("start chrome");
			break;
		case 2:
			system("start notepad++");
			break;
		case 3:
			system("start lol.launcher");//tam doðru olmadýðýdan açmýyor
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "yanlýþ secenek";
			break;
		}
	}

}
