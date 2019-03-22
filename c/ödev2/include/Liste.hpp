#ifndef LISTE_HPP
#define LISTE_HPP
#include"Dugum.hpp"
class Liste{
	private:
		Dugum *basDugum,*sonDugum;
		int elemanSayisi;
	public:
		Liste(){
			basDugum=sonDugum=NULL;
			elemanSayisi=0;
		}
		void SonEkle(int sy){//Liste sonuna ekleme
			if (basDugum == NULL)
			{
				basDugum = new Dugum(sy);
				sonDugum = basDugum;
			}
			else
			{
				sonDugum->ileri = new Dugum(sy, NULL, sonDugum);
				sonDugum = sonDugum->ileri;
			}
			elemanSayisi++;
		}
		void BasEkle(int sy){//Liste ba��na ekleme
			if (sonDugum == NULL)
			{
				sonDugum = new Dugum(sy);
				basDugum = sonDugum;
			}
			else
			{
				basDugum->geri = new Dugum(sy, basDugum, NULL);
				basDugum = basDugum->geri;
			}
			elemanSayisi++;
		}
		void Temizle(){//Listeyi temizleme
			for (int i = 0; i < elemanSayisi; i++){
				if (elemanSayisi == 0)
				{
					cout << "Eleman Yok";
				}
				else
				{
					Dugum *tmp;
					tmp = basDugum;
					basDugum = tmp->ileri;
					delete tmp;
				}
			}
			basDugum = sonDugum = NULL;
			elemanSayisi = 0;
		}
		string Listele(){//Bu fonksiyon << operat�r a��r� y�klemde ekrana yaz�lacak yaz� y� sa�lar
			string yazi;
			Dugum *tmp;
			tmp = basDugum;
			while (tmp != NULL)
			{
				if (tmp != basDugum)
					yazi+=" - ";
				yazi+=((char)tmp->sayi+48);//int i char a �evirmek i�in gerekn i�lem
				tmp = tmp->ileri;
			}
			return yazi;
		}
		int ElemanSayisi(){
			return elemanSayisi;
		}
		int ElemanVeri(int konum){//Bu konumu verilen Listenin verisini getirir
			int sayac=1;
			Dugum *tmp;
			tmp = basDugum;
			while (tmp != NULL)
			{
				if (sayac==konum)
					return tmp->sayi;
				tmp = tmp->ileri;
				sayac++;
			}
		}
		~Liste(){
			Temizle();
		}	
};

#endif
