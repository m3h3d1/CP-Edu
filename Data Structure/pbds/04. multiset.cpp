// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

#include<iostream>
#include<vector>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using __gnu_pbds::tree;
using __gnu_pbds::null_type;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree_order_statistics_node_update;

int main(){
    tree<int,null_type,std::less_equal<int>,
        rb_tree_tag,tree_order_statistics_node_update> t;

    { // initialize
        t.insert(3);
        t.insert(2);
        t.insert(1);
        t.insert(3);
        t.insert(1);
        t.insert(3);
        t.insert(1);
        t.insert(2);
        t.insert(3);
    }

    { // expected behavior
        assert(t.size()==9);
        assert(!t.empty());

        assert((std::vector<int>(begin(t),end(t))==
                std::vector<int>{1,1,1,2,2,3,3,3,3}));
        assert((std::vector<int>(rbegin(t),rend(t))==
                std::vector<int>{3,3,3,3,2,2,1,1,1}));
    }

    /* // unsupported functions (for both "set" and "multiset")
        t.count(1);

        t.emplace(1);

        std::vector<int> z{4,5};
        t.insert(begin(z),end(z)); // insert range
    */

    // find will always return end
    assert(t.find(1)==t.end());
    assert(t.find(2)==t.end());

    // lower_bound works like upper_bound in normal set
    // (to return the first element > it)
    assert(*t.lower_bound(1)==2);
    assert(*t.lower_bound(2)==3);

    // upper_bound works like lower_bound in normal set
    // (to return the first element >= it)
    assert(*t.upper_bound(1)==1);
    assert(*t.upper_bound(2)==2);

    // note that find_by_order and order_of_key works properly
    // and doesn't need subtraction by 1
    assert(t.order_of_key(1)==0);
    assert(t.order_of_key(2)==3);
    assert(t.order_of_key(3)==5);

    assert(*t.find_by_order(0)==1);
    assert(*t.find_by_order(1)==1);
    assert(*t.find_by_order(3)==2);
    assert(*t.find_by_order(6)==3);

    std::cin.get();
}

/*
Note on using less_equal as comparison function to use it as a multiset:
    _GLIBCXX_DEBUG must not be defined, otherwise some internal check will fail.
    find will always return end.
    lower_bound works like upper_bound in normal set (to return the first element > it)
    upper_bound works like lower_bound in normal set (to return the first element >= it)
    find_by_order and order_of_key works properly (unlike the 2 functions above).
*/