#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tanggal, bulan, tglMaks;
    char bulann[10];

    system("cls");
    printf("|============================================|\n");
    printf("|           PROGRAM MENENTUKAN ZODIAK        | \n");
    printf("|============================================|\n");
    printf("|   Januari   |    Februari    |    Maret    |\n");
    printf("|-------------|----------------|-------------|\n");
    printf("|    April    |       Mei      |     Juni    |\n");
    printf("|-------------|----------------|-------------|\n");
    printf("|    Juli     |     Agustus    |  September  |\n");
    printf("|-------------|----------------|-------------|\n");
    printf("|   Oktober   |    November    |   Desember  |\n");
    printf("|============================================|\n\n");

    printf(" Masukkan Bulan   (1-12) = ");
    bulan=validasiBulan();

    tglMaks = cari_tanggal_max(bulan);

    do{
    printf(" Masukkan Tanggal (1-%d) = ", tglMaks);
    tanggal = validasiTanggal();
    }while(tanggal<1||tanggal>31);

    printf("\n==========================================\n\n");
    if(tanggal>=21&&bulan==3 || tanggal<=19 && bulan==4){
        printf("Zodiak = Aries");
    }else if(tanggal>=20&&bulan==4 || tanggal<=20 && bulan==5){
        printf("Zodiak = Taurus");
    }else if(tanggal>=21&&bulan==5 || tanggal<=20 && bulan==6){
        printf("Zodiak = Gemini");
    }else if(tanggal>=21&&bulan==6 || tanggal<=22 && bulan==7){
        printf("Zodiak = Cancer");
    }else if (tanggal >=23&&bulan==7 || tanggal<=22 && bulan==8){
        printf("Zodiak = Leo");
    }else if (tanggal >=23&&bulan==8 || tanggal<=22 && bulan==9){
        printf("Zodiak = Virgo");
    }else if (tanggal >=23&&bulan==9  || tanggal<=22 && bulan==10){
        printf("Zodiak = Libra");
    }else if (tanggal >=23&&bulan==10  || tanggal<=21 && bulan==11){
        printf("Zodiak = Scorpio");
    }else if (tanggal >=22&&bulan==11  || tanggal<=21 && bulan==12){
        printf("Zodiak = Sagitarius");
    }else if (tanggal >=22&&bulan==12  || tanggal<=19 && bulan==1){
        printf("Zodiak = Capricorn");
    }else if (tanggal >=20&&bulan==1  || tanggal<=18 && bulan==2){
        printf("Zodiak = Aquarius");
    }else if (tanggal >=19&&bulan==2  || tanggal<=20 && bulan==3){
        printf("Zodiak = Pisces");
    }

    printf("\n\n==========================================\n");
    system("pause");
    system("cls");

    perulangan();

    return 0;
}

int cari_tanggal_max(int i){
    if(i==2){
        return 29;
    }else if(i==1 || i==3 || i==5 || i==7 || i==9){
        return 31;
    }else{
        return 30;
    }
}

int perulangan() {
    char pilihan[2] ;
    printf("=================================================\n\n");
    printf ("Apakah anda ingin menghitung kembali? (y/t): ") ;
    printf("\n\n=================================================\n");
    printf ("\nPilih : ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if ((strcmp(pilihan, "t")==0) || (strcmp(pilihan, "T")==0))
    {
        printf("\n=================================================\n\n");
        printf ("  Terima Kasih Telah Menggunakan Program ini") ;
        printf("\n\n=================================================\n");
    }
    else
    {
        printf("\n=================================================\n\n");
        printf ("\tSilahkan pilih (y/t) saja!") ;
        printf("\n\n=================================================\n");
        system ("pause");
        system ("cls");
        perulangan();
    }
    return 0;
}

int validasiBulan()
{
    int absen;
    char check;

    if (scanf("%i%c", &absen, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf(" *hanya menerima inputan angka!\n\n"
               " Masukkan Bulan   (1-12) = ");
        return validasiBulan();
        }

    else if (absen > 12 )
        {
        printf(" *hanya menerima angka (1-12)!\n\n"
               "  Masukkan Bulan   (1-12) = ");
        return validasiBulan();
        }
}

int validasiTanggal()
{
    int absen;
    char check;

    if (scanf("%i%c", &absen, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf(" *hanya menerima inputan angka!\n\n"
               " Masukkan Tanggal = ");
        return validasiTanggal();
        }

}




