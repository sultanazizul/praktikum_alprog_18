#include <stdio.h>

int main()
{
    float nilaiTotal;
    int absensi, nilaiTugas1, nilaiTugas2, nilaiTugas3, nilaiQuiz, nilaiUTS, nilaiUAS;
    char nilaiHuruf;

    printf("\n|============================================|\n"
           "|                                            |\n"
           "|      PROGRAM MENENTUKAN NILAI AKHIR        |\n"
           "|                                            |\n"
           "|============================================|\n"
           "| Presentase Nilai:                          |\n"
           "|--------------------------------------------|\n"
           "|                                            |\n"
           "|  QUIZ [15%%]  |   UTS [30%%]   |  UAS [30%%]  |\n"
           "|                                            |\n"
           "|--------------------------------------------|\n"
           "|                                            |\n"
           "|    TUGAS 1 - 3 [20%%]   |   ABSENSI [15%%]   |\n"
           "|                                            |\n"
           "|============================================|\n\n");
    system("pause");
    system("cls");

    printf("\n============================================\n"
           "                ABSENSI [15%%]\n"
           "============================================\n"
           " Jumlah kehadiran (1-15): ");absensi = validasiAbsensi();
    system("cls");

    printf("\n============================================\n"
           "              TUGAS 1 - 3 [20%%]             \n"
           "============================================\n");
    printf(" Nilai Tugas 1          : ");nilaiTugas1=validasiNilai();
    printf(" Nilai Tugas 2          : ");nilaiTugas2=validasiNilai();
    printf(" Nilai Tugas 3          : ");nilaiTugas3=validasiNilai();
    system("cls");

    printf("\n============================================\n");
    printf("                 QUIZ [15%%]                 \n");
    printf("============================================\n");
    printf(" Nilai Quiz             : ");nilaiQuiz=validasiNilai();
    system("cls");

    printf("\n============================================\n"
           "                 UTS [30%%]                  \n"
           "============================================\n"
           " Nilai UTS              : ");nilaiUTS=validasiNilai();
    system("cls");

    printf("\n============================================\n"
           "                 UAS [30%%]                  \n"
           "============================================\n"
           " Nilai UAS              : ");nilaiUAS=validasiNilai();
    printf("============================================\n\n");
    system("cls");


    nilaiTotal = (absensi/3)+((nilaiTugas1+nilaiTugas2+nilaiTugas3)/3*0.2)+(nilaiQuiz*0.15)+(nilaiUTS*0.3)+(nilaiUAS*0.3);

    if (nilaiTotal < 45) nilaiHuruf='E';
    else if (nilaiTotal < 50) nilaiHuruf='D';
    else if (nilaiTotal < 55) nilaiHuruf='D+';
    else if (nilaiTotal < 60) nilaiHuruf='C';
    else if (nilaiTotal < 65) nilaiHuruf='C+';
    else if (nilaiTotal < 75) nilaiHuruf='B';
    else if (nilaiTotal < 80) nilaiHuruf='B+';
    else if (nilaiTotal <= 100) nilaiHuruf='A';

    printf("\n============================================\n"
           "                   Hasil:\n"
           "============================================\n");
    printf("\n Nilai Akhir anda adalah %.2f\n", nilaiTotal);
    printf(" Nilai Huruf anda adalah %c\n", nilaiHuruf);
    printf("\n============================================\n");

    system("pause");
    system("cls");

    perulangan();

    return 0;
}

int validasi()
{
    int angka;
    char karakter;
    scanf("%d%c", &angka, &karakter);
    if(karakter != '\n' || angka<0){
    printf("\n============================================\n");
    printf("    Hanya Menerima Input Berupa ANGKA! \n");
    printf("============================================\n");
    printf(" Masukkan ulang: ");
    fflush(stdin);
    validasi();
}
else{
return angka;
}
}

int validasiAbsensi()
{
    int absen;
    char check;

    if (scanf("%i%c", &absen, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf(" *hanya menerima inputan angka!\n\n"
               " Masukkan ulang absensi : ");
        return validasiAbsensi();
        }

    else if (absen > 15 )
        {
        printf(" *hanya menerima angka (1-15)!\n\n"
               " Masukkan ulang absensi : ");
        return validasiAbsensi();
        }
}

int validasiNilai()
{
    int nilai;
    char check;

    if (scanf("%i%c", &nilai, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf(" *hanya menerima inputan angka!\n\n"
               " Masukkan ulang nilai   : ");
        return validasiNilai();
        }

    else if (nilai > 100 )
        {
        printf(" *hanya bisa menerima nilai maks (100)!\n\n"
               " Masukkan ulang nilai   : ");
        return validasiNilai();
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

