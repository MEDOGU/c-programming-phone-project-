
#include<stdio.h>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void ekle();
void ara();
void sil();
void rehber();
void guncelle();
void menu();
int main()
{
    system("cls");
    menu();
    int secim;
    scanf("%d",&secim);
    switch(secim)
    {
    case 1:
        ekle();
        break;
    case 2:
       guncelle(); 
        break;
    case 3:
        ara();
        break;
    case 4:
        sil();
        break;
    case 5:
        exit(0);
    case 6:
    	rehber();	
    default:
        main();
    }
}
//buradaki fonksiyonda kullanıcıdan girilen bilgiler dogrultusunda kisi oluşturulur
void ekle()
{
    FILE *fp;
    fp=fopen("contact.txt","a+");
    system("cls");
    printf("\t*****KISI EKLEME*****");
    printf("\n\tAD    :");
    char ad[20];
    scanf("%s",ad);
    printf("\n\tSOYAD    :");
    char soyad[20];
    scanf("%s",soyad);
    printf("\n\t No. :" );
    char no[20];
    scanf("%s",no);
    fprintf(fp,"%s %s %s\n",ad,soyad,no);
    fclose(fp);
    printf("\n\tGECMEK ICIN HERHANGI BIR TUSA BASINIZ");
    getch();
    main();
}
//buradaki fonksiyonda kullanıcıdan girilen bilgiler dogrultusunda rehberde kisi aranır.
void ara()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t*****KISI ARAMA*****");
    printf("\n\t AD :");
    char ad[20];
    scanf("%s",ad);
    char ad1[20],no[20],soyad[20];
    while(fscanf(fp,"%s %s %s",ad1,soyad,no)!=EOF)
    {
        if(strcmp(ad,ad1)==0)
        {
            printf("\n\t AD     : %s\n",ad1);
            printf("\n\t SOYAD     : %s\n",soyad);
            printf("\n\t NO  : %s\n",no);
        }
    }
    fclose(fp);
    printf("\n\tGECMEK ICIN HERHANGI BIR TUSA BASINIZ");
    getch();
    main();
}
//buradaki fonksiyonda kullanıcıdan girilen bilgiler dogrultusunda rehberde bulunan kisi silinir.
void sil()
{
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("\t*****SILME*****");
    printf("\n\t AD :");
    char ad[20];
    scanf("%s",ad);
    char ad1[20],no[20],soyad[20];
    while(fscanf(fp,"%s %s %s",ad1,soyad,no)!=EOF)
    {
        if(strcmp(ad,ad1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s\n",ad1,soyad,no);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s",ad1,no)!=EOF)
    {

        fprintf(fp,"%s %s %s\n",ad1,soyad,no);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\n\tGECMEK ICIN HERHANGI BIR TUSA BASINIZ");
    getch();
    main();
}
//buradaki fonksiyonda kullanıcıdan girilen bilgiler dogrultusunda rehberde bulunan tüm kişiler gösterilir.
void rehber()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t*****REHBER*****");
    char ad1[20],no[20],soyad[20];
    while(fscanf(fp,"%s %s %s",ad1,soyad,no)!=EOF)
    {
        printf("\n\t AD    :  %s",ad1);
         printf("\n\t SOYAD    :  %s",soyad);
        printf("\n\t NO. :  %s",no);
    }
    fclose(fp);
    printf("\n\tGECMEK ICIN HERHANGI BIR TUSA BASINIZ");
    getch();
    main();
}
//BURADAKİ FONKSİYONDA VAR OLAN KISI YENI GIRILEN BILGILER ILE DEGISIR
void guncelle()
{
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("\t*****GUNCELLEME*****");
    printf("\n\t AD :");
    char ad[20];
    scanf("%s",ad);
    //SOYAD2 DEĞİŞTİRİLECEK OLAN SOYAD NO2 DEĞİŞTİRİLECEK OLAN NO AD2 DEĞİŞTİRİLECEK OLAN AD2
    char ad1[20],ad2[20],no[20],soyad[20],soyad2[20],no2[20];
    while(fscanf(fp,"%s %s %s",ad1,soyad,no)!=EOF)
    {
        if(strcmp(ad,ad1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s %s\n",ad1,soyad,no);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s",ad1,no)!=EOF)
    {

        fprintf(fp,"%s %s %s\n",ad1,soyad,no);
    }
    printf("YENI AD GIRINIZ:\n");
            scanf("%s",&ad2);
            printf("YENI SOYAD GIRINIZ:\n");
            scanf("%s",&soyad2);
            printf("YENI NO GIRINIZ:\n");
            scanf("%s",&no2);
            strcpy(ad1,ad2);
            strcpy(soyad,soyad2);
            strcpy(no,no2);
            printf("AD1:%s\n",ad1);
            printf("SOYAD:%s\n",soyad);
            printf("NO:%s\n",no);
            fprintf(fp,"%s %s %s",ad1,soyad,no);
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\n\tGECMEK ICIN HERHANGI BIR TUSA BASINIZ");
    getch();
    main();
}
void menu()
{
	 printf("\t*****TELEFON REHBERI*****\n");
	printf("-----------------------------------\n");
    printf("\t 1. KAYIT\n");
    printf("\t 2. GUNCELLE\n");
    printf("\t 3. ARA\n");
    printf("\t 4. SIL\n");
    printf("\t 5. CIKIS\n");
    printf("\t 6. REHBER\n");
    printf("-----------------------------------\n");
    printf("LUTFEN ISLEM YAPMAK ISTEDGINIZ TUSA BASINIZ==>");
}
