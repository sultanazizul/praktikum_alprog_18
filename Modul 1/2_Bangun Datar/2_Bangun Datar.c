#include <stdio.h>
#include <stdlib.h>
#define PHI 3.14
float keliling, luas, sisi1, sisi2, sisi3, sisi4, alas, tinggi;

float segitigaSembarang(){
    printf("\n============ Segitiga Sembarang ===========\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang sisi 1 : ");
    sisi1=validasi();
    printf("\nMasukkan panjang sisi 2 : ");
    sisi2=validasi();
    printf("\nMasukkan panjang sisi 3 : ");
    sisi3=validasi();
    printf("\nMasukkan alas           : ");
    alas=validasi();
    printf("\nMasukkan tinggi         : ");
    tinggi=validasi();
    // rumus K= sisi1+sisi2+sisi3
    keliling = sisi1+sisi2+sisi3;
    // luas L=1/2*alas*tinggi
    luas = 0.5*alas*tinggi;
    // menampilkan hasil
    printf("\n================ Hasil ====================\n\n");
    printf("Keliling segitiga sembarang adalah %.2f", keliling);
    printf("\nLuas segitiga sembarang adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}
float belahketupat(){
    int sisi, d1, d2;
    printf("\n============ Belah Ketupat ===========\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang sisi       : ");
    sisi=validasi();
    printf("\nMasukkan panjang diagonal 1 : ");
    d1=validasi();
    printf("\nMasukkan panjang diagonal 2 : ");
    d2=validasi();

    // rumus K= 4*s
    keliling = 4*sisi;
    // luas L= 1/2*diagonal1*diagoonal2
    luas = 0.5*d1*d2;
    // menampilkan hasil
    printf("\n================ Hasil ====================\n\n");
    printf("Keliling Belah Ketupat adalah %.2f", keliling);
    printf("\nLuas Belah Ketupat adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}
float jajargenjang(){
    int sisisejajar, sisimiring;

    printf("\n============ Jajar Genjang ===========\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang sisi sejajar : ");
    sisisejajar=validasi();
    printf("\nMasukkan panjang sisi miring  : ");
    sisimiring=validasi();
    printf("\nMasukkan tinggi               : ");
    tinggi=validasi();
    printf("\nMasukkan alas                 : ");
    alas=validasi();
    // rumus K=2*(sisi sejajar + sisi miring)
    keliling= 2*(sisisejajar+sisimiring);
    // rumus L=alas*tinggi
    luas= alas*tinggi;
    // menampilkan hasil
    printf("\n================ Hasil ====================\n\n");
    printf("Keliling jajar genjang adalah %.2f", keliling);
    printf("\nLuas jajar genjang adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}
float trapesium(){
    int alas1, alas2;

    printf("\n============ Trapesium ===========\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang sisi 1: ");
    sisi1=validasi();
    printf("\nMasukkan panjang sisi 2: ");
    sisi2=validasi();
    printf("\nMasukkan panjang sisi 3: ");
    sisi3=validasi();
    printf("\nMasukkan panjang sisi 4: ");
    sisi4=validasi();
    printf("\nMasukkan alas 1        : ");
    alas1=validasi();
    printf("\nMasukkan alas 2        : ");
    alas2=validasi();
    printf("\nMasukkan tinggi        : ");
    tinggi=validasi();
    // rumus K= sisi1+sisi2+sisi3+sisi4
    keliling = sisi1+sisi2+sisi3+sisi4;
    // Rumus L=1/2*(alas a+alasb)* tinggi
    luas = 0.5*(alas1+alas2)*tinggi;
    // menampilkan hasil
    printf("\n================ Hasil ====================\n\n");
    printf("Keliling trapesium adalah %.2f", keliling);
    printf("\nLuas trapesium adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}
float lingkaran(){
    int jari2;
    printf("\n================ Lingkaran ================\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang jari jari : ");
    jari2=validasi();
    // rumus K=2*phi*r
    keliling= 2*PHI*jari2;
    // rumus L=phi*r*r
    luas= PHI*jari2*jari2;
    // menampilkan hasil
    printf("\n================ Hasil ====================\n\n");
    printf("Keliling lingkaran adalah %.2f", keliling);
    printf("\nLuas lingkaran adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

int main(){

    int  pilih;

    printf("\n============================================\n\n");
    printf("   Program Menghitung Keliling dan Luas \n");
    printf("\n============================================\n\n");
    printf("1. Segitiga Sembarang \n");
    printf("2. Belah Ketupat\n");
    printf("3. Jejar Genjang \n");
    printf("4. Trapesium \n");
    printf("5. Lingkaran \n");
    printf("6. Keluar\n");
    printf("\n============ Pilih Bangun Datar ============\n");
    koreksi(&pilih,("\nMasukkan pilihan anda : "));


    switch(pilih){
        case 1 :
            system("cls");
            segitigaSembarang();
            perulangan();
        break;
        case 2 :
            system("cls");
            belahketupat();
            perulangan();
        break;
        case 3 :
            system("cls");
            jajargenjang();
            perulangan();
        break;
        case 4 :
            system("cls");
            trapesium();
            perulangan();
        break;
        case 5 :
            system("cls");
            lingkaran();
            perulangan();
        break;
        case 6 :
            exit (0);
        break;
        default:
            system("cls");
            main();
        break;
    }

    return 0;

}

int perulangan() {
    char pilihan[2] ;
    printf ("Apakah anda ingin menghitung kembali? (y/t): ") ;
    scanf ("%s", &pilihan) ;
    system("cls");

    if ((strcmp(pilihan, "y")==0) || (strcmp(pilihan, "Y")==0))
    {
        main();
    }
    else if ((strcmp(pilihan, "t")==0) || (strcmp(pilihan, "T")==0))
    {
        printf("\n=================================================\n");
        printf ("  Terima Kasih Telah Menggunakan Program ini") ;
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

//Validasi Inputan Angka
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

int validasi() {
    int angka;
    char karakter;
    scanf("%d%c", &angka, &karakter);
    if(karakter != '\n' || angka<0){
    printf("\n============================================\n");
    printf("    Hanya Menerima Input Berupa ANGKA! \n");
    printf("============================================\n");
    printf("Masukkan ulang: ");
    fflush(stdin);
    validasi();
}
    else{
    return angka;
}
}


