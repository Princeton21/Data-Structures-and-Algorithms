#include <stdio.h>
int main()
{
   int lowl, highl, check;
   printf("Enter two integer range:");
   scanf("%d %d",&lowl,&highl);
   printf("Prime numbers b/w %d and %d are:\n", lowl, highl);
   for(int i=(lowl +1); i<highl; ++i)
   {
     check=0;
      for(int j=2; j<=i/2; ++j)
      {
         if(i%j==0)
         {
            check=1;
            break;
         }
      }
      if(check==0&&i>1)
         printf("%d,",i);
  }
  printf( "\b \n");
  return 0;
}