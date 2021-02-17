#include<iostream>
using namespace std;
#define mxn 7489
int dp[mxn+7];
// dp[i] will be storing the number of solutions for value i. 
// We need n+1 rows as the table is constructed in 
// bottom up manner using the base case (n = 0) 

void pre() {
	int n = 5;
	int coin[] = {1,5,10,25,50};
	dp[0] = 1; // there is one way to get sum 0: take nothing

	// Pick all coins one by one and update the dp[] values after
    // the index greater than or equal to the value of the picked coin
	for(int i=0;i<n;++i) {
		for(int j=coin[i];j<=mxn;++j) {
			dp[j] += dp[j-coin[i]];
		}
	}
}
int main() {
	pre();
	int mon;
	while(cin>>mon) {
		cout<<dp[mon]<<endl;
	}
	return 0;
}

/*
Time Complexity: O(mn)
The auxiliary space required here is O(n) only
*/