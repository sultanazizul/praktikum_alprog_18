#include <stdio.h>

//PROGRAM KALKULATOR

int main()
{
    int bilangan1, bilangan2, pilih;
    float operasi;

    printf("======== Kalkulator ========\n\n");
    printf("1. Pertambahan (+)\n");
    printf("2. Pengurangan (-)\n");
    printf("3. Perkalian   (*)\n");
    printf("4. Pembagian   (/)\n");
    printf("5. Modulus     (%%)\n");
    printf("6. Keluar\n\n");
    printf("============================\n");

    koreksi(&pilih,("Masukkan pilihan operasi : "));

    switch(pilih){
       case 1:
           printf("\n============================\n");
           printf("\nMasukkan bilangan pertama: ");
           bilangan1=validasi1();
           printf("Masukkan bilangan kedua  : ");
           bilangan2=validasi2();
           fflush(stdin);
           printf("\n============================\n");
           operasi =  bilangan1 + bilangan2;
           printf("\nHasil %d + %d = %.2f\n", bilangan1, bilangan2, operasi);
           printf("\n============================\n\n");
           system("pause");
           system ("cls");
           perulangan();
        break;
        case 2:
           printf("\n============================\n");
           printf("\nMasukkan bilangan pertama: ");
           bilangan1=validasi1();
           printf("Masukkan bilangan kedua  : ");
           bilangan2=validasi2();
           fflush(stdin);
           printf("\n============================\n");
           operasi =  bilangan1 - bilangan2;
           printf("\nHasil %d - %d = %.2f\n", bilangan1, bilangan2, operasi);
           printf("\n============================\n\n");
           system("pause");
           system("cls");
           perulangan();
        break;
        case 3:
           printf("\n============================\n");
           printf("\nMasukkan bilangan pertama: ");
           bilangan1=validasi1();
           printf("Masukkan bilangan kedua  : ");
           bilangan2=validasi2();
           fflush(stdin);
           printf("\n============================\n");
           operasi =  bilangan1 * bilangan2;
           printf("\nHasil %d * %d = %.2f\n", bilangan1, bilangan2, operasi);
           printf("\n============================\n\n");
           system("pause");
           system ("cls");
           perulangan();
        break;
        case 4:
           printf("\n============================\n");
           printf("\nMasukkan bilangan pertama: ");
           bilangan1=validasi1();
           printf("Masukkan bilangan kedua  : ");
           bilangan2=validasi2();
           fflush(stdin);
           printf("\n============================\n");
           operasi =  bilangan1 / bilangan2;
           printf("\nHasil %d / %d = %.2f\n", bilangan1, bilangan2, operasi);
           printf("\n============================\n\n");
           system("pause");
           system ("cls");
           perulangan();
        break;
        case 5:
           printf("\n============================\n");
           printf("\nMasukkan bilangan pertama: ");
           bilangan1=validasi1();
           printf("Masukkan bilangan kedua  : ");
           bilangan2=validasi2();
           fflush(stdin);
           printf("\n============================\n");
           operasi =  bilangan1 % bilangan2;
           printf("\nHasil %d %% %d = %.2f\n", bilangan1, bilangan2, operasi);
           printf("\n============================\n\n");
           system("pause");
           system ("cls");
           perulangan();
        break;
        case 6:
            exit (0);
        default:
            system ("cls");
            main();
        break;

}

return(0);

    }

//fungsi perulangan
int perulangan() {
    char pilihan[2] ;
    printf ("Apakah anda ingin menghitung kembali? (y/t): ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if(strcmp(pilihan, "t")==0)
    {
        printf("\n=================================================\n");
        printf ("  Terima Kasih Telah Menggunakan  Program ini") ;
        printf("\n=================================================\n");
        exit(0);
    }
    else
    {
        system ("cls");
        printf("\n=================================================\n");
        printf ("\tSilahkan pilih (y/t) saja!") ;
        printf("\n=================================================\n\n");
        perulangan();
    }
}


//Validasi pilihan operasi
int check(int *var) {
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
void koreksi(int *var, char *prompt) {
    while(1){
        printf("%s", prompt);
    if(check(var))
    break;

    printf("\n============================================\n");
    printf("    Hanya Menerima Input Berupa ANGKA! \n");
    printf("============================================\n");
}
}

//validasi utk bilangan pertama
int validasi1() {
    int angka;
    char karakter;
    scanf("%d%c", &angka, &karakter);
    if(karakter != '\n' || angka<0){

    printf("\n============================================\n");
    printf("    Hanya Menerima Input Berupa ANGKA! \n");
    printf("============================================\n");
    printf("\nMasukkan bilangan pertama: ");

    fflush(stdin);
    validasi1();
}
else{
return angka;
}
}

//validasi utk bilangan kedua
int validasi2() {
    int angka;
    char karakter;
    scanf("%d%c", &angka, &karakter);
    if(karakter != '\n' || angka<0){

    printf("\n============================================\n");
    printf("    Hanya Menerima Input Berupa ANGKA! \n");
    printf("============================================\n");
    printf("\nMasukkan bilangan kedua: ");

    fflush(stdin);
    validasi2();
}
else{
return angka;
}
}

