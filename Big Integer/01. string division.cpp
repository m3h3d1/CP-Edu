#include <bits/stdc++.h>
using namespace std;
 
string longDivision(string num, int divisor) {
    string ans;
 
    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = num[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (num[++idx] - '0');
 
    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (num.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';
 
        // Take next digit of number
        temp = (temp % divisor) * 10 + num[++idx] - '0';
    }
 
    // If divisor is greater than number
    if (ans.length() == 0) return "0";
 
    return ans;
}
 
int main() {
    string num = "1248163264128256512";
    int divisor = 125;
    cout << longDivision(num, divisor);
    return 0;
}