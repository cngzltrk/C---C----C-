#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
#include<cstddef>
using namespace std;
class Dugum{
	public:
		int sayi;
		Dugum *ileri;
		Dugum *geri;
		Dugum(int sy,Dugum *ilr=NULL,Dugum *gr=NULL){
			sayi=sy;
			ileri=ilr;
			geri=gr;
		}
};

#endif
