#include<stdio.h>
#include <stdlib.h>
#include <conio.h>

int perulangan();
void enkripsi();
void deskripsi();
int validInt(int *var);
void keluar();

char kata [100], temp;
int menu, geser, i;

int main(){
    printf("\t----------------------------------------------\n"
           "\t      PROGRAM MENGHITUNG GAJI KARYAWAN       \n"
           "\t----------------------------------------------\n\n"
           "\t     1.   Enkripsi \n"
           "\t     2.   Deskripsi \n"
           "\t     3.   Keluar     \n\n"
           "\t----------------------------------------------\n");
 	printf("\t Masukkan Pilihan Menu : "); menu=validasi();

  	switch (menu){
  		case 1 :
  			enkripsi();
			break;
		case 2 :
			deskripsi();
			break;
		case 3:
			system ("cls");
		 	keluar ();
    		break;
    	default:
			system ("cls");
			main();
	}
	return 0;
}

void enkripsi(){
	system ("cls");
	printf("\t----------------------------------------------\n");
	printf("\t                  Enkripsi\n");
	printf("\t----------------------------------------------\n\n");
	fflush(stdin);
	printf("\t Jumlah Pergeseran : "); geser=validasi();
	printf("\n\t Plaintext         : "); 	gets(kata);
	printf("\n\t----------------------------------------------\n");
	for(i = 0; kata[i] != '\0'; ++i){
		temp = kata[i];
		if(temp >= 'a' && temp <= 'z'){
			temp = temp + geser;
			if(temp > 'z'){
			temp = temp - 'z' + 'a' - 1;
			}
			kata[i] = temp;
		}
		else if(temp >= 'A' && temp <= 'Z'){
			temp = temp + geser;
			if(temp > 'Z'){
			temp = temp - 'Z' + 'A' - 1;
			}
			kata[i] = temp;
		}
	}
	printf("\n\t Hasil Enkripsi : %s \n\n",kata);
	printf("\t----------------------------------------------\n");
	system("pause");
	perulangan();
}

void deskripsi(){
	system ("cls");
	printf("\t----------------------------------------------\n");
	printf("\t                 Deskripsi\n");
	printf("\t----------------------------------------------\n\n");
	fflush(stdin);
    printf("\t Jumlah Pergeseran: "); geser=validasi();
	printf("\n\t Ciphertext           : "); gets(kata);
	printf("\n\t----------------------------------------------\n");


	for(i = 0; kata[i] != '\0'; ++i){
		temp = kata[i];
		if(temp >= 'a' && temp <= 'z'){
			temp = temp - geser;
			printf("%c", 'a' - 4);
			if(temp < 'a'){
				temp = temp + 'z' - 'a' + 1;
			}
			kata[i] = temp;
		}
		else if(temp >= 'A' && temp <= 'Z'){
			temp = temp - geser;
			if(temp < 'A'){
				temp = temp + 'Z' - 'A' + 1;
			}
		kata[i] = temp;
		}

	}
	printf("\n Hasil Deskripsi\t: %s \n\n",kata);
	printf("\t----------------------------------------------\n");
	system("pause");
	perulangan();
}


int validasi()
{
    int angka;
    char huruf;

    scanf("%i%c", &angka,&huruf);
    if(huruf != '\n'){
        printf("\t *hanya menerima inputan angka!\n\n");
        printf("\t Masukkan Nilai Yang Benar     = ");
        fflush(stdin);
        validasi();

    }else if (angka < 1){
        printf("\t *tidak menerima  bilangan negatif!\n\n");
        printf("\t Masukkan Nilai Yang Benar     = ");
        fflush(stdin);
        validasi();

    }else{
        return angka;
    }
}

int perulangan()
{
    system("pause");
    system("cls");
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


int validInt(int *var)
{
	char buff[1024];
	char check;

	if (fgets(buff, sizeof(buff), stdin) != NULL) {
		if (sscanf(buff, "%d %c", var, &check) ==1){
			return 1;
		}
	}
	return 0;
}

void keluar(){

	system("cls");
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                     TERIMA KASIH                    \n");
	printf ("\t---------------------------------------------------------\n");
	exit (0);

}





