/**
* @file test
* @description main dosyası
* @course 2B
* @assignment 1. ödev
* @date 29.10.2018
* @author G171210113 Dilek Ayşe Gün   	dilek.gun@ogr.sakarya.edu.tr 
		  G171210017 Tuğba Ulusoy 		tugba.ulusoy@ogr.sakarya.edu.tr 
*/
#include "ogrenci.hpp"

Ogrenci::Ogrenci(char i)
{
	isim=i;
}
char Ogrenci::ogrenciGetir()
{
	return isim;
}