#include<iostream>
#include<vector>
using namespace std;
vector<int> temp, res;
int mx,arr[25],n,m;

void func(int idx, int s) {
	if(s > mx) {
		mx = s;
		res = temp;
	}
	for(int i=idx;i<m;++i) {
		if(s+arr[i] <= n) {
			temp.push_back(arr[i]);
			func(i+1,s+arr[i]);
			temp.pop_back();
		}
	}
}
int main() {
	int a,b;
	while(scanf("%d %d",&n,&m) !=EOF) {
		mx = 0;
		for(int i=0;i<m;++i) scanf("%d",&arr[i]);
		func(0,0);
		for(int i=0;i<res.size();++i) {
			printf("%d ",res[i]);
		}
		printf("sum:%d\n",mx);
		temp.clear(), res.clear();
	}
	return 0;
}

/*
5 3  1 3 4
10 4  9 8 4 2
20 4  10 5 7 4
90 8  10 23 1 2 3 4 5 7
45 8  4 10 44 43 12 9 8 2
*/

/*
uva 634
You have a long drive by car ahead. You have a tape recorder, but unfortunately your best music is on
CDs. You need to have it on tapes so the problem to solve is: you have a tape N minutes long. How
to choose tracks from CD to get most out of tape space and have as short unused space as possible.
Assumptions:
• number of tracks on the CD does not exceed 20
• no track is longer than N minutes
• tracks do not repeat
• length of each track is expressed as an integer number
• N is also integer
Program should find the set of tracks which fills the tape best and print it in the same sequence as
the tracks are stored on the CD
*/