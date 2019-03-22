/***************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**						BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**							BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**								PROGRAMLAMA GÝRÝÞ DERSÝ
**								  2015-2016 GÜZ DÖNEMÝ
**
**						ÖDEV NUMARASI........:	ÖDEV 2
**						ÖÐRENCÝ ADI..........:	CENGÝZ ALTÜRK
**						ÖÐRENCÝ NUMARASI.....:	G140910048
**						DERSÝN ALINDIÐI GRUP.:  2.ÖÐRETÝM B
******************************************************************/
#include<iostream>
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int d[101], sayi, secenek, mod;//d dizimiz
	for (int i = 0; i <= 100; i++)//bu döngü dizideki tüm elemanlara -1 deðeri atar
	{
		d[i] = -1;
	}
	do{//5 seçeneði seçilmeden durmadan tekrar etmesini saðlamak için baþlangýç döngüsü
		cout << "\n1- Eleman Ekle\n";
		cout << "2- Eleman sil\n";
		cout << "3- Eleman ara\n";
		cout << "4- Eleman listele\n";
		cout << "5- Çýkýþ\n";
		cout << "Seçenek = ";
		cin >> secenek;
		switch (secenek)
		{
		case 1:
			do{// bu döngü pozitif girilmediðinde yeniden döndürmesi için
				cout << "eklenecek sayý = ";
				cin >> sayi;
				if (sayi >= 0)//deðiþken kontrolü pozitifse iþleme baþlar
				{
					mod = sayi % 101;
					if (d[mod] == -1)//bu indeksin dolu olup olmadýðý konrolü
					{
						d[mod] = sayi; cout << "sayý baþarý ile eklenmiþtir.\n";
					}
					else
					{
						cout << "ilgili indeks dolu eleman eklenemedi.\n";
					}
				}
				else
				{
					cout << "pozitif sayi gir.\n";
				}
			} while (sayi < 0);
			break;
		case 2:
			do{// bu döngü pozitif girilmediðinde yeniden döndürmesi için
				cout << "silinecek sayý = ";
				cin >> sayi;
				if (sayi >= 0)//deðiþken kontrolü pozitifse iþleme baþlar
				{
					int i;// i yi dýþarda tanýmlamamýn sebebi eðerki  sayýyý bulup sildiðinde sonradan sayý bulunamadý yazdýrmamasý koþulunda kullana bilmek için
					for (i = 0; i <= 100; i++)
					{
						if (d[i] == sayi)//girilen sayýnýn olup olmadýðý kontrolü
						{
							d[i] = -1;
							cout << "sayý baþarý ile silinmiþtir.\n";
							break;//bu break sadece for düngüsü dýþýna çýkarýr 
						}
					}
					if (i != 101)// for döngüsü sayýyý bulup sildiðinde i 101 den küçük olur sayý bulunamadý çýktýsý vermemesi için döngü dýþýna çýkmamýzý saðlayan koþul
						break; // bu break bize bulunduðu do while döngüsünden çýkmamýzý saðlar
					cout << "sayý bulunamadý.\n";

				}
				else
					cout << "pozitif sayý gir.\n";
			} while (sayi < 0);
			break;
		case 3:
			do{// bu döngü pozitif girilmediðinde yeniden döndürmesi için
				cout << "sayý = ";
				cin >> sayi;
				if (sayi >= 0)//deðiþken kontrolü pozitifse iþleme baþlar
				{
					int i;// i yi dýþarda tanýmlamamýn sebebi eðerki  sayýyý bulup çýktý verdiðinde sonradan sayý bulunamadý yazdýrmamasý koþulunda kullana bilmek için
					for (i = 0; i <= 100; i++)
					{
						if (d[i] == sayi)//girilen sayýnýn olup olmadýðý kontrolü
						{
							cout << "sayý dizide var.\n";
							break;//bu break sadece for düngüsü dýþýna çýkarýr
						}
					}
					if (i != 101)// for döngüsü sayýyý bulup çýktý verdiðinde i 101 den küçük olur sayý bulunamadý çýktýsý vermemesi için döngü dýþýna çýkmamýzý saðlayan koþul
						break;// bu break bize bulunduðu do while döngüsünden çýkmamýzý saðlar
					cout << "sayý bulunamadý.\n";
				}
				else
					cout << "pozitif sayý gir.\n";
			} while (sayi < 0);
			break;
		case 4:
			cout << endl;
			for (int i = 0; i <= 100; i++)
			{
				if (d[i] != -1)//bu döngü girilen sayýlarýn kontrolü
				{
					cout << "[" << i << "]" << "=" << d[i] << endl;

				}
			}
			break;
		case 5:
			cout << endl;
			break;
		default:
			cout << " hatalý seçenek\n";
			break;
		}

	} while (secenek != 5);

}