#include<stdio.h>
#include<math.h>
int main()
{
  long double k=0,x,z,y=0;
  printf("请输入精度");
  printf("\n");
  scanf("%f",&x);
  while(y-3.1415926>x||3.1415926-y>x) {
    z=pow(16,-k);
    y=z*(4.0/(8*k+1)-2.0/(8*k+4)-1.0/(8*k+5)-1.0/(8*k+6))+y;
    k++;
    }
  printf("%lf",y);
  return 0;
}

/* long double k=0,x,z,y=0;
  scanf("%f",&x);
  变量格式和输入不匹配*/