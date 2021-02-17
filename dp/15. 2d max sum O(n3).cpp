#include<bits/stdc++.h>
using namespace std;
int r, c;
int A[105][105], temp[105];

int findmax(int j) {
    int sum = 0, curMax = 0;
    for(int k=0;k<c;++k) {
        temp[k]+=A[j][k];
        sum+=temp[k];
        if(sum<0) sum=0;
        else if(sum>curMax) curMax=sum;
    }
    return curMax;
}
int solve() {
    int Max = 0;
    for(int i=0;i<r;++i) { //L
        memset(temp, 0, sizeof(temp));
        for(int j=i;j<r;++j) { //R
            int curMax = findmax(j);
            if(curMax>Max) Max = curMax;
        }
    }
    return Max;
}
int main() {
    while(cin>>r>>c) {
        for(int i=0;i<r;++i) {
            for(int j=0;j<c;++j) {
                cin>>A[i][j];
            }
        }
        int res = solve();
        cout<<res<<endl;
    }
    return 0;
}

/*
4 5
 2  1 -3 -4  5
 0  6  3  4  1
 2 -2 -1  4 -5
-3  3  1  0  3
*/
/*
4 5
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
*/

/*
https://www.redgreencode.com/three-ways-solve-uva-108/
https://www.pwzxxm.com/2016/uva-108/
*/
/*
define integer array memo[N][N]
read input values into memo
for each startRow
    define integer array squashed[N]
    for each endRow
        for each col
            increment squashed[col] by memo[endRow][col]
        for each col
            increment candidateSum by squashed[col]
            if candidateSum > sum, update sum
            if candidateSum < 0, candidateSum = 0
        if sum > max, update max
print max
*/

/*
In one dimension, if we want to find the maximum sum of successive elements, we have equation:
    d[k]=max(d[k−1]+d[k],d[k])
There is a small improvement. By using greedy, we know if the sum is less than 0, there is no point to "add" it, we can just discard it.

After we know how to compute in one dimension, it is easy to do it in two dimension.

Let,
i = the starting line 
j = the ending line, where i <= j 
k = the number of columns

We can compress all lines between i and j into a 1D array. In other words, add each number in the same column together and put it in the 1D array. Hence, we have an array with i to j lines in it.

Now, it is just the problem we have already seen. Find the maximum sum of successive elements in the 1D array. That is the sum of the whole rectangle in the original 2D array.
*/