#include<stdio.h>
int main()
{
    int a,b,c,d;

    for(a=100;a<=999;a=a+1);
    {
        b=a%10, c=(a/10)%10, d=(a/100)%10;
        if(a==b*b*b+c*c*c+d*d*d);
             printf("%d \n",a);

        //printf("%d ", a);
        //printf("%d \n", b*b*b+c*c*c+d*d*d);
    }
    return 0;
}

//for和if后有；