#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	//string is;
	//cout << "B�LG�SAYARDA A�ILMAK �STENEN �SM� YAZIN ..:";
	//cin >> is;
	//cout << is;
	////system("start is");
	//system("shutdown -r"); bilgisayar� resetler
	//system("shutdown -s -t 1");bilgisayar� kapat�r
	//system("shutdown -l -f -t 1");//�zel kod :Uygulamlar� kapat ve bilgisayar oturmunu 1 saniyede kapat :)
	int s,d=1;
	while (d){
		cout << "1- taray�c� chorome a�\n";
		cout << "2- not defteri a�\n";
		cout << "3- lol  a�\n";
		cout << "0- ��k�� \n";
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
			system("start lol.launcher");//tam do�ru olmad���dan a�m�yor
			break;
		case 0:
			d = 0;
			break;
		default:
			cout << "yanl�� secenek";
			break;
		}
	}

}
