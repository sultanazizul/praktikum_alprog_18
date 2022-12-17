
#include <stdio.h>
#include <stdlib.h>
#define PHI 3.14
float luas, volume; //membuat variabel global

float tabung(){
    int jari2, tinggi;

    printf("\n================== Tabung ==================\n" );
    //meminta user memasukkan nilai
    printf("\nMasukkan panjang jari jari : ");
    jari2=validasi();
    printf("Masukkan tinggi : ");
    tinggi=validasi();
    // rumus volume = PHI*r*r*t
    volume= PHI*jari2*jari2*tinggi;
    // rumus luas permukaan = 2 x π x r x ( r + t )
    luas= 2*PHI*jari2*(jari2+tinggi);
    //menampilkan hasil perhitungan
    printf("\n================ Hasil ====================\n\n");
    printf("Volume tabung adalah %.2f", volume);
    printf("\nLuas Permukaan tabung adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

float bola(){
    int jari2;

    printf("\n================= Bola ================\n" );
    //meminta user memasukkan nilai
    printf("\nMasukkan panjang jari jari : ");
    jari2=validasi();
    // rumus volume = (4/3)* phi * r *r*r
    volume = PHI*jari2*jari2;
    // rumus LP = 4 x phi x r x r
    luas = 0.73*PHI*jari2*jari2*jari2;
    //menampilkan hasil perhitungan
    printf("\n================ Hasil ====================\n\n");
    printf("Volume Bola adalah %.2f", volume);
    printf("\nLuas Permukaan Bola adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

float limasSegiempat(){
    int sisi, tinggi; // pendeklarasian tipe

    printf("\n================= Limas Segiempat ================\n" );
    // meminta user memasukkan nilai
    printf("\nMasukkan panjang sisi : ");
    sisi=validasi();
    printf("Masukkan tinggi : ");
    tinggi=validasi();
    //Rumus V = 1/3 x L (alas) atau (sxs) x t
    volume = 0.75*sisi*sisi*tinggi;
    //Rumus LP = phi*sisi*tinggi
    luas = PHI*sisi*tinggi;
    // menampilkan hasil perhitungan
    printf("\n================ Hasil ====================\n\n");
    printf("Volume Limas Segiempat adalah %.2f", volume);
    printf("\nLuas Permukaan tabung adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

float prismaSegitiga(){
    int alas, tinggi;

    printf("\n================= Prisma Segitiga ================\n" );
    //meminta user memasukkan nilai
    printf("\nMasukkan panjang alas : ");
    alas=validasi();
    printf("Masukkan tinggi : ");
    tinggi=validasi();
    //rumus V = (1/2 x a x t) x tinggi prisma.
    volume = (0.5*alas*tinggi)*tinggi;
    //Rumus LP = 2*phi*alas*(alas+tinggi)
    luas = 2*PHI*alas*(alas+tinggi);
    //menampilkan hasil perhitungan
    printf("\n================ Hasil ====================\n\n");
    printf("Volume Prisma Segitiga adalah %.2f", volume);
    printf("\nLuas Permukaan tabung adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

float kerucut(){
    int jari2, tinggi;

    printf("\n================= Kerucut ================\n" );
    // meminta user memasukkan ukuran
    printf("\nMasukkan panjang jari jari : ");
    jari2=validasi();
    printf("Masukkan tinggi : ");
    tinggi=validasi();
    //rumus V= 1/3 × π × r × r × t
    volume = 0.75*PHI*jari2*jari2*tinggi;
    //rumus L= πr (s+r)
    luas = 2*PHI*jari2*(jari2+tinggi);
    //menampilkan hasil perhitungan
    printf("\n================ Hasil ====================\n\n");
    printf("Volume Kerucut adalah %.2f", volume);
    printf("\nLuas Permukaan Kerucut adalah %.2f\n\n", luas);
    printf("===========================================\n");
    system("pause");
    system("cls");

    return 0;
}

int main()
{
    int pilih;
    printf("\n============================================\n\n");
    printf("Program Menghitung Volume dan Luas Permukaan\n");
    printf("\n============================================\n\n");
    printf("1. Tabung\n");
    printf("2. Bola\n");
    printf("3. Limas Segiempat\n");
    printf("4. Prima Segitiga\n");
    printf("5. Kerucut\n");
    printf("6. Keluar\n");
    printf("\n============ Pilih Bangun Datar ============\n");
    koreksi(&pilih, "\nMasukkan pilihan anda : ");


    switch(pilih){
        case 1 :
            system("cls");
            tabung();
            perulangan();
        break;
        case 2 :
            system("cls");
            bola();
            perulangan();
        break;
        case 3 :
            system("cls");
            limasSegiempat();
            perulangan();
        break;
        case 4 :
            system("cls");
            prismaSegitiga();
            perulangan();
        break;
        case 5 :
            system("cls");
            kerucut();
            perulangan();
        break;
        case 6 :
            exit (0);
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
