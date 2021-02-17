#include<bits/stdc++.h>
using namespace std;
#define lchild v<<1,l,m
#define rchild v<<1|1,m+1,r
const int mxn = 3e4+9;
#define ll long long
char str[mxn];
struct Data {
    int open, close;
    void assign(char ch) {
        if(ch=='(') {
            open = 1, close = 0;
        }
        else {
            open = 0, close = 1;
        }
    }
    void merge(Data a, Data b) {
        int match = min(a.open, b.close);
        open = a.open + b.open - match;
        close = a.close + b.close - match;
    }
} st[mxn*4];

void update(int v, int l, int r, int i) {
    if(l==r) {
        st[v].assign(str[l]);
        return;
    }
    int m = (l+r)/2;
    if(i<=m) update(lchild,i);
    else update(rchild,i);
    st[v].merge(st[v*2], st[v*2+1]);
}
void build(int v, int l, int r) {
    if(l==r) {
        st[v].assign(str[l]);
        return;
    }
    int m = (l+r)/2;
    build(lchild);
    build(rchild);
    st[v].merge(st[v*2], st[v*2+1]);
}
int main() {
    int n,q,x;
    for(int cas=1;cas<=10;++cas) {
        scanf("%d",&n);
        getchar();
        printf("Test %d:\n", cas);
        for(int i=1;i<=n;++i) {
            str[i] = getchar();
        }
        build(1,1,n);
        scanf("%d",&q);
        while(q--) {
            scanf("%d",&x);
            if(x!=0) {
                if(str[x]=='(') str[x] = ')';
                else str[x] = '(';
                update(1,1,n,x);
            }
            else {
                //printf("    %d %d\n", st[1].open,st[1].close);
                if(st[1].open==0 && st[1].close==0) printf("YES\n");
                else printf("NO\n");
            }
        }
    }
    return 0;
}

/*
Brackets SPOJ - BRCKTS 

Input:
4
()((
4
4
0
2
0
[and 9 test cases more]
Output:
Test 1:
YES
NO
[and 9 test cases more]
*/

/*
We will call a bracket word any word constructed out of two sorts of characters: the opening bracket "(" and the closing bracket ")". Among these words we will distinguish correct bracket expressions. These are such bracket words in which the brackets can be matched into pairs such that

every pair consists of an opening bracket and a closing bracket appearing further in the bracket word
for every pair the part of the word between the brackets of this pair has equal number of opening and closing brackets
On a bracket word one can do the following operations:
replacement -- changes the i-th bracket into the opposite one
check -- if the word is a correct bracket expression
Task
Write a program which

reads (from standard input) the bracket word and the sequence of operations performed,
for every check operation determines if the current bracket word is a correct bracket expression,
writes out the outcome (to standard output).
*/

/*
This problem gives a string containing parenthesis (open and closed), requires making updates to individual parenthesis (changing an open parenthesis to closed or vice versa), and checking if the whole string represents a correct parenthesization.
As it turns out, we need only 2 things in each segment tree node:

The number of unmatched open parenthesis in this range
The number of unmatched closed parenthesis in this range
*/