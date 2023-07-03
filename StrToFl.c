#include "Cargo.h"

float StrToFl (char* s, int size)
{ int i;
float fl;
    for (i=0; i<size;i++)
                *(s+i)==','?*(s+i)='.':*(s+i);

    fl=atof(s);
    return fl;
}
