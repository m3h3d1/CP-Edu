#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
const int mxn = 2e5+9;
 
template <int N>
struct Sieve {
    bool is_prime[N];
    constexpr Sieve() : is_prime() {
        for (int i = 2; i < N; i++) {
            is_prime[i] = true;
        }
        for (int i = 2; i < N; i++)
            if (is_prime[i]) {
                for (int j = 2 * i; j < N; j += i) {
                    is_prime[j] = false;
                }
            }
    }
};
 
bool fast_is_prime(int n) {
    static constexpr Sieve<mxn> s;
    return s.is_prime[n];
}
 
bool slow_is_prime(int n) {
    return (Sieve<mxn>{}).is_prime[n];
}
 
const int reps = 1000;
int main() {
    vector<int> numbers(reps);
    for (int i = 0; i < reps; i++) {
        numbers[i] = rand() % mxn;
    }

    int ans = 0;
    auto t1 = chrono::high_resolution_clock::now();
    for (auto &n : numbers) {
        ans += fast_is_prime(n);
    }
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Compiletime ans: " << ans << ". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
 
    ans = 0;
    t1 = chrono::high_resolution_clock::now();
    for (auto &n : numbers) {
        ans += slow_is_prime(n);
    }
    t2 = chrono::high_resolution_clock::now();
    cout << "Runtime ans: " << ans << ". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;
}

/*
https://codeforces.com/blog/entry/79941
*/
/*
‘constexpr’ loop iteration count has limit of 262144 (use ‘-fconstexpr-loop-limit=’ to increase the limit), and we can't use -fconstexpr-loop-limit= parameter in CP, sadly this ideal may can't put prime sieve in practice


Of course no one re-computes sieve 1000 times, this is done here for the sole purpose of showing that the algorithm is not computing sieve in run time 1000 times.
*/