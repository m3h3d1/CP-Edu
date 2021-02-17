#include<stdio.h>
#include<string.h>
int main()
{
    while(1){
        char str[1001]; int n,arr[1000];
        scanf("%s %d",str,&n);
        int l=strlen(str);
        int r=0;
        int idx=0;// index of array
        int c=0;// to activate just 1 condition (either or 'if' neither nor 'else if')
        for(int i=0;i<l;i++){
            r=r*10+(str[i]-'0');
            if(c==1){
                arr[idx++]=r/n;
                r=r%n;
                //idx++;
            }
            else if(r/n>0){ //this condition will be implimented for just once. it is used to eliminate '0' from the main value of quotient
                arr[idx++]=r/n;
                r=r%n;
                //idx++;
                c=1;
            }
        }
        printf("quotiont is:");
        for(int i=0;i<idx;i++) printf("%d",arr[i]);
        if(idx==0) printf("0");; //handling 1st number is lesser than 2nd one
        printf("\nremainder is:%d\n",r);
    }
    return 0;
}
