#include"source.h"
char* oku_cumle(){
  //dışardan kodu okuyup tek stringe atama
  char *cumle=(char*)malloc(sizeof(char)*MAX);
  char c;
  int i=0;
  while(c != '\n')
   {
       c = getchar();
       cumle[i]= c;
       i++;
   }
  cumle[i]='\0';//sonlanma noktası
  return &cumle[0];//ilk parametresinin adresini yönlendirdim
}
Komut* kelimelere_bol(char* cumle)
{
  /*kelimelere bölme burda komut structın içerisinde
 uzunluk kaç adet kelime olduğunu gösterir*/

  Komut* komut;
  int i=0;
  char **kelimem=(char**)malloc(sizeof(char)*MAX);
  char *token,*bol;
  //bol burda eğer pro girilirse boşluk ile bölsün
  //diğer türlü dik çizgi şeklinde bölme
  if(cumle[0]=='p')
  {
    bol=" \n";
  }
  else{
    bol="|\n";
  }
  token=strtok(cumle,bol);
  while(token!=NULL){
    kelimem[i]=token;
    token=strtok(NULL,bol);
    i++;
  }
  kelimem[i]="\n";
  //komut işlemi yer ayrılıp atamalr yapılır.
  komut=(Komut*)malloc(sizeof(Komut));
  komut->kelimeler=kelimem;
  komut->uzunluk=i;
  return komut;
}
int cikis_kontrol(Komut* komut)
{
  //quit girildiğinde işlem
  if(strcmp("quit",&(*komut->kelimeler[0]))==0)
  {
    return 0;
  }
  return 1;
}
JRB ekle_calistir(JRB agac,Komut* komut)
{
  //add diye ekleme girildiğinde
  //biçim uygun değilse kabul etme
  if(komut->uzunluk!=5)
  {
    printf("Biçim uygun değil.\n" );
    return agac;
  }
  //gelen leri sipraiş türünde bulunan struct yapısına atamaları yaparız
  Siparis *siparis=malloc(sizeof(Siparis));
  siparis->renk=strdup(komut->kelimeler[komut->uzunluk-1]);
  siparis->malzeme=strdup(komut->kelimeler[komut->uzunluk-2]);
  siparis->adi=strdup(komut->kelimeler[komut->uzunluk-3]);
  jrb_insert_int(agac, atoi(strdup(komut->kelimeler[komut->uzunluk-4])), new_jval_v((Siparis*) siparis));
  return agac;
}
JRB ekle_giris(JRB agac,Komut *komut)
{
  //burda eğer dışardan bir input girilmesi gerektiğifnde
  //satır satır alıp kelimelere bölüp komut structına aktarıp
  //ordanda ekle_calıstır fonksiyonu ile agaca ekleniyor.

  IS is;//dosya işlemleri için
  //giriş yönlendirme ise kontrolu
  if(strcmp("<",&(*komut->kelimeler[1]))==0)
  {
    is = new_inputstruct(&(*komut->kelimeler[2]));
    if (is == NULL) {
      printf("dosya bulunamadı\n");
      return agac;
    }
    while(get_line(is) >= 0) {
      komut=kelimelere_bol(is->fields[0]);
      agac=ekle_calistir(agac,komut);

    }
    //işlem bitiminden sonra kapatma
    jettison_inputstruct(is);
  }
  else
  {
    printf("Hatalı Giriş\n" );
  }
  return agac;

}
void* arama(JRB agac,Komut *komut)
{
  JRB arama;
  Siparis *siparis;
  arama=jrb_find_int(agac, atoi(komut->kelimeler[1]));
  if ( arama== NULL){
      printf("Aranan kayıt bulunamadı\n");
  }
  else{
    siparis=(Siparis*)arama->val.v;
    printf("%d , %s , %s , %s\n", arama->key,siparis->adi,siparis->malzeme,siparis->renk);
  }
}
void* yazdir(JRB agac,Komut *komut)
{
  Siparis *siparis;
  JRB tmp;
  FILE* fd = fopen(komut->kelimeler[1], "w");
  jrb_traverse(tmp, agac){
    siparis = (Siparis*)tmp->val.v;
    fprintf(fd,"%d , %s , %s , %s\n",tmp->key,siparis->adi,siparis->malzeme,siparis->renk );
  }
  fclose(fd);
}
void* goster(JRB agac)
{
  Siparis *siparis;
  JRB tmp;
  jrb_traverse(tmp, agac){
    siparis = (Siparis*)tmp->val.v;
    printf("%d , %s , %s , %s\n",tmp->key,siparis->adi,siparis->malzeme,siparis->renk );
  }
}
