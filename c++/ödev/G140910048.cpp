/***************************************************************
**								SAKARYA �N�VERS�TES�
**						B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�			
**							B�LG�SAYAR M�HEND�SL��� B�L�M�
**								PROGRAMLAMA G�R�� DERS�
**								  2015-2016 G�Z D�NEM�
**
**						�DEV NUMARASI........:	�DEV 1
**						��RENC� ADI..........:	CENG�Z ALT�RK
**						��RENC� NUMARASI.....:	G140910048
**						DERS�N ALINDI�I GRUP.:    B
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
	cout << " k degerini giriniz (5'den b�y�k 10'dan k���k olmal�)...=";
	cin >> k;
	cout << " t degerini giriniz (1'den b�y�k 9'dan  k���k olmal�)...=";
	cin >> t;
	if (5 <= k&&k <= 10)//�LK DE���KEN KONTROL�
	{
		if (1 <= t&&t < 9)//�K�NC� ED���KEN KONTROL� E�ER DO�RUYSA ��LEME BA�LAR
		{
			cout << endl << setw(10) << "faktoriyel" << setw(17) << "carp�m" << setw(15) << "AraToplam" << endl << endl;//BA�LIK LAR ���N YAZMA KODU
		bas:
			if (s <= k)//ilk saya� konrol�
			{
				fak = fak*s;
				cout << setw(10) << fak << setw(5) << "+";
				c = s;
				if (c <= t)//burda �arp�m sembol�n�n i�levi olup  olmad���n�n  kontrol�
				{
					carp = 1;
				car:
					if (c <= t)//ikinci sayac kontrol�
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
				carp = 0;//�arp�m�n i�levi bitti�inde +1 eklememesi i�in 
				s = s + 1;
				goto bas;
			}
			cout << endl << "Toplam.....=" << top << endl;
		}
		else
		{
			cout << " t de�eri yanl�� girilmi�tir" << endl;
			goto gir;
		}
	}
	else
	{
		cout << " k de�eri yanl�� girilmi�tir" << endl;
		if (!(1 <= t&&t < 9))//burda 1. yanl��sa 2. sinide kontrol� yap�lmas� i�in
		{
			cout << " t de�eri yanl�� girilmi�tir" << endl;
		}	
		goto gir;
	}
	
	system ("pause");
	return 0;
}
