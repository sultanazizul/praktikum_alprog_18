#include <stdio.h>
#include <stdlib.h>

void cekValid(int *var, char *msg);
int validInt(int *var);
void perulangan();
void keluar();
void kubusStruct();
void kubusUnion();
int panjangSisi;


typedef struct{

	int panjang;
	int luasPermukaan;
	int volume;

}kubus_struct;

typedef union{

	int panjang;
	int luasPermukaan;
	int volume;

}kubus_union;

int main(){
	int menu;
	system("cls");
	printf ("\t---------------------------------------------------------\n");
	printf ("\t             PROGRAM PERHITUNGAN KUBUS                    \n");
	printf ("\t---------------------------------------------------------\n");
	printf ("\t   1.   STRUCT                \n");
	printf ("\t   2.   UNION                 \n");
	printf ("\t   3.   KELUAR                                   \n");
	printf ("\t---------------------------------------------------------\n");
	cekValid(&menu, "\t Pilih Menu(1-3) : ");

	if (menu==1){
		kubusStruct();
	}
	else if (menu==2){
		kubusUnion();
	}
	else if (menu==3){
		keluar();
	}
	else{
		printf ("\n\t *Menu Tidak Ada!\n");
		system ("pause");
		system ("cls");
		main();
	}

}

void kubusStruct(){
	system("cls");
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                PERHITUNGAN DENGAN STRUCT            \n");
	printf ("\t---------------------------------------------------------\n\n");
	cekValid(&panjangSisi, "\t Masukkan Panjang Sisi Kubus      : ");
	printf ("\n\t---------------------------------------------------------\n\n");
	kubus_struct structs = {.panjang = panjangSisi,
	.luasPermukaan = 6 *panjangSisi * panjangSisi,
	.volume = panjangSisi * panjangSisi * panjangSisi};
	printf("\t Panjang Sisi Kubus               : %d\n", structs.panjang);
	printf("\t Luas Permukaan Kubus             : %d\n", structs.luasPermukaan);
	printf("\t Volume Kubus                     : %d\n", structs.volume);
	printf("\t Ukuran Memory Pada Kubus Struct  : %d\n", sizeof(structs));
	printf ("\n\t---------------------------------------------------------\n");
	system("pause");
	system("cls");
	perulangan();
}

void kubusUnion(){
	system("cls");
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                PERHITUNGAN DENGAN UNION            \n");
	printf ("\t---------------------------------------------------------\n\n");
	cekValid(&panjangSisi, "\t Masukkan Panjang Sisi Kubus      :");
	printf ("\t---------------------------------------------------------\n\n");
	kubus_union unions[3];
	unions[0].panjang = panjangSisi;
	unions[1].luasPermukaan = 6 * panjangSisi * panjangSisi;
	unions[2].volume = panjangSisi * panjangSisi *  panjangSisi;
	printf("\t Panjang Sisi Kubus               : %d\n", unions[0]);
	printf("\t Luas Permukaan Kubus             : %d\n", unions[1]);
	printf("\t Volume Kubus                     : %d\n", unions[2]);
	printf("\t Ukuran Memory Pada Kubus Union   : %d\n", sizeof(unions[0]));
	printf ("\n\t---------------------------------------------------------\n");
	system("pause");
	system("cls");
	perulangan();
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
	system("exit");
}



