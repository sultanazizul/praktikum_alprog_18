#include <stdio.h>

void biner();
int pangkat();
int cekDesimal();
int cekBiner();
int perulangan();


int main()
{
    int bilDesimal;
    char bilBiner[16];
	char pilih;
    system("cls");
	printf("\n\n|============================================|\n"
	       "|                                            |\n"
           "|           PROGRAM KONVERSI BILANGAN        |\n"
           "|                                            |\n"
           "|============================================|\n"
           "|                                            |\n"
           "|  1. Desimal ke Biner                       |\n"
           "|                                            |\n"
           "|  2. Biner ke Desimal                       |\n"
           "|                                            |\n"
           "|  3. Keluar                                 |\n"
           "|                                            |\n"
           "|============================================|\n\n"
           "  Pilih menu yang anda inginkan: "); pilih=validasiMenu();

    switch(pilih){
        case 1:
            system("cls");
            printf("\n\n|============================================|\n");
            printf("|     Konversi Bilangan Desimal ke Biner     | \n");
            printf("|============================================|\n\n");
            printf("  Masukan angka desimal  : ");bilDesimal=validasiDesimal();

            printf("\n  Biner: "); biner(bilDesimal);
            printf("\n\n|============================================|\n\n");
            break;

        case 2:
            system("cls");
            printf("\n\n|============================================|\n");
            printf("|     Konversi Bilangan Biner ke Desimal     | \n");
            printf("|============================================|\n\n");

            printf("  Masukan angka biner : "); scanf("%s",bilBiner);
            if(cekBiner(bilBiner,&bilDesimal) != 0) {
            printf("  *Hanya Menerima bilangan biner (0 dan 1)\n\n");
            }

            printf("\n  Desimal: %d",bilDesimal);
            printf("\n\n|============================================|\n\n");
            break;

        case 3:
            system("cls");
            exit (0);
            break;

    }
    system("pause");
    system("cls");
    perulangan();

    return 0;
}


void biner(int bil_desimal)
{
    if (bil_desimal > 0) {
        biner(bil_desimal /2);
        printf("%d",bil_desimal%2);
    }
}

int pangkat(int n,int x)
{
    int nilai=1,i;
    for (i=0;i<x;i++) {
        nilai=nilai*n;
    }
    return nilai;
}


int cekBiner(char bil_biner[],int *bil_desimal)
{
    int i, bilDesimal = 0;

    for (i = 0; i < strlen(bil_biner); i++)
    {
        if ((bil_biner[i] - '0' != 1 ) && (bil_biner[i] - '0' != 0))
        {
            return 1;
        }
    }

    for (i =0; i <  strlen(bil_biner) ; i++)
    {
        if (bil_biner[i] - '0' == 1) {
            bilDesimal = bilDesimal + pangkat(2,strlen(bil_biner)-1-i);
        }
    }
    *bil_desimal = bilDesimal;
    return 0;
}



int validasiMenu()
{
    int pilihan;
    char check;

    if (scanf("%i%c", &pilihan, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("  *hanya menerima inputan angka!\n\n"
               "  Pilih menu yang anda inginkan : ");
        return validasiMenu();
        }

    else if (pilihan < 0 || pilihan > 3)
        {
        printf("  *pilihan tidak tersedia!\n\n"
               "  Pilih menu yang anda inginkan : ");
        return validasiMenu();
        }
}

int validasiDesimal()
{
    int desimal;
    char check;

    if (scanf("%i%c", &desimal, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("  *hanya menerima inputan angka!\n\n"
               "  Masukan angka desimal  : ");
        return validasiDesimal();
        }

    else if (desimal < 0)
        {
        printf("  *tidak menerima bilangan negatif!\n\n"
               "  Masukan angka desimal  : ");
        return validasiDesimal();
        }
}



int perulangan()
{
    char pilihan[2] ;
    printf("\n|============================================|\n\n");
    printf ("  Apakah anda ingin menghitung kembali? (y/t): ") ;
    printf("\n\n|============================================|\n");
    printf ("\n  pilih : ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if ((strcmp(pilihan, "t")==0) || (strcmp(pilihan, "T")==0))
    {
        printf("\n|============================================|\n\n");
        printf ("  Terima Kasih Telah Menggunakan Program ini") ;
        printf("\n\n|============================================|\n");
    }
    else
    {
        printf("\n|============================================|\n\n");
        printf ("\tSilahkan pilih (y/t) saja!") ;
        printf("\n\n|============================================|\n");
        system ("pause");
        system ("cls");
        perulangan();
    }
    return 0;
}

int validasi4(){
    int bilangan;
    char ch;

	printf("\n\t\t\t\t  Masukan angka: ");
    scanf("%d%c", &bilangan, &ch);

    if(ch != '\n' || bilangan < 0){
    	printf("\t\t\t\t|-------------------------------------------------------------|\n");
        printf("\n\t\t\t\t  Input yang dimasukkan tidak berupa angka!\n", bilangan, ch);
        printf("\t\t\t\t  Silahkan Input Ulang\n");
        printf("\t\t\t\t|-------------------------------------------------------------|\n");

        fflush(stdin);
        validasi4();

    }else if(ch != '\n' || bilangan > 1){
    	printf("\t\t\t\t|-------------------------------------------------------------|\n");
        printf("\n\t\t\t\t  Input yang dimasukkan tidak berupa angka!\n", bilangan, ch);
        printf("\t\t\t\t  Silahkan Input Ulang\n");
        printf("\t\t\t\t|-------------------------------------------------------------|\n");

        fflush(stdin);
        validasi4();

    }else{
        return bilangan;
    }
}

