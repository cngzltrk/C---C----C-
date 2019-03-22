#ifndef ISLEM_HPP
#define ISLEM_HPP
#include"Liste.hpp"

class Islem{
	private:
		Liste *l;
	public:
	Liste* Ekle(string sy){//bu fonksiyonumuz ald��� stringi par�alay�p int e �evirip listeye ekler
		int deger;
		l = new Liste();
		for (int i = 0; 1; i++){
			if (sy[i] == '\0')
				break;
			deger=(int)sy[i]-48;
			l->SonEkle(deger);
		}
		return l;
	}
	//bu fonksiyon da ald��� listeleri alt alta toplama i�lemi yaparak 
	//liste  olu�turup pointer d�nd�rmektedir
	//hata:::burada e�er elde olay� 2 nin �st�nde ise hatal� sonu� vermektedir 
	
	Liste* Topla(Liste *l1,Liste *l2){
		int uzunluk,top,kalan=0,e1,e2;
		e1=l1->ElemanSayisi();
		e2=l2->ElemanSayisi();
		Liste *sonuc=new Liste();
		
		if(e1<=e2)
			uzunluk=e2;
		else
			uzunluk=e1;
		for(int i=0;i<uzunluk;i++){
			if(e1<0)
				top=l2->ElemanVeri(e2);
			else if(e2<0)
				top=l1->ElemanVeri(e1);		
			else
				top=l1->ElemanVeri(e1)+l2->ElemanVeri(e2)+kalan;
			
			kalan=top/10;
			if(kalan==1){
				kalan=1;
			}
			else
				kalan=0;
			sonuc->BasEkle(top%10);
			e1--;
			e2--;
		}
		if(kalan>0){
			sonuc->BasEkle(kalan);
		}
		return sonuc;
	}
};

#endif
