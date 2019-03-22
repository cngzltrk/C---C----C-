/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/


#include<iostream>
#include "yonetim.hpp"
#include <locale.h>

using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Turkish"); //Türkçe karater
	Yonetim *y=new Yonetim();

	int secim;
	do{
		cout<<"\n1- Sinif Degistir"<<endl;
		cout<<"2- Ogrenci Degistir"<<endl;
		cout<<"3- Cikis"<<endl;
		cout<<"->";
		cin>>secim;
		switch(secim)
		{
			case 1:
				char sinif1,sinif2;
				cout<<"Birinci sinif :";
				cin>>sinif1;
				cout<<"Ikinci sinif :";
				cin>>sinif2;
				y->sinifDegistir(sinif1,sinif2);
			break;
			case 2:
				char ogrenci1,ogrenci2;
				cout<<"1- ogrenci :";
				cin>>ogrenci1;
				cout<<"1- ogrenci: ";
				cin>>ogrenci2;
				y->ogrenciDegistir(ogrenci1,ogrenci2);
			break;
			case 3:
			break;
			default:
				cout<<"Hatalı giriş"<<endl;
				break;
		}
		
	}while(secim!=3);
	delete y;
}