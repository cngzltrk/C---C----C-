/***************************************************************
**								SAKARYA �N�VERS�TES�
**						B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**							B�LG�SAYAR M�HEND�SL��� B�L�M�
**								PROGRAMLAMA G�R�� DERS�
**								  2015-2016 G�Z D�NEM�
**
**						�DEV NUMARASI........:	�DEV 3-4
**						��RENC� ADI..........:	CENG�Z ALT�RK
**						��RENC� NUMARASI.....:	G140910048
**						DERS�N ALINDI�I GRUP.:  2.��RET�M B
******************************************************************/
#include<iostream>
#include<locale>//T�rk�e karakter i�in
using namespace std;
void degistir(char*);//bu fonksiyon 3 se�enek i�in fonksiyon deklerasyonu
void degistir(char*, char*);//bu fonksiyon 4 se�enek i�in ve ayn� fonksiyonu kullanarak a��r� y�kleme yapt�m
int ozyinemeli(int);//bu fonksiyon 1. se�enek i�in fonksiyon deklerasyonu
struct dikd�rtgen{// yap�m�z
	double x;
	double y;
	double y�ksek;
	double genis;
};
bool nokta(struct dikd�rtgen, double, double);//nokta i�in fonksiyon deklerasyonu
double alan(struct dikd�rtgen);//dikd�rtgenin alan� i�in fonksiyon deklerasyonu
int main()
{
	setlocale(LC_ALL, "Turkish");//T�rk�e karakter i�in
	int secenek,n;
	do//bu d�ng� 5 e basmadan  her seferinde d�nd�rmemizi sa�lar
	{	
		cout << "\n 1) �zyinelemeli Fonksiyon\n";
		cout << " 2) Dikd�rtgen Yap�s�\n";
		cout << " 3) B�y�k-K���k Harf de�i�imi\n";
		cout << " 4) �ki karakter dizisinin yer de�i�imi\n";
		cout << " 5) Programdan ��k��\n";
		cout << " \n��lem se�iniz...:";
		cin >> secenek;
		switch (secenek)
		{
		case 1:
			do//bu d�ng� pozitif girilmedi�inde d�nd�rmemizi sa�lar
			{
				cout << "n de�erini giriniz...:";
				cin >> n;
				if (n >= 0)//e�er say� pozitif ise i�leme ba�lar
				{
					cout << "�zyinemeli F(" << n << ")...:" << ozyinemeli(n) << endl;// burada fonksiyona g�nderip orda i�lem yapt�r�yoruz
					
				}
				else
				{
					cout << "pozitif de�er giriniz\n";
				}
			} while (n < 0);
			break;
		case 2:
			double bx, by;//bunlar verilen noktan�n dikd�rtgen i�indemi d���ndam� diye koordinatlar�
			dikd�rtgen d1;
			cout << "Sol alt k��e koordinatlar�n� giriniz (x,y)...:\n";
			cin >> d1.x >> d1.y;//yap�m�zda bulunan x ve y ba�lang�� noktalar�
			cout << "y�kseklik de�erini giriniz...:";
			cin >> d1.y�ksek;
			cout << "geni�lik de�erini giriniz...:";
			cin >> d1.genis;
			cout << "Nokta koordinatlar�n� giriniz (x,y)...:\n";
			cin >> bx >> by;//noktan�n koordinatlar�

			cout << "alan...:" << alan(d1) << endl;//fonksiyona g�nderip orda i�lemleri yapt�r�yoruz
			cout << "Belirti�iniz nokta i�inde mi ?...:" << nokta(d1, bx, by) << endl;//fonksiyona g�nderip orda i�lemleri yapt�r�yoruz
			break;
		case 3:
			char dizi[20];//dizimiz 
			cout << "Kelime giriniz....:";
			cin >> dizi;
			degistir(&dizi[0]);//fonksiyona g�ndererek orda i�lem yapt�r�yoruz
		
			
			break;
		case 4:

			char dizi1[20], dizi2[20];//dizilerimiz
			cout << "ilk dizimizi giriniz....:";
			cin >> dizi1;//1 . dizimize veri yazd�ran
			cout << "�kinci dizimizi giriniz....:";
			cin >> dizi2;//2 . dizimize veri yazd�ran
			degistir(&dizi1[0], &dizi2[0]);//fonksiyona g�nderek orda i�lem yapt�r�yoruz
			break;
		case 5:	//program� kapatm�z� sa�layan se�enek
			break;
		default:// se�enekler d���nda se�im yap�ld���nda 
			cout << "\n Hatal� i�lem\n";
			break;
		}
	} while (secenek != 5);
	return 0;
}
int ozyinemeli(int sayi)// �zyeinemeli yapt�m
{
	if (sayi == 0) //burda verilen denklemde f(0) ise 1 d�nd�rmesi i�in
		return 1;
	else if (sayi == 1) //burda verilen denklemde f(1) ise 2 d�nd�rmesi i�in
		return 2;
	else
	{
		return 2*(ozyinemeli(sayi - 1) - (sayi - 1)*ozyinemeli(sayi - 2));//denklemi 2 parantezine alarak yapt�m burda  n say�s� e�er 1 den b�y�kse verilen denklemde f(1) ve f(0) lara fonksiyonu �a��rarak d�nd�rme yapmas� i�in 
	}
}
void degistir(char* fdizi)
{
	int ks = 0;//ks karakter say�s�
	cout << "\n Kelimenin �ncesi....:";
	for (int i = 0; 1; i++)//bu d�ng� hem karakter say�s�n� saymam�z� hemde dizimizi yazm�z� sa�lar
	{
		if (*fdizi == '\0')//e�erki dizinin sonu geldi�inde for d�ng�s�nden ��kmam�z� sa�lamas� i�in gereken ko�ul
		{
			break;
		}
		else
		{
			ks += 1;
		}
		cout << *fdizi;//burda adreste bulunan veriyi yazd�rmam�z� sa�lar

		fdizi += 1;//bu dizimizin adreslerini bulabilmemiz i�in adresi 1 bayt olarak art�rmam�z� sa�lar
	}
	cout << "\n Kelimenin sonras�.....:";
	fdizi -= ks;//burda dizinin son adresinden karakter say�s�n� ��kararak ilk adresine bulmam�z� sa�l�yor
	for (int i = 0; i < ks; i++)//bu d�ng� karakterleri de�i�tirmemizi sa�lar 
	{//asc�� taplosunda k���k harflar b�y�k harflerden sonra geldi�ini g�steriyor ve her b�y�k k���k harf aras�nda 32 say�s� kadar fark var 
		if (*fdizi > 'Z')//burda e�er karakter k���kse b�y�k yapm�z�
		{
			*fdizi -= 32;//burda adresteki veriyide�i�tiren kod;
		}
		else//de�ilse b�y�kse yani harf k���k yapm�m�z� sa�lar
		{
			*fdizi += 32;//asc� taplosunda A=65 a=97 de�erlerini g�steriyor farklar�ndan yararlanarak 32
		}
		cout << *fdizi;//adresteki veriyi yazd�ran
		fdizi += 1;//dizinin adreslerini bulmam�z� sa�layan kod
	}
	cout << endl;
}
void degistir(char* fdizi1, char *fdizi2)
{
	char *ftemp;//de�i�tirmemizi sa�lamas� ge�ici adres
	int ks1 = 0, ks2 = 0;//dizilerimizin karakter say�s� 1.dizi ii�in ks1,2.dizimiz i�in ks2
	cout << "\n �lk dizinin �ncesi....:";
	for (int i = 0; 1; i++)////bu d�ng� hem karakter say�s�n� saymam�z� hemde dizimizi yazmam�z� sa�lar
	{
		if (*fdizi1 == '\0')//e�erki dizinin sonu geldi�inde for d�ng�s�nden ��kmam�z� sa�lamas� i�in gereken ko�ul
		{
			break;
		}
		else
		{
			ks1 += 1;
		}
		cout << *fdizi1;//burda adreste bulunan veriyi yazd�rmam�z� sa�lar
		fdizi1 += 1;//dizinin adreslerini bulmam�z� sa�layan kod
	}
	cout << "\n �kinci dizinin �ncesi....:";
	for (int i = 0; 1; i++)//bu d�ng� hem karakter say�s�n� saymam�z� hemde dizimizi yazmam�z� sa�lar
	{
		if (*fdizi2 == '\0')//e�erki dizinin sonu geldi�inde for d�ng�s�nden ��kmam�z� sa�lamas� i�in gereken ko�ul
		{
			break;
		}
		else
		{
			ks2 += 1;
		}
		cout << *fdizi2;//burda adreste bulunan veriyi yazd�rmam�z� sa�lar
		fdizi2 += 1;//dizinin adreslerini bulmam�z� sa�layan kod
	}
	cout << "\n";
	fdizi1 -= ks1;//burda dizinin son adresinden karakter say�s�n� ��kararak ilk adresine bulmam�z� sa�l�yor 
	fdizi2 -= ks2;//burda dizinin son adresinden karakter say�s�n� ��kararak ilk adresine bulmam�z� sa�l�yor
	ftemp = fdizi1;//dizi 1 de bulunan adresi ge�iciye atarak
	fdizi1 = fdizi2;//dizi 2 de bulunan adresi dizi 1e atarak
	fdizi2 = ftemp;//ge�icide de bulunan adresi dizi 2 atarak dizilerimizin adreslerini de�i�tirdik
	cout << "\n �lk dizinin sonras�.....:";
	for (int i = 0; 1; i++)//bu d�ng�  dizimizi yazmam�z� sa�lar
	{
		if (*fdizi1 == '\0')//e�erki dizinin sonu geldi�inde for d�ng�s�nden ��kmam�z� sa�lamas� i�in gereken ko�ul
		{
			break;
		}
		else
		{
			cout << *fdizi1;
		}

		fdizi1 += 1;//dizinin adreslerini bulmam�z� sa�layan kod
	}
	cout << "\n �kinci dizinin sonras�.....:";
	for (int i = 0; 1; i++)//bu d�ng�  dizimizi yazmam�z� sa�lar
	{
		if (*fdizi2 == '\0')//e�erki dizinin sonu geldi�inde for d�ng�s�nden ��kmam�z� sa�lamas� i�in gereken ko�ul
		{
			break;
		}
		else
		{
			cout << *fdizi2;//adreste bulunan veriyi yazd�ran kod
		}

		fdizi2 += 1;//dizinin adreslerini bulmam�z� sa�layan kod
	}
	cout << "\n";
}
double alan(struct dikd�rtgen d)
{
	return d.genis*d.y�ksek;//bize gereken en ve boylar�n� �arp�p geri d�nd�rerek alan� hesaplama
}
bool nokta(dikd�rtgen d1, double bx, double by)
{
	if (d1.x <= bx && bx <= d1.x + d1.y�ksek && d1.y <= by && by <= d1.y + d1.genis)//burda aras�nda de�ilmi diye kontrol�
		return 1;
	return 0;//else ye gerek yok ��nk� �stteki ko�ul do�ru ise direk 1 verip ��kar de�ilse 0
}