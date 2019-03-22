/***************************************************************
**								SAKARYA �N�VERS�TES�
**						B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**							B�LG�SAYAR M�HEND�SL��� B�L�M�

**							CENG�Z ALT�RK

******************************************************************/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<locale>
using namespace std;
struct hasta{
	string tc;
	string ad;
	string soyad;
	string kay�tno;
	string tel;
	int yas;

};// hsata yap�m�z
struct muayene{
	string tc;
	string tarih;
	string saat;
};//randevu yap�m�z
struct muayenekay�t{
	string tc;
	string doktor;
	string teshis;
	string ilac;
	string tahlil;
	double ucret;
};//muayene yap�m�z
void hastakay�t(struct hasta);//Fonksiyon deklerasyonu
void hastad�zelt(struct hasta);//Fonksiyon deklerasyonu
void hastasil(struct hasta, struct muayene, struct muayenekay�t);//Fonksiyon deklerasyonu
void hastarandevu(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastarandevusilme(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastarandevud�zelt(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastasorgulama(struct hasta, struct muayene, struct muayenekay�t);//Fonksiyon deklerasyonu
void hastalistesi(struct hasta);//Fonksiyon deklerasyonu
void muayenekayd�(struct hasta, struct muayene, struct muayenekay�t);//Fonksiyon deklerasyonu
int main()
{
	
	setlocale(LC_ALL,"Turkish");//t�rk�e karakterler i�in
	int secim;
	hasta hastaa;
	muayene muayenee;
	muayenekay�t muayenekayd��;
	do{//men�n�n her i�lemden sonra kar��m�za gelmesi i�in d�ng�
		cout << "\n 1- Hasta kayd�\n";
		cout << " 2- Hasta kayd� d�zeltme\n";
		cout << " 3- Hasta silme\n";
		cout << " 4- Randevu alma\n";
		cout << " 5- Randevu silme\n";
		cout << " 6- Randevu g�ncelleme\n";
		cout << " 7- Hasta sorgulama\n";
		cout << " 8- Hasta listesi\n";
		cout << " 9- Hasta muayene kayd�\n";
		cout << " 0- Sistemi kapat\n";
		cout << " ��leminiz ...:";
		cin >> secim;
		switch (secim)//men� i�eri�inin i�lemleri i�in switch kod yard�m� ile yapt�m
		{
		case 1:			
			hastakay�t(hastaa);//fonksiyonumuzu �a��rd�k
			break;
		case 2:
			hastad�zelt(hastaa);//fonksiyonumuzu �a��rd�k
			break;
		case 3:
			hastasil(hastaa, muayenee,muayenekayd��);//fonksiyonumuzu �a��rd�k
			break;
		case 4:
			hastarandevu(hastaa, muayenee);//fonksiyonumuzu �a��rd�k
			break;
		case 5:
			hastarandevusilme(hastaa,muayenee);//fonksiyonumuzu �a��rd�k
			break;
		case 6:
			hastarandevud�zelt(hastaa, muayenee);//fonksiyonumuzu �a��rd�k
			break;
		case 7:
			hastasorgulama(hastaa, muayenee,muayenekayd��);//fonksiyonumuzu �a��rd�k
			break;
		case 8:
			hastalistesi(hastaa);//fonksiyonumuzu �a��rd�k
			break;
		case 9:
			muayenekayd�(hastaa,muayenee,muayenekayd��);//fonksiyonumuzu �a��rd�k
			break;
		case 0://i�lemden ��kmas� i�in
			break;
		default://men� d��� i�lem yap�ld���nda
			cout << " =HATALI ��LEM= \n";
			break;
		}
	} while (secim!=0);
	return 0;
}
void hastakay�t(hasta h1)
{
	char s;//birden fazla kay�t eklememiz i�in, se�im;
	ofstream dosya;//dosyam�z
	dosya.open("hasta.txt", ios::app);//dosyay� a�an kodumuz varsa �zerine ekleyen 
	dosya.setf(ios::left);//bu i�lem dosyam�zda yazd�rma i�leminde setw yapt���m�zda  sola yazd�rmam�z i�in
	do{//bud�ng� birden fazla kay�t eklememiz i�in
		cout << "\n  Hasta kayd�\n";
		cout << " TC NO ...:";
		cin >> h1.tc;
		cout << " ADI ...:";
		cin >> h1.ad;
		cout << " SOYADI ...:";
		cin >> h1.soyad;
		cout << " HASTA KAYIT NO ...:";
		cin >> h1.kay�tno;
		cout << " TELEFON ...:";
		cin >> h1.tel;
		cout << " YA�I ...:";
		cin >> h1.yas;
		dosya << setw(15) << h1.tc << setw(15) << h1.ad//dosyaya yazd�ran kodumuz
			<< setw(15) << h1.soyad
			<< setw(15) << h1.kay�tno
			<< setw(15) << h1.tel
			<< setw(15) << h1.yas << endl;
		cout << "\n ba�ka kay�t eklemek istermisiniz?(e/h) ..:";
		cin >> s;//se�im
	} while (s == 'e');
	dosya.close();//dosya i�lemi bittikten sonra kapatt�k
	cout << "\ndosyaya yaz�m tamamland�.\n";
}
void hastad�zelt(hasta h1)
{
	int kontrol = 1;//e�er i�lem yap�lmad���nda bize bilgilendirmesi i�in kontrol�m�z
	string tc;//aranan ki�iyi bulmam�z i�in girilen tc
	ofstream dosyadegis("temp.txt");//ge�ici dosyam�zdosyam�z
	ifstream dosyaoku("hasta.txt");//dosyam�z� okumam�z i�in a�an kod
	cout << "d�zeltimesini istenen ki�inin tcsi ...:";
	cin >> tc;//aranan ki�i
	dosyadegis.setf(ios::left);//metin dosyam�zda setw yapt���m�zda sola yaslamas� i�in
	while (!(dosyaoku.eof()))//dosyay� ba�tan sona kadar okumam�z� sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//dosyam�zdan verileri �eken kodumuz
		if (tc == h1.tc)//aranan ki�i hasta dosyam�zda bulunanlardan biri ile e�le�irse i�lem ba�lar
		{
			if (!(dosyaoku.eof()))//bu i�lem sonda 2 kez yazd�rmas� i�in
			{
				cout << "\n=HASTA KAYIT D�ZELTME=\n";
				cout << " TC NO ...:";
				cin >> h1.tc;
				cout << " ADI ...:";
				cin >> h1.ad;
				cout << " SOYADI ...:";
				cin >> h1.soyad;
				cout << " HASTA KAYIT NO ...:";
				cin >> h1.kay�tno;
				cout << " TELEFON ...:";
				cin >> h1.tel;
				cout << " YA�I ...:";
				cin >> h1.yas;
				kontrol = 0;//e�er i�lem yap�lmad���nda bize bilgidirmesi i�in kontrol�m�z
				dosyadegis << setw(15) << h1.tc << setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kay�tno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
				cout << "\n��LEM TAMAMLANDI\n";
				
			}
		}
		else//aranan ki�i de�ilse direk yazd�rmas� i�in
		{
			if (!(dosyaoku.eof()))
			{
				dosyadegis << setw(15) << h1.tc//ge�ici dosyam�za yazd�ran kodumuz
					<< setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kay�tno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
			}
		}
		
	}
	if (kontrol)//i�lem yap�lmad���n uyaran kodumuz
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosyaoku.close();//dosyam�z� kapatma kodumuz
	dosyadegis.close();//dosyam�z� kapatma kodumuz
	remove("hasta.txt");//silen kodumuz
	rename("temp.txt", "hasta.txt");//isim de�i�imi
}
void hastarandevu(hasta h1, muayene m1)
{
	int kontrol = 1;//e�er i�lem yap�lmad���nda bize bilgilendirmesi i�in kontrol�m�z
	char s;//randevu i�in uyar� i�in se�imiziz
	string TC;//aranan ki�iyi bulmam�z i�in girilen tc
	ofstream dosya;//dosyam�z
	ifstream dosyaoku("hasta.txt");//dosya okuma kodumuz
	dosya.open("muayene.txt", ios::app);//dosyam�z� a��p ekleme yapmam�z� sa�layan kod
	dosya.setf(ios::left);//metin dosyam�zda setw yapt���m�zda sola yaslamas� i�in
	cout << "Tc no giriniz ... :";
	cin >> TC;
	while (!(dosyaoku.eof()))//dosyay� ba�tan sona kadar okumam�z� sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//dosyam�zdan veri �eken kodumuz

		if (TC == h1.tc)//aranan ki�i dosyadaki veri ile ayn� ise i�lem ba�lar
		{
			if (!(dosyaoku.eof()))//iki kez okumamas� i�in
			{
				cout << "\n=HASTA B�LG�LER�=\n";//alta bulunan lar dosyam�zdan verileri bize g�steren kodlar�m�z
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kay�tno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YA�I ...:";
				cout << h1.yas << endl;
				kontrol = 0;//uyar� vermesi i�in
				cout << "Randevu almak istermisiniz(e/h) ...:";
				cin >> s;//bu se�im randevu i�in soran kodumuz
				if (s == 'e')
				{
					
					cout << "\n=RANDEVU KAYIT=\n";
					cout << " tarih ...:";
					cin >> m1.tarih;
					cout << " Saat ...:";
					cin >> m1.saat;
					m1.tc = h1.tc;//bu kodumuz bidaha tc girmemiz i�in yazd�ran kodumuz
					dosya << setw(15) << m1.tc << setw(15) << m1.tarih//dosyam�za yazd�ran kodumuz
						<< setw(15) << m1.saat << endl;
				}
			}
		}
	}
	dosya.close();
	dosyaoku.close();
	if (kontrol)//i�lem yapmad���nda uyaran kodumuz
	{
		cout << "\nhasta kayd� bulunamad� \n";
		cout << "Kay�t yapmak istermisiniz(e/h) ...:";
		cin >> s;//se�imimiz
		if (s == 'e')//kay�t yapak isteyenlere kayt ekleme y�ndirme kodumuz
		{
			hastakay�t(h1);
			cout << "Randevu almak istermisiniz(e/h) ...:";
			cin >> s;//se�imimiz
			if (s == 'e')//randevu almak isteyenlere y�nlendirme kodumuz
			{	
			hastarandevu(h1, m1);
			}
		}
	}


}
void hastasil(hasta h1,muayene m1,muayenekay�t k1)
{
	int kontrol = 1;//i�lem yap�l�p yap�lmad���n� uyarmas� i�in ko�ulumuz
	string tc;//aranan ki�i
	ofstream dosyadegis("temp.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	ofstream dosyadegis2("temp2.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	ofstream dosyadegis3("temp3.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	ifstream dosyaoku("hasta.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	ifstream dosyaoku2("muayene.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	ifstream dosyaoku3("muayenekayd�.txt");//t�m dosyalarda i�lem yap�lca�� i�in hepsi i�in ge�ici dosyam�z
	cout << "Silinmesi istenen ki�inin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//dosyam�za metin dosyam�za setw i�in sola yaslay�p yazmas� i�in
	dosyadegis2.setf(ios::left);//dosyam�za metin dosyam�za setw i�in sola yaslay�p yazmas� i�in
	dosyadegis3.setf(ios::left);//dosyam�za metin dosyam�za setw i�in sola yaslay�p yazmas� i�in
	while (!(dosyaoku.eof()) || !(dosyaoku2.eof()) || !(dosyaoku2.eof()))//dosyalar�m�z� okuyan d�ng�m�z
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//verileri �eken kodumuz
		dosyaoku2 >> m1.tc>>m1.tarih>>m1.saat ;//verileri �eken kodumuz
		dosyaoku3 >> k1.tc >> k1.doktor >> k1.teshis >> k1.ilac >> k1.tahlil >> k1.ucret;//verileri �eken kodumuz
		if (tc == h1.tc )//aran ki�i e�lenirse i�leme ba�lar bu hasta dosyam�za silinmesi i�in
		{
			if (!(dosyaoku.eof()))//ikikez okumams� i�in
			{
				cout << "\n=HASTA B�LG�LER� S�L�ND�=\n";
				kontrol = 0;//i�lem yap�lmad���nda uyar� vermesi i�in
			}
		}
		else//aranan ki�i de�ilse aynen yazar
		{
			if (!(dosyaoku.eof()))//ikikez yazmams� i�in i�in
			{
				dosyadegis << setw(15) << h1.tc//dosyam�za yazd�ran kodumuz
					<< setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kay�tno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
			}
		}
		if (tc == m1.tc)//aran ki�i e�lenirse i�leme ba�lar bu randevu dosyam�zda silinmesi i�in
		{
			if (!(dosyaoku2.eof()))//ikikez okumams� i�in
			{
				cout << "\n=HASTA RANDEVULARI S�L�ND�=\n";
			}
		}
		else//aranan ki�i de�ilse aynen yazar
		{
			if (!(dosyaoku2.eof()))//ikikez okumams� i�in
			{
				dosyadegis2 << setw(15) << m1.tc//dosyam�za yazd�ran kodumuz
					<< setw(15) << m1.tarih
					<< setw(15) << m1.saat << endl;
			}
		}
		if (tc == k1.tc)//aran ki�i e�lenirse i�leme ba�lar bu muayene dosyam�zda silinmesi i�in
		{
			if (!(dosyaoku3.eof()))//ikikez okumams� i�in
			{
				cout << "\n=HASTA MUAYENE KAYITLARI S�L�ND�=\n";
				kontrol = 0;
			}
		}
		else//aranan ki�i de�ilse aynen yazar
		{
			if (!(dosyaoku3.eof()))//ikikez okumams� i�in
			{
				dosyadegis3 << setw(15) << k1.tc//dosyam�za yazd�ran kodumuz
					<< setw(15) << k1.doktor
					<< setw(15) << k1.teshis
					<< setw(15) << k1.ilac
					<< setw(15) << k1.tahlil
					<< setw(15) << k1.ucret << endl;
			}
		}
	}
	if (kontrol)//i�em yap�lmad���nda uyar� vermesi i�in
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosyaoku.close();//dosyalar�m�z� kapat�p
	dosyadegis.close();
	dosyaoku2.close();
	dosyadegis2.close();
	dosyaoku3.close();
	dosyadegis3.close();
	remove("hasta.txt");//dosylar�m�z�n eskisini silip ge�ici dosyalar�m�z� isimlerini de�i�tiriyoruz
	rename("temp.txt", "hasta.txt");
	remove("muayene.txt" );
	rename("temp2.txt", "muayene.txt");
	remove("muayenekayd�.txt");
	rename("temp3.txt", "muayenekayd�.txt");
}
void hastarandevusilme(hasta h1, muayene m1)
{
	int kontrol = 1;////e�er i�lem yap�lmad���nda bize bilgilendirmesi i�in kontrol�m�z
	string tc;//aranan ki�i
	ofstream dosyadegis("temp.txt");//ge�ici dosym�z
	ifstream dosyaoku("hasta.txt");//hasta bilgilerini g�stermesi i�in
	ifstream dosyaoku2("muayene.txt");//dosyam�zda bulunan verileri okumam�z i�in kodumuz
	cout << "Randevusu silinmesi istenen ki�inin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//sola yaslamas� i�in kodmuz
	while (!(dosyaoku.eof()) || !(dosyaoku2.eof()))//dosyada bulunan verileri okumuzu sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//verileri �ekme kodumuz
		dosyaoku2 >> m1.tc>>m1.tarih>>m1.saat;//verileri �ekme kodumuz
		if (tc == m1.tc)
		{
			if (!(dosyaoku2.eof()))
			{
				cout << "\n=HASTA B�LG�LER�=\n";
				cout << " TC NO ...:";
				cout << h1.tc << endl;//hasta bilgilerini �eken kodumuz
				cout << " ADI ...:";
				cout << h1.ad << endl;//hasta bilgilerini �eken kodumuz
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;//hasta bilgilerini �eken kodumuz
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kay�tno << endl;//hasta bilgilerini �eken kodumuz
				cout << " TELEFON ...:";//hasta bilgilerini �eken kodumuz
				cout << h1.tel << endl;//hasta bilgilerini �eken kodumuz
				cout << " YA�I ...:";//hasta bilgilerini �eken kodumuz
				cout << h1.yas << endl;
				kontrol = 0;//i�lem yap�ld��� zaman uyar� g�stermemesi i�in
				cout << "\n =RANDEVU S�L�ND�=\n";

			}
		}
		else//arana ki�i de�ilse ayn� �ekilde yazd�rmas�n� sa�layan kodumuz
		{
			if (!(dosyaoku2.eof()))//ikikez yazd�rmamas� i�in
			{
				dosyadegis << setw(15) << m1.tc
					<< setw(15) << m1.tarih
					<< setw(15) << m1.saat << endl;
			}
		}

	}
	if (kontrol)//i�lem yap�lmad�m� uyar� g�stermesi i�in
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosyaoku.close();//dosyalar�m�z� kapatan kodumuz
	dosyadegis.close();//dosyalar�m�z� kapatan kodumuz
	dosyaoku2.close();//dosyalar�m�z� kapatan kodumuz
	remove("muayene.txt");//dosyam�z� silen 
	rename("temp.txt", "muayene.txt");//dosya ismini de�i�tiren kodumuz

}
void hastarandevud�zelt(hasta h1, muayene m1)
{
	int kontrol = 0;//e�er i�lem yap�lmad���nda bize bilgilendirmesi i�in kontrol�m�z
	string tc;//aranan ki�i
	ofstream dosyadegis("temp.txt");//ge�ici dosym�z
	ifstream dosyaoku("hasta.txt");//hasta bilgilerini g�stermesi i�in
	ifstream dosyaoku2("muayene.txt");//dosyam�zda bulunan verileri okumam�z i�in kodumuz
	cout << "Randevusu g�ncellenmesi istenen ki�inin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//sola yaslamas� i�in kodmuz
	while (!(dosyaoku.eof()))//dosyam�z�da bulunan verileri okumuzu sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//dosyam�zdan verimizi �eken kodumuz
		if (tc == h1.tc)//aranan ki�i dosyam�zda bulunan veri ile e�le�irse i�leme ba�lar
		{
			if (!(dosyaoku.eof()))
			{
				cout << "\n=HASTA B�LG�LER�=\n";//hasta bilgilerini cout ekran�na yazd�ran koodlar�m�z
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kay�tno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YA�I ...:";
				cout << h1.yas << endl;
				kontrol = 1;//e�erki i�lem yapt���nda di�er i�lemleri sa�lamas� i�in
			}
		}	
	}
	if (kontrol)//burda e�er ki�i bulunmazsa randevu lara bakmamas�na gerek olmad��� i�in yapt���m ko�ul
	{
		while (!(dosyaoku2.eof()))//dosyam�z� okumam�z� sa�layan d�ng�
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//verileri �eken kodumuz
			if (tc == m1.tc)//aranan ki�i 
			{
				if (!(dosyaoku2.eof()))//ikikez okuyup yazd�rmamas� i�in
				{

					cout << "\n =RANDEVU G�NCELLEME=\n";//yeni veriler girilip 
					cout << " tarih ...:";
					cin >> m1.tarih;
					cout << " Saat ...:";
					cin >> m1.saat;
					dosyadegis << setw(15) << m1.tc//dosyam�za yazd�ran kodumuz
						<< setw(15) << m1.tarih
						<< setw(15) << m1.saat << endl;

				}
			}
			else//aranan ki�i de�ilse ayn� �ekilde yazd�ran kodumuz
			{
				if (!(dosyaoku2.eof()))//ikikez yazd�rmams� i�in
				{
					dosyadegis << setw(15) << m1.tc
						<< setw(15) << m1.tarih
						<< setw(15) << m1.saat << endl;
				}
			}
		}
	}
	if (kontrol-1)//e�er arananki�i yoksa uyar� vermesi i�in
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosyaoku.close();//dosyalarm�z� kapatan kodumuz
	dosyadegis.close();//dosyalarm�z� kapatan kodumuz
	dosyaoku2.close();//dosyalarm�z� kapatan kodumuz
	remove("muayene.txt");//dosyay� silen kod
	rename("temp.txt", "muayene.txt");//dosyan�n ad�n� de�i�tiren kodumuz
}
void hastasorgulama(hasta h1, muayene m1,muayenekay�t k1)
{
	int kontrol = 0;//e�er i�lem yap�lmad���nda bize bilgilendirmesi i�in kontrol�m�z
	string tc;//aranan ki�i
	ifstream dosyaoku("hasta.txt");//verileri okumam�z� sa�layan kod
	ifstream dosyaoku2("muayene.txt");//verileri okumam�z� sa�layan kod
	ifstream dosyaoku3("muayenekayd�.txt");//verileri okumam�z� sa�layan kod
	cout << "Hasta ge�imi�i istenen ki�inin tcsi ...:";
	cin >> tc;
	while (!(dosyaoku.eof()))//ilk olarak hasta bilgilerini �eken kodumuzun d�ng�s�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//dosyam�zdan verileri �eken kodumuz
		if (tc == h1.tc)//aran ki�i ise i�lme ba�lar
		{
			if (!(dosyaoku.eof()))//ikikez okumamas� i�in
			{
				cout << "\n=HASTA B�LG�LER�=\n";//biligileri cout bilgilerine yazd�ran kodlar�m�z
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kay�tno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YA�I ...:";
				cout << h1.yas << endl;
				kontrol = 1;//e�erki i�lem yapt���nda di�er i�lemleri sa�lamas� i�in
			}
		}
	}
	if (kontrol)//burda e�er ki�i bulunmazsa randevu lara bakmamas�na gerek olmad��� i�in yapt���m ko�ul
	{
		while (!(dosyaoku2.eof()))//randevu dosyam�zda bulunan randevu ge�mi�ini g�sterne kodumuz
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//dosyam�zdan verileri �eken kodumuz
			if (tc == m1.tc) //aran ki�i ise i�lme ba�lar
			{
				if (!(dosyaoku2.eof()))//ikikez okumamas� i�in
				{
					cout << "\n =Randevu ge�imi�i=\n";//biligileri cout bilgilerine yazd�ran kodlar�m�z
					cout << " tarih ...:";
					cout << m1.tarih<<endl;
					cout << " Saat ...:";
					cout << m1.saat << endl;
				}
			}
		}
		while (!(dosyaoku3.eof()))//muayene dosyam�zda bulunan muayene ge�mi�ini g�sterne kodumuz
		{
			dosyaoku3 >> k1.tc >> k1.doktor >> k1.teshis >> k1.ilac >> k1.tahlil >> k1.ucret;//dosyam�zdan verileri �eken kodumuz
			if (tc == k1.tc)//aran ki�i ise i�lme ba�lar
			{
				if (!(dosyaoku3.eof()))//ikikez okumamas� i�in
				{
					cout << "\n MUANE ge�mi�i\n";//biligileri cout bilgilerine yazd�ran kodlar�m�z
					cout << " doktor ...:";
					cout << k1.doktor << endl;
					cout << " Te�his ...:";
					cout << k1.teshis << endl;
					cout << " ila� ...:";
					cout << k1.ilac << endl;
					cout << " Tahliller ...:";
					cout << k1.tahlil << endl;
					cout << " �cret ...:";
					cout << k1.ucret << endl;


				}
			}
		}
	}
	if (kontrol - 1)//e�er arananki�i yoksa uyar� vermesi i�in
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosyaoku.close();//dosyam�z� kapatan kodumuz
	dosyaoku2.close();//dosyam�z� kapatan kodumuz
	dosyaoku3.close();//dosyam�z� kapatan kodumuz
}
void hastalistesi(hasta h1)
{
	ifstream dosyaoku("hasta.txt");//dosyam�z� okuyan kodumuz
	cout << "\n=HASTA B�LG�LER�=\n";
	cout << setw(12) << "TC" << setw(12) << "ADI" << setw(12) << "SOYADI" << setw(15) << "KAYIT NO" << setw(12) << "TELEFON" << setw(6) << "YA�I" << endl;//ba�l�k i�in tablo ba�l�klar�
	while (!(dosyaoku.eof()))//dosyam�z� okumam�z� sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//verileri �eken kodumuz
			if (!(dosyaoku.eof()))//ikikez yazd�rmams� i�in
			{
				
				cout << setw(12) << h1.tc;//verileri yazd�ran kodumuz
				cout << setw(12) << h1.ad;
				cout << setw(12) << h1.soyad;
				cout << setw(15) << h1.kay�tno;
				cout << setw(12) << h1.tel;
				cout << setw(6) << h1.yas << endl;
			}
	}
	dosyaoku.close();//dosyam�z� kaparan kodumuz
}
void muayenekayd�( hasta h1,  muayene m1,muayenekay�t k1)
{
	int kontrol = 0;//i�lem yap�l�p yap�mad�m� bilgilendirmesi i�in
	string tc;//i�lem yap�lmas� istenen ki�inin tcsi
	ofstream dosya("muayenekayd�.txt",ios::app);//dosyam�z� veri yazd�ramz� i�in a�an kodumuuz
	ifstream dosyaoku("hasta.txt");////dosyam�z� okuyan kodumuz
	ifstream dosyaoku2("muayene.txt");//dosyam�z� okuyan kodumuz
	cout << "Muayene kayd�  girilmesi istenen ki�inin tcsi ...:";
	cin >> tc;
	dosya.setf(ios::left);//sola yaslamas� i�in
	while (!(dosyaoku.eof()))////dosyam�z� okumam�z� sa�layan d�ng�
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kay�tno >> h1.tel >> h1.yas;//verileri �eken kodumuz
		if (tc == h1.tc)////aran ki�i ile e�le�irse i�lme ba�lar
		{
			if (!(dosyaoku.eof()))//ikikez okumamas� i�in
			{
				cout << "\n=HASTA B�LG�LER�=\n";//biligileri cout bilgilerine yazd�ran kodlar�m�z
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kay�tno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YA�I ...:";
				cout << h1.yas << endl;
				kontrol = 1;//e�erki i�lem yapt���nda di�er i�lemleri sa�lamas� i�in
			}
		}
	}
	if (kontrol)//burda e�er ki�i bulunmazsa randevu lara bakmamas�na gerek olmad��� i�in yapt���m ko�ul
	{
		while (!(dosyaoku2.eof())) // dosyam�z� okumam�z� sa�layan d�ng�
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//verileri �eken kodumuz
			if (tc == m1.tc)///aran ki�i ile e�le�irse i�lme ba�lar
			{
				if (!(dosyaoku2.eof()))//ikikez okumamas� i�in
				{
					cout << "\n =Randevu ge�imi�i=\n";//biligileri cout bilgilerine yazd�ran kodlar�m�z
					cout << " tarih ...:";
					cout << m1.tarih << endl;
					cout << " Saat ...:";
					cout << m1.saat << endl;
					cout << "\n  Hasta muayene kayd�\n";//muayene kayd� i�in girilen verilerimiz
					cout << " doktor ...:";
					cin >> k1.doktor;
					cout << " Te�his ...:";
					cin >> k1.teshis;
					cout << " ila� ...:";
					cin >> k1.ilac;
					cout << " Tahliller ...:";
					cin >> k1.tahlil;
					cout << " �cret ...:";
					cin >> k1.ucret;
					k1.tc = tc;//muayene kayd�nda bir kez daha tc girilmemesi i�in 
					dosya << setw(15) << k1.tc << setw(15) << k1.doktor//dosyam�za yazd�ran kodumuz
					<< setw(15) << k1.teshis
					<< setw(15) << k1.ilac
					<< setw(15)<<k1.tahlil 
					<< setw(15) << k1.ucret<< endl;
				}
			}
		}		
	}
	if (kontrol - 1)//e�er arananki�i yoksa uyar� vermesi i�in
	{
		cout << "\nkay�t bulunamad� \n";
	}
	dosya.close();//dosyam�z� kapatan kodumuz
	dosyaoku.close();//dosyam�z� kapatan kodumuz
	dosyaoku2.close();//dosyam�z� kapatan kodumuz
}
