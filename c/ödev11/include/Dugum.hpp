#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
using namespace std;
class Dugum{
	private:
		char sayi;
		Dugum *ileri;
	public:
		Dugum(const char sy,Dugum *ilr=NULL)
		{
			sayi=sy;
			ileri=ilr;
		}
	
};

#endif
