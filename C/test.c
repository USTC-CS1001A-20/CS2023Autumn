#include <stdio.h>
#include <math.h>
int main()
{
    float a3,a2,a1,a0,e,x,low,high,x1,xx=100,y;
    int i,n;
    scanf("%f %f %f %f\n",&a3,&a2,&a1,&a0);
    scanf("%f\n",&e);
    scanf("%f\n",&x);
    scanf("%f %f\n",&low,&high);
    for(i=0;xx>e;i++)
    {
        xx=(x*x*x*a3+x*x*a2+x*a1+a0)/(3*x*x*a3+2*x*a2+a1);
        x=x-xx;
        xx=fabs(xx);
    }
    for(n=0;high-low>=e;n++)
    {
        x1=(high+low)/2;
        y=x1*x1*x1*a3+x1*x1*a2+x1*a1+a0;
        if(high*y<=0)
            low=x1;
        else
            high=x1;
    }
    printf("%f\n",x);
    printf("%d\n",i);
    printf("%f\n",high);
    printf("%d\n",n);
    return 0;
}


