#include <iostream>
using namespace std;
#define db(x) cout << (#x) <<" is "<< (x) << '\n'

int main(){
    int i,j,len,max,c,sum[105]={0};
    string str;
    while(cin>>str){
        if(str=="0") break;
        len=str.size();
        if(len>max) max=len;
        for(i=0,j=len-1;i<len;i++,j--){
            sum[i]+=str[j]-'0';
        }
    }
    c=0;
    for(i=0;i<max;i++){
        sum[i]+=c;
        if(sum[i]>=10){
            c=sum[i]/10;
            sum[i]%=10;
        }
        else c=0;
    }
    if(c>0) printf("%d",c);
    for(i=max-1;i>=0;i--) printf("%d",sum[i]);
    printf("\n");
    return 0;
}