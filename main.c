#include "Cargo.h"



int main()
{   int i=0,j=0;

    int b, c;
    system ("chcp 1251 > nul");
    struct Tank Tnk[14];

    strcpy(Tnk[0].Name, "1P");
    strcpy(Tnk[1].Name, "1S");
    strcpy(Tnk[2].Name, "2P");
    strcpy(Tnk[3].Name, "2S");
    strcpy(Tnk[4].Name, "3P");
    strcpy(Tnk[5].Name, "3S");
    strcpy(Tnk[6].Name, "4P");
    strcpy(Tnk[7].Name, "4S");
    strcpy(Tnk[8].Name, "5P");
    strcpy(Tnk[9].Name, "5S");
    strcpy(Tnk[10].Name, "6P");
    strcpy(Tnk[11].Name, "6S");
    strcpy(Tnk[12].Name, "DP");
    strcpy(Tnk[13].Name, "DS");
    for (i=0;i<14;i++)
        {strcpy(Tnk[i].Grade, " ");
        strcpy(Tnk[i].Table, " ");
        Tnk[i].Dens=0;
        Tnk[i].Vol=0;
        Tnk[i].Temp=0;
        }


    system("chcp 1251 > nul");
    char File[5][27]={"Новый","Редактировать","Просмотреть Stowage Plan", "Просмотреть Ullage Report", "Выход"};
    char Menu[3][15]={"Grade 1", "Grade 2", "Grade 3"};

    while(1)
    {system("cls");


    for (i=0;i<5;i++)
    { if(j==i)
    printf(">%d. %s\n",i+1, File[i]);
    else
        printf(" %d. %s\n",i+1, File[i]);
    }

    printf("\nВыберите и нажмите Enter\n");

    b=getch();
    if (b==0xE0)
    {
        b=getch();
        switch (b)
        {
           case 0x50: j++; break;
           case 0x48:j--;break;
        }
        if (j<0)
            j=4;
        if (j>4)
            j=0;

    }
    switch (b)
    {
        case '1': j=0; break;
        case '2': j=1; break;
        case '3': j=2; break;
        case '4': j=3; break;
        case '5': j=4; exit(0);
    }
    if (b==0xD)
    {
        printf("%d\n",j);
        switch (j)
        {
            case 0: c=0; break;
            case 1: exit(0);
            case 2: exit(0);
            case 3: exit(0);
            case 4: exit(0);
        }
    if (c==0) break;
    }


    }

    while(1)
    {system("cls");


    for (i=0;i<3;i++)
    { if(j==i)
    printf(">%d. %s\n",i+1, Menu[i]);
    else
        printf(" %d. %s\n",i+1, Menu[i]);
    }

    printf("\nВыберите и нажмите Enter\n");

    b=getch();
    if (b==0xE0)
    {
        b=getch();
        switch (b)
        {
           case 0x50: j++; break;
           case 0x48:j--;break;
        }
        if (j<0)
            j=2;
        if (j>2)
            j=0;

    }
    switch (b)
    {
        case '1': j=0; break;
        case '2': j=1; break;
        case '3': j=2; break;
        case 0x1B: return;

    }
    if (b==0xD)
        Vvod(j,Tnk,Menu);
        //if(c==0) {Grade=j; break;}
    }





    /*char sDens[N], sTemp[N], sVol[N];

    //float Dens, Temp;
    printf("Введите назнание груза\n");
    fflush(stdin);
    gets(Tnk.Grade);
    printf("Введите Таблицу для вычисления\n");
    fflush(stdin);
    gets(Tnk.Table);
    printf("Введите объем груза\n");
    fflush(stdin);
    gets(sVol);
    Tnk.Vol=atof(sVol);
    printf("Введите плотность\n");
    fflush(stdin);
    gets(sDens);
    printf("Введите температуру\n");
    fflush(stdin);
    gets(sTemp);
    for (i=0;i<N;i++)
        {sDens[i]==','?sDens[i]='.':sDens[i];
         sTemp[i]==','?sTemp[i]='.':sTemp[i];}
    Tnk.Dens=atof(sDens);
    Tnk.Temp=atof(sTemp);
    printf("Dens %f Temp %f\n ", Tnk.Dens, Tnk.Temp);
    system ("pause");
    if (!strcmp(Tnk.Table, "ASTM54B"))
        {printf("Dens %f Temp %f\n ", Tnk.Dens, Tnk.Temp);
            Tnk.VCF = ASTM54B(Tnk.Dens,Tnk.Temp);}

    Tnk.Weight=Tnk.Vol*Tnk.Dens*Tnk.VCF;


    printf("|%s |%s |%.4f |%.2f |%.3f |%.4f |%.3f\n", Tnk.Grade, Tnk.Table, Tnk.Dens, Tnk.Temp, Tnk.Vol, Tnk.VCF, Tnk.Weight);

    //printf("VCF ASTM54B %.4f\nVCF ASTM54D %.4f\n", ASTM54B(Dens,Temp), ASTM54D(Dens, Temp));*/

}


