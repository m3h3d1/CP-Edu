#include<bits/stdc++.h>
using namespace std;
int A[15];

int lis(int n) {
	set<int> s;
	for(int i=0;i<n;++i) {
		if(s.insert(A[i]).second) { //if 1 new element is inserted
			auto it = s.find(A[i]);
			it++;
			if(it != s.end()) {
				s.erase(it);
			}
		}
	}
	return s.size();
}
int main() {
	int a,b,n,T,cas=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i) {
		scanf("%d",&A[i]);
	}
	int res = lis(n);
	printf("%d\n", res);
	return 0;
}

/*
5
1 4 2 4 3
*/

/*
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for(int x: nums) {
            if(sub.empty() || sub.back()<x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x);
                *it = x;
            }
        }
        for(int x: sub) cout<<x<<" ";
        return sub.size();
    }
*/