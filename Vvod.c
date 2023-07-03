#include "Cargo.h"

void Vvod (int num, struct Tank*p, char *m)
{   char sDens[N], sTemp[N], sVol[N], sTable[N];

    int i,j=0,b,c=1;
    char Nast[2][40]={"Настройки (название, плотность и тд)", "Создать Ullage report"};
    char Tab[3][10]={"ASTM54B","ASTM54D","Chem"};


    while(1)
{   system ("cls");
    printf("%s\n", m+15*num);
    for (i=0; i<2;i++)
        {if (i==j)
        printf(">%s\n", Nast[i]);
        else printf(" %s\n", Nast[i]);}
    b=getch();

        switch(b)
        {
            case 0xE0: switch (getch()) {case 0x50: j++; break; case 0x48: j--; break;} if (j<0) j=1; if (j>1) j=0;  break;
            case 13: c=0; break;
        }
        if (c==0) break;
}



    if (j==0)  //если выбраны настройки
        {
           system("cls");
    printf("Введите название груза для Grade %d\n", num+1);
    fflush(stdin);
    gets(m+15*num);
    c=1;
    while(1)
    { system("cls");
        printf("Выберете танки для погрузки %s\n",m+15*num);
        printf("\n");

        for (i=0;i<14;i++)
        {if(i==j)
            printf("> %s %s\n", (p+i)->Name,(p+i)->Grade);
            else printf("  %s %s\n", (p+i)->Name,(p+i)->Grade);
        }
       b=getch();

        switch(b)
        {
            case 32: if (strcmp((p+j)->Grade, " ")==0)
                        strcpy((p+j)->Grade,m+15*num);
                        else strcpy((p+j)->Grade," "); break;
            case 0xE0: switch (getch()) {case 0x50: j++; break; case 0x48: j--; break;} if (j<0) j=13; if (j>13) j=0;  break;
            case 13: c=0; break;
        }
        if (c==0) break;
        }

    system("cls");
    printf("Введите Таблицу для вычисления\n");
        c=1;j=0;
        while(1)
{   system ("cls");
    for (i=0; i<3;i++)
        {if (i==j)
        printf(">%s\n", Tab[i]);
        else printf(" %s\n", Tab[i]);}
    b=getch();

        switch(b)
        {
            case 0xE0: switch (getch()) {case 0x50: j++; break; case 0x48: j--; break;} if (j<0) j=2; if (j>2) j=0;  break;
            case 13: c=0; strcpy(sTable, Tab[j]); break;
        }
        if (c==0) break;}

        if (j==2)
        {printf("Введите коэффициент\n");
        fflush(stdin);
        scanf("%s",&sTable);}


    for (i=0;i<14;i++)
       if (strcmp((p+i)->Grade,m+15*num)==0)
        strcpy((p+i)->Table, sTable);

    system("cls");
    printf("Введите плотность\n");
    fflush(stdin);
    gets(sDens);


    for (i=0;i<14;i++)
        if (strcmp((p+i)->Grade,m+15*num)==0)
        (p+i)->Dens= StrToFl(sDens,N);

   for (i=0;i<14;i++)
        printf("%3s %10s %8s %.4f\n", (p+i)->Name, (p+i)->Grade, (p+i)->Table,(p+i)->Dens);
        system("pause");
        }
        else // если выбран Ullage report
        {
            for (i=0;i<14;i++)
            {   system("cls");
                if (strcmp((p+i)->Grade,m+15*num)==0)
                    {printf("Введите объем груза в танке %s\n", (p+i)->Name);
                fflush(stdin);
                gets(sVol);
                (p+i)->Vol = StrToFl(sVol,N);
                system("cls");
                printf("Введите температуру груза в танке %s\n", (p+i)->Name);
                fflush(stdin);
                gets(sTemp);
                (p+i)->Temp = StrToFl(sTemp,N);
                }

              }

    FILE *fp=fopen("Ullage.txt","wt");
    //fseek(fp,0L,SEEK_SET);
        for (i=0;i<14;i++)
        fprintf(fp,"| %3s | %10s | %8s | %.4f | %-6.2f | %-4.1f |\n", (p+i)->Name, (p+i)->Grade, (p+i)->Table,(p+i)->Dens, (p+i)->Vol, (p+i)->Temp );
        //system("pause");
   fclose(fp);
}
}
