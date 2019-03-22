#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
#include<fstream>//dosya okuma iþlemi için
#include<windows.h>//sleep fonksiyonu için
#include<cstddef>//null hatasý vermemesi için
using namespace std;
class Dugum{
	public:
		char sayi;
		Dugum *ileri;
		Dugum(char sy,Dugum *ilr=NULL){
			sayi=sy;
			ileri=ilr;
		}
};

#endif
