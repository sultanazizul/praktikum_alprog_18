#include <stdio.h>
#include <stdlib.h>
int perulangan();
int validasiMenu();
int validasiHanoi();


int main()
{
     int menu;

     printf("|============================================|\n");
     printf("|                                            |\n");
     printf("|              PROGRAM MENARA HANOI          |\n");
     printf("|                                            |\n");
     printf("|============================================|\n");
     printf("|                                            |\n");
     printf("|            1.   Hanoi Rekursif             |\n");
     printf("|            2.   Hanoi Iteratif             |\n");
     printf("|            3.   Keluar                     |\n");
     printf("|                                            |\n");
     printf("|============================================|\n\n");
     printf("  Pilih menu yang anda inginkan : ");
     menu=validasiMenu();
     system("cls");

     if (menu==1) { rekursifHanoi('A', 'B', 'C'); }
     else if (menu==2) { iteratifHanoi('A', 'B', 'C'); }
     else if (menu==3){ exit(0); }

     system("pause");
     system("cls");
     perulangan();

 return 0;
}

void rekursifHanoi(char tiangA, char tiangB, char tiangC)
{
     int cakram, langkah;

     printf("|============================================|\n");
     printf("|                                            |\n");
     printf("|             PROGRAM HANOI REKURSIF         |\n");
     printf("|                                            |\n");
     printf("|============================================|\n\n");
     printf("  Masukkan jumlah cakram yang diinginkan : ");
     cakram=validasiHanoi();
     system("cls");

     langkah=(1<<cakram)-1;

     printf("\n|===========================================================|\n");
     printf("|                                                           |\n");
     printf("| Langkah minimum untuk memindahkan %d cakram yaitu : %d      |\n", cakram, langkah);
     printf("|                                                           |\n");
     printf("|===========================================================|\n");
     printf("|            Langkah-langkah pemindahan cakram :            |\n");
     printf("|===========================================================|\n");
     printf("|                                                           |\n");
     hitungHanoi(cakram, 'A', 'B', 'C');
     printf("|                                                           |\n");
     printf("|===========================================================|\n\n");

}

hitungHanoi(int cakram, int tiangA,int tiangB,int tiangC)
{
     if (cakram==1){
        printf("|   Pindahkan cakram paling atas dari tiang %c ke tiang %c    |\n", tiangA, tiangC);
     } else {
        hitungHanoi(cakram-1,tiangA,tiangC, tiangB);
        hitungHanoi(1,tiangA,tiangB,tiangC);
        hitungHanoi(cakram-1,tiangB,tiangA,tiangC);
     }
}


void iteratifHanoi(char tiangA, char tiangB, char tiangC)
{
     int cakram, i, langkah;
     char tiang[3];
     tiang[0]=tiangA;
     tiang[1]=tiangB;
     tiang[2]=tiangC;

     printf("|============================================|\n");
     printf("|                                            |\n");
     printf("|             PROGRAM HANOI ITERATIF         |\n");
     printf("|                                            |\n");
     printf("|============================================|\n\n");
     printf("  Masukkan jumlah cakram yang diinginkan : ");
     cakram=validasiHanoi();
     system("cls");

     langkah=(1<<cakram)-1;

     printf("\n|===========================================================|\n");
     printf("|                                                           |\n");
     printf("| Langkah minimum untuk memindahkan %d cakram yaitu : %d      |\n", cakram, langkah);
     printf("|                                                           |\n");
     printf("|===========================================================|\n");
     printf("|            Langkah-langkah pemindahan cakram :            |\n");
     printf("|===========================================================|\n");

     if (cakram%2==0){
         tiang[1] = tiangC;
         tiang[2] = tiangB;
     }
        printf("|                                                           |\n");
     for(i = 1; i <=langkah; i++){
        printf("|  %d. Pindahkan cakram paling atas dari tiang %c ke tiang %c  |\n", i, tiang[(i&i-1)%3], tiang[((i|i-1)+1)%3]);
     }
        printf("|                                                           |\n");
        printf("|===========================================================|\n\n");
}

int validasiMenu()
{
    int nilai;
    char check;

    if (scanf("%i%c", &nilai, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("  *hanya menerima inputan angka!\n\n"
               "  Pilih menu yang anda inginkan : ");
        return validasiMenu();
        }

    else if (nilai < 0 || nilai > 3)
        {
        printf("  *pilihan tidak tersedia!\n\n"
               "  Pilih menu yang anda inginkan : ");
        return validasiMenu();
        }
    else{
            return nilai;
        }
}

int validasiHanoi()
{
    int nilai;
    char check;

    if (scanf("%i%c", &nilai, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("  *inputan hanya berupa angka!\n\n"
               "  Masukkan ulang jumlah cakram yang diinginkan : ");
        return validasiHanoi();
        }
    else if (nilai <= 0)
        {
        printf("  *inputan hanya berupa bilangan positif!\n\n"
               "  Masukkan ulang jumlah cakram yang diinginkan : : ");
        return validasiHanoi();
        }
    else{
        return nilai;
        }
}


int perulangan()
{
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


