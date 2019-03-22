/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/
#include "sinif.hpp"

Sinif::Sinif(int sayi,char c)
	{
		isim=c;
		ogrenciSayisi=sayi;
		ogrenciler=new Ogrenci*[sayi];
		oes=0;
	}
void Sinif::ogrenciEkle(char c)
{
	if(oes<ogrenciSayisi)
	{
		Ogrenci *o =new Ogrenci(c);
		*(ogrenciler+oes)=o;
		
		oes+=1;
	}
	else
		cout<<"Ogrenci eklenemedi"<<endl;
}
void Sinif::ogrenciListele()
{
	for(int i=0;i<ogrenciSayisi;i++)
	{
		cout<<ogrenciler[i]->ogrenciGetir()<<" ";
	}
}
Ogrenci* Sinif::ogrenciDondur(int i)
{
	if( i < ogrenciSayisi)
	{
		return *(ogrenciler+i);
	}
	return NULL;
}
Ogrenci** Sinif::ogrencileriDondur(){
	return ogrenciler;
}
int Sinif::OgrenciSayisi(){
	return ogrenciSayisi;
}
char Sinif::sinifGetir()
{
	return isim;
}
Sinif::~Sinif(){
	delete *ogrenciler;
}