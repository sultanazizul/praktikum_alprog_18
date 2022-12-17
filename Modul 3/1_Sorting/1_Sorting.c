#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void cekValid(int *var, char *msg);
void insertionSort(int array[], int n);
void bubbleSort(int array[], int n);
void quickSort(int array[], int low, int high);
double sequentialSearch(int array[], int n, int cari_angka);
double binarySearch(int array[], int low, int high, int cari_angka);
int pivot(int array[], int low, int high);
int perulangan();
void sorting();
void searching();
void salinArray(int asal[], int target[], int n);
void cetakArray(int arr[], int n);
void bilanganAcak(int arr[], int n);
void keluar();

int main(){
	system ("cls");
	int menu;
	printf ("---------------------------------------------------------\n");
	printf ("                        MENU                   \n");
	printf ("---------------------------------------------------------\n");
	printf ("1.   SORTING                                 \n");
	printf ("2.   SEARCHING                               \n");
	printf ("3.   KELUAR                                  \n");
	printf ("---------------------------------------------------------\n");
	cekValid(&menu, " Pilih Menu(1-3) : ");

	if (menu==1){
		sorting();
	}
	else if (menu==2){
		searching();
	}
	else if (menu==3){
		keluar();
	}
	else{
		printf ("\n *Kategori Menu Tidak Ada! [ENTER UNTUK MENGULANG] \n\n");
		system ("pause");
		system ("cls");
		main();
	}
}

//MENU SORTING
void sorting(){
	clock_t mulai, berakhir;
	double waktu1; //untuk waktu perhitungan insertion sort
	double waktu2; //untuk waktu perhitungan bubble sort
	double waktu3; //untuk waktu perhitungan quick sort
	int data;

	int menu2;
	system("cls");
	printf ("---------------------------------------------------------\n");
	printf ("                     PILIHAN DATA                        \n");
	printf ("---------------------------------------------------------\n");
	printf ("1.   1000 DATA                               \n");
	printf ("2.   16000 DATA                               \n");
	printf ("3.   64000 DATA                              \n");
	printf ("4.   KELUAR                                  \n");
	printf ("---------------------------------------------------------\n");
	cekValid(&menu2, " Masukkan Pilihan Data(1-4) : ");

	if (menu2==1){
		data = 1000;
	}
	else if (menu2==2){
		data = 16000;
	}
	else if (menu2==3){
		data = 64000;
	}
	else if (menu2==4){
		keluar();
	}
	else {
		printf ("\n *Pilihan Data Tidak Ada! [ENTER UNTUK MENGULANG] \n\n");
		system ("pause");
		system ("cls");
		sorting();
	}

	int arr1[data];
	int arr2[data];
	int arr3[data];
	//Mencetak Bilangan Random
	bilanganAcak(arr1, data);
	printf("\n");
	printf ("---------------------------------------------------------\n");
	printf (" Array [%d] Random Sebelum di Sorting\n", data);
	cetakArray(arr1, data);
	salinArray(arr1, arr2, data);
	salinArray(arr1, arr3, data);

	//penghitungan waktu insertionSort
	mulai = clock();
	insertionSort(arr1, data);
	berakhir = clock();
	waktu1 = (double)(berakhir-mulai) / CLOCKS_PER_SEC;

	//penghitungan waktu bubbleSort
	mulai = clock();
	bubbleSort(arr2, data);
	berakhir = clock();
	waktu2 = (double)(berakhir-mulai) / CLOCKS_PER_SEC;
	//penghitungan waktu quickSort
	mulai = clock();
	quickSort(arr3, 0, data-1);
	waktu3 = (double)(berakhir-mulai) / CLOCKS_PER_SEC;

	//Mencetak Bilangan Setelah di Sorting
	printf("\n");
	printf ("---------------------------------------------------------\n");
	printf ("  [%d] Angka Setelah di Sorting\n", data);
	sleep(3);
	cetakArray(arr1, data);

	//Waktu Yang Dibutuhkan
	printf("\n");
	printf ("\n---------------------------------------------------------\n");
	printf ("               HASIL WAKTU PERHITUNGAN               \n");
	printf ("---------------------------------------------------------\n");
	printf ("Waktu Perhitungan [INSERTION SORT] = %f Millisecond", waktu1);
	printf ("\nWaktu Perhitungan [BUBBLE SORT] = %f Millisecond", waktu2);
	printf ("\nWaktu Perhitungan [QUICK SORT] = %f Millisecond", waktu3);

	//Melakukan Perbandingan
	if (waktu1 == waktu2 && waktu1 == waktu3){
		printf ("\n---------------------------------------------------------\n");
		printf ("              WAKTU PERHITUNGAN SETARA               \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu1 == waktu2){
		printf ("\n---------------------------------------------------------\n");
		printf ("  WAKTU PERHITUNGAN INSERTION & BUBBLE SORT SETARA   \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu1 == waktu3){
		printf ("\n---------------------------------------------------------\n");
		printf ("   WAKTU PERHITUNGAN INSERTION & QUICK SORT SETARA   \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu2 == waktu3){
		printf ("\n---------------------------------------------------------\n");
		printf ("    WAKTU PERHITUNGAN BUBBLE & QUICK SORT SETARA     \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu1 <= waktu2 && waktu1 <= waktu3){
		printf ("\n---------------------------------------------------------\n");
		printf ("    WAKTU PERHITUNGAN INSERTION SORT PALING CEPAT    \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu2 <= waktu1 && waktu2 <= waktu3){
		printf ("\n---------------------------------------------------------\n");
		printf ("      WAKTU PERHITUNGAN BUBBLE SORT PALING CEPAT     \n");
		printf ("---------------------------------------------------------\n");
	}
	else if (waktu3 <= waktu1 && waktu3 <= waktu2){
		printf ("\n---------------------------------------------------------\n");
		printf ("       WAKTU PERHITUNGAN QUICK SORT PALING CEPAT     \n");
		printf ("---------------------------------------------------------\n");
	}
	perulangan();

}

void searching(){
	clock_t mulai, berakhir;
	double waktu1;
	double waktu2;
	int data, menu3, cari_angka;

	system("cls");
	printf ("---------------------------------------------------------\n");
	printf ("                      PILIHAN DATA                       \n");
	printf ("---------------------------------------------------------\n");
	printf ("1.   1000 DATA                                \n");
	printf ("2.   16000 DATA                              \n");
	printf ("3.   64000 DATA                               \n");
	printf ("4.   KELUAR                                  \n");
	printf ("---------------------------------------------------------\n");
	cekValid(&menu3, " Masukkan Pilihan Data(1-4) : ");
	if (menu3==1){
		data = 1000;
	}
	else if (menu3==2){
		data = 16000;
	}
	else if (menu3==3){
		data = 64000;
	}
	else if (menu3==4){
		keluar();
	}
	else {
		printf ("\n *Pilihan Data Tidak Ada! [ENTER UNTUK MENGULANG] \n");
		system ("pause");
		system ("cls");
		searching();
	}

	int arr[data];
	int arr2[data];
	bilanganAcak(arr, data);
	cekValid(&cari_angka, " Silahkan Inputkan Angka Yang Ingin Dicari : ");
	input_angka:
		if (cari_angka < 0){
			printf (" *input Salah! Hanya Menerima Inputan Angka Positif");
			goto input_angka;
		}
		insertionSort(arr, data);
		waktu1 = sequentialSearch(arr, data, cari_angka);
		waktu2 = binarySearch(arr, 0, data-1, cari_angka);
		printf("\n");
		printf ("\n---------------------------------------------------------\n");
		printf ( "            HASIL WAKTU PERHITUNGAN               \n");
		printf ("---------------------------------------------------------\n");
		printf (" Waktu Perhitungan [SEQUENTIAL SEARCH] = %f Millisecond", waktu1);
		printf ("\n Waktu Perhitungan [BINARY SEARCH] = %f Millisecond", waktu2);

		if (waktu1 < waktu2){
			printf ("\n---------------------------------------------------------\n");
			printf ("     WAKTU PERHITUNGAN SEQUENTIAL SEARCH TERCEPAT    \n");
			printf ("---------------------------------------------------------\n");
		}
		else if (waktu1 > waktu2){
			printf ("\n---------------------------------------------------------\n");
			printf ("       WAKTU PERHITUNGAN BINARY SEARCH TERCEPAT      \n");
			printf ("---------------------------------------------------------\n");
		}
		else if (waktu1 == waktu2){
			printf ("\n---------------------------------------------------------\n");
			printf ("               WAKTU PERHITUNGAN SETARA              \n");
			printf ("---------------------------------------------------------\n");
		}
		perulangan();
}

void cetakArray(int arr[], int n){
	int i;
	for (i = 0; i < n; i++){
		printf("\n Angka Ke-[%d] = [%d]", i + 1, arr[i]);
	}
}

void salinArray(int asal[], int target[], int n){
	int i;
	for (i = 0; i < n; i++)
	target[i]=asal[i];
}

void insertionSort(int array[], int n){
	int i;
	int j;
	int key;
	for ( i =1; i < n; i++){
		key = array[i];
		j= i-1;
	while (j >= 0 && array[j] > key){
		array[j+1] = array[j];
		j--;
	}
	array[j+1] = key;
	}
}

void bubbleSort(int array[], int n){
	int i;
	int j;
	int temp;
	for (i =0; i < n - 1; i++){
		for (j =0; j < n - i - 1; j++){
			if (array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j + 1] = temp;
			}
		}
	}
}

void quickSort(int array[], int low, int high){
	int p = pivot(array, low, high);
	if (low < high){
		quickSort(array, low, p-1);
		quickSort(array, p+1, high);
	}
}

double sequentialSearch(int array[], int n, int cari_angka){
	clock_t mulai, berakhir;
	double waktu;
	int i;
	int counter = 0;
	mulai = clock();
	for (i =0; i < n; i++){
		if (array[i] == cari_angka){
			counter++;
		}
		printf("||Angka Ke-[%d] = [%d]", i+1, array[i]);
		printf("\n");
	}
	berakhir = clock();
	waktu = (double)(berakhir-mulai) / CLOCKS_PER_SEC;
	if (counter == 0){
		printf ("\n---------------------------------------------------------\n");
		printf ("          MENCARI DENGAN METODE SEQUENTIAL SEARCH      \n");
		printf (" ANGKA [%d] TIDAK DITEMUKAN DALAM ARRAY\n", cari_angka);
		printf ("---------------------------------------------------------\n");
	}
	else{
		int indexCariAngka[counter];
		counter = 0;
		for (i = 0; i < n; i++){
			if (array[i] == cari_angka){
				indexCariAngka[counter] = i;
				counter++;
			}
		}
		printf ("\n---------------------------------------------------------\n");
		printf ("        MENCARI DENGAN METODE SEQUENTIAL SEARCH      \n");
		printf (" ANGKA DITEMUKAN DALAM INDEXS KE-");
		for (i = 0; i < counter; i++){
			if (i == 0 && i == counter - 1){
				printf ("[%d]", indexCariAngka[i]);
			}
			else{
				if (i == counter - 1){
					printf ("dan [%d]", indexCariAngka[i]);
				}
				else{
					printf ("[%d]", indexCariAngka[i]);
				}
				}
				}
				printf ("\n---------------------------------------------------------\n");
			}
			return waktu;
		}

//binarySearch
double binarySearch(int array[], int low, int high, int cari_angka){
	clock_t mulai, berakhir;
	double waktu;
	int i;
	int counter = 0;
	mulai = clock();
	while( low <= high){
		int tengah = low + (high-low) / 2;
		if (array[tengah] == cari_angka){
			counter++;
			for ( i = tengah + 1; i < high + 1 && array[i] == cari_angka; i++){
				counter++;
			}
			for ( i = tengah - 1; i < high + 1 && array[i] == cari_angka; i++){
				counter++;
			}
			break;
		}
		else if (array[tengah] > cari_angka){
			high = tengah - 1;
		}
		else{
			low = tengah + 1;
		}
	}
	berakhir=clock();
	waktu = (double)(berakhir-mulai) / CLOCKS_PER_SEC;
	if (counter == 0){
		printf ("\n---------------------------------------------------------\n");
		printf ("          MENCARI DENGAN METODE BINARY SEARCH        \n");
		printf (" ANGKA [%d] TIDAK DITEMUKAN DALAM ARRAY\n", cari_angka);
		printf ("---------------------------------------------------------\n");
	}
	else{
		int indexCariAngka[counter];
		counter = 0;
		while( low <= high){
			int tengah = low + (high - low) /2;
			if (array[tengah] == cari_angka){
				indexCariAngka[counter] = tengah;
				counter++;
				for ( i = tengah + 1; i < high + 1 && array[i] == cari_angka; i++){
					indexCariAngka[counter] = i;
					counter++;
				}
				for (i = tengah - 1; i > 0 && array[i] == cari_angka; i--){
					indexCariAngka[counter] = i;
					counter++;
				}
				break;
			}
			else if (array[tengah] > cari_angka){
				high = tengah - 1;
			}
			else{
				low = tengah + 1;
			}
		}
		printf ("\n---------------------------------------------------------\n");
		printf ("        MENCARI DENGAN METODE BINARY SEARCH          ||\n");
		printf (" ANGKA DITEMUKAN DALAM INDEXS KE-");
		insertionSort(indexCariAngka, counter);
		for (i = 0; i < counter; i++){
			if (i == 0 && i == counter - 1){
				printf ("[%d]", indexCariAngka[i]);
			}
			else{
				if (i == counter - 1){
					printf ("dan [%d]", indexCariAngka[i]);
				}
				else{
					printf ("[%d]", indexCariAngka[i]);
				}
				}
		}
		printf ("\n---------------------------------------------------------\n");
	}
	return waktu;
}

int pivot(int array[], int low, int high){
	int p = array[high];
	int temp;
	int i = (low - 1);
	int j;
	for (j = low; j <= high - 1; j++){
		if (array[j] <= p){
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i+1];
	array[i+1]= array[high];
	array[high]=temp;
	return (i+1);
}

void bilanganAcak(int arr[], int n){
	int i;
	srand(0);
	for (i = 0; i < n; i++){
		arr[i] = rand();
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
		printf(" *Input hanya berupa angka!!\n");
		printf("\n");
	}
}


void keluar(){
	system("cls");
	printf ("\n---------------------------------------------------------\n");
	printf ("                      TERIMA KASIH                     \n");
	printf ("---------------------------------------------------------\n");
	system("exit");
}


int perulangan()
{
    system("pause");
    system("cls");
    char pilihan[2] ;
    printf("\n\n|============================================|\n\n");
    printf (" Apakah anda ingin menghitung kembali?(y/t): ") ;
    printf("\n\n|============================================|\n");
    printf ("\n pilih : ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if ((strcmp(pilihan, "t")==0) || (strcmp(pilihan, "T")==0))
    {
        printf("\n\n|============================================|\n\n");
        printf ("  Terima Kasih Telah Menggunakan Program ini") ;
        printf("\n\n|============================================|\n\n");
    }
    else
    {
        printf("\n\n|============================================|\n\n");
        printf ("\tSilahkan pilih (y/t) saja!") ;
        printf("\n\n|============================================|\n\n");
        system ("pause");
        system ("cls");
        perulangan();
    }
    return 0;
}

