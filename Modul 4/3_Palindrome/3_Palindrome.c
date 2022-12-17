
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int palindrom(char kata[], int size);
char kata [1000];
void cekValid(int *var, char *msg);
int validInt(int *var);
void tampil(char kata[]);
void hitung(char kata[]);
void keluar();
void perulangan();

int main (){
	int alphabet = 0;
	int panjang;
	int i;
	int digit=0;

	system ("cls");
    printf("----------------------------------------------\n"
           "              PROGRAM PALINDROME\n"
           "----------------------------------------------\n\n");
	printf (" Masukkan Kata : "); gets(kata);

	panjang = strlen(kata);


	for (i=0; i<panjang; i++){
		if (isdigit(kata[i]) !=0)
		digit++;
	}

	if (digit > 0){
		printf (" *Kata Tidak Boleh Mengandung Angka\n\n");

		printf (" Masukkan Kata : "); gets(kata);

		panjang = strlen(kata);
	}
	fflush(stdin);
	if (panjang <=1){
		printf (" *Kata Harus Lebih Dari 1 Huruf\n\n");
		printf (" Masukkan Kata : "); gets(kata);

		panjang = strlen(kata);
	}
	fflush(stdin);
    printf("\n----------------------------------------------\n");
	hitung (kata);

	return 0;
}

void hitung(char kata[]){
	int i,j;
	int jumlahKarakter;
	int temp, counter=0;

	FILE *file;
	file = fopen("kamuskata.txt", "a");
	jumlahKarakter = strlen(kata);
	fprintf(file, " %s(%d)\t : ", kata, jumlahKarakter);
	for (i=0; i<strlen (kata); i++){
		temp = 0;
		for (j=i-1; j>=0; j--){
			if (tolower(kata[j]) == tolower(kata[i])){
				temp++;
			}
		}
		if (temp == 0){
			counter++;
		}
		else {
			continue;
		}
	}
	char huruf[counter];
	int jumlahHuruf[counter];
	printf(" %s(%d) : ", kata, jumlahKarakter);
	for (i=0; i<strlen(kata); i++){
		kata[i] = tolower(kata[i]);
	}
	for (i=0; i<strlen(kata); i++){
		counter = 0;
		temp = 0;

		for (j=i-1; j>=0; j--){
			if (kata[j] == kata[i]){
				temp++;
			}
		}
		if (temp == 0){
			for (j=i; j<strlen(kata); j++){
				if (kata[j] == kata[i]){
					temp++;
				}
			}
			huruf[counter] = kata[i];
			jumlahHuruf[counter] = temp;
			printf(" %c=%d ",huruf[counter], jumlahHuruf[counter]);
			fprintf(file, "%c=%d ", huruf[counter], jumlahHuruf[counter]);
			counter++;
		}
		else{
			continue;
		}
	}
	fclose(file);
	tampil(kata);
}

void tampil(char kata[]){
	FILE *file;
	file = fopen("kamuskata.txt", "a");
	if (palindrom(kata, strlen(kata)) == 1){
		printf("\t = [PALINDROM]\n");
		fprintf(file, " = [PALINDROM]\n");
	}
	else {
		printf("\t = [BUKAN PALINDROM]\n");
		fprintf(file, " = [BUKAN PALINDROM]\n");
	}
	fclose(file);
	 printf("----------------------------------------------\n");
	system("\n\npause");
	system("cls");
	perulangan();
}

int palindrom(char kata[], int size){
	int i, status = 1;
	for (i=0; i<size; i++){
		if (kata[i] == kata[size-1-i]){
			continue;
		}
		else {
			status = 0;
			break;
		}
	}
	return status;
}


void perulangan (){
	int ulang;
	pilihan:
	printf ("\t---------------------------------------------------------");
	printf ("\n\t\tApakah anda ingin memasukkan kata lagi?\n");
	printf ("\n\t\t      [1] Ya        [2] Tidak\n");
	printf ("\t---------------------------------------------------------\n");

	cekValid(&ulang, "\n\t\t Pilih Menu(1-2) : ");
	if (ulang == 1){
		main();
	}
	else if (ulang == 2){
		keluar();
	}
	else{
		printf ("\n\t *Kategori Menu Tidak Ada! Silahkan Input Ulang \n");
		system ("pause");
		system ("cls");
		perulangan();
	}
}

void keluar(){
	system("cls");
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                     TERIMA KASIH                    \n");
	printf ("\t---------------------------------------------------------\n");
	system("exit");
}

int validInt(int *var){
	char buff[1024];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void cekValid(int *var, char *msg){
	while(1){
		printf(msg);
		if(validInt(var))
			break;
		printf("\t *Input hanya berupa angka!!");
		printf("\n");
	}
}

