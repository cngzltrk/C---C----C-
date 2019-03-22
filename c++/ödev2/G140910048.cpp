/***************************************************************
**								SAKARYA �N�VERS�TES�
**						B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**							B�LG�SAYAR M�HEND�SL��� B�L�M�
**								PROGRAMLAMA G�R�� DERS�
**								  2015-2016 G�Z D�NEM�
**
**						�DEV NUMARASI........:	�DEV 2
**						��RENC� ADI..........:	CENG�Z ALT�RK
**						��RENC� NUMARASI.....:	G140910048
**						DERS�N ALINDI�I GRUP.:  2.��RET�M B
******************************************************************/
#include<iostream>
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Turkish");
	int d[101], sayi, secenek, mod;//d dizimiz
	for (int i = 0; i <= 100; i++)//bu d�ng� dizideki t�m elemanlara -1 de�eri atar
	{
		d[i] = -1;
	}
	do{//5 se�ene�i se�ilmeden durmadan tekrar etmesini sa�lamak i�in ba�lang�� d�ng�s�
		cout << "\n1- Eleman Ekle\n";
		cout << "2- Eleman sil\n";
		cout << "3- Eleman ara\n";
		cout << "4- Eleman listele\n";
		cout << "5- ��k��\n";
		cout << "Se�enek = ";
		cin >> secenek;
		switch (secenek)
		{
		case 1:
			do{// bu d�ng� pozitif girilmedi�inde yeniden d�nd�rmesi i�in
				cout << "eklenecek say� = ";
				cin >> sayi;
				if (sayi >= 0)//de�i�ken kontrol� pozitifse i�leme ba�lar
				{
					mod = sayi % 101;
					if (d[mod] == -1)//bu indeksin dolu olup olmad��� konrol�
					{
						d[mod] = sayi; cout << "say� ba�ar� ile eklenmi�tir.\n";
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
			do{// bu d�ng� pozitif girilmedi�inde yeniden d�nd�rmesi i�in
				cout << "silinecek say� = ";
				cin >> sayi;
				if (sayi >= 0)//de�i�ken kontrol� pozitifse i�leme ba�lar
				{
					int i;// i yi d��arda tan�mlamam�n sebebi e�erki  say�y� bulup sildi�inde sonradan say� bulunamad� yazd�rmamas� ko�ulunda kullana bilmek i�in
					for (i = 0; i <= 100; i++)
					{
						if (d[i] == sayi)//girilen say�n�n olup olmad��� kontrol�
						{
							d[i] = -1;
							cout << "say� ba�ar� ile silinmi�tir.\n";
							break;//bu break sadece for d�ng�s� d���na ��kar�r 
						}
					}
					if (i != 101)// for d�ng�s� say�y� bulup sildi�inde i 101 den k���k olur say� bulunamad� ��kt�s� vermemesi i�in d�ng� d���na ��kmam�z� sa�layan ko�ul
						break; // bu break bize bulundu�u do while d�ng�s�nden ��kmam�z� sa�lar
					cout << "say� bulunamad�.\n";

				}
				else
					cout << "pozitif say� gir.\n";
			} while (sayi < 0);
			break;
		case 3:
			do{// bu d�ng� pozitif girilmedi�inde yeniden d�nd�rmesi i�in
				cout << "say� = ";
				cin >> sayi;
				if (sayi >= 0)//de�i�ken kontrol� pozitifse i�leme ba�lar
				{
					int i;// i yi d��arda tan�mlamam�n sebebi e�erki  say�y� bulup ��kt� verdi�inde sonradan say� bulunamad� yazd�rmamas� ko�ulunda kullana bilmek i�in
					for (i = 0; i <= 100; i++)
					{
						if (d[i] == sayi)//girilen say�n�n olup olmad��� kontrol�
						{
							cout << "say� dizide var.\n";
							break;//bu break sadece for d�ng�s� d���na ��kar�r
						}
					}
					if (i != 101)// for d�ng�s� say�y� bulup ��kt� verdi�inde i 101 den k���k olur say� bulunamad� ��kt�s� vermemesi i�in d�ng� d���na ��kmam�z� sa�layan ko�ul
						break;// bu break bize bulundu�u do while d�ng�s�nden ��kmam�z� sa�lar
					cout << "say� bulunamad�.\n";
				}
				else
					cout << "pozitif say� gir.\n";
			} while (sayi < 0);
			break;
		case 4:
			cout << endl;
			for (int i = 0; i <= 100; i++)
			{
				if (d[i] != -1)//bu d�ng� girilen say�lar�n kontrol�
				{
					cout << "[" << i << "]" << "=" << d[i] << endl;

				}
			}
			break;
		case 5:
			cout << endl;
			break;
		default:
			cout << " hatal� se�enek\n";
			break;
		}

	} while (secenek != 5);

}