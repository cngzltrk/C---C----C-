#include<stdio.h>
#include"source.h"
main(int argc,char* argv[])
{

  int kontrol;
  char *cumle;
  Komut* komut;
  JRB agac,tmp;
  Siparis *siparis;
  agac=make_jrb();
  do{
    printf(">");
    cumle=oku_cumle();
    komut=kelimelere_bol(cumle);
    //komutlar için kontrol
    if(strcmp("add",&(*komut->kelimeler[0]))==0)
    {
      agac=ekle_calistir(agac,komut);
    }
    else if(strcmp("pro",&(*komut->kelimeler[0]))==0)
    {
      agac=ekle_giris(agac,komut);
    }
    else if(strcmp("search",&(*komut->kelimeler[0]))==0)
    {
      arama(agac,komut);
    }
    else if(strcmp("write",&(*komut->kelimeler[0]))==0)
    {
      yazdir(agac,komut);
    }
    else if(strcmp("print",&(*komut->kelimeler[0]))==0)
    {
      goster(agac);
    }
    else{
      printf("Hatalı giriş\n");
    }
    //çıkış için
    kontrol=cikis_kontrol(komut);
    //girilen cumle ve komut ları free işlemleri
    free(cumle);
    free(komut->kelimeler);
    free(komut);
  }while(kontrol);
  //ağacı temizleme işlemi
    jrb_traverse(tmp, agac) {
    siparis = (Siparis*)tmp->val.v;
    free(siparis->adi);
    free(siparis->renk);
    free(siparis->malzeme);
    free(siparis);
  }
}
