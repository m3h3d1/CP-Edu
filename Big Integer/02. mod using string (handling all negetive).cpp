//Handling negetive numbers

#include<iostream>
using namespace std;

int main() {
  int n,cas=0,T;
  string str;
  cin>>T;
  while(T--) {
    cin>>str>>n;
    long long r=0;
    int i;
    if(str[0]=='-') i=1;
    else i=0;
    for(;str[i];++i) {
      r=r*10+(str[i]-'0');
      r=r%n;
    }
    printf("Case %d: remainder=%lld\n",++cas,r);
  }
  return 0;
}

/*
6

101 101
0 67
-101 101
7678123668327637674887634 101
11010000000000000000 256
-202202202202000202202202 -101
*/

/*
Input starts with an integer T (≤ 525), denoting the number of test cases.
Each case starts with a line containing two integers a (-10^200 ≤ a ≤ 10^200) 
and b (|b| > 0, b fits into a 32 bit signed integer). 
Numbers will not contain leading zeroes.
*/