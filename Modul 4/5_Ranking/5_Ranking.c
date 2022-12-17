#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void inputNilai();
void rangkingNilai();
void cekValid(int *var, char *msg);
void perulangan();
void keluar();
int clean();

struct mahasiswa{

	char nama[100];
	int nilai;

};

int main(){
	int menu;
	system("cls");
	printf ("\t ---------------------------------------------------------\n");
	printf ("\t             PROGRAM RANGKING MAHASISWA                  \n");
	printf ("\t ---------------------------------------------------------\n");
	printf ("\t    1.    INPUT DATA                               \n");
	printf ("\t    2.    RANKING DATA                             \n");
	printf ("\t    3.    KELUAR                                   \n");
	printf ("\t ---------------------------------------------------------\n");
	cekValid(&menu, "\t  Pilih Menu(1-3) : ");

	if (menu==1){
		inputNilai();
	}
	else if (menu==2){
		rangkingNilai();
	}
	else if (menu==3){
		keluar();
	}
	else{
		printf ("\n\t Kategori Menu Tidak Ada! [ENTER UNTUK MENGULANG] \n");
		system ("pause");
		system ("cls");
		main();
	}
}

void inputNilai(){
	int abjad=0, panjang, digit=0, i;
	int ulang;
	char cek;
	struct mahasiswa nilaiMahasiswa;
	FILE *nilai;
	int pilihan;
	system("cls");
	printf ("\t ---------------------------------------------------------\n");
	printf ("\t               INPUT NILAI MAHASISWA             \n");
	printf ("\t ---------------------------------------------------------\n");
	printf("\t Input Nama Anda : ");
	scanf(" %[^\n]s", &nilaiMahasiswa.nama);
	cekValid(&nilaiMahasiswa.nilai, "\t Input Nilai Anda : ");



	nilai = fopen("asistenin.txt","a");
	fprintf(nilai,"%s\n%d\n", nilaiMahasiswa.nama,
	nilaiMahasiswa.nilai);
	fclose(nilai);

	printf ("\t ---------------------------------------------------------\n");
	printf ("\t                 DATA BERHASIL DISIMPAN               \n");
	printf ("\t ---------------------------------------------------------\n");

    system("pause");
    system("cls");

	printf ("\t---------------------------------------------------------");
	printf ("\n\t\t Apakah anda ingin kembali ke menu utama?\n");
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
		printf ("\n\t Kategori Menu Tidak Ada! Silahkan Input Ulang \n");
		cekValid(&ulang, "\n\t Silahkan Pilih Kategori Menu(1-2) : ");
		system ("cls");

	}
}

void rangkingNilai(){
	char temp [100];
	int ulang;
	int counter = 0, i,j,temp2;
	FILE *nilai;
	system("cls");
	nilai = fopen("asistenin.txt", "r");
	if (nilai!=0){
		while (fgets(temp, 100, nilai)){
			counter++;
			fgets(temp, 100, nilai);
		}
		fclose(nilai);

		struct mahasiswa nilaiMahasiswa[counter];
		nilai = fopen("asistenin.txt", "r");
		for (i=0; i<counter; i++){
			fgets(temp, 100, nilai);
			temp[strcspn(temp, "\n")] = '\0';
			strcpy(nilaiMahasiswa[i].nama, temp);
			fgets(temp, 100, nilai);
			temp[strcspn(temp, "\n")] = '\0';
			nilaiMahasiswa[i].nilai = atoi(temp);
		}
		fclose(nilai);
		for (i=0; i<counter-1; i++){
			for (j=0; j<counter-1-i; j++){
				if (nilaiMahasiswa[j].nilai < nilaiMahasiswa[j+1].nilai){
					strcpy(temp, nilaiMahasiswa[j].nama);
					strcpy(nilaiMahasiswa[j].nama, nilaiMahasiswa[j+1].nama);
					strcpy(nilaiMahasiswa[j+1].nama,temp);
					temp2 = nilaiMahasiswa[j].nilai;
					nilaiMahasiswa[j].nilai = nilaiMahasiswa[j+1].nilai;
					nilaiMahasiswa[j+1].nilai = temp2;
				}
			}
		}
		nilai = fopen("asistenout.txt", "w");
		fprintf(nilai, "Nilai Mata Kuliah Algoritma dan Pemrograman\n");
		for (i=0; i<counter; i++){
			fprintf(nilai, "%d. %s %d\n", i+1, nilaiMahasiswa[i].nama, nilaiMahasiswa[i].nilai);
		}
		fclose(nilai);
		printf ("\n\t PERANKINGAN SUDAH DILAKUKAN \n");
		printf ("\t [SUKSES] CEK FILE asistenout.txt UNTUK MELIHAT \n");
	}
	else{
		fclose(nilai);
		printf ("\n\t PERANKINGAN GAGAL DILAKUKAN DILAKUKAN \n");
		printf ("\n\t [ERROR] FILE BELUM TERSEDIA, SILAHKAN INPUT DATA DAHULU\n");
	}

	system("pause");
    system("cls");


	printf ("\t---------------------------------------------------------");
	printf ("\n\t\t Apakah anda ingin kembali ke menu utama??\n");
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
		printf ("\n\t Kategori Menu Tidak Ada! Silahkan Input Ulang \n");
		cekValid(&ulang, "\n\t Silahkan Pilih Kategori Menu(1-2) : ");
		system ("cls");

	}
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
		printf("\t  *Input hanya berupa angka!!\n");
		printf("\n");
	}
}

int clean(){
while(getchar() != '\n');
return 1;
}

void keluar(){
	system("cls");
	printf ("\n\t ---------------------------------------------------------\n");
	printf ("\t                      TERIMA KASIH                    \n");
	printf ("\t ---------------------------------------------------------\n");
	system("exit");
}

