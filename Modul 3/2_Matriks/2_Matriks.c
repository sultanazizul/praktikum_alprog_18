#include<stdio.h>
#include<stdlib.h>

void matriksPenjumlahan();
void matriksPerkalian();
void matriksTranspose();
void cekValidasi(int *var, char *prompt);
int perulangan();


int main(){
	system("cls");
	int menu;

    system("cls");

	printf("\t----------------------------------------------\n"
           "\t      PROGRAM MENGHITUNG MATRIKS      \n"
           "\t----------------------------------------------\n\n");
	printf ("\t    1. Penjumlahan Matriks\n"
            "\t    2. Perkalian Matriks\n"
            "\t    3. Transpose Matriks\n\n"
            "\t----------------------------------------------\n");
    printf("\t  Pilih menu : ");

	menu=validasiMenu();
	system("cls");
	fflush(stdin);
	if (menu == 1){
		matriksPenjumlahan();
	}
	else if (menu == 2){
		matriksPerkalian();
	}
	else if (menu == 3){
		matriksTranspose();
	}
	else if (menu == 4){
		exit(0);
	}


}

void matriksPenjumlahan(){
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                MATRIKS PENJUMLAHAN                  \n");
	printf ("\t---------------------------------------------------------\n");
	int i,j,m,n,matriks1[10][10], matriks2[10][10], hasil[10][10];
	cekValidasi(&m,"\t Baris Matriks : ");
	cekValidasi(&n,"\t Kolom Matriks : ");
	fflush(stdin);
	//mengisi elemen matriks pertama
	printf ("\n\n\t---------------------------------------------------------\n");
	printf ("\t                    Masukkan Elemen Matriks 1 \n");
	printf ("\t---------------------------------------------------------\n");
	for (i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf ("\t Masukkan elemen matriks [%d][%d]. ",i,j);
			cekValidasi(&matriks1[i][j],"\t Masukkan elemen : ");
		}
	}

	//mengisi elemen matriks kedua
	printf ("\n\n\t---------------------------------------------------------\n");
	printf ("\t                   Masukkan Elemen Matriks 2 \n");
	printf ("\t---------------------------------------------------------\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			printf ("\t Masukkan elemen matriks [%d][%d]. ",i,j);
			cekValidasi(&matriks2[i][j],"\t Masukkan elemen : ");
		}
	}
	printf ("\n");
	//menampilkan elemen matriks pertama
	printf ("\n\t---------------------\n");
	printf ("\tData Matriks Ke-1\n");
	printf ("\t---------------------\n");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	    	printf("\t|");
	      	printf(" %d ", matriks1[i][j]);
	      	printf("|");
	    }
	    printf ("\n");
	}
	//menampilkan elemen matriks kedua
	printf ("\n\t---------------------\n");
	printf ("\t  Data Matriks Ke-2\n");
	printf ("\t---------------------\n");

	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	    	printf("\t|");
	        printf (" %d ", matriks2[i][j]);
	        printf("|");
	    }
	    printf ("\n");
	}
	//menampilkan hasil penjumlahan matriks 1 dan matriks 2
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                Hasil Penjumlahan Matriks               \n");
	printf ("\t---------------------------------------------------------\n");
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			hasil[i][j] = matriks1[i][j] + matriks2 [i][j];
			printf("\t|");
			printf (" %d ", hasil[i][j]);
			printf("|");
		}
		printf ("\n");
	}
	printf ("\n");
	perulangan();
}

void matriksPerkalian(){
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                   MATRIKS PERKALIAN                 \n");
	printf ("\t---------------------------------------------------------\n");
	int matriks1[10][10], matriks2[10][10], hasil[10][10];
	int i, j, k, m, n, p, q, jumlah = 0;
	cekValidasi(&m,"\t Baris Matriks 1 : ");
	cekValidasi(&n,"\t Kolom Matriks 1 : ");
	cekValidasi(&p,"\t Baris Matriks 2 : ");
	cekValidasi(&q,"\t Kolom Matriks 2 : ");
	fflush(stdin);
	printf ("\n\n\t---------------------------------------------------------\n");

	if(n != p){
	    printf("\t Matriks tidak dapat dikalikan satu sama lain.\n");
	} else {
		//mengisi elemen matriks pertama
		printf("\t              Masukkan Elemen Matriks 1 \n");
		printf ("\t---------------------------------------------------------\n");
		for(i = 0; i < m; i++){
	      for(j = 0; j < n; j++){
	      	printf ("\t Masukkan elemen matriks [%d][%d]. ",i,j);
			cekValidasi(&matriks1[i][j],"\t Masukkan elemen : ");
	      }
	    }

	    //mengisi elemen matriks kedua
	    printf ("\n\n\t---------------------------------------------------------");
	    printf("\n\t              Masukkan Elemen Matriks 2 \n");
	    printf ("\t---------------------------------------------------------\n");
	    for(i = 0; i < p; i++){
	      for(j = 0; j < q; j++){
	        printf ("\t Masukkan elemen matriks [%d][%d]. ",i,j);
			cekValidasi(&matriks2[i][j],"\t Masukkan elemen : ");
	      }
	    }
	    //menampilkan elemen matriks pertama
	   printf ("\n\t---------------------\n");
	printf ("\tData Matriks Ke-1\n");
	printf ("\t---------------------\n");
	    for(i = 0; i < m; i++){
	      for(j = 0; j < n; j++){
	      	printf("\t|");
	      	printf (" %d ", matriks1[i][j]);
	      	printf("|");
	      }
	      printf ("\n");
	    }
	    //menampilkan elemen matriks kedua
	    printf ("\n\t---------------------\n");
	printf ("\tData Matriks Ke-2\n");
	printf ("\t---------------------\n");
	    for(i = 0; i < p; i++){
	      for(j = 0; j < q; j++){
	      	printf("\t|");
	        printf (" %d ", matriks2[i][j]);
	        printf("|");
	      }
	      printf ("\n");
	    }
	    //mengalikan matriks 1 dengan matriks 2
	    for(i = 0; i < m; i++){
	      for(j = 0; j < q; j++){
	        for(k = 0; k < p; k++){
	          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
	        }
	        hasil[i][j] = jumlah;
	        jumlah = 0;
	      }
	    }
	    //menampilkan hasil perkalian matriks
	    printf ("\n\t---------------------------------------------------------\n");
		printf ("\t                Hasil Perkalian Matriks        \n");
		printf ("\t---------------------------------------------------------\n");
	    for(i = 0; i < m; i++){
	      for(j = 0; j < n; j++){
	      	printf("\t|");
	        printf(" %d ", hasil[i][j]);
	        printf("|");
	      }
	      printf("\n");
	    }
	  }
	  perulangan();
}

void matriksTranspose(){
	printf ("\n\t---------------------------------------------------------\n");
	printf ("\t                   MATRIKS TRANSPOSE                 \n");
	printf ("\t---------------------------------------------------------\n");
	int i, j, m, n;
	int matriks[10][10];
	int transpose[10][10];
	cekValidasi(&m,"\t Baris Matriks : ");
	cekValidasi(&n,"\t Kolom Matriks : ");
	fflush(stdin);
	//memasukkan elemen matriks

	printf ("\n\n\t---------------------------------------------------------\n");
	printf("\t               Masukkan elemen matriks\n");
	printf ("\t---------------------------------------------------------\n\n");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	      	printf ("Masukkan elemen matriks [%d][%d]. ",i,j);
			cekValidasi(&matriks[i][j],"Masukkan elemen: ");
		}
	}
	printf ("\n");
	printf ("\t---------------------------------------------------------\n\n");
	//menampilkan matriks
	printf("\n\tSEBELUM TRANSPOSE\n");
	for(i = 0; i < m; i++){
	    for(j = 0; j < n; j++){
	    	printf("\t|");
	      	printf (" %d ", matriks[i][j]);
	      	printf("|");
		}
		printf ("\n");
	}
	//transpose matriks
	for (i = 0; i < m; i ++){
	    for(j = 0; j < n; j++){
	    transpose[j][i] = matriks[i][j];
		}
	}
	printf ("\n");
	//menampilkan hasil transpose matriks
	printf("\n\tHASIL TRANSPOSE\n");
	for (i = 0; i < n; i ++){
		for(j = 0; j < m; j++){
		printf("\t|");
	    printf(" %d ",transpose[i][j]);
	    printf("|");
	    }
	printf("\n");
	}
	perulangan();
}

int validasiInteger(int *var){
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

int validasiMenu()
{
    int nilai;
    char check;

    if (scanf("%i%c", &nilai, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("\t  *hanya menerima inputan angka!\n\n"
               "\t  Pilih menu : ");
        return validasiMenu();
        }

    else if (nilai < 0 || nilai > 3)
        {
        printf("\t  *pilihan tidak tersedia!\n\n"
               "\t  Pilih menu : ");
        return validasiMenu();
        }
    else{
            return nilai;
        }
}


void cekValidasi(int *var, char *msg){
	while(1){
		printf(msg);
		if(validasiInteger(var))
			break;
		printf("\t *inputan hanya berupa angka!!\n\n");
		printf("\n");
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
        printf ("Silahkan pilih (y/t) saja!") ;
        printf("\n\n|============================================|\n\n");
        system ("pause");
        system ("cls");
        perulangan();
    }
    return 0;
}

