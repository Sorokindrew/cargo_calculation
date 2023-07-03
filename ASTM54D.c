#include "Cargo.h"

float ASTM54D(float Dens, float Temp)
{   /*system ("chcp 1251 > nul");
    char sDens[N], sTemp[N];
    int i;*/
    float /*Dens, Temp,*/ VCF;
    /*printf("Введите плотность\n");
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
       VCF = pow(M_E,(-0.6278/Dens * Temp * (1 + 0.8 * 0.6278/Dens * Temp)));
    /*printf("Плотность %g  Разность температур %g  VCF  %.4g\n", Dens, Temp, VCF);*/
    return VCF;
}
