

#include"shell.h"


#define MAX 100
char* oku_cumle(){
  char *cumle=(char*)malloc(sizeof(char)*MAX);
  char c;
  int i=0;
  while(c != '\n')
   {
       c = getchar();
       cumle[i]= c;
       i++;
   }
  cumle[i]='\n';//sonlanma noktası
  return &cumle[0];//ilk parametresinin adresini yönlendirdim
}
int calistir(char* cumle)
{
  //kelimelere bölme
  int i=0;
  char *kelimeler[10];
  char *token;
  token=strtok(cumle," \n");
  while(token!=NULL){
    kelimeler[i]=token;
    token=strtok(NULL," \n");
    i++;
  }
  kelimeler[i]="\n";
  char *komut[]={"quit"};
  //quit girildiğinde işlem
  if(strcmp(&(*komut[0]),&(*kelimeler[0]))==0)
  {
    wait(NULL);
    execlp("/bin/kill","kill",-9,getpid());
    return 0;
  }
  if(*(kelimeler[1])=='<')
    girisYonlendir_calistir(kelimeler);
  else if(*(kelimeler[2])=='>')
    cikisYonlendir_calistir(kelimeler);
  else
    tekKomut_calistir(kelimeler);
  return 1;
}
void tekKomut_calistir(char** kelimeler)
{
  pid_t pid;
  pid=fork();
  if(pid < 0){
    printf("HATA\n" );

  }
  else if(pid==0){
    //coçuk proses

    //dizin adresi
    char *dizin=(char*)malloc(sizeof(char)*20);
    for(int i=0;i<20;i++)
    {//dizin adresinin başına /bin/ ekleyip
      if(i<5)
      {
        dizin[0]='/';
        dizin[1]='b';
        dizin[2]='i';
        dizin[3]='n';
        dizin[4]='/';
        i=5;
      }//dizinin çağrılaccak komutunu ekletip
      if(*(kelimeler[0]+(i-5))=='\n')
        {
          dizin[i]=*(kelimeler[0]+(i-5));
          break;
        }
        dizin[i]=*(kelimeler[0]+(i-5));
    }
    int sayac=0;//tek komut veya özellikli komut olmak üzere
    for(int i=0;*kelimeler[i]!='\n';i++)
    {//ls bu tek komut
      //ls -la  buda özellikli komut
      sayac++;
    }

    //tek komut
    if(sayac==1)
    {
      //çalıştırıyoruz
      execlp(dizin,kelimeler[0],NULL);
    }
    //özellikli komut
    if(sayac==2)
    {
      //çalıştırıyoruz
      execlp(dizin,kelimeler[0],kelimeler[1],NULL);
    }
    else
      printf("\nHatalı  işlem\n");
    exit(getpid());//çocuğu sonlandır
  }
  else{
    //parent
    wait(NULL);//çocugu bekle
  }
}

void girisYonlendir_calistir(char** kelimeler)
{
  pid_t pid;
  pid=fork();
  if(pid<0){
    printf("HATA\n" );
  }
  else if(pid==0){
    //coçuk proses
    int dosya;
    //dosyayı açamazsa yada bulamazsa hatamız
    if ((dosya = open(kelimeler[2], O_RDONLY)) < 0) {
        printf("%s Giris Dosyası bulunamadı\n",kelimeler[2]);
        exit(EXIT_FAILURE);
    }
    dup2(dosya,0);
    //dizin adresi
    char *dizin=(char*)malloc(sizeof(char)*20);
    for(int i=0;i<20;i++)
    {//dizin adresinin başına /bin/ ekleyip
      if(i<5)
      {
        dizin[0]='/';
        dizin[1]='b';
        dizin[2]='i';
        dizin[3]='n';
        dizin[4]='/';
        i=5;
      }//dizinin çağrılaccak komutunu ekletip
      if(*(kelimeler[0]+(i-5))=='\n')
        {
          dizin[i]=*(kelimeler[0]+(i-5));
          break;
        }
        dizin[i]=*(kelimeler[0]+(i-5));
    }
    //çalıştırma
    execlp(dizin,kelimeler[0],kelimeler[2],NULL);
    close(dosya);
  }
  else{
    //parent
    wait(NULL);
  }
}
void cikisYonlendir_calistir(char** kelimeler)
{
  pid_t pid;
  pid=fork();
  if(pid<0){
    printf("HATA\n" );
  }
  else if(pid==0){
    //coçuk proses
    int dosyaGirdi;
    int dosyaCikti;
    //dosyayı açamazsa yada bulamazsa hatamız
    if ((dosyaGirdi = open(kelimeler[1], O_RDONLY)) < 0) {
        printf("%s Giris Dosyası bulunamadı\n",kelimeler[2]);
        exit(EXIT_FAILURE);
    }
    dup2(dosyaGirdi,0);
    //dizin adresi
    char *dizin=(char*)malloc(sizeof(char)*20);
    for(int i=0;i<20;i++)
    {//dizin adresinin başına /bin/ ekleyip
      if(i<5)
      {
        dizin[0]='/';
        dizin[1]='b';
        dizin[2]='i';
        dizin[3]='n';
        dizin[4]='/';
        i=5;
      }//dizinin çağrılaccak komutunu ekletip
      if(*(kelimeler[0]+(i-5))=='\n')
        {
          dizin[i]=*(kelimeler[0]+(i-5));
          break;
        }
        dizin[i]=*(kelimeler[0]+(i-5));
    }
    //Çıktı dosyası
    if ((dosyaCikti = open(kelimeler[3], O_APPEND | O_WRONLY)) <0) {
        printf("%s Cıkıs Dosyası bulunamadı\n",kelimeler[2]);
        exit(EXIT_FAILURE);
    }
    dup2(dosyaCikti,1);
    execlp(dizin,kelimeler[0],kelimeler[1],kelimeler[3],NULL);
    close(dosyaCikti);
    close(dosyaGirdi);
  }
  else{
    //parent
    wait(NULL);
  }

}











void yaz_cumle(char *kelimeler){
    for(int i=0;kelimeler[i]!='\n';i++)
    {
      printf("%c",kelimeler[i]);
    }
}
