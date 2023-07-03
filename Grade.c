#include "Cargo.h"
int Num_Grade(int num, struct Tank *p, char *m)
{
    //int num;
    printf("¬ведите название груза дл€ Grade %d\n",num+1);
    fflush(stdin);
    gets(m+15*num/*(p+num)->Grade*/);
    //strcpy((m+15*num),(p+num)->Grade);
    return 0;
}
