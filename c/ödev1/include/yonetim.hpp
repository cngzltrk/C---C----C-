/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/
#ifndef YONETIM_HPP
#define YONETIM_HPP
#include<iostream>
#include<fstream>//dosya işemleri
#include <iomanip>//düzenli çıktı
#include "okul.hpp"
using namespace std;
class Yonetim{
	private:
		Okul *o;
		int sinifSayisiGetir();// sınıf Sayısını bulur
		void siniflariEkle();
		void ogrencileriEkle();
		void Listele();
		void Kaydet();//işlemler bittikten sonra eldeki veriyi txt dosyasına kaydetme
	public:
		Yonetim();
		~Yonetim();
		void sinifDegistir(char sinif1,char sinif2);
		void ogrenciDegistir(char ogrenci1,char ogrenci2);
};
#endif
