#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
 
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, 
             tree_order_statistics_node_update> ordered_multiset;
 
int main() {
    ordered_multiset ms;
    vector<int> v{1, 1, 2, 2, 2, 3, 4, 5, 6, 6};
 
    for(int i : v) ms.insert(i);
 
    cout << "Ordered Multiset: ";
    for(auto x : ms) cout << x << ' '; 
    cout << '\n';
 
    cout << "Lower bound of 2: " << *ms.lower_bound(6) << '\n';
    cout << "Upper bound of 2: " << *ms.upper_bound(6) << '\n';
    return 0;
}

/*
Another drawback of using less_equal instead of less is that lower_bound works as upper_bound and vice-versa. 


To delete element:
ordered_set :: iterator it; it=st.upper_bound(key); st.erase(it); it works;
*/