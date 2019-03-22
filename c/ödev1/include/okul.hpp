/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/

#ifndef OKUL_HPP
#define OKUL_HPP
#include "sinif.hpp"
class Okul{
	private:
		Sinif **siniflar;
		int sinifSayisi;
		int ses;//sinif ekleme sayısı kontrol amaçlı
	public:
		Okul(int s);
		void sinifEkle(int s,char c);//adet ve isim
		void sinifListele();
		int sinifSayisiDondur();
		Sinif* sinifDondur(int i);
		Sinif** okulDondur();
		~Okul();
};
#endif
