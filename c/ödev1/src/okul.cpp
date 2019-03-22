/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/

#include "okul.hpp"

Okul::Okul(int s)
{
	sinifSayisi=s;
	siniflar=new Sinif*[s];
	ses=0;
}
void Okul::sinifEkle(int s,char c)//adet ve isim
{
	if(ses<sinifSayisi)
	{
		Sinif *t =new Sinif(s,c);
		*(siniflar+ses)=t;
		
		ses+=1;
	}
}
void Okul::sinifListele()
{
	for(int i=0;i<sinifSayisi;i++)
	{
		cout<<siniflar[i]->sinifGetir()<<endl;
	}
}
int Okul::sinifSayisiDondur()
{
	return sinifSayisi;
}
Sinif** Okul::okulDondur()
{
	return siniflar;
}
Sinif* Okul::sinifDondur(int i)
{
	return *(siniflar+i);
}
Okul::~Okul(){
	delete *siniflar;
}
