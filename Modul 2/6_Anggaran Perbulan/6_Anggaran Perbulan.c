#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double pokokPinjaman,angsuranPokok,bungaBulan,totalBunga = 0,totalAngsuran = 0, bunga;
int lamaPinjam, i;


double validasi()
{
    int angka;
    char huruf;

    scanf("%i%c", &angka,&huruf);
    if(huruf != '\n'){
        printf("    *hanya menerima inputan angka!\n\n");
        printf("    Masukkan Nilai Yang Benar     = ");
        fflush(stdin);
        validasi();

    }else if (angka < 1){
        printf("    *tidak menerima  bilangan negatif!\n\n");
        printf("    Masukkan Nilai Yang Benar     = ");
        fflush(stdin);
        validasi();

    }else{
        return angka;
    }
}

float hitungBunga()
{
    bungaBulan = (pokokPinjaman-((i-1)*angsuranPokok))*(bunga/12);
    return bungaBulan;
}

int main()
{
    //system("color 0A");
    printf("\n\n |=================================================|\n\n"
           "              PROGRAM MENGHITUNG ANGSURAN         \n\n "
           "|=================================================|\n");
    printf("\n    Masukkan Pokok Pinjaman       = Rp. "); pokokPinjaman=validasi(); //scanf("%f", &pokokPinjaman);
    printf("\n    Masukkan Besar Bunga (%%)      = "); bunga=validasi(); //scanf("%f", &bunga);
    printf("\n    Masukkan Lama Pinjaman (Bulan)= "); lamaPinjam=validasi(); //scanf("%d", &lamaPinjam);
    printf("\n\n|=================================================|");

    angsuranPokok = pokokPinjaman / lamaPinjam;
    bunga = bunga/100;

    system("cls");
    printf("\n\n|===================================================================|\n");
    printf("   BULAN           BUNGA       ANGSURAN POKOK   ANGSURAN PERBULAN\n");
    printf("|===================================================================|\n\n");

    for (i = 1; i<=lamaPinjam; i++)
        {
        bungaBulan = hitungBunga();
        printf("     %i  \tRp. %.0f \tRp. %.0f  \tRp. %.0f \n", i, bungaBulan, angsuranPokok, angsuranPokok+bungaBulan );
        totalBunga = totalBunga + bungaBulan;
        totalAngsuran += (angsuranPokok+bungaBulan);
        }
    printf("                                                                 (+)");
    printf("\n|===================================================================|\n\n");
    printf("   Total Bunga                                = Rp. %2.f\n", totalBunga);
    printf("   Total Angsuran                             = Rp. %2.f\n", totalAngsuran);
    printf("\n|===================================================================|\n\n");

    system("pause");
    system("cls");
    perulangan();

    return 0;

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



