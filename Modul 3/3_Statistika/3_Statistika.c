#include <stdio.h>
#include <stdlib.h>

int perulangan();
int input_data(float (*angka)[100], int *banyak);
int validasiInteger(int *var);
float mean(float (*angka)[100], int banyak);
float median(float (*angka)[100], int banyak);
float modus(float (*angka)[100], int banyak);
float urutkan(float (*angka)[100], int banyak);
float validasiFloat(float *var);

int pilih, i, j;

int main(){
	int banyak;
	float angka[100];

	printf("\n Program Statistika ");
	input_data(&angka, &banyak);
	urutkan(&angka, banyak);
	printf("\n\n\t------------------------------");
	mean(&angka, banyak);
	printf("\n\t------------------------------");
	median(&angka, banyak);
	printf("\n\t------------------------------");
	modus(&angka, banyak);
	printf("\n\t------------------------------");
	sleep(2);
	perulangan();

	return(0);
}

//validasi float
float validasiFloat(float *var){

	char buff[1024];
	char cek;
	if(fgets(buff, sizeof(buff), stdin) !=NULL){
  		if(sscanf(buff, "%f %c", var, &cek) ==1){
   		return 1;
  		}
 	}
	return 0;
}

//validasi int
int validasiInteger(int *var){
	char buff[1024];
	char cek;

	if(fgets(buff, sizeof(buff), stdin) !=NULL){
  		if(sscanf(buff, "%d %c", var, &cek) ==1){
   		return 1;
  		}
 	}
 	return 0;
}

int input_data(float (*angka)[100], int *banyak){
	float _angka[100];
	int _banyak;

	//input banyak data
	fflush(stdin);
	printf("\tMasukan Banyak Data	  : ");
	if(validasiInteger(&_banyak)){
	}
	else{
		printf("\n\tInput yang Anda Masukan Salah !");
		getch();
		main();
	}

	*banyak = _banyak;

	//input data
	fflush(stdin);
	printf("\n");
	for(i=0; i<_banyak; i++){
		printf("\tMasukan nilai dari data %d : ", i+1);
		if(validasiFloat(&_angka[i])){
		}
		else{
			printf("\n\tInput yang anda masukan salah !");
			getch();
			main();
		}

		(*angka)[i]=_angka[i];
	}
	return(0);
}

//fungsi mean
float mean(float (*angka)[100], int banyak){
	float rata;
	float temp=0;

	for(i=0 ; i<banyak; i++){
		temp = temp+(*angka)[i];
	}

	rata = temp/banyak;
	printf("\n\t\tMean\t: %.2f", rata);
	return rata;
}


//shorting angka
float urutkan(float (*angka)[100], int banyak){
	float temp=0;
	for(i=0 ; i<(banyak-1) ; i++){
		for(j=i+1;j<banyak;j++){
			if((*angka)[i]>(*angka)[j]){
				temp = (*angka)[i];
				(*angka)[i] = (*angka)[j];
				(*angka)[j] = temp;
			}
		}
	}
	printf("\n\tData yang Telah Diurutkan : \n\t");
 	for(i=0; i<banyak; i++){
  		printf("%.2f ", (*angka)[i]);
 	}

}

//fungsi median
float median(float (*angka)[100], int banyak){
	float tengah;

	if(banyak%2==0){
		tengah = ((*angka)[(banyak-1)/2]+(*angka)[((banyak-1)/2)+1]/2);
		printf("\n\t\tMedian\t: %.2f", tengah);
	}
	else{
		tengah = (*angka)[banyak/2];
		printf("\n\t\tMedian\t: %.2f", tengah);
	}
	return(0);
}

//fungsi modus
float modus(float (*angka)[100], int banyak){
	int k=1, l=0, m=0;
	float temp[100], mod[100];

	//menghitung berapa kali muncul tiap angka
	for(i=0 ; i<banyak ; i++){
		temp[i]=0;
		for(j=0;j<banyak;j++){
			if((*angka)[i]==(*angka)[j]){
				temp[i]++;
			}
		}
	}

	//menentukan nilai paling sering muncul
	for(i=0 ; i<banyak ; i++){
		if(temp[i]>k){
			k = temp[i];
		}
	}

	//jika modus lebih dari 1
	for(i=0 ; i<banyak ; i++){
		if(m==0){
			mod[m]=0;
		}
		else{
			mod[m]=mod[m-1];
		}
		if(temp[i]==k){
			if((*angka)[i]!=mod[m]){
				mod[m] = (*angka)[i];
				m++;
			}
		}

	}
	//jika semua angka muncul sama banyak
	for(i=0 ; i<banyak ; i++){
		if(temp[i]==k){
			l++;
		}
	}

	if(l==banyak){
		m=0;
	}
	if(m==0){
		printf("\n\t\tTidak Ada Modus");
	}
	else{
		for(i=0;i<m;i++){
			printf("\n\t\tModus\t: %.2f", mod[i]);
		}
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


