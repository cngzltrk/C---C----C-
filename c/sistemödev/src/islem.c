#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"jrb.h"
#include"fields.h"

#define UZUNLUK 256

//BU STRUCT 2 BOYUTLU BİR DİZİ TANIMLAMA YAPABİLMEK İÇİN
typedef struct {
  char **kelime;
  int adet;
} Komut_Dizi;

typedef struct {
  char *adi;
  char *malzeme;
  char *renk;
} Siparis;

//FONKSİYON TANIMLARI
char* girdi();
Komut_Dizi* dizilere_bol(char*);
JRB jrb_ekle(JRB,Komut_Dizi*);
JRB jrb_girdi(JRB,Komut_Dizi*);
void* arama_yap(JRB,Komut_Dizi*);
void* dosya_yazdir(JRB,Komut_Dizi*);
void* ekrana_yaz(JRB);

main()
{
  int kontrol=1;//ÇIKIŞ KONTROLÜ
  char *komut;
  Komut_Dizi *dizi;
  JRB t,tmp;
  Siparis *siparis;
  t=make_jrb();
  while(kontrol)
  {
    printf(">");
    komut=girdi();
    dizi=dizilere_bol(komut);
    //çıkış için kontrol
    if(strcmp("quit",&(*dizi->kelime[0]))==0)
    {
      kontrol=0;
    }
    else if(strcmp("add",&(*dizi->kelime[0]))==0)
    {
      t=jrb_ekle(t,dizi);
    }
    else if(strcmp("pro",&(*dizi->kelime[0]))==0)
    {
      t=jrb_girdi(t,dizi);
    }
    else if(strcmp("search",&(*dizi->kelime[0]))==0)
    {
      arama_yap(t,dizi);
    }
    else if(strcmp("write",&(*dizi->kelime[0]))==0)
    {
      dosya_yazdir(t,dizi);
    }
    else if(strcmp("print",&(*dizi->kelime[0]))==0)
    {
      ekrana_yaz(t);
    }
    else{
      printf("HATALI GİRİŞ\n");
    }
  }
  //BELLEK TEMİZLEME
  jrb_traverse(tmp, t) {
    siparis = (Siparis*)tmp->val.v;
    free(siparis->adi);
    free(siparis->renk);
    free(siparis->malzeme);
    free(siparis);
  }
  jrb_free_tree(t);
}
char* girdi(){
  //dışardan kodu alıp char pointırına atama
  char *komut=(char*)malloc(sizeof(char)*UZUNLUK);
  gets(komut);
  return &komut[0];
}
Komut_Dizi* dizilere_bol(char* komut)
{
  /* struct yaspına çevirme yapılır
  adet bize kaç kelime olduğunu gösterir*/
  Komut_Dizi* dizi;
  dizi=(Komut_Dizi*)malloc(sizeof(Komut_Dizi));
  int i=0;
  dizi->kelime=(char**)malloc(sizeof(char)*UZUNLUK);
  char *token,*s;
  if(komut[0]=='p')
  {
    s=" \n";
  }
  else{
    s="|\n";
  }
  token=strtok(komut,s);
  while(token!=NULL){
    dizi->kelime[i]=token;
    token=strtok(NULL,s);
    i++;
  }
  dizi->kelime[i]="\n";
  dizi->adet=i;
  return dizi;
}
JRB jrb_ekle(JRB t,Komut_Dizi* dizi)
{
  //uygunluk kontrolü
  //add|-sipKey-|-sipAd-|-sipMalezeme-|-sipRenk
  //add dahil 5 adet olmalı
  if(dizi->adet!=5)
  {
    printf("Biçim uygun değil.\n" );
    return t;
  }
  Siparis *siparis=malloc(sizeof(Siparis));
  siparis->renk=strdup(dizi->kelime[dizi->adet-1]);
  siparis->malzeme=strdup(dizi->kelime[dizi->adet-2]);
  siparis->adi=strdup(dizi->kelime[dizi->adet-3]);
  jrb_insert_int(t, atoi(strdup(dizi->kelime[dizi->adet-4])), new_jval_v((Siparis*) siparis));
  return t;
}
JRB jrb_girdi(JRB t,Komut_Dizi* dizi)
{
  IS is;//dosya işlemleri için
  //giriş yönlendirme kontrolü
  if(strcmp("<",&(*dizi->kelime[1]))==0)
  {
    is = new_inputstruct(&(*dizi->kelime[2]));
    if (is == NULL) {//dosya kontrolü
      printf("dosya bulunamadı\n");
      return t;
    }
    while(get_line(is) >= 0) {
      dizi=dizilere_bol(is->text1);
      t=jrb_ekle(t,dizi);
    }
    //kapatma
    jettison_inputstruct(is);
  }
  else
  {
    printf("Hatalı Giriş\n" );
  }
  return t;
}
void* arama_yap(JRB t,Komut_Dizi *dizi)
{
  JRB arama;
  Siparis *siparis;
  arama=jrb_find_int(t, atoi(dizi->kelime[1]));
  if (arama== NULL){
      printf("Aranan kayıt bulunamadı\n");
  }
  else{
    siparis=(Siparis*)arama->val.v;
    printf("%d , %s , %s , %s\n", arama->key,siparis->adi,siparis->malzeme,siparis->renk);
  }
}
void* dosya_yazdir(JRB t,Komut_Dizi *dizi)
{
  Siparis *siparis;
  JRB tmp;
  FILE* fd = fopen(dizi->kelime[1], "a");
  jrb_traverse(tmp, t){
    siparis = (Siparis*)tmp->val.v;
    fprintf(fd,"%d , %s , %s , %s\n",tmp->key,siparis->adi,siparis->malzeme,siparis->renk );
  }
  fclose(fd);
}
void* ekrana_yaz(JRB t)
{
  Siparis *siparis;
  JRB tmp;
  jrb_traverse(tmp, t){
    siparis = (Siparis*)tmp->val.v;
    printf("%d , %s , %s , %s\n",tmp->key,siparis->adi,siparis->malzeme,siparis->renk );
  }
}
