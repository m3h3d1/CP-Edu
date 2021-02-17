#include<iostream>
using namespace std;

class Myclass {
	int n;
	int *arr;
public:
	Myclass(int a) {
		n=a;
		arr=new int[n+1];
	}
	void input();
	void insertion_sort();
	void print();
};
void Myclass::input() {
	for(int i=1;i<=n;++i) {
	    int x=rand()%20+1;
	    arr[i]=x;
	}
	for(int i=1;i<=n;++i) {
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void Myclass::insertion_sort() {
	for(int j=2;j<=n;++j) {
	    int key=arr[j];
	    int i=j-1;
	    while(i>0 && arr[i]>key) {
	        arr[i+1]=arr[i];
	        i--;
	    }
	    arr[i+1]=key;
	}
}
void Myclass::print() {
	for(int i=1;i<=n;++i) cout<<arr[i]<<" ";
	cout<<endl;
}

int main() {
	srand(2);
	Myclass obj(10);
	obj.input();
	obj.insertion_sort();
	obj.print();
	return 0;
}