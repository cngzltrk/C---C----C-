#ifndef AGAC_HPP
#define AGAC_HPP
#include"DugumAgac.hpp"
#include"KuyrukListe.hpp"
class Agac{
	private:
		DugumAgac *kok;

		void AraveEkle(DugumAgac *&alt_Dugum,KuyrukListe *yeni){
			if(alt_Dugum == NULL)
				alt_Dugum = new DugumAgac(yeni);
			else if(yeni->Toplam() < alt_Dugum->liste->Toplam())
				AraveEkle(alt_Dugum->sol,yeni);
			else if(yeni->Toplam() > alt_Dugum->liste->Toplam())
				AraveEkle(alt_Dugum->sag,yeni);
			else return; // Ayný eleman var. ekleme yapmýyoruz
		}
		bool DugumSil(DugumAgac *&alt_Dugum)
		{
			DugumAgac *tmp = alt_Dugum;
			
			if(alt_Dugum->sag == NULL) 
			{
				alt_Dugum = alt_Dugum->sol;
				tmp->liste->Temizle();
			}		
			else if(alt_Dugum->sol == NULL)
			{
				alt_Dugum = alt_Dugum->sag;
				tmp->liste->Temizle();
			}
				
			else{
				tmp = alt_Dugum->sol;
				DugumAgac *ebeveynDugum = alt_Dugum;
				while(tmp->sag != NULL){
					ebeveynDugum=tmp;
					tmp=tmp->sag;
				}
				alt_Dugum->liste->Temizle();
				alt_Dugum->liste = tmp->liste;
				if(ebeveynDugum == alt_Dugum) alt_Dugum->sol = tmp->sol;
				else ebeveynDugum->sag = tmp->sol;
			}			
			delete tmp;
			return true;
		}
		void Inorder(DugumAgac *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Inorder(alt_Dugum->sol);
				cout<<alt_Dugum->liste->Toplam()<<" ";
				Inorder(alt_Dugum->sag);
			}
		}
		void Preorder(DugumAgac *alt_Dugum) const{
			if(alt_Dugum != NULL){
				cout<<alt_Dugum->liste->Toplam()<<" ";
				Preorder(alt_Dugum->sol);
				Preorder(alt_Dugum->sag);
			}
		}
		void Postorder(DugumAgac *alt_Dugum) const{
			if(alt_Dugum != NULL){
				Postorder(alt_Dugum->sol);
				Postorder(alt_Dugum->sag);				
				cout<<alt_Dugum->liste->Toplam()<<" ";
			}
		}		
		int Yukseklik(DugumAgac *alt_Dugum){
			if(alt_Dugum == NULL) return -1;
			return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
		}
		public:
			Agac(){
				kok = NULL;
			}
			bool Bosmu() const{
				return kok == NULL;
			}
			void Ekle(KuyrukListe *yeni)
			{
				AraveEkle(kok,yeni);
			}
			void Inorder() const{
				Inorder(kok);
			}
			void Preorder() const{
				Preorder(kok);
			}
			void Postorder() const{
				Postorder(kok);
			}
			void Temizle(){
				while(!Bosmu())
					DugumSil(kok);
			}
			int Yukseklik(){
				return Yukseklik(kok);
			}
			~Agac(){
				Temizle();
			}
};
#endif
