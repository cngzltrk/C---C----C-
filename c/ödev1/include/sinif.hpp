/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/
#ifndef SINIF_HPP
#define SINIF_HPP
#include "ogrenci.hpp"
#include<iostream>
using namespace std;
class Sinif{
	private:
		Ogrenci **ogrenciler;
		char isim;
		int ogrenciSayisi;
		int oes;//öğrenci ekleme sayisi kontrol amaçlı
	public:
		Sinif(int sayi,char c);//sınıf ismi ve kaç adaet öğrenci parametreleri
		void ogrenciEkle(char c);
		void ogrenciListele();//öğrencileri listeler
		char sinifGetir();//ismi döndürür
		int OgrenciSayisi();//öğrenci sayisi 
		Ogrenci* ogrenciDondur(int i);
		Ogrenci** ogrencileriDondur();
		~Sinif();
};
#endif
