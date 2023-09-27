#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main (){
    printf ("\aStartled by the sudden sound ,Sally shouted,\n\"By the Great Pumpkin,what was that!\"");
    int a = 153351;
    for(unsigned i = 1; (int)log2(i) < 8*sizeof(int); i<<=1){
        printf("%d", (i&a)>>(unsigned int)log2(i));
    }
    return 0;
}
