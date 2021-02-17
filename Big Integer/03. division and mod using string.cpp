//uva 10494
#include<iostream>
using namespace std;

int main() {
    long long n=0,arr[10000];
    string str,sym;
    while(cin>>str>>sym>>n){
        int siz=str.size();
        long long r=0,idx=0,c=0;
        for(int i=0;i<siz;++i){
            r=r*10+(str[i]-'0');
            if(c==1){
                arr[idx++]=r/n;
                r=r%n;
            }
            else if(r/n > 0){
                arr[idx++]=r/n;
                r=r%n;
                c=1;
            }
        }
        if(sym=="/"){
            for(int i=0;i<idx;++i) cout<<arr[i];
            if(idx==0) cout<<"0"; //handling 1st number is lesser than 2nd one
            cout<<'\n';
        }
        else{
            cout<<r<<endl;
        }
    }
    return 0;
} 

/*
71108506462 % 1470503465
228472406 / 1238433452
*/