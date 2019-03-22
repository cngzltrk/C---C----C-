/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/

#include "yonetim.hpp"

Yonetim::Yonetim(){
	o=new Okul(sinifSayisiGetir());
	siniflariEkle();
	ogrencileriEkle();
	Listele();
}
void Yonetim::Listele()
{
	/*
	Y kordinatında en buyuk kenar bulunur
	*/
	int yEnBuyuk=0;
	for(int i=0;i<o->sinifSayisiDondur();i++)
	{
		cout<<o->sinifDondur(i)->sinifGetir()<<"-Sinif 		"<<setw(2);
		if(yEnBuyuk < (o->sinifDondur(i)->OgrenciSayisi()))
			yEnBuyuk=(o->sinifDondur(i)->OgrenciSayisi());
	}
	cout<<endl;
	for(int y=0;y<=yEnBuyuk;y++)//y kordinatı
	{
		cout<<endl;
		for(int x=0;x<o->sinifSayisiDondur();x++)//x kordinatı
		{
			if(o->sinifDondur(x)->ogrenciDondur(y)==NULL)
				cout<<" 		"<<"	"<<setw(2);
			else
				cout<<o->sinifDondur(x)->ogrenciDondur(y)->ogrenciGetir()<<"("<<o->sinifDondur(x)->ogrenciDondur(y)<<")		"<<setw(2);
		}
	}

}	
int Yonetim::sinifSayisiGetir()// sınıf Sayısını bulur
{
	ifstream dosya;
	dosya.open("okul.txt", ios::in);
	int satir=0;
	string okunan;
	while (!dosya.eof())
	{
		getline(dosya, okunan);
		if(okunan[0]!='\0')
			satir++;
	}
	dosya.close();
	return satir;
}
void Yonetim::siniflariEkle(){
	ifstream dosya;
	dosya.open("okul.txt", ios::in);
	string okunan;
	int sutun;
	while (!dosya.eof())
	{
		sutun=0;
		getline(dosya, okunan);
		for(int i=0;i<okunan.length();i++)
		{
			if(okunan[i]!=' '&&i>0)
				sutun++;
		}
		o->sinifEkle(sutun,okunan[0]);
	}
	dosya.close();
}
void Yonetim::ogrencileriEkle(){
	ifstream dosya;
	dosya.open("okul.txt", ios::in);
	string okunan;
	int satir=0;
	while (!dosya.eof())
	{
		getline(dosya, okunan);
		for(int i=0;i<okunan.length();i++)
		{
			if(okunan[i]!=' ')
			{
				if(i>0)
				{
					o->sinifDondur(satir)->ogrenciEkle(okunan[i]);
				}
			}
		}
		satir++;
	}
	dosya.close();
}
void Yonetim::sinifDegistir(char sinif1,char sinif2)
{
	int i1,i2;
	for(int i=0;i<o->sinifSayisiDondur();i++)
	{
		if(sinif1==o->sinifDondur(i)->sinifGetir())
			i1=i;
		if(sinif2==o->sinifDondur(i)->sinifGetir())
			i2=i;
	}
	Sinif *temp=o->okulDondur()[i1];
	o->okulDondur()[i1]=o->okulDondur()[i2];
	o->okulDondur()[i2]=temp;
	Listele();
}
void Yonetim::ogrenciDegistir(char o1,char o2)
{
	int i1,i2,j1,j2;
	for(int i=0;i<o->sinifSayisiDondur();i++)
	{
		for(int j=0;j<o->sinifDondur(i)->OgrenciSayisi();j++)
		{
			if (o1==o->sinifDondur(i)->ogrenciDondur(j)->ogrenciGetir())
			{
				i1=i;j1=j;
			}
			if (o2==o->sinifDondur(i)->ogrenciDondur(j)->ogrenciGetir())
			{
				i2=i;j2=j;
			}
		}	
	}
	Ogrenci *t=o->sinifDondur(i1)->ogrencileriDondur()[j1];
	o->sinifDondur(i1)->ogrencileriDondur()[j1]=o->sinifDondur(i2)->ogrencileriDondur()[j2];
	o->sinifDondur(i2)->ogrencileriDondur()[j2]=t;
	Listele();
}
void Yonetim::Kaydet(){
	ofstream dosya;
	dosya.open("okul.txt");
	for(int i=0;i<o->sinifSayisiDondur();i++)
	{
		dosya<<o->sinifDondur(i)->sinifGetir()<<" ";
		for(int j=0;j<o->sinifDondur(i)->OgrenciSayisi();j++)
		{
			dosya<<o->sinifDondur(i)->ogrenciDondur(j)->ogrenciGetir()<<" ";
		}
		dosya<<endl;	
	}
	dosya.close();
}
Yonetim::~Yonetim(){
	Kaydet();
	delete o;
}