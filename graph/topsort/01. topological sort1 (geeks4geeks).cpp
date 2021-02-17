#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph {
	int v;
	list<int> *adj;
	void topologicalSortUtil(int v,bool visited[],stack<int>&st);
public:
	Graph(int v) {
		this->v=v;
		adj=new list<int>[v];
	}
	void addEdge(int v,int w) {
		adj[v].push_back(w);
	}
	void topologicalSort() {
		stack<int> st;
		bool *visited=new bool[v];
		for(int i=0;i<v;++i) {
			visited[i]=false;
		}
		for(int i=0;i<v;++i) {
			if(!visited[i]) {
				topologicalSortUtil(i,visited,st);
			}
		}
		while(!st.empty()) {
			cout<<st.top()<<" ";
			st.pop();
		}
	}
};

void Graph::topologicalSortUtil(int v,bool visited[],stack<int>&st) {
	visited[v]=true;
	for(list<int>::iterator it=adj[v].begin();it!=adj[v].end();++it) {
		if(!visited[*it]){
			topologicalSortUtil(*it,visited,st);
		}
	}
	st.push(v);
}

int main() {
	int a,b,n;
	Graph g(6);
	for(int i=0;i<6;++i) {
		cin>>a>>b;
		g.addEdge(a,b);
	}

	cout<<"Topological sort:\n";
	g.topologicalSort();
	return 0;
}

/*
5 2
5 0
4 0
4 1
2 3
3 1
*/