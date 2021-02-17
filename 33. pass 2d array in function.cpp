#include<iostream>
using namespace std;

void func(int **arr){
	cout<<arr[1][1]<<endl;
}
int main() {
	int r=2,c=2;
	int **arr=new int*[r];
	for(int i=0;i<r;++i) {
		arr[i]=new int[c];
	}
	for(int i=0;i<r;++i) for(int j=0;j<c;++j) {
		cin>>arr[i][j];
	}
	func(arr);
	return 0;
} 

/*
1 2
3 4
*/