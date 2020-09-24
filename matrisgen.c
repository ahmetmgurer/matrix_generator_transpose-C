#include "matrisgen.h"


matris* matrisuret(char* komut, int r, int c, int min, int max){
matris *mat;
mat = (matris *) malloc(sizeof(matris)*(r*c));


if(strcmp(komut,"i")==0){
		for (int i = 0; i < r*c; i++) 
			mat[i].i = min + rand() % (max+1 - min); }

	if(strcmp(komut,"f")==0){
		for (int i = 0; i < r*c; i++) 
			mat[i].f = min + rand() % (max+1 - min)+ (float)(rand() % (100)) /100;}

	if(strcmp(komut,"d")==0){
		for (int i = 0; i < r*c; i++) 
			mat[i].d = min + rand() % (max+1 - min)+ (double)(rand() % (1000)) /1000; }
return mat;


}//matris uret sonu



int main(int argc, char **argv)
{
  srand(time(NULL));
  komuti="i";
  komutf="f";
  komutd="d";
  transpoz=0;
  satirsayi=-1;sutunsayi=-1;min=-1;max=-1;

if (argc > 3 && argc < 6)
{
	if(argc==5) if(strcmp(argv[4],"-t")==0) transpoz=1;
	if(argc==5) if(strcmp(argv[4],"-t")!=0) { 
		printf("\nLütfen parametre olarak sadece -t girin\n"); exit(1); }
	if(argc==4) transpoz=0;

	sscanf(argv[1], "%d%*1[xX,]%d", &satirsayi, &sutunsayi);
	sscanf(argv[2], "%d%*1[-,]%d", &min, &max);

	if (satirsayi==-1 || sutunsayi==-1) { 
		printf("Matrisi NxM formunda girin\n");
		exit(1);}
	if (satirsayi<0 || sutunsayi<0) { 
		printf("Matris boyutu negatif olamaz\n");
		exit(1);}

	if (min==-1 || max==-1) { 
		printf("Araligi Sayi-Sayi seklinde girin\n");
		exit(1);}
	if (min<0 || max<0) { 
		printf("Sayi araligi pozitif deger girilmelidir\n");
		exit(1);}

	if (min>max) { 
		printf("Araliktaki ilk sayı ikinicisinden büyük olmalıdır.\n");
		exit(1);}



	if(strcmp(argv[3],komuti)!=0 && strcmp(argv[3],komutf)!=0 && strcmp(argv[3],komutd)!=0) { 
		printf("\nHatalı tip. sadece i,f,d giriniz\n"); exit(1); }


	mat2 = (matris *) malloc(sizeof(matris)*(satirsayi*sutunsayi));
	mat2=matrisuret(argv[3],satirsayi,sutunsayi,min,max);

sonuc = (char*) malloc(sizeof(char)*(500)); 
char donustur[8];


printf("\nMatris:\n");
	

for (int i = 0; i < satirsayi*sutunsayi; i++) {

if(i%sutunsayi==0 && i!=0) strcat(sonuc,"\n");

if(strcmp(argv[3],komuti)==0) 
{sprintf(donustur, "%d", mat2[i].i); strcat(donustur," "); strcat(sonuc,donustur);}

if(strcmp(argv[3],komutf)==0)
{sprintf(donustur, "%.2f", mat2[i].f); strcat(donustur," "); strcat(sonuc,donustur);}

if(strcmp(argv[3],komutd)==0)
{sprintf(donustur, "%.4f", mat2[i].d); strcat(donustur," "); strcat(sonuc,donustur);}
}//For sonu

//// yaz


  fd = open("soru1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) { perror("w1"); exit(1); }

  sz = write(fd, sonuc, strlen(sonuc));

  close(fd); //dosya kapa
///



printf("%s \n",sonuc);
free(sonuc);



if (transpoz==1){
printf("\nTranspoz:\n");
int satirda=0;
int sutunsay=0;
int i=0;
	while (satirda!=sutunsayi){ //sutunsayisina kadar dongu

if(strcmp(argv[3],komuti)==0) 
{sprintf(donustur, "%d", mat2[i].i); strcat(donustur," "); strcat(sonuc,donustur);}

if(strcmp(argv[3],komutf)==0)
{sprintf(donustur, "%.2f", mat2[i].f); strcat(donustur," "); strcat(sonuc,donustur);}

if(strcmp(argv[3],komutd)==0)
{sprintf(donustur, "%.4f", mat2[i].d); strcat(donustur," "); strcat(sonuc,donustur);}

i=i+sutunsayi;
sutunsay++; 
if (sutunsay!=0)
if(sutunsay%satirsayi==0)
{i=(i%sutunsayi)+1; sutunsay=0; satirda++; strcat(sonuc,"\n"); }

}//while sonu

//// yaz


  fd = open("soru1-transpoze.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) { perror("w1"); exit(1); }

  sz = write(fd, sonuc, strlen(sonuc));

  close(fd); //dosya kapa
///

printf("%s ",sonuc);
printf("\n");
}//if (transpoz==1) sonu

free(sonuc);
free(mat2);

}  //en üst if sonu
else {
fprintf(stderr, "Parametre olarak: 'matis(NxM) aralık(N-M) tip(i,d,f)' seklinde giris yapin\n"); exit(1); }



exit(0);
}
