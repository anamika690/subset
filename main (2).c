/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
long set[] = {3,2,1,2,4,3,4,1};
long sum =7;
long n = sizeof(set)/sizeof(set[0]);
iter_subset_sum(set, n, sum);
return 0;
}

int iter_subset_sum (int *y, long n, long sum) {
  int i,j,k,**x;
  x=malloc((n+1)*sizeof(long**));
  for(i=0;i<=n;i++)
    x[i]=malloc((sum+1)*sizeof(long*));

  for (i=0; i<=n; i++)
    x[i][0] = 1;    
  for (i=1; i<=sum; i++)
    x[0][i] =0;
  for (i=1; i<=n; i++) {    
    for (j=1; j<=sum; j++){
    x[i][j]=x[i-1][j];
    if(j>=y[i-1])
        x[i][j]+=x[i-1][j-y[i-1]];  }   }
  for (i = 0; i <= n; i++){
        for (j = 0; j <= sum; j++)
          printf ("%4d", x[i][j]);
              printf("\n");
      }
      printf("There are %d subsets :", x[n][sum]);
}