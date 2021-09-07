#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(){
    const int maxkata = 2048;
    const int maxpanjang = 64;
    srand(time(NULL));
    
    char kata[maxkata][maxpanjang];
    int katamasuk = 0;

    FILE *file = fopen("words.txt","r");

    if(file == NULL){
        printf("Gagal membaca file\n");
    }

    char input[64];

    while(fgets(input,63, file)){
        sscanf(input, "%s", kata[katamasuk]);
        printf("Terpindai: Input:%s kata[%d]:%s\n",input,katamasuk,kata[katamasuk]);
        katamasuk++;
    }

    printf("Jumlah Kata Masuk:%d\n",katamasuk);

    fclose(file);

    int indeksAcak = rand() % 7;
    int sisaNyawa = 6;
    int jawabanBenar = 0;
    int jawabanLama = 0;
    int panjangKata = strlen(kata[indeksAcak]);
    int hurufTertebak [8] = {0,0,0,0,0,0,0,0};

    int quit = 0;
    int loopIndex = 0; 

    char tebak[12];
    char inputHuruf;
    /*printf("kata: %s indeksAcak: %d panjangKata: %d\n",
        kata[indeksAcak] ,
        indeksAcak,
        panjangKata);*/

     // loop game   
    while (jawabanBenar < panjangKata) {
        printf("\n\nGiliran Baru\nkata Hangman:");

        for(loopIndex = 0; loopIndex < panjangKata; loopIndex++){

            if(hurufTertebak[loopIndex] == 1) {
                printf("%c",kata[indeksAcak][loopIndex]);
            }else{
                printf("-");
            }
        }

    printf("\n");

        printf("Jumlah huruf benar:%d\n", jawabanBenar);
        printf("Masukkan huruf: ");
        fgets(tebak, 12, stdin);

        if( strncmp(tebak, "quit", 4) == 0){
           quit = 1;
           break;     
        }  

       inputHuruf = tebak[0];
       printf("inputHuruf: %c\n", inputHuruf);
       jawabanLama = jawabanBenar;

        for(loopIndex = 0; loopIndex < panjangKata; loopIndex++){
            if(hurufTertebak[loopIndex] == 1) {
                continue;
            }
           if(inputHuruf == kata[indeksAcak][loopIndex]){
               hurufTertebak[loopIndex] = 1;
               jawabanBenar++; 
           }
        }
        if(jawabanLama == jawabanBenar){
            sisaNyawa--;
            printf("Maaf, tebakan salah\n");
            if (sisaNyawa == 0){
                break;
            }
        }else {
            printf("Tebakan benar\n");
        }
        
    } // while loop 
    
    if(quit == 1) {
        printf("\npemain keluar lebih awal\n");
    }else if(sisaNyawa == 0){
        printf("\nmaaf anda kalah, jawabannya adalah : %s \n", 
        kata[indeksAcak]);
    }else {
        printf("\nAnda menang!\n");
    }    
        return 0;   
}
