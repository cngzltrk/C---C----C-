#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
#include<fstream>//dosya okuma i�lemi i�in
#include<windows.h>//sleep fonksiyonu i�in
#include<cstddef>//null hatas� vermemesi i�in
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
