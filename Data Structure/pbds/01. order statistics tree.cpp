#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp> //common file
#include<ext/pb_ds/tree_policy.hpp> //Including tree_order_statistics_node_update
using namespace __gnu_pbds;

template <typename T> using orderedSet =
	tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n=5;
	orderedSet<int> os;
	for(int i=1;i<=n;++i) os.insert(i);
	os.insert(3);

	cout<<os.size()<<endl;
	for(auto x:os) cout<<x<<" "; //print all set values
	cout<<endl;
	
	os.erase(os.find_by_order(os.order_of_key(3))); //order_of_key-> returns index of element, find_by_order-> returns pointer of indexed value
	//same as os.erase(os.find_by_order(2));

	for(auto it=os.begin();it!=os.end();++it) cout<<*it<<" ";
	cout<<endl;
	
	if(os.find(3)==os.end()) cout<<"not found\n";
	return 0;
}