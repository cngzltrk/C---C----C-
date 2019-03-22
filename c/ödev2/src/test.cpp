
#include"Sayi.hpp"
int main(){
	string sayi1,sayi2;
	cout << "Sayi 1 ..:";
	cin >> sayi1;
	cout << "Sayi 2 ..:";
	cin >> sayi2;
	Sayi *s1, *s2;
	s1 = new Sayi(sayi1);
	s2 = new Sayi(sayi2);
	cout << "Sayi 1 Listesi..:" << *s1 << endl;
	cout << "Sayi 2 Listesi..:" << *s2 << endl;
	Sayi *s3=(*s1+*s2);
	
	cout << endl << "toplam ..:"<<*s3;
	delete s1, s2,s3;
	cin.ignore();
	return 0;

}
