#include <iostream>
using namespace std;

#define db(x) cout << (#x) <<" is "<< (x) << '\n'
#define size 100
int adj[size][size];

int main(){
    ios_base::sync_with_stdio(false);
    int vertex,edge,i,j;
    cin>>vertex>>edge;
    int node1,node2;
    for(i=0;i<edge;i++){
        int w;
        cin>>node1>>node2>>w;
        adj[node1][node2]=w;
        adj[node2][node1]=w;
    }
    for(i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++) cout<<adj[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
/*
8 9
0 3 3
0 4 6
1 5 5
1 6 1
2 4 6
3 5 8
5 6 3
5 7 2
6 7 6
*/