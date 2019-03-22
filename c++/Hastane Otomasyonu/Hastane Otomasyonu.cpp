/***************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**						BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**							BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ

**							CENGÝZ ALTÜRK

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
	string kayýtno;
	string tel;
	int yas;

};// hsata yapýmýz
struct muayene{
	string tc;
	string tarih;
	string saat;
};//randevu yapýmýz
struct muayenekayýt{
	string tc;
	string doktor;
	string teshis;
	string ilac;
	string tahlil;
	double ucret;
};//muayene yapýmýz
void hastakayýt(struct hasta);//Fonksiyon deklerasyonu
void hastadüzelt(struct hasta);//Fonksiyon deklerasyonu
void hastasil(struct hasta, struct muayene, struct muayenekayýt);//Fonksiyon deklerasyonu
void hastarandevu(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastarandevusilme(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastarandevudüzelt(struct hasta, struct muayene);//Fonksiyon deklerasyonu
void hastasorgulama(struct hasta, struct muayene, struct muayenekayýt);//Fonksiyon deklerasyonu
void hastalistesi(struct hasta);//Fonksiyon deklerasyonu
void muayenekaydý(struct hasta, struct muayene, struct muayenekayýt);//Fonksiyon deklerasyonu
int main()
{
	
	setlocale(LC_ALL,"Turkish");//türkçe karakterler için
	int secim;
	hasta hastaa;
	muayene muayenee;
	muayenekayýt muayenekaydýý;
	do{//menünün her iþlemden sonra karþýmýza gelmesi için döngü
		cout << "\n 1- Hasta kaydý\n";
		cout << " 2- Hasta kaydý düzeltme\n";
		cout << " 3- Hasta silme\n";
		cout << " 4- Randevu alma\n";
		cout << " 5- Randevu silme\n";
		cout << " 6- Randevu güncelleme\n";
		cout << " 7- Hasta sorgulama\n";
		cout << " 8- Hasta listesi\n";
		cout << " 9- Hasta muayene kaydý\n";
		cout << " 0- Sistemi kapat\n";
		cout << " Ýþleminiz ...:";
		cin >> secim;
		switch (secim)//menü içeriðinin iþlemleri için switch kod yardýmý ile yaptým
		{
		case 1:			
			hastakayýt(hastaa);//fonksiyonumuzu çaðýrdýk
			break;
		case 2:
			hastadüzelt(hastaa);//fonksiyonumuzu çaðýrdýk
			break;
		case 3:
			hastasil(hastaa, muayenee,muayenekaydýý);//fonksiyonumuzu çaðýrdýk
			break;
		case 4:
			hastarandevu(hastaa, muayenee);//fonksiyonumuzu çaðýrdýk
			break;
		case 5:
			hastarandevusilme(hastaa,muayenee);//fonksiyonumuzu çaðýrdýk
			break;
		case 6:
			hastarandevudüzelt(hastaa, muayenee);//fonksiyonumuzu çaðýrdýk
			break;
		case 7:
			hastasorgulama(hastaa, muayenee,muayenekaydýý);//fonksiyonumuzu çaðýrdýk
			break;
		case 8:
			hastalistesi(hastaa);//fonksiyonumuzu çaðýrdýk
			break;
		case 9:
			muayenekaydý(hastaa,muayenee,muayenekaydýý);//fonksiyonumuzu çaðýrdýk
			break;
		case 0://iþlemden çýkmasý için
			break;
		default://menü dýþý iþlem yapýldýðýnda
			cout << " =HATALI ÝÞLEM= \n";
			break;
		}
	} while (secim!=0);
	return 0;
}
void hastakayýt(hasta h1)
{
	char s;//birden fazla kayýt eklememiz için, seçim;
	ofstream dosya;//dosyamýz
	dosya.open("hasta.txt", ios::app);//dosyayý açan kodumuz varsa üzerine ekleyen 
	dosya.setf(ios::left);//bu iþlem dosyamýzda yazdýrma iþleminde setw yaptýðýmýzda  sola yazdýrmamýz için
	do{//budöngü birden fazla kayýt eklememiz için
		cout << "\n  Hasta kaydý\n";
		cout << " TC NO ...:";
		cin >> h1.tc;
		cout << " ADI ...:";
		cin >> h1.ad;
		cout << " SOYADI ...:";
		cin >> h1.soyad;
		cout << " HASTA KAYIT NO ...:";
		cin >> h1.kayýtno;
		cout << " TELEFON ...:";
		cin >> h1.tel;
		cout << " YAÞI ...:";
		cin >> h1.yas;
		dosya << setw(15) << h1.tc << setw(15) << h1.ad//dosyaya yazdýran kodumuz
			<< setw(15) << h1.soyad
			<< setw(15) << h1.kayýtno
			<< setw(15) << h1.tel
			<< setw(15) << h1.yas << endl;
		cout << "\n baþka kayýt eklemek istermisiniz?(e/h) ..:";
		cin >> s;//seçim
	} while (s == 'e');
	dosya.close();//dosya iþlemi bittikten sonra kapattýk
	cout << "\ndosyaya yazým tamamlandý.\n";
}
void hastadüzelt(hasta h1)
{
	int kontrol = 1;//eðer iþlem yapýlmadýðýnda bize bilgilendirmesi için kontrolümüz
	string tc;//aranan kiþiyi bulmamýz için girilen tc
	ofstream dosyadegis("temp.txt");//geçici dosyamýzdosyamýz
	ifstream dosyaoku("hasta.txt");//dosyamýzý okumamýz için açan kod
	cout << "düzeltimesini istenen kiþinin tcsi ...:";
	cin >> tc;//aranan kiþi
	dosyadegis.setf(ios::left);//metin dosyamýzda setw yaptýðýmýzda sola yaslamasý için
	while (!(dosyaoku.eof()))//dosyayý baþtan sona kadar okumamýzý saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//dosyamýzdan verileri çeken kodumuz
		if (tc == h1.tc)//aranan kiþi hasta dosyamýzda bulunanlardan biri ile eþleþirse iþlem baþlar
		{
			if (!(dosyaoku.eof()))//bu iþlem sonda 2 kez yazdýrmasý için
			{
				cout << "\n=HASTA KAYIT DÜZELTME=\n";
				cout << " TC NO ...:";
				cin >> h1.tc;
				cout << " ADI ...:";
				cin >> h1.ad;
				cout << " SOYADI ...:";
				cin >> h1.soyad;
				cout << " HASTA KAYIT NO ...:";
				cin >> h1.kayýtno;
				cout << " TELEFON ...:";
				cin >> h1.tel;
				cout << " YAÞI ...:";
				cin >> h1.yas;
				kontrol = 0;//eðer iþlem yapýlmadýðýnda bize bilgidirmesi için kontrolümüz
				dosyadegis << setw(15) << h1.tc << setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kayýtno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
				cout << "\nÝÞLEM TAMAMLANDI\n";
				
			}
		}
		else//aranan kiþi deðilse direk yazdýrmasý için
		{
			if (!(dosyaoku.eof()))
			{
				dosyadegis << setw(15) << h1.tc//geçici dosyamýza yazdýran kodumuz
					<< setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kayýtno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
			}
		}
		
	}
	if (kontrol)//iþlem yapýlmadýðýn uyaran kodumuz
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosyaoku.close();//dosyamýzý kapatma kodumuz
	dosyadegis.close();//dosyamýzý kapatma kodumuz
	remove("hasta.txt");//silen kodumuz
	rename("temp.txt", "hasta.txt");//isim deðiþimi
}
void hastarandevu(hasta h1, muayene m1)
{
	int kontrol = 1;//eðer iþlem yapýlmadýðýnda bize bilgilendirmesi için kontrolümüz
	char s;//randevu için uyarý için seçimiziz
	string TC;//aranan kiþiyi bulmamýz için girilen tc
	ofstream dosya;//dosyamýz
	ifstream dosyaoku("hasta.txt");//dosya okuma kodumuz
	dosya.open("muayene.txt", ios::app);//dosyamýzý açýp ekleme yapmamýzý saðlayan kod
	dosya.setf(ios::left);//metin dosyamýzda setw yaptýðýmýzda sola yaslamasý için
	cout << "Tc no giriniz ... :";
	cin >> TC;
	while (!(dosyaoku.eof()))//dosyayý baþtan sona kadar okumamýzý saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//dosyamýzdan veri çeken kodumuz

		if (TC == h1.tc)//aranan kiþi dosyadaki veri ile ayný ise iþlem baþlar
		{
			if (!(dosyaoku.eof()))//iki kez okumamasý için
			{
				cout << "\n=HASTA BÝLGÝLERÝ=\n";//alta bulunan lar dosyamýzdan verileri bize gösteren kodlarýmýz
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kayýtno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YAÞI ...:";
				cout << h1.yas << endl;
				kontrol = 0;//uyarý vermesi için
				cout << "Randevu almak istermisiniz(e/h) ...:";
				cin >> s;//bu seçim randevu için soran kodumuz
				if (s == 'e')
				{
					
					cout << "\n=RANDEVU KAYIT=\n";
					cout << " tarih ...:";
					cin >> m1.tarih;
					cout << " Saat ...:";
					cin >> m1.saat;
					m1.tc = h1.tc;//bu kodumuz bidaha tc girmemiz için yazdýran kodumuz
					dosya << setw(15) << m1.tc << setw(15) << m1.tarih//dosyamýza yazdýran kodumuz
						<< setw(15) << m1.saat << endl;
				}
			}
		}
	}
	dosya.close();
	dosyaoku.close();
	if (kontrol)//iþlem yapmadýðýnda uyaran kodumuz
	{
		cout << "\nhasta kaydý bulunamadý \n";
		cout << "Kayýt yapmak istermisiniz(e/h) ...:";
		cin >> s;//seçimimiz
		if (s == 'e')//kayýt yapak isteyenlere kayt ekleme yöndirme kodumuz
		{
			hastakayýt(h1);
			cout << "Randevu almak istermisiniz(e/h) ...:";
			cin >> s;//seçimimiz
			if (s == 'e')//randevu almak isteyenlere yönlendirme kodumuz
			{	
			hastarandevu(h1, m1);
			}
		}
	}


}
void hastasil(hasta h1,muayene m1,muayenekayýt k1)
{
	int kontrol = 1;//iþlem yapýlýp yapýlmadýðýný uyarmasý için koþulumuz
	string tc;//aranan kiþi
	ofstream dosyadegis("temp.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	ofstream dosyadegis2("temp2.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	ofstream dosyadegis3("temp3.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	ifstream dosyaoku("hasta.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	ifstream dosyaoku2("muayene.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	ifstream dosyaoku3("muayenekaydý.txt");//tüm dosyalarda iþlem yapýlcaðý için hepsi için geçici dosyamýz
	cout << "Silinmesi istenen kiþinin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//dosyamýza metin dosyamýza setw için sola yaslayýp yazmasý için
	dosyadegis2.setf(ios::left);//dosyamýza metin dosyamýza setw için sola yaslayýp yazmasý için
	dosyadegis3.setf(ios::left);//dosyamýza metin dosyamýza setw için sola yaslayýp yazmasý için
	while (!(dosyaoku.eof()) || !(dosyaoku2.eof()) || !(dosyaoku2.eof()))//dosyalarýmýzý okuyan döngümüz
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//verileri çeken kodumuz
		dosyaoku2 >> m1.tc>>m1.tarih>>m1.saat ;//verileri çeken kodumuz
		dosyaoku3 >> k1.tc >> k1.doktor >> k1.teshis >> k1.ilac >> k1.tahlil >> k1.ucret;//verileri çeken kodumuz
		if (tc == h1.tc )//aran kiþi eþlenirse iþleme baþlar bu hasta dosyamýza silinmesi için
		{
			if (!(dosyaoku.eof()))//ikikez okumamsý için
			{
				cout << "\n=HASTA BÝLGÝLERÝ SÝLÝNDÝ=\n";
				kontrol = 0;//iþlem yapýlmadýðýnda uyarý vermesi için
			}
		}
		else//aranan kiþi deðilse aynen yazar
		{
			if (!(dosyaoku.eof()))//ikikez yazmamsý için için
			{
				dosyadegis << setw(15) << h1.tc//dosyamýza yazdýran kodumuz
					<< setw(15) << h1.ad
					<< setw(15) << h1.soyad
					<< setw(15) << h1.kayýtno
					<< setw(15) << h1.tel
					<< setw(15) << h1.yas << endl;
			}
		}
		if (tc == m1.tc)//aran kiþi eþlenirse iþleme baþlar bu randevu dosyamýzda silinmesi için
		{
			if (!(dosyaoku2.eof()))//ikikez okumamsý için
			{
				cout << "\n=HASTA RANDEVULARI SÝLÝNDÝ=\n";
			}
		}
		else//aranan kiþi deðilse aynen yazar
		{
			if (!(dosyaoku2.eof()))//ikikez okumamsý için
			{
				dosyadegis2 << setw(15) << m1.tc//dosyamýza yazdýran kodumuz
					<< setw(15) << m1.tarih
					<< setw(15) << m1.saat << endl;
			}
		}
		if (tc == k1.tc)//aran kiþi eþlenirse iþleme baþlar bu muayene dosyamýzda silinmesi için
		{
			if (!(dosyaoku3.eof()))//ikikez okumamsý için
			{
				cout << "\n=HASTA MUAYENE KAYITLARI SÝLÝNDÝ=\n";
				kontrol = 0;
			}
		}
		else//aranan kiþi deðilse aynen yazar
		{
			if (!(dosyaoku3.eof()))//ikikez okumamsý için
			{
				dosyadegis3 << setw(15) << k1.tc//dosyamýza yazdýran kodumuz
					<< setw(15) << k1.doktor
					<< setw(15) << k1.teshis
					<< setw(15) << k1.ilac
					<< setw(15) << k1.tahlil
					<< setw(15) << k1.ucret << endl;
			}
		}
	}
	if (kontrol)//iþem yapýlmadýðýnda uyarý vermesi için
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosyaoku.close();//dosyalarýmýzý kapatýp
	dosyadegis.close();
	dosyaoku2.close();
	dosyadegis2.close();
	dosyaoku3.close();
	dosyadegis3.close();
	remove("hasta.txt");//dosylarýmýzýn eskisini silip geçici dosyalarýmýzý isimlerini deðiþtiriyoruz
	rename("temp.txt", "hasta.txt");
	remove("muayene.txt" );
	rename("temp2.txt", "muayene.txt");
	remove("muayenekaydý.txt");
	rename("temp3.txt", "muayenekaydý.txt");
}
void hastarandevusilme(hasta h1, muayene m1)
{
	int kontrol = 1;////eðer iþlem yapýlmadýðýnda bize bilgilendirmesi için kontrolümüz
	string tc;//aranan kiþi
	ofstream dosyadegis("temp.txt");//geçici dosymýz
	ifstream dosyaoku("hasta.txt");//hasta bilgilerini göstermesi için
	ifstream dosyaoku2("muayene.txt");//dosyamýzda bulunan verileri okumamýz için kodumuz
	cout << "Randevusu silinmesi istenen kiþinin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//sola yaslamasý için kodmuz
	while (!(dosyaoku.eof()) || !(dosyaoku2.eof()))//dosyada bulunan verileri okumuzu saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//verileri çekme kodumuz
		dosyaoku2 >> m1.tc>>m1.tarih>>m1.saat;//verileri çekme kodumuz
		if (tc == m1.tc)
		{
			if (!(dosyaoku2.eof()))
			{
				cout << "\n=HASTA BÝLGÝLERÝ=\n";
				cout << " TC NO ...:";
				cout << h1.tc << endl;//hasta bilgilerini çeken kodumuz
				cout << " ADI ...:";
				cout << h1.ad << endl;//hasta bilgilerini çeken kodumuz
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;//hasta bilgilerini çeken kodumuz
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kayýtno << endl;//hasta bilgilerini çeken kodumuz
				cout << " TELEFON ...:";//hasta bilgilerini çeken kodumuz
				cout << h1.tel << endl;//hasta bilgilerini çeken kodumuz
				cout << " YAÞI ...:";//hasta bilgilerini çeken kodumuz
				cout << h1.yas << endl;
				kontrol = 0;//iþlem yapýldýðý zaman uyarý göstermemesi için
				cout << "\n =RANDEVU SÝLÝNDÝ=\n";

			}
		}
		else//arana kiþi deðilse ayný þekilde yazdýrmasýný saðlayan kodumuz
		{
			if (!(dosyaoku2.eof()))//ikikez yazdýrmamasý için
			{
				dosyadegis << setw(15) << m1.tc
					<< setw(15) << m1.tarih
					<< setw(15) << m1.saat << endl;
			}
		}

	}
	if (kontrol)//iþlem yapýlmadýmý uyarý göstermesi için
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosyaoku.close();//dosyalarýmýzý kapatan kodumuz
	dosyadegis.close();//dosyalarýmýzý kapatan kodumuz
	dosyaoku2.close();//dosyalarýmýzý kapatan kodumuz
	remove("muayene.txt");//dosyamýzý silen 
	rename("temp.txt", "muayene.txt");//dosya ismini deðiþtiren kodumuz

}
void hastarandevudüzelt(hasta h1, muayene m1)
{
	int kontrol = 0;//eðer iþlem yapýlmadýðýnda bize bilgilendirmesi için kontrolümüz
	string tc;//aranan kiþi
	ofstream dosyadegis("temp.txt");//geçici dosymýz
	ifstream dosyaoku("hasta.txt");//hasta bilgilerini göstermesi için
	ifstream dosyaoku2("muayene.txt");//dosyamýzda bulunan verileri okumamýz için kodumuz
	cout << "Randevusu güncellenmesi istenen kiþinin tcsi ...:";
	cin >> tc;
	dosyadegis.setf(ios::left);//sola yaslamasý için kodmuz
	while (!(dosyaoku.eof()))//dosyamýzýda bulunan verileri okumuzu saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//dosyamýzdan verimizi çeken kodumuz
		if (tc == h1.tc)//aranan kiþi dosyamýzda bulunan veri ile eþleþirse iþleme baþlar
		{
			if (!(dosyaoku.eof()))
			{
				cout << "\n=HASTA BÝLGÝLERÝ=\n";//hasta bilgilerini cout ekranýna yazdýran koodlarýmýz
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kayýtno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YAÞI ...:";
				cout << h1.yas << endl;
				kontrol = 1;//eðerki iþlem yaptýðýnda diðer iþlemleri saðlamasý için
			}
		}	
	}
	if (kontrol)//burda eðer kiþi bulunmazsa randevu lara bakmamasýna gerek olmadýðý için yaptýðým koþul
	{
		while (!(dosyaoku2.eof()))//dosyamýzý okumamýzý saðlayan döngü
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//verileri çeken kodumuz
			if (tc == m1.tc)//aranan kiþi 
			{
				if (!(dosyaoku2.eof()))//ikikez okuyup yazdýrmamasý için
				{

					cout << "\n =RANDEVU GÜNCELLEME=\n";//yeni veriler girilip 
					cout << " tarih ...:";
					cin >> m1.tarih;
					cout << " Saat ...:";
					cin >> m1.saat;
					dosyadegis << setw(15) << m1.tc//dosyamýza yazdýran kodumuz
						<< setw(15) << m1.tarih
						<< setw(15) << m1.saat << endl;

				}
			}
			else//aranan kiþi deðilse ayný þekilde yazdýran kodumuz
			{
				if (!(dosyaoku2.eof()))//ikikez yazdýrmamsý için
				{
					dosyadegis << setw(15) << m1.tc
						<< setw(15) << m1.tarih
						<< setw(15) << m1.saat << endl;
				}
			}
		}
	}
	if (kontrol-1)//eðer aranankiþi yoksa uyarý vermesi için
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosyaoku.close();//dosyalarmýzý kapatan kodumuz
	dosyadegis.close();//dosyalarmýzý kapatan kodumuz
	dosyaoku2.close();//dosyalarmýzý kapatan kodumuz
	remove("muayene.txt");//dosyayý silen kod
	rename("temp.txt", "muayene.txt");//dosyanýn adýný deðiþtiren kodumuz
}
void hastasorgulama(hasta h1, muayene m1,muayenekayýt k1)
{
	int kontrol = 0;//eðer iþlem yapýlmadýðýnda bize bilgilendirmesi için kontrolümüz
	string tc;//aranan kiþi
	ifstream dosyaoku("hasta.txt");//verileri okumamýzý saðlayan kod
	ifstream dosyaoku2("muayene.txt");//verileri okumamýzý saðlayan kod
	ifstream dosyaoku3("muayenekaydý.txt");//verileri okumamýzý saðlayan kod
	cout << "Hasta geçimiþi istenen kiþinin tcsi ...:";
	cin >> tc;
	while (!(dosyaoku.eof()))//ilk olarak hasta bilgilerini çeken kodumuzun döngüsü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//dosyamýzdan verileri çeken kodumuz
		if (tc == h1.tc)//aran kiþi ise iþlme baþlar
		{
			if (!(dosyaoku.eof()))//ikikez okumamasý için
			{
				cout << "\n=HASTA BÝLGÝLERÝ=\n";//biligileri cout bilgilerine yazdýran kodlarýmýz
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kayýtno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YAÞI ...:";
				cout << h1.yas << endl;
				kontrol = 1;//eðerki iþlem yaptýðýnda diðer iþlemleri saðlamasý için
			}
		}
	}
	if (kontrol)//burda eðer kiþi bulunmazsa randevu lara bakmamasýna gerek olmadýðý için yaptýðým koþul
	{
		while (!(dosyaoku2.eof()))//randevu dosyamýzda bulunan randevu geçmiþini gösterne kodumuz
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//dosyamýzdan verileri çeken kodumuz
			if (tc == m1.tc) //aran kiþi ise iþlme baþlar
			{
				if (!(dosyaoku2.eof()))//ikikez okumamasý için
				{
					cout << "\n =Randevu geçimiþi=\n";//biligileri cout bilgilerine yazdýran kodlarýmýz
					cout << " tarih ...:";
					cout << m1.tarih<<endl;
					cout << " Saat ...:";
					cout << m1.saat << endl;
				}
			}
		}
		while (!(dosyaoku3.eof()))//muayene dosyamýzda bulunan muayene geçmiþini gösterne kodumuz
		{
			dosyaoku3 >> k1.tc >> k1.doktor >> k1.teshis >> k1.ilac >> k1.tahlil >> k1.ucret;//dosyamýzdan verileri çeken kodumuz
			if (tc == k1.tc)//aran kiþi ise iþlme baþlar
			{
				if (!(dosyaoku3.eof()))//ikikez okumamasý için
				{
					cout << "\n MUANE geçmiþi\n";//biligileri cout bilgilerine yazdýran kodlarýmýz
					cout << " doktor ...:";
					cout << k1.doktor << endl;
					cout << " Teþhis ...:";
					cout << k1.teshis << endl;
					cout << " ilaç ...:";
					cout << k1.ilac << endl;
					cout << " Tahliller ...:";
					cout << k1.tahlil << endl;
					cout << " Ücret ...:";
					cout << k1.ucret << endl;


				}
			}
		}
	}
	if (kontrol - 1)//eðer aranankiþi yoksa uyarý vermesi için
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosyaoku.close();//dosyamýzý kapatan kodumuz
	dosyaoku2.close();//dosyamýzý kapatan kodumuz
	dosyaoku3.close();//dosyamýzý kapatan kodumuz
}
void hastalistesi(hasta h1)
{
	ifstream dosyaoku("hasta.txt");//dosyamýzý okuyan kodumuz
	cout << "\n=HASTA BÝLGÝLERÝ=\n";
	cout << setw(12) << "TC" << setw(12) << "ADI" << setw(12) << "SOYADI" << setw(15) << "KAYIT NO" << setw(12) << "TELEFON" << setw(6) << "YAÞI" << endl;//baþlýk için tablo baþlýklarý
	while (!(dosyaoku.eof()))//dosyamýzý okumamýzý saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//verileri çeken kodumuz
			if (!(dosyaoku.eof()))//ikikez yazdýrmamsý için
			{
				
				cout << setw(12) << h1.tc;//verileri yazdýran kodumuz
				cout << setw(12) << h1.ad;
				cout << setw(12) << h1.soyad;
				cout << setw(15) << h1.kayýtno;
				cout << setw(12) << h1.tel;
				cout << setw(6) << h1.yas << endl;
			}
	}
	dosyaoku.close();//dosyamýzý kaparan kodumuz
}
void muayenekaydý( hasta h1,  muayene m1,muayenekayýt k1)
{
	int kontrol = 0;//iþlem yapýlýp yapýmadýmý bilgilendirmesi için
	string tc;//iþlem yapýlmasý istenen kiþinin tcsi
	ofstream dosya("muayenekaydý.txt",ios::app);//dosyamýzý veri yazdýramzý için açan kodumuuz
	ifstream dosyaoku("hasta.txt");////dosyamýzý okuyan kodumuz
	ifstream dosyaoku2("muayene.txt");//dosyamýzý okuyan kodumuz
	cout << "Muayene kaydý  girilmesi istenen kiþinin tcsi ...:";
	cin >> tc;
	dosya.setf(ios::left);//sola yaslamasý için
	while (!(dosyaoku.eof()))////dosyamýzý okumamýzý saðlayan döngü
	{
		dosyaoku >> h1.tc >> h1.ad >> h1.soyad >> h1.kayýtno >> h1.tel >> h1.yas;//verileri çeken kodumuz
		if (tc == h1.tc)////aran kiþi ile eþleþirse iþlme baþlar
		{
			if (!(dosyaoku.eof()))//ikikez okumamasý için
			{
				cout << "\n=HASTA BÝLGÝLERÝ=\n";//biligileri cout bilgilerine yazdýran kodlarýmýz
				cout << " TC NO ...:";
				cout << h1.tc << endl;
				cout << " ADI ...:";
				cout << h1.ad << endl;
				cout << " SOYADI ...:";
				cout << h1.soyad << endl;
				cout << " HASTA KAYIT NO ...:";
				cout << h1.kayýtno << endl;
				cout << " TELEFON ...:";
				cout << h1.tel << endl;
				cout << " YAÞI ...:";
				cout << h1.yas << endl;
				kontrol = 1;//eðerki iþlem yaptýðýnda diðer iþlemleri saðlamasý için
			}
		}
	}
	if (kontrol)//burda eðer kiþi bulunmazsa randevu lara bakmamasýna gerek olmadýðý için yaptýðým koþul
	{
		while (!(dosyaoku2.eof())) // dosyamýzý okumamýzý saðlayan döngü
		{
			dosyaoku2 >> m1.tc >> m1.tarih >> m1.saat;//verileri çeken kodumuz
			if (tc == m1.tc)///aran kiþi ile eþleþirse iþlme baþlar
			{
				if (!(dosyaoku2.eof()))//ikikez okumamasý için
				{
					cout << "\n =Randevu geçimiþi=\n";//biligileri cout bilgilerine yazdýran kodlarýmýz
					cout << " tarih ...:";
					cout << m1.tarih << endl;
					cout << " Saat ...:";
					cout << m1.saat << endl;
					cout << "\n  Hasta muayene kaydý\n";//muayene kaydý için girilen verilerimiz
					cout << " doktor ...:";
					cin >> k1.doktor;
					cout << " Teþhis ...:";
					cin >> k1.teshis;
					cout << " ilaç ...:";
					cin >> k1.ilac;
					cout << " Tahliller ...:";
					cin >> k1.tahlil;
					cout << " Ücret ...:";
					cin >> k1.ucret;
					k1.tc = tc;//muayene kaydýnda bir kez daha tc girilmemesi için 
					dosya << setw(15) << k1.tc << setw(15) << k1.doktor//dosyamýza yazdýran kodumuz
					<< setw(15) << k1.teshis
					<< setw(15) << k1.ilac
					<< setw(15)<<k1.tahlil 
					<< setw(15) << k1.ucret<< endl;
				}
			}
		}		
	}
	if (kontrol - 1)//eðer aranankiþi yoksa uyarý vermesi için
	{
		cout << "\nkayýt bulunamadý \n";
	}
	dosya.close();//dosyamýzý kapatan kodumuz
	dosyaoku.close();//dosyamýzý kapatan kodumuz
	dosyaoku2.close();//dosyamýzý kapatan kodumuz
}
