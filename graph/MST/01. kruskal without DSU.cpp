#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
    int u,v,weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main() {
    int n=5;
    vector<Edge> edges;

    int cost = 0;
    vector<int> tree_id(n);
    vector<Edge> result;
    for(int i=0;i<n;++i) {
        tree_id[i] = i;
    }

    sort(edges.begin(),edges.end());

    for(Edge e: edges) {
        if(tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for(int i=0;i<n;++i) {
                if(tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }
    return 0;
}

/*
cp-algorithms

The simplest implementation:
The following code directly implements the algorithm described above, and is having O(MlogM+N^2) time complexity. 
Sorting edges requires O(MlogN) (which is the same as O(MlogM)) operations. Information regarding the subtree to which a vertex belongs is maintained with the help of an array tree_id[] - for each vertex v, tree_id[v] stores the number of the tree , to which v belongs. 
For each edge, whether it belongs to the ends of different trees, can be determined in O(1). Finally, the union of the two trees is carried out in O(N) by a simple pass through tree_id[] array. Given that the total number of merge operations is N−1, we obtain the asymptotic behavior of O(MlogN+N^2).





Proof of correctness:
Why does Kruskal's algorithm give us the correct result?

If the original graph was connected, then also the resulting graph will be connected. Because otherwise there would be two components that could be connected with at least one edge. Though this is impossible, because Kruskal would have chosen one of these edges, since the ids of the components are different. Also the resulting graph doesn't contain any cycles, since we forbid this explicitly in the algorithm. Therefore the algorithm generates a spanning tree.

So why does this algorithm give us a minimum spanning tree?

We can show the proposal "if F is a set of edges chosen by the algorithm at any stage in the algorithm, then there exists a MST that contains all edges of F" using induction.

The proposal is obviously true at the beginning, the empty set is a subset of any MST.

Now let's assume F is some edge set at any stage of the algorithm, T is a MST containing F and e is the new edge we want to add using Kruskal.

If e generates a cycle, then we don't add it, and so the proposal is still true after this step.

In case that T already contains e, the proposal is also true after this step.

In case T doesn't contain the edge e, then T+e will contains a cycle C. This cycle will contain at least one edge f, that is not in F. The set of edges T−f+e will also be a spanning tree. Notice that the weight of f cannot be smaller than the weight of e, because otherwise Kruskal would have chosen f earlier. It also cannot have a bigger weight, since that would make the total weight of T−f+e smaller than the total weight of T, which is impossible since T is already a MST. This means that the weight of e has to be the same as the weight of f. Therefore T−f+e is also a MST, and it contains all edges from F+e. So also here the proposal is still fulfilled after the step.

This proves the proposal. Which means that after iterating over all edges the resulting edge set will be connected, and will be contained in a MST, which means that it has to be a MST already.
*/