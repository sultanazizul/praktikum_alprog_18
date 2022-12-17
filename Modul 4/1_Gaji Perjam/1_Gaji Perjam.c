#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void cekValid(int *var, char *msg);
int validInt(int *var);
void perulangan();
void keluar();

typedef struct{

	int jamLembur;
	int jamPokok;
	int totalJamKerja;
	int gajiPokok;
	int gajiLembur;
	int gajiTotal;

}gajiPegawai;

int main(){

	system("cls");
	gajiPegawai pegawai;

	pegawai.totalJamKerja=0;
	pegawai.jamLembur=0;
	pegawai.jamPokok=0;
	pegawai.gajiPokok=0;
	pegawai.gajiLembur=0;
	pegawai.gajiTotal=0;

	printf("\t----------------------------------------------\n"
           "\t      PROGRAM MENGHITUNG GAJI PEGAWAI       \n"
           "\t----------------------------------------------\n");
	cekValid(&pegawai.totalJamKerja,"\t Masukkan Jam Kerja Anda : ");
	if(pegawai.totalJamKerja > 8){
		pegawai.jamPokok=8;
		pegawai.jamLembur= pegawai.totalJamKerja-8;
		pegawai.gajiPokok= 8*10625;
		pegawai.gajiLembur= (pegawai.jamLembur*85000);
	}
	else{
		pegawai.gajiPokok= 10625* pegawai.totalJamKerja;
		pegawai.jamPokok = pegawai.totalJamKerja;
	}

	pegawai.gajiTotal = pegawai.gajiLembur + pegawai.gajiPokok;
    printf("\t----------------------------------------------\n\n");
	printf("\t Jam Kerja 		: %d\n\n", pegawai.totalJamKerja);
	printf("\t Jam Kerja Pokok 	: %d\n\n", pegawai.jamPokok);
	printf("\t Jam Kerja Lembur 	: %d\n\n", pegawai.jamLembur);
	printf("\t Gaji Pokok 		: %d\n\n", pegawai.gajiPokok);
	printf("\t Gaji Lembur 		: %d\n\n", pegawai.gajiLembur);
	printf("\t----------------------------------------------\n");
	printf("\t Total Gaji            : %d\n", pegawai.gajiTotal);
	printf("\t----------------------------------------------\n");
	system("pause");
	system("cls");
	perulangan();

	return 0;
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
		printf("\t *Inputan hanya berupa angka!!\n");
		printf("\n");
	}

}

void perulangan (){
	int ulang;
	pilihan:
	printf ("\t---------------------------------------------------------");
	printf ("\n\t\t Apakah anda ingin menghitung lagi?\n");
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
	exit (0);

}

