#include "Cargo.h"

float ASTM54B(float Dens, float Temp)
{   /*system ("chcp 1251 > nul");
    char sDens[N], sTemp[N];
    int i;*/
    float /*Dens, Temp,*/ VCF;/*
    printf("Введите плотность\n");
    fflush(stdin);
    gets(sDens);
    printf("Введите температуру\n");
    fflush(stdin);
    gets(sTemp);
    for (i=0;i<N;i++)
        {sDens[i]==','?sDens[i]='.':sDens[i];
         sTemp[i]==','?sTemp[i]='.':sTemp[i];}
    Dens=atof(sDens);
    Temp=atof(sTemp);*/
    Dens*=1000;
    Temp-=15;
    if (Dens>839&&Dens<1075)
        VCF = pow(M_E,(-(186.9696 / (Dens*Dens)+ 0.4862 / Dens) * Temp * (1 + 0.8 * (186.9696 / (Dens*Dens) + 0.4862 / Dens) * Temp)));
    else if (Dens > 788 && Dens < 838.5)
        VCF = pow(M_E,(-594.5418 / (Dens*Dens) * Temp * (1 + 0.8 * 594.5418 / (Dens*Dens)  * Temp)));
    else if (Dens > 770.5 && Dens < 787.5)
        VCF = pow(M_E,(-(-0.00336312 + 2680.3206 / (Dens*Dens)) * Temp * (1 + 0.8 * (-0.00336312 + 2680.3206 / (Dens*Dens) * Temp))));
    else
        VCF = pow(M_E,(-(346.4228 / (Dens*Dens) + 0.4388 / Dens) * Temp * (1 + 0.8 * (346.4228 / (Dens*Dens) + 0.4388 / Dens) * Temp)));
    /*printf("Плотность %g  Разность температур %g  VCF  %.4g\n", Dens, Temp, VCF);*/
    return VCF;
}
