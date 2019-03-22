
#include"Sayi.hpp"
int main(){
	Sayi *s=new Sayi();
	int secim;
	s->Listele();
	do{
		
		cout<<"\n1- Sayi ekle";
		cout<<"\n2- Sayi listesi";
		cout<<"\n0- Sistemden Cik ve Agac veri yapisini listele";
		cout<<"\n Isleminiz...:";
		cin>>secim;
		
		switch(secim){
			case 1:
				s->SayiEkle();
				break;
			case 2:
				s->Listele();//metin belgesinde bulunan sayýlarý listeler
				break;
			case 0:
				cout<<"Listeleme islemi yapiliyor ..";
				Sleep(1000);
				break;
			default:
				cout<<" \nHatali secim \n";
				break;			
		}
	}while(secim!=0);
	s->Bitir();
	delete s;
	cin.ignore();
	return 0;

}
