#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char data [200];

typedef struct{

	data nama;
	data nim;

} mahasiswa;

void cekValid(int *var, char *msg);
void inputData(mahasiswa mhs);
void cariData(mahasiswa mhs);
void lihatData(mahasiswa mhs);
void perulangan();
void keluar();

int main(){
	int menu;
	mahasiswa mhs;
	system("cls");

	printf ("\t---------------------------------------------------------\n");
	printf ("\t            PROGRAM SISTEM INFORMASI MAHASISWA            \n");
	printf ("\t---------------------------------------------------------\n");
	printf ("\t   1.  INPUT DATA                               \n");
	printf ("\t   2.  CARI DATA                                \n");
	printf ("\t   3.  LIHAT DATA                               \n");
	printf ("\t   4.  KELUAR                                   \n");
	printf ("\t---------------------------------------------------------\n");
	cekValid(&menu, "\t Pilih Menu(1-4) : ");

	if (menu==1){
		inputData(mhs);
	}
	else if (menu==2){
		cariData(mhs);
	}
	else if (menu==3){
		lihatData(mhs);
	}
	else if (menu==4){
		keluar();
	}
	else{
		printf ("\n\t *Kategori Menu Tidak Ada! [ENTER UNTUK MENGULANG] \n");
		system ("pause");
		system ("cls");
		main();
	}

}

int get_size(const char *file_name){
	FILE *file = fopen(file_name, "r");
	if (file == NULL)
	return 0;
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fclose(file);
	return size;

}

void inputData(mahasiswa mhs){
	int abjad=0, panjang, digit=0, riwayat=0, i;
	int pilihan;
	data noId,nama;
	//inisialisasi data
	const char *data_nim = "";
	const char *data_id = "";
	const char *data_nama = "";

	system("cls");
	printf ("\t---------------------------------------------------------\n");
	printf ("\t                 INPUT DATA MAHASISWA              \n");
	printf ("\t---------------------------------------------------------\n\n");
	printf ("\t Input NIM Anda : ");
	if (fgets(mhs.nim, sizeof(mhs.nim), stdin) != NULL){
		char *ptr = strchr(mhs.nim, '\n');
		if (ptr){
			*ptr = '\0';
		}
	}
	panjang= strlen(mhs.nim);
	//validasi nim hanya angka
	for (i = 0; i < panjang; i++){
	//cek abjad
	if (isalpha(mhs.nim[i]) != 0) abjad++;
	}
	if (abjad >0){
		printf("\t *NIM Tidak Boleh Mengandung Huruf!\n\n");
		cekValid(&pilihan, "\t Input NIM Anda : ");
		inputData(mhs);
	}
	fflush(stdin);

	// validasi nim minimal 2 angka
	if (panjang <= 1){
		printf("\t *NIM Tidak Kurang Dari Dua Angka!\n\n");
		cekValid(&pilihan, "\t Input NIM Anda :");
		inputData(mhs);
	}

	//validasi nim tidak boleh ada spasi
	else{
		if (strchr(mhs.nim, ' ')){
		printf("\t *NIM Tidak Boleh Mengandung Spasi!\n\n");
		cekValid(&pilihan, "\t Input NIM Anda : ");
		inputData(mhs);
		}
	}
	fflush(stdin);

	printf ("\t Input Nama Anda : ");
	gets(mhs.nama);
	panjang= strlen(mhs.nama);
	for (i = 0; i < panjang; i++){

	if (isdigit(mhs.nama[i]) !=0) digit++;
	}

	if (digit >0){
		printf("\t *Nama Tidak Boleh Mengandung Angka!\n\n");
		cekValid(&pilihan, "\t Tekan Angka Untuk Input Ulang : ");
		inputData(mhs);
	}
	fflush(stdin);


	if (panjang <=2){
		printf("\t *Nama Tidak Kurang Dari Tiga Huruf!\n\n");
		cekValid(&pilihan, "\t Tekan Angka Untuk Input Ulang : ");
		inputData(mhs);
	}
	fflush(stdin);
	printf ("\n\t---------------------------------------------------------\n\n");
	FILE *out = fopen("dataMahasiswa.txt", "r");
	riwayat=0;
	if (!out){
	printf("\t [DATA BELUM ADA]\n");
	}
	else{
		if (get_size("dataMahasiswa.txt")==0){
			riwayat=0;
		}
		else{
			while (!feof(out)){
			fflush(stdin);
			fscanf(out, "%s # %[^#] #\n", &noId, &nama);
			const char *data_nim = mhs.nim;
			const char *data_id = noId;
			if (strcmp(data_nim, data_id) == 0){
				riwayat = riwayat +1;
			}
			}
		}
		fclose(out);
	}
	if (riwayat >0){
		printf("\t [DATA SUDAH ADA PADA FILE]\n");
		riwayat = 0;
		system("pause");
        system("cls");
		perulangan();
	}
	else{
		printf("\t [INPUT DATA BERHASIL]\n");
		FILE *in = fopen("dataMahasiswa.txt", "a");
		const char *data_nim = mhs.nim;
		const char *data_nama = mhs.nama;
		fprintf(in, "%s # %s # \n", data_nim, data_nama);
		fclose(in);
		system("pause");
        system("cls");
		perulangan();
	}

}

void cariData(mahasiswa mhs){
	system("cls");
	int riwayat;
	data data_cari;

	printf ("\t---------------------------------------------------------\n");
	printf ("\t               CARI DATA MAHASISWA              \n");
	printf ("\t---------------------------------------------------------\n\n");
	printf ("\t Masukkan NIM: ");
	scanf ("%s", data_cari);
	fflush(stdin);
	printf ("\n\t---------------------------------------------------------\n\n");
	FILE *cari = fopen("dataMahasiswa.txt", "r");
	riwayat = 0;

	if (data_cari == NULL){//akan berjalan ketika file txt tidak ada
		printf("\t [DATA TIDAK ADA / FILE TXT TIDAK ADA]\n");
	}
	else{
		while (!feof(cari)){
			fflush(stdin);
			fscanf (cari, "%s # %[^#] #\n", &mhs.nim, mhs.nama);
			if (strcmp(mhs.nim, data_cari) == 0){
				printf("\t\t [DATA BERHASIL DITEMUKAN]\n");
				printf("\t NIM	:%s\n", mhs.nim);
				printf("\t NAMA	:%s\n", mhs.nama);
				printf ("\n\t---------------------------------------------------------\n");
				riwayat = riwayat + 1;
			}
		}
		fclose(cari);
		if (riwayat == 0){
			printf("\t [DATA MAHASISWA TIDAK DITEMUKAN DALAM FILE ]\n");
			printf ("\n\t---------------------------------------------------------\n");
		}
		riwayat = 0;
	}
	system("pause");
	system("cls");
	perulangan();


}


void lihatData(mahasiswa mhs){
	int nomor =1;
	system("cls");
	int ulang;

	printf ("\t---------------------------------------------------------\n");
	printf ("\t                    DATA MAHASISWA                   \n");
	printf ("\t---------------------------------------------------------\n");

	FILE *lihat = fopen("dataMahasiswa.txt", "r");
	if (lihat == NULL){
		printf("\t [DATA BELUM ADA]\n");
	}
	else {
		while (!feof(lihat)){
			fflush(stdin);
			fscanf (lihat, "%s # %[^#] #\n", &mhs.nim, &mhs.nama);
			printf("\t [%d] NIM : %s\n", nomor, mhs.nim);
			nomor++;
			printf("\t NAMA : %s\n", mhs.nama);
			printf ("\t---------------------------------------------------------\n");
		}
		fclose(lihat);
		system("pause");
        system("cls");
		perulangan();
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
		printf("\t *Input hanya berupa angka!\n");
		printf("\n");
	}
}

void perulangan (){
	int ulang;
	pilihan:
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

