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
		const void Ekle(const char sy){//ekleme sondan ekleme kuyruk veri yapýsý olduðundan
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
		const void Listele(){//kuyruktaki verileri göstermek amaçlý fonksiyon
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
		int Toplam(){//kuyruktaki verilerin toplamýný veren fonk
			int top=0;
			Dugum *tmp;
			tmp=basDugum;
			while(tmp!=NULL)
			{
				top+=((int)tmp->sayi-48);//char versini int e çevirme iþlemi
				tmp=tmp->ileri;
			}
			return top;
		}
		void Sil(){//silme iþlemi kuyruðun baþýndan silme 
			if(elemanSayisi==0)
			{
				cout<<"Liste Boþ";
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
