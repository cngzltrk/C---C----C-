/***************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**						BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**							BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**								PROGRAMLAMA GÝRÝÞ DERSÝ
**								  2015-2016 GÜZ DÖNEMÝ
**
**						ÖDEV NUMARASI........:	ÖDEV 3-4
**						ÖÐRENCÝ ADI..........:	CENGÝZ ALTÜRK
**						ÖÐRENCÝ NUMARASI.....:	G140910048
**						DERSÝN ALINDIÐI GRUP.:  2.ÖÐRETÝM B
******************************************************************/
#include<iostream>
#include<locale>//Türkçe karakter için
using namespace std;
void degistir(char*);//bu fonksiyon 3 seçenek için fonksiyon deklerasyonu
void degistir(char*, char*);//bu fonksiyon 4 seçenek için ve ayný fonksiyonu kullanarak aþýrý yükleme yaptým
int ozyinemeli(int);//bu fonksiyon 1. seçenek için fonksiyon deklerasyonu
struct dikdörtgen{// yapýmýz
	double x;
	double y;
	double yüksek;
	double genis;
};
bool nokta(struct dikdörtgen, double, double);//nokta için fonksiyon deklerasyonu
double alan(struct dikdörtgen);//dikdörtgenin alaný için fonksiyon deklerasyonu
int main()
{
	setlocale(LC_ALL, "Turkish");//Türkçe karakter için
	int secenek,n;
	do//bu döngü 5 e basmadan  her seferinde döndürmemizi saðlar
	{	
		cout << "\n 1) Özyinelemeli Fonksiyon\n";
		cout << " 2) Dikdörtgen Yapýsý\n";
		cout << " 3) Büyük-Küçük Harf deðiþimi\n";
		cout << " 4) Ýki karakter dizisinin yer deðiþimi\n";
		cout << " 5) Programdan Çýkýþ\n";
		cout << " \nÝþlem seçiniz...:";
		cin >> secenek;
		switch (secenek)
		{
		case 1:
			do//bu döngü pozitif girilmediðinde döndürmemizi saðlar
			{
				cout << "n deðerini giriniz...:";
				cin >> n;
				if (n >= 0)//eðer sayý pozitif ise iþleme baþlar
				{
					cout << "Özyinemeli F(" << n << ")...:" << ozyinemeli(n) << endl;// burada fonksiyona gönderip orda iþlem yaptýrýyoruz
					
				}
				else
				{
					cout << "pozitif deðer giriniz\n";
				}
			} while (n < 0);
			break;
		case 2:
			double bx, by;//bunlar verilen noktanýn dikdörtgen içindemi dýþýndamý diye koordinatlarý
			dikdörtgen d1;
			cout << "Sol alt köþe koordinatlarýný giriniz (x,y)...:\n";
			cin >> d1.x >> d1.y;//yapýmýzda bulunan x ve y baþlangýç noktalarý
			cout << "yükseklik deðerini giriniz...:";
			cin >> d1.yüksek;
			cout << "geniþlik deðerini giriniz...:";
			cin >> d1.genis;
			cout << "Nokta koordinatlarýný giriniz (x,y)...:\n";
			cin >> bx >> by;//noktanýn koordinatlarý

			cout << "alan...:" << alan(d1) << endl;//fonksiyona gönderip orda iþlemleri yaptýrýyoruz
			cout << "Belirtiðiniz nokta içinde mi ?...:" << nokta(d1, bx, by) << endl;//fonksiyona gönderip orda iþlemleri yaptýrýyoruz
			break;
		case 3:
			char dizi[20];//dizimiz 
			cout << "Kelime giriniz....:";
			cin >> dizi;
			degistir(&dizi[0]);//fonksiyona göndererek orda iþlem yaptýrýyoruz
		
			
			break;
		case 4:

			char dizi1[20], dizi2[20];//dizilerimiz
			cout << "ilk dizimizi giriniz....:";
			cin >> dizi1;//1 . dizimize veri yazdýran
			cout << "Ýkinci dizimizi giriniz....:";
			cin >> dizi2;//2 . dizimize veri yazdýran
			degistir(&dizi1[0], &dizi2[0]);//fonksiyona gönderek orda iþlem yaptýrýyoruz
			break;
		case 5:	//programý kapatmýzý saðlayan seçenek
			break;
		default:// seçenekler dýþýnda seçim yapýldýðýnda 
			cout << "\n Hatalý iþlem\n";
			break;
		}
	} while (secenek != 5);
	return 0;
}
int ozyinemeli(int sayi)// özyeinemeli yaptým
{
	if (sayi == 0) //burda verilen denklemde f(0) ise 1 döndürmesi için
		return 1;
	else if (sayi == 1) //burda verilen denklemde f(1) ise 2 döndürmesi için
		return 2;
	else
	{
		return 2*(ozyinemeli(sayi - 1) - (sayi - 1)*ozyinemeli(sayi - 2));//denklemi 2 parantezine alarak yaptým burda  n sayýsý eðer 1 den büyükse verilen denklemde f(1) ve f(0) lara fonksiyonu çaðýrarak döndürme yapmasý için 
	}
}
void degistir(char* fdizi)
{
	int ks = 0;//ks karakter sayýsý
	cout << "\n Kelimenin öncesi....:";
	for (int i = 0; 1; i++)//bu döngü hem karakter sayýsýný saymamýzý hemde dizimizi yazmýzý saðlar
	{
		if (*fdizi == '\0')//eðerki dizinin sonu geldiðinde for döngüsünden çýkmamýzý saðlamasý için gereken koþul
		{
			break;
		}
		else
		{
			ks += 1;
		}
		cout << *fdizi;//burda adreste bulunan veriyi yazdýrmamýzý saðlar

		fdizi += 1;//bu dizimizin adreslerini bulabilmemiz için adresi 1 bayt olarak artýrmamýzý saðlar
	}
	cout << "\n Kelimenin sonrasý.....:";
	fdizi -= ks;//burda dizinin son adresinden karakter sayýsýný çýkararak ilk adresine bulmamýzý saðlýyor
	for (int i = 0; i < ks; i++)//bu döngü karakterleri deðiþtirmemizi saðlar 
	{//ascýý taplosunda küçük harflar büyük harflerden sonra geldiðini gösteriyor ve her büyük küçük harf arasýnda 32 sayýsý kadar fark var 
		if (*fdizi > 'Z')//burda eðer karakter küçükse büyük yapmýzý
		{
			*fdizi -= 32;//burda adresteki veriyideðiþtiren kod;
		}
		else//deðilse büyükse yani harf küçük yapmýmýzý saðlar
		{
			*fdizi += 32;//ascý taplosunda A=65 a=97 deðerlerini gösteriyor farklarýndan yararlanarak 32
		}
		cout << *fdizi;//adresteki veriyi yazdýran
		fdizi += 1;//dizinin adreslerini bulmamýzý saðlayan kod
	}
	cout << endl;
}
void degistir(char* fdizi1, char *fdizi2)
{
	char *ftemp;//deðiþtirmemizi saðlamasý geçici adres
	int ks1 = 0, ks2 = 0;//dizilerimizin karakter sayýsý 1.dizi iiçin ks1,2.dizimiz için ks2
	cout << "\n Ýlk dizinin öncesi....:";
	for (int i = 0; 1; i++)////bu döngü hem karakter sayýsýný saymamýzý hemde dizimizi yazmamýzý saðlar
	{
		if (*fdizi1 == '\0')//eðerki dizinin sonu geldiðinde for döngüsünden çýkmamýzý saðlamasý için gereken koþul
		{
			break;
		}
		else
		{
			ks1 += 1;
		}
		cout << *fdizi1;//burda adreste bulunan veriyi yazdýrmamýzý saðlar
		fdizi1 += 1;//dizinin adreslerini bulmamýzý saðlayan kod
	}
	cout << "\n Ýkinci dizinin öncesi....:";
	for (int i = 0; 1; i++)//bu döngü hem karakter sayýsýný saymamýzý hemde dizimizi yazmamýzý saðlar
	{
		if (*fdizi2 == '\0')//eðerki dizinin sonu geldiðinde for döngüsünden çýkmamýzý saðlamasý için gereken koþul
		{
			break;
		}
		else
		{
			ks2 += 1;
		}
		cout << *fdizi2;//burda adreste bulunan veriyi yazdýrmamýzý saðlar
		fdizi2 += 1;//dizinin adreslerini bulmamýzý saðlayan kod
	}
	cout << "\n";
	fdizi1 -= ks1;//burda dizinin son adresinden karakter sayýsýný çýkararak ilk adresine bulmamýzý saðlýyor 
	fdizi2 -= ks2;//burda dizinin son adresinden karakter sayýsýný çýkararak ilk adresine bulmamýzý saðlýyor
	ftemp = fdizi1;//dizi 1 de bulunan adresi geçiciye atarak
	fdizi1 = fdizi2;//dizi 2 de bulunan adresi dizi 1e atarak
	fdizi2 = ftemp;//geçicide de bulunan adresi dizi 2 atarak dizilerimizin adreslerini deðiþtirdik
	cout << "\n Ýlk dizinin sonrasý.....:";
	for (int i = 0; 1; i++)//bu döngü  dizimizi yazmamýzý saðlar
	{
		if (*fdizi1 == '\0')//eðerki dizinin sonu geldiðinde for döngüsünden çýkmamýzý saðlamasý için gereken koþul
		{
			break;
		}
		else
		{
			cout << *fdizi1;
		}

		fdizi1 += 1;//dizinin adreslerini bulmamýzý saðlayan kod
	}
	cout << "\n Ýkinci dizinin sonrasý.....:";
	for (int i = 0; 1; i++)//bu döngü  dizimizi yazmamýzý saðlar
	{
		if (*fdizi2 == '\0')//eðerki dizinin sonu geldiðinde for döngüsünden çýkmamýzý saðlamasý için gereken koþul
		{
			break;
		}
		else
		{
			cout << *fdizi2;//adreste bulunan veriyi yazdýran kod
		}

		fdizi2 += 1;//dizinin adreslerini bulmamýzý saðlayan kod
	}
	cout << "\n";
}
double alan(struct dikdörtgen d)
{
	return d.genis*d.yüksek;//bize gereken en ve boylarýný çarpýp geri döndürerek alaný hesaplama
}
bool nokta(dikdörtgen d1, double bx, double by)
{
	if (d1.x <= bx && bx <= d1.x + d1.yüksek && d1.y <= by && by <= d1.y + d1.genis)//burda arasýnda deðilmi diye kontrolü
		return 1;
	return 0;//else ye gerek yok çünkü üstteki koþul doðru ise direk 1 verip çýkar deðilse 0
}