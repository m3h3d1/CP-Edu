#include<stdio.h>
#include<string.h>
int main()
{
    printf("%d\n",-3%-3);
    char str[10000];
    int i; 
    long long int num,l,r;
    while(scanf("%s %lld",str,&num)){
        l=strlen(str);
        r=0;
        for(i=0;i<l;i++){
            r=r*10+(str[i]-'0');
            r=r%num;
        }
        printf("remainder is:%lld\n",r);
    }
    
}


/*
same
*/

/*#include<stdio.h>
#include <string.h>
int main()
{
   char bhajjo[1000];
   long long i,bhajok,bhagshesh=0;

   scanf("%s",bhajjo);
   scanf("%lld",&bhajok);

   int l=strlen(bhajjo);
   for(i=0; i<l; i++)
   {
       bhagshesh = ((bhagshesh*10) + (bhajjo[i]-'0') )%bhajok; // Amra character theke integer e convert kore nilam '0' biyog kore
   }
   printf("%lld\n",bhagshesh);
   return 0;
}
*/