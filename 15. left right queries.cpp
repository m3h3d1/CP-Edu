//http://codeforces.com/contest/1066/problem/C
//C. Books Queries
#include<stdio.h>
int main(){
	int l=0,r=-1,T,a,arr[200005],x;
	char ch;
	scanf("%d",&T);
	while(T--){
		getchar();
		scanf("%c %d",&ch,&x);
		if(ch=='L') arr[x]=--l;
		else if(ch=='R') arr[x]=++r;
		else{
			a=(arr[x]-l) < (r-arr[x]) ? arr[x]-l : r-arr[x];
			printf("%d\n",a);
		}
	}
	return 0;
}

/*
8
L 1
R 2
R 3
? 2
L 4
? 1
L 5
? 1

Let's take a look at the first example and let's consider queries:

The shelf will look like [1];
The shelf will look like [1,2];
The shelf will look like [1,2,3];
The shelf looks like [1,2,3] so the answer is 1;
The shelf will look like [4,1,2,3];
The shelf looks like [4,1,2,3] so the answer is 1;
The shelf will look like [5,4,1,2,3];
The shelf looks like [5,4,1,2,3] so the answer is 2.
*/

/*
10
L 100
R 100000
R 123
L 101
? 123
L 10
R 115
? 100
R 110
? 115


Let's take a look at the second example and let's consider queries:

The shelf will look like [100];
The shelf will look like [100,100000];
The shelf will look like [100,100000,123];
The shelf will look like [101,100,100000,123];
The shelf looks like [101,100,100000,123] so the answer is 0;
The shelf will look like [10,101,100,100000,123];
The shelf will look like [10,101,100,100000,123,115];
The shelf looks like [10,101,100,100000,123,115] so the answer is 2;
The shelf will look like [10,101,100,100000,123,115,110];
The shelf looks like [10,101,100,100000,123,115,110] so the answer is 1.
*/