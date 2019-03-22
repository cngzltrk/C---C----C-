#ifndef SAYI_HPP
#define SAYI_HPP
#include"Agac.hpp"
#include"KuyrukListe.hpp"
class Sayi{
private:
	KuyrukListe *liste;
	Agac *agac;
public:
	Sayi(){
		agac=new Agac();
	}
	void SayiEkle(){
		string sayi;
		ofstream dosya;
		dosya.open("sayilar.txt",ios::app);
		cout<<"\n Sayi ...:";
		cin>>sayi;
		dosya<<sayi<<endl;
		dosya.close();
		cout<<"\n Sayi eklendi .  \n";
	}
	void Listele(){
		string sayi;
		ifstream dosyaoku("sayilar.txt");
		cout<<"\n";
		while(!(dosyaoku.eof()))
		{
			dosyaoku>>sayi;
			if(!(dosyaoku.eof()))
				cout<<sayi<<endl;
		}
	}
	void Bitir(){
		cout<<endl<<"Liste ..\n";
		Listele();
		cout<<endl<<"Kuyruklar ..\n";
		
		string sayi;
		ifstream dosyaoku("sayilar.txt");
		while(!(dosyaoku.eof()))
		{
			liste=new KuyrukListe();
			dosyaoku>>sayi;
			if(!(dosyaoku.eof()))
			{
				for(int i=0;1;i++)
				{
					if(sayi[i]=='\0')
						break;
					liste->Ekle(sayi[i]);
				}
				cout<<"\n";
				liste->Listele();
				agac->Ekle(liste);
				
				
			}
		}
		cout<<"\n";
		cout<<"inorder...:\n";
		agac->Inorder();
		cout<<"\npreorder...:\n";
		agac->Preorder();
		cout<<"\npostorder...:\n";
		agac->Postorder();
		cout<<"\n";
		
	}
	~Sayi(){
		delete agac;
	}
};
#endif
