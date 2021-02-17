#include<stdio.h>
#include<math.h>
#include<string.h>
#define db(x) printf("%s is %d\n",#x,x);
int factors[105][105];

void pFactors(int num){
    int n=num;
    while(n%2==0){
        factors[num][2]++;
        n=n/2;
    }
    int i;
    for(i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            factors[num][i]++;
            n=n/i;
        }
    }
    if(n>2){
        factors[num][n]++;
    }
}
void fact(){
    int i;
    for(i=2;i<=100;i++){
        pFactors(i);
    }
}
void traverseFact(int n){
    int i,j,arr[101]={0};
    for(i=n;i>=2;i--){
        arr[2]+=factors[i][2];
        for(j=3;j<=n;j+=2){
            arr[j]+=factors[i][j];
        }
    }
    int cnt=0,c=1;
    if(arr[2]) {
        printf("%3d",arr[2]);
        cnt++;
    }
    for(i=3;i<=n;i+=2){
        if(arr[i]) {
            if(c==0){
                printf("      ");
                c=1;
            }
            printf("%3d",arr[i]);
            cnt++;
        }
        if(cnt==15) {
            printf("\n");
            cnt=0;
            c=0;
        }
    }
    if(c) printf("\n");
}

int main(){
    int n;
    fact();
    while(scanf("%d",&n) && n){
        printf("%3d! =",n);
        traverseFact(n);
    }
    return 0;
}