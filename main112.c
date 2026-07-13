#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char you, char pc)
{
    if(you==pc) return -1;
    if((you=='T'&&pc=='M')||(you=='K'&&pc=='T')||(you=='M'&&pc=='K')) return 1;
    else return 0;
}

int main()
{
    int result, hedef_skor;
    int your_score=0, pc_score=0;
    char you, pc;
    char options[]={'T', 'K', 'M'};
    
    srand(time(NULL));
    
    printf("------TAS KAGIT MAKAS OYUNU------\n");
    
    sayi:
    printf("Hangi Skora (Max: 100) Ulasan Kazansin? ");
    
    if(scanf("%d", &hedef_skor)!=1) // 1 -> sayi iken 0 -> harf demektir.
    {
        while(getchar()!='\n'); // Klavye tamponunu (buffer) temizler
        printf("\n=> HATA! Lutfen Sadece Sayi Giriniz.\n");
        goto sayi;
    }    
    
    if(hedef_skor<=0||hedef_skor>100)
    {
        printf("\n=> Gecersiz Sayi! Lutfen 1 ile 100 Arasinda Bir Sayi Giriniz.\n\n");
        goto sayi;
    }
    
    while(your_score<hedef_skor&&pc_score<hedef_skor) 
    {
        printf("\n________Skor Durumu________\n[Sen -> %d - %d <- Bilgisayar]\n", your_score, pc_score);
        secim:
        printf("\nTas -> T | Kagit -> K | Makas -> M\nHamlenizi Yapiniz: ");
        scanf(" %c", &you);
        
        if(you!='T'&&you!='K'&&you!='M')
        {
            printf("\n=> Gecersiz hamle! Lutfen Tekrar Deneyiniz.\n");
            goto secim;
        }
        
        pc=options[rand()%3];
    
        printf("Bilgisayarin Secimi: %c\n", pc);
    
        result=game(you, pc);
        
        if(result==1) 
        {
            printf(">>>Bu eli kazandin!\n");
            your_score++;
        }
        else if(result==0)
        {
            printf(">>>Bu eli kaybettin!\n");
            pc_score++;
        }
        else 
        {
            printf(">>>Berabere!\n");
        }
    }
    
    printf("\n========OYUN BITTI========\n");
    printf("\n________FINAL SKORU________\n[Sen -> %d - %d <- Bilgisayar]", your_score, pc_score);
    
    if(your_score>pc_score) printf("\n\n --> Tebrikler! Oyunu Kazandin!");
    else printf("\n\n --> Maalesef! Oyunu Kaybettin!");

    return 0;
}