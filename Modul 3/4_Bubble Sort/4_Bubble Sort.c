#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>

#define NILAI1 1000
#define NILAI2 16000
#define NILAI3 64000


clock_t mulai, berakhir;
int data1[NILAI3], data2[NILAI3];

void setmulai(void);
void membuatDataAcak(int *data, int pilih);
void printData(int *arr, int banyak);
void bubbleSort(int banyak);
void bubbleSortPointer(int *ptr, int banyak);
void menu();
int perulangan();
int setdata();
int validasi();
double setberakhir(void);


int main(){
	menu();

	return(0);
}
void menu(){
	int pilih;
	double time1, time2;

    pilih = setdata();
    membuatDataAcak(data1, pilih);
    membuatDataAcak(data2, pilih);
    sleep(1);
    printf("\n\n\tMemulai Mengacak Data . . .");
    sleep(1);
    printf("\n\n");
	printData(data1, pilih);
	sleep(1);
    printf("\n\n\tMulai Proses Bubble Sort . . .");
    sleep(1);
    printf("\n\n");

    //bubble sort tanpa pointer
    setmulai();
    bubbleSort(pilih);
    time1 = setberakhir();

    //bubble sort dengan pointer
    setmulai();
    bubbleSortPointer(data2,pilih);
    time2 = setberakhir();
    printData(data2, pilih);

    sleep(1);
    printf("\n\tWaktu proses Bubble Sort tanpa pointer	: %lf detik\n", time1);
    printf("\n\tWaktu proses Bubble Sort dengan pointer	: %lf detik\n", time2);
    sleep(1);

    system("pause");
    system("cls");
    perulangan();

    getch();
}
void bubbleSortPointer(int *ptr, int banyak){
	int i,j;
	int temp;
	for(i = 1 ; i < banyak ; i++){
  		for(j = 0; j < banyak - i ; j++){
   			if(*(ptr+j)>*(ptr+j+1)){
    			temp=*(ptr+j);
    			*(ptr+j)=*(ptr+j+1);
    			*(ptr+j+1)=temp;
       		}
  		}
 	}
}

void bubbleSort(int banyak){
    int i, j, tmp;
    for (i = banyak - 1 ; i >= 0 ; i--){
        for (j = 0 ; j < i ; j++){
            if (data1[j] > data1[j + 1]){
                tmp = data1[j];
                data1[j] = data1[j + 1];
                data1[j + 1] = tmp;
            }
        }
    }
}

//penghitung mulai
void setmulai(void){
    mulai = clock();
}

//penghitung waktu selesai
double setberakhir(void){
    berakhir = clock();
    return ((double)berakhir - mulai) / CLOCKS_PER_SEC;
}

//membuat data acak
void membuatDataAcak(int *data, int pilih){
    int i;
    time_t t;

    srand((unsigned)time(&t));
    for (i = 0; i < pilih; i++){
        data[i] = rand() % pilih;
    }
}

//menampilkan data
void printData(int *arr, int banyak){
    int i;
    for (i = 0; i < banyak; i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");
}






int setdata(){
    int pilihan;
    system("cls");
	fflush(stdin);
	printf("\t----------------------------------------------\n");
    printf("\t         PROGRAM PENGURUTAN BUBBLE \n");
    printf("\t----------------------------------------------\n\n");
	printf("\t            Pilihan Banyak Data  :\n\n");
    printf("\t       1.  1000  Bilangan Acak\n");
    printf("\t       2.  16000 Bilangan Acak\n");
    printf("\t       3.  64000 Bilangan Acak\n\n");
    printf("\t----------------------------------------------\n");
    printf("\t    Masukan Pilihan Data : "); pilihan=validasi();

    switch (pilihan){
    case 1:
        return NILAI1;
        break;
    case 2:
        return NILAI2;
        break;
    case 3:
    	return NILAI3;
        break;

        getch();
        setdata();
    }
    return 0;
}


int validasi()
{
    int nilai;
    char check;

    if (scanf("%i%c", &nilai, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("\t    *hanya menerima inputan angka!\n\n");
        printf("\t    Masukan Pilihan Data : ");
        return validasi();
        }

    else if (nilai < 0 || nilai > 3)
        {
        printf("\t    *pilihan tidak tersedia!\n\n");
        printf("\t    Masukan Pilihan Data : ");
        return validasi();
        }
    else{
            return nilai;
        }
}


int perulangan()
{
    char pilihan[2] ;
    printf("\n\n|============================================|\n\n");
    printf (" Apakah anda ingin menghitung kembali? (y/t): ") ;
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



