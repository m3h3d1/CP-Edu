#include<iostream>
#include<cstring>
using namespace std;
const int mxn = 1e6+5;
struct Node {
	int end;
	int child[26];
	Node() {
		end = 0;
		memset(child,-1,sizeof(child));
	}
};
Node tree[mxn];

int avail = 0;
void insert(string str) {
	int cur = 0;
	for(int i=0;i<str.size();++i) {
		int x = str[i]-'a';
		if(tree[cur].child[x]==-1) {
			tree[cur].child[x]=++avail;
		}
		cur = tree[cur].child[x];
	}
	tree[cur].end = 1;
}
int query(string str) {
	int cur = 0;
	for(int i=0;i<str.size();++i) {
		int x = str[i]-'a';
		if(tree[cur].child[x]==-1) return 0;
		cur = tree[cur].child[x];
		// cout<<str<<" "<<tree[cur].end<<endl;
	}
	return tree[cur].end;
}
int main() {
	insert("abcdef");
	insert("abc");
	insert("ab");
	insert("abk");
	printf("%d\n",query("abc"));
	printf("%d\n",query("abk"));
	printf("%d\n",query("a"));
	printf("%d\n",query("adc"));
	printf("%d\n",query("abcdef"));
	return 0;
}