/***************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**						BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ			
**							BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**								PROGRAMLAMA GÝRÝÞ DERSÝ
**								  2015-2016 GÜZ DÖNEMÝ
**
**						ÖDEV NUMARASI........:	ÖDEV 1
**						ÖÐRENCÝ ADI..........:	CENGÝZ ALTÜRK
**						ÖÐRENCÝ NUMARASI.....:	G140910048
**						DERSÝN ALINDIÐI GRUP.:    B
******************************************************************/
#include<iostream>
#include<iomanip>
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int k, t, s = 1, top = 0, fak = 1, carp = 1, aratop = 0, c;//s=SAYACIMIZ	c=2.SAYACIMIZ
	gir:
	cout << " k degerini giriniz (5'den büyük 10'dan küçük olmalý)...=";
	cin >> k;
	cout << " t degerini giriniz (1'den büyük 9'dan  küçük olmalý)...=";
	cin >> t;
	if (5 <= k&&k <= 10)//ÝLK DEÐÝÞKEN KONTROLÜ
	{
		if (1 <= t&&t < 9)//ÝKÝNCÝ EDÐÝÞKEN KONTROLÜ EÐER DOÐRUYSA ÝÞLEME BAÞLAR
		{
			cout << endl << setw(10) << "faktoriyel" << setw(17) << "carpým" << setw(15) << "AraToplam" << endl << endl;//BAÞLIK LAR ÝÇÝN YAZMA KODU
		bas:
			if (s <= k)//ilk sayaç konrolü
			{
				fak = fak*s;
				cout << setw(10) << fak << setw(5) << "+";
				c = s;
				if (c <= t)//burda çarpým sembolünün iþlevi olup  olmadýðýnýn  kontrolü
				{
					carp = 1;
				car:
					if (c <= t)//ikinci sayac kontrolü
					{
						carp = 2 * carp*c;
						c = c + 1;
						goto car;
					}
				}
				cout << setw(12) << carp;
				aratop = fak + carp;
				top = top + fak + carp;
				cout << setw(5) << " " << "=" << aratop << endl;
				carp = 0;//çarpýmýn iþlevi bittiðinde +1 eklememesi için 
				s = s + 1;
				goto bas;
			}
			cout << endl << "Toplam.....=" << top << endl;
		}
		else
		{
			cout << " t deðeri yanlýþ girilmiþtir" << endl;
			goto gir;
		}
	}
	else
	{
		cout << " k deðeri yanlýþ girilmiþtir" << endl;
		if (!(1 <= t&&t < 9))//burda 1. yanlýþsa 2. sinide kontrolü yapýlmasý için
		{
			cout << " t deðeri yanlýþ girilmiþtir" << endl;
		}	
		goto gir;
	}
	
	system ("pause");
	return 0;
}
