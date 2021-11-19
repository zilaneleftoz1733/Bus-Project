#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>


   char salonsecimi;        int bilet_ucreti;
    int matine;
    int toplam_hasilat;
    int i;
    int koltuksayaci=0;
    int j,k;
    int koltuk_no=0;
    int odemesekli;
    int tutar=0;


   typedef struct
{
    char Red[5][50];
    char Green[5][50];
    char Blue[5][50];
}   Salonlar;

    typedef enum
{
        ogrenci_bilet=0,
        tam_bilet,
}  ucretler;

int main()
{
    Salonlar salon;
    ucretler ucret;
    int hasilat;
    int koltuksayaci=0;

    char sifre[25];
    printf("SISTEME GIRIS ICIN SIFREYI GIRINIZ \n");
    gets(sifre);

    FILE *filep1;
    filep1=fopen("Sifre.txt","r");

    if(sifre[1] == '\NULL' )
    {

    }

    for(i=1;i<strlen(sifre);i++)
    {
         printf("***BASARILI GIRIS***\n\n");
    }
    fclose(filep1);
    FILE *filep5;
    filep5=fopen("hasilat.txt","r");

            fscanf(filep5,"%d",&toplam_hasilat);

    fclose(filep5);


    int menuSecimi;
    printf("SINEMA REZARVASYON SISTEMI\n");
    printf("(:**************************************************:)\n");
    printf("Rezervasyon yapmak icin 1'e BASINIZ \n");
    printf("Hasilat bilgisi icin 2'e BASINIZIZ \n");
    printf("Izlenme miktarlari icin 3'e BASINIZ \n");
    scanf("%d",&menuSecimi);
    Salonlar *psalon;
    psalon = &salon;

    FILE *filep2;
    filep2=fopen("koltukred.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Red[j][k] = getc(filep2) ;
        }

    }
    fclose(filep2);

    FILE *filep3;
    filep3=fopen("koltukgreen.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Green[j][k] = getc(filep3) ;
        }

    }
    fclose(filep3);

    FILE *filep4;
    filep4=fopen("koltukblue.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Blue[j][k] = getc(filep4) ;
        }

    }
    fclose(filep4);

    switch(menuSecimi)
    {
        case 1:
            printf("\n REZERVASYON YAPMAK ISTEDIGINIZ SALONU SECINIZ \nRed icin 1\nGreen icin 2\nBlue icin 3\n");
            scanf(" %c",&salonsecimi);
            switch(salonsecimi)
            {
                case '1':


                    printf("\n\n REZERVASYON YAPMAK ISTEDIGINIZ MATINEYI SECINIZ\n 1/2/3/4/5");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<5;j++)
                        {
                            if(psalon->Red[i][j] == 'NULL')
                            {
                                psalon->Red[i][j] = 1;
                                koltuk_no = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nODEME SEKLINI SECINIZ\n(Ogrenci icin 1'e  Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci_bilet )
                    {
                        tutar = 20;
                        toplam_hasilat+=tutar;
                    }
                    else if(odemesekli == tam_bilet)
                    {
                        tutar = 30;
                        toplam_hasilat+=tutar;
                    }
                    printf("\nREZERVASYON BILGILERI:\n");
                    printf("\n\nrezerve edilen koltuk numaraniz % d dir.\n",koltuk_no+1);
                    printf("\n %d lira odeyiniz.\n",tutar);

                    filep2=fopen("koltukred.txt","r");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Red[j][k] == 'NULL')
                            fputc('NULL',filep2);
                        else
                            fputc('1',filep2);
                        }

                    }
                    fclose(filep2);

                    filep5=fopen("hasilat.txt","r");

                    fprintf(filep5,"%d",toplam_hasilat);

                    fclose(filep5);



                break;
                break;

                case '2':

                    printf("\n\n REZERVASYON YAPACAGINIZ MATINEYI SECİNİZ\n(1/n2/n3/n4/n5)");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Green[i][j] == 'NULL')
                            {
                                psalon->Green[i][j] = 1;
                                koltuk_no = j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nODEME SEKLINI SECINIZ\n(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);


                    if(odemesekli == ogrenci_bilet )
                    {
                        tutar = 20;
                        toplam_hasilat+=tutar;
                    }
                    else if(odemesekli == tam_bilet)
                    {
                        tutar = 30;
                    toplam_hasilat+=tutar;
                    }
                    printf("\nRezarvasyon Bilgileri:\n");
                    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuk_no+1);
                    printf("\nUcretiniz %d liradir.\n",tutar);

                    filep3=fopen("koltukgreen.txt","r");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Green[j][k] == 'NULL')
                            fputc('NULL',filep2);
                        else
                            fputc('1',filep2);
                        }

                    }
                    fclose(filep3);
                    filep5=fopen("hasilat.txt","r");

                    fprintf(filep5,"%d",toplam_hasilat);

                    fclose(filep5);


                    break;
                    break;

                case '3':


                    printf("\n\n MATINEYI SECINIZ.\n(1/2/3/4/5)");
                    scanf("%d",&matine);
                    for(i=matine-1;i<matine;i++)
                    {
                        for(j=0;j<50;j++)
                        {
                            if(psalon->Blue[i][j] == 'NULL')
                            {
                                psalon->Blue[i][j] = 1;
                                koltuk_no= j;
                                break;
                            }
                            else
                                continue;

                        }
                    }

                    printf("\nODEME SEKLINI SECINIZ\n(Ogrenci_bilet icin 1'e Tam_bilet icin 2'ye basin)\n");
                    scanf(" %d",&odemesekli);
                    if(odemesekli == ogrenci_bilet )
                    {
                        tutar = 20;
                        toplam_hasilat+=tutar;
                    }
                    else if(odemesekli == tam_bilet)
                    {
                        tutar = 30;
                        toplam_hasilat+=tutar;
                    }
                    printf("\nREZERVASYON BİLGİLERİ:\n");
                    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuk_no+1);
                    printf("\nUcretiniz %d liradir.\n",tutar);

                    filep4=fopen("koltukblue.txt","r");
                    for(j=0;j<5;j++)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(psalon->Blue[j][k] == NULL)
                            fputc('NULL',filep4);
                        else
                            fputc('1',filep4);
                        }

                    }
                    fclose(filep4);
                    filep5=fopen("hasilat.txt","r");

                    fprintf(filep5,"%d",toplam_hasilat);

                    fclose(filep5);

                    break;
                    break;

                default:
                    printf("\nYanlis secim yaptiniz.\n");
                    break;

            }
            break;

        case 2:
            filep5=fopen("hasilat.txt","r");

            fscanf(filep5,"%d",&toplam_hasilat);

            fclose(filep5);
            printf("\nToplam hasilat : %d TL.\n",toplam_hasilat);

            break;

        case 3:
            printf("\nRed salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Red[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            printf("\nGreen salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Green[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

            printf("\nBlue salonu izin izlenme bilgileri,\n");
            for(i=0;i<5;i++)
            {
                for(j=0;j<50;j++)
                {
                    if(psalon->Blue[i][j] == '1')
                    {
                        koltuksayaci++;

                    }
                }
                printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                koltuksayaci=0;
            }

            break;

        default:
            break;

    }

    }
