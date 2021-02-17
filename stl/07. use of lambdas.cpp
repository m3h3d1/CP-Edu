#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

auto myfunc=[](int x) {
	cout<<endl<<x<<endl;
};
int main() {
	vector<int> v={561,222,2323,34};
	sort(v.begin(),v.end(),[](int x,int y)->bool {return x>y;});
	for(int x:v) cout<<x<<" ";
	myfunc(999);
	return 0;
}

/*
[capture-list](params) -> ReturnType {
	//code
};
*/