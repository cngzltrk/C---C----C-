#ifndef SHELL_H
#define SHELL_H
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
  char* oku_cumle();
  void yaz_cumle(char*);
  int calistir(char*);
  void tekKomut_calistir(char**);
  void girisYonlendir_calistir(char**);
  void cikisYonlendir_calistir(char**);
#endif
