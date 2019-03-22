#ifndef KUYRUKLISTE_HPP
#define KUYRUKLISTE_HPP
#include"Dugum.hpp"
class KuyrukListe{
	private:
		Dugum *basDugum,*sonDugum;
		int elemanSayisi;
	public:
		KuyrukListe(){
			basDugum=sonDugum=NULL;
			elemanSayisi=0;
		}
		const void Ekle(const char sy){//ekleme sondan ekleme kuyruk veri yap�s� oldu�undan
			if(basDugum==NULL)
			{
				basDugum=new Dugum(sy);
				sonDugum=basDugum;
			}
			else{
				sonDugum->ileri=new Dugum(sy);
				sonDugum=sonDugum->ileri;
			}
			elemanSayisi++;
		}
		const void Listele(){//kuyruktaki verileri g�stermek ama�l� fonksiyon
			Dugum *tmp;
			tmp=basDugum;
			while(tmp!=NULL)
			{
				cout<<" "<<tmp->sayi;
					if(tmp->ileri!=NULL)
						cout<<" -";
				tmp=tmp->ileri;
			}
			cout<<endl;
			
		}
		int Toplam(){//kuyruktaki verilerin toplam�n� veren fonk
			int top=0;
			Dugum *tmp;
			tmp=basDugum;
			while(tmp!=NULL)
			{
				top+=((int)tmp->sayi-48);//char versini int e �evirme i�lemi
				tmp=tmp->ileri;
			}
			return top;
		}
		void Sil(){//silme i�lemi kuyru�un ba��ndan silme 
			if(elemanSayisi==0)
			{
				cout<<"Liste Bo�";
			}
			else
			{
				Dugum *tmp;
				tmp=basDugum;
				basDugum=basDugum->ileri;
				delete tmp;
				elemanSayisi--;
			}
		}
		void Temizle(){
			for(int i=1;i<=elemanSayisi;i++){
				Sil();
			}
			basDugum=sonDugum=NULL;
		} 
		int Elemansayisi()const{
			return elemanSayisi;
		}
		~KuyrukListe(){
			Temizle();
		}
};

#endif
