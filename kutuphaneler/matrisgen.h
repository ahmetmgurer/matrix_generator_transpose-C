#ifndef MATRISGEN_H
#define MATRISGEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

char mucco[]="abaaa ss s";

typedef struct { 
  int i;
  float f;
  double d;
} matris; 


matris* matrisuret(char*, int, int, int, int );

int satirsayi,sutunsayi,min,max;
char *komuti;
char *komutf;
char *komutd;
matris *mat2;
int transpoz;
char* sonuc;
int fd, sz;
#endif
