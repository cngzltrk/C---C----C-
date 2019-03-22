#include<stdio.h>
#include"shell.h"
int main(void){
  char *cumle;
  int kontrol;
  do{
    printf(">");
    cumle=oku_cumle();
    kontrol=calistir(cumle);
    //yaz_cumle(cumle);
    free(cumle);//ayrılan belleği özgür bırakma
    fflush(stdout);
  }while(kontrol);
  return 0;
}
