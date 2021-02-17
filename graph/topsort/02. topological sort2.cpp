#include<iostream>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
vector< vector<int> > adj; //or, vector<int> *adj;
stack<int> st;
bool *visited;

void dfs(int x) {
    visited[x]=true;
    for(int i=0;i<adj[x].size();++i) if(!visited[adj[x][i]]) {
        dfs(adj[x][i]);
    }
    st.push(x);
}
void toposort(int node) {
    visited=new bool[node];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<node;++i) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int node,edge,a,b;
    cin>>node>>edge;
    adj.resize(node+1); //or, adj=new vector<int> [node];
    for(int i=0;i<edge;++i) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    toposort(node);
    for(int i=0;i<node;++i) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}

/*
5 5

0 1
4 2
1 3
1 4
4 3

*/