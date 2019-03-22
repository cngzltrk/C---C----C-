#ifndef SOURCE_H
#define SOURCE_H
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
#define MAX 100
  typedef struct {
    char **kelimeler;
    int uzunluk;
  } Komut;
  typedef struct {
    char *adi;
    char *malzeme;
    char *renk;
  } Siparis;
  char* oku_cumle();
  Komut* kelimelere_bol(char*);
  int cikis_kontrol(Komut*);
  JRB ekle_calistir(JRB,Komut*);
  JRB ekle_giris(JRB,Komut*);
  void* arama(JRB,Komut*);
  void* yazdir(JRB,Komut*);
  void* goster(JRB);
#endif
