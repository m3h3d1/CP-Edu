#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > st;

int intersectionCardinality(vector<int> &idx) {
    //if(idx.size()==0) return 0;

    printf("Set indexes -> ");
    for(int i=0;i<idx.size();++i) {
        printf("%d ", idx[i]);
    }
    printf("\n");

    vector<int> v = st[idx[0]];
    for(int i=1;i<idx.size();++i) {
        auto it=set_intersection(v.begin(), v.end(), st[idx[i]].begin(), st[idx[i]].end(), v.begin());
        v.resize(it-v.begin());
    }
    printf("Intersection: ");
    for(int i=0;i<v.size();++i) printf("%d ", v[i]);
    printf("\n");
    return v.size();
}
int main() {
    int n, x;
    cin>>n; cin.ignore();
    st.resize(n);
    for(int i=0;i<n;++i) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        while(ss>>x) st[i].push_back(x);
        sort(st[i].begin(), st[i].end());
    }
    int res=0;
    for(int b=1;b<(1<<n);++b) { //b=0 is empty set
        vector<int> idx;
        for(int k=0;k<n;++k) {
            if(b&(1<<k)) {
                idx.push_back(k);
            }
        }
        int cardinality = intersectionCardinality(idx);
        if(idx.size()%2 == 1) res += cardinality;
        else res -= cardinality;
    }
    cout<<"Result: "<<res<<endl;
    return 0;
}

/*
4
1 2 3
2 3 4
1 3 5
2 3
*/

//https://www.hackerearth.com/practice/math/combinatorics/inclusion-exclusion/tutorial/

/*
//Template function of set_intersection:
template <class InputIterator1, class InputIterator2, class OutputIterator>
  OutputIterator set_intersection (InputIterator1 first1, InputIterator1 last1,
                                   InputIterator2 first2, InputIterator2 last2,
                                   OutputIterator result)
{
  while (first1!=last1 && first2!=last2)
  {
    if (*first1<*first2) ++first1;
    else if (*first2<*first1) ++first2;
    else {
      *result = *first1;
      ++result; ++first1; ++first2;
    }
  }
  return result;
}
*/