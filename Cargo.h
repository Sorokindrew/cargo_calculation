#ifndef CARGO_H
#define CARGO_H

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#define N 10
#define M 15

float ASTM54B(float Dens, float Temp);
float ASTM54D(float Dens, float Temp);

struct Tank
{
    char Name[3];
    char Grade[15];
    float Dens;
    char Table[10];
    float Vol;
    float VCF;
    float Temp;
    float Weight;
};
int Num_Grade(int , struct Tank *,char *);
void Vvod (int grade_num,struct Tank*,char *);
float StrToFl (char *, int size);

#endif // CARGO_H
