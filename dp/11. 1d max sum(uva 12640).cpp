#include <iostream>
#include<sstream>
#include<stdio.h>
using namespace std;

int main(){
    int max,sum,num;
    string str;
    while(getline(cin,str)){
        stringstream ss(str);
        sum=0,max=0;
        while(ss>>num){
            sum+=num;
            max=max(sum,max);
            if(sum<0) sum=0;
        }
        printf("%d\n",max);
        str.clear();
    }
    return 0;
}

/*
1 2 3 4 5 6 7 8 9
-1 -1 -1
23 -1 -24 2 23
1 -14 -4 14 -11 -7 6
-2 -3 4 -1 -2 1 5 -3
*/