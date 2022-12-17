#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pilihan,kembali;

    printf("\n\n|======================================================|\n"
           "|                                                      |\n"
           "|          PROGRAM MENAMPILKAN DERET FIBONACCI         |\n"
           "|                                                      |\n"
           "|======================================================|\n"
           "|                                                      |\n"
           "|          1. REKURSIF                                 |\n"
           "|                                                      |\n"
           "|          2. ITERATIF                                 |\n"
           "|                                                      |\n"
           "|          0. KELUAR                                   |\n"
           "|                                                      |\n"
           "|======================================================|\n\n");
    do{
    validasiPilihan(&pilihan, "  Masukkan pilihan Anda : ");
    if (pilihan>2){
        printf("  *pilihan tidak tersedia\n\n");
    }
    }while(pilihan>2);


    system("cls");
    switch(pilihan)
    {
        case 1 : fiboRekursif();break;
        case 2 : fiboIteratif();break;
        case 0 : exit (0);

    }
    system("pause");
    system("cls");
    perulangan();

}

void fiboRekursif()
{
    int fibonacci(int number)
{
    if(number == 0){return 0;}
    else if(number < 2){}
    else{
        return fibonacci(number-1) + fibonacci(number-2);
    }
}

{
    int i, banyakFibo;
    printf("\n\n|======================================================|\n"
           "|                                                      |\n"
           "|      PROGRAM MENAMPILKAN DERET FIBONACCI REKURSIF    |\n"
           "|                                                      |\n"
           "|======================================================|\n"
           "|                                                      |\n");
    printf("| Masukkan banyak bilangan fibonacci : "); banyakFibo=validasiFibo();
    printf("|                                                      |\n");
    printf("|======================================================|\n\n");
    printf("  Deret fibonacci %d bilangan :\n\n",banyakFibo);

    for(i = 0; i <banyakFibo; i++){
        printf("  %d", fibonacci(i));
    }
    printf("\n\n|======================================================|\n\n");
    return 0;
}

}

void fiboIteratif()
{
    int bil_n, banyakFibo;
    int bil_n1 = 1;
    int bil_n2 = 0;

    printf("\n\n|======================================================|\n"
           "|                                                      |\n"
           "|      PROGRAM MENAMPILKAN DERET FIBONACCI ITERATIF    |\n"
           "|                                                      |\n"
           "|======================================================|\n"
           "|                                                      |\n");
    printf("| Masukkan banyak bilangan fibonacci : "); banyakFibo=validasiFibo();
    printf("|                                                      |\n");
    printf("|======================================================|\n\n");

    if(banyakFibo != 0)
    {
        printf("  Deret fibonacci %d bilangan : \n\n",banyakFibo);

        for(int i = 0 ; i < banyakFibo ; i++)
        {
            if(i == 0){
                bil_n = bil_n2;
            }
            else if(i == 1){
                bil_n = bil_n1;
            }
            else if(i > 1){
                bil_n = bil_n1 + bil_n2;
                bil_n2 = bil_n1;
                bil_n1 = bil_n;
            }
            if(i == (banyakFibo-1)){
                printf("  %d",bil_n);
            }
            else{
                printf("  %d",bil_n);
            }
        }
        printf("\n\n|======================================================|\n\n");
    }

    return(0);
}

int cekvalidasiInt(int *var)
{
    char buff[1020];
    char cek;
    fflush(stdin);
    if (fgets(buff, sizeof(buff), stdin) != NULL)
    {
        if (sscanf(buff, "%d %c", var, &cek) == 1)
        {
            return 1;
        }
    }
    return 0;
}

void validasiPilihan(int *var, char *prompt)
{
    while (1)
    {
        printf(prompt);
        if (cekvalidasiInt(var))
            break;
        printf("  *inputan hanya berupa angka! \n\n");
    }
}

int validasiFibo()
{
    int desimal;
    char check;

    if (scanf("%i%c", &desimal, &check) != 2 || check != '\n')
        {
        fflush(stdin);
        printf("  *hanya menerima inputan angka!\n\n"
               "  Masukkan banyak bilangan fibonacci : ");
        return validasiFibo();
        }

    else if (desimal < 0)
        {
        printf("  *angka tidak valid!\n\n"
               "  Masukkan bilangan fibonacci positif : ");
        return validasiFibo();
        }
}


int perulangan()
{
    char pilihan[2] ;
    printf("\n\n|====================================================|\n\n");
    printf("|    Apakah anda ingin menghitung kembali? (y/t):    |") ;
    printf("\n\n|====================================================|\n");
    printf ("\n pilih : ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if ((strcmp(pilihan, "t")==0) || (strcmp(pilihan, "T")==0))
    {
        printf("\n\n|=============================================|\n\n");
        printf("|  Terima Kasih Telah Menggunakan Program ini |") ;
        printf("\n\n|==============================================|\n\n");
    }
    else
    {
        printf("\n\n|============================================|\n\n");
        printf("|         Silahkan pilih (y/t) saja!         |") ;
        printf("\n\n|============================================|\n\n");
        system ("pause");
        system ("cls");
        perulangan();
    }
    return 0;
}

