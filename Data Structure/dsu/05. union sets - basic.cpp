#include<bits/stdc++.h>
using namespace std;
vector<int> par,Rank;

int find_par(int u) {
    if(par[u] == u) return u;
    return par[u] = find_par(par[u]);
}
void union_set(int a,int b) {
    a = find_par(a);
    b = find_par(b);
    if(a != b) par[a] = b;
}

// void union_set(int a, int b) {
//     a = find_par(a);
//     b = find_par(b);
//     if (a != b) {
//         if (Rank[a] < Rank[b])
//         {
//             par[a]=b;
//             Rank[b]++;
//         }

//         else
//         {
//             par[b]=a;
//             Rank[a]++;
//         }
//     }
// }
int main() {
    int n=5;
    par.resize(n+1);
    Rank.resize(n+1);
    for(int i=1;i<=n;++i) par[i] = i;
    union_set(1, 3);
    union_set(2, 1);
    union_set(4, 5);
    for(int i=1;i<=n;++i) cout<<i<<" "<<par[i]<<endl;
    return 0;
}