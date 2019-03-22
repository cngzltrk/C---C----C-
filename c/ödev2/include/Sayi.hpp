#ifndef SAYI_HPP
#define SAYI_HPP
#include"Islem.hpp"
class Sayi{
	private:
		Liste *l;
		Islem *i;
		
	public:
		Sayi(string sy){
			i=new Islem();
			l=new Liste();
			Eklet(sy);//islem fonksiyonuna g�ndermek i�in �a�r�lan fonksiyon
		}
		Sayi(Liste *l)
		{
			this->l=l;
		}
		void Eklet(string sayi){//i�lem s�n�f�na sayimiz� g�nderip i�lem yapmam�z� sa�lar
			l=i->Ekle(sayi);
		}
		string Getir(){//bu fonksiyonumuz yazd�rma i�lemi i�in
			return l->Listele();
		}
		Liste* GetirListe(){//listemizi getiren fonksiyonumuz static fonksiyonda i� g�rmesi i�in
			return l;
		}
		
		friend ostream& operator<<(ostream& ekran, Sayi& sag){
			ekran <<sag.Getir();
			return ekran;
		}
		
		friend Sayi* operator+(Sayi &s1,Sayi &s2)
		{
			Islem *y=new Islem();
			Liste *l1,*l2;
			l1=s1.GetirListe();
			l2=s2.GetirListe();
			
			Liste *l=y->Topla(l1,l2);
			Sayi *sonuc=new Sayi(l);
			delete y;
			return sonuc;
		}
		~Sayi(){
			delete l;
		}
};
#endif
