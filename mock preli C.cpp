#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

const int MOD = 998244353;

// Function to calculate power with modular arithmetic
long long modPow(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate modular inverse
long long modInverse(long long x, int mod) {
    return modPow(x, mod - 2, mod);
}

int main() {
    int N;
    cin >> N;
    
    vector<long long> red(N), green(N);
    for (int i = 0; i < N; ++i) {
        cin >> red[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> green[i];
    }
    
    // Calculate the total sum S of all weights
    long long S = 0;
    for (int i = 0; i < N; ++i) {
        S += red[i] + green[i];
        S %= MOD;
    }
    
    // Precompute the factorial and modular inverses for combinatorial calculations
    vector<long long> fact(N + 1, 1), invFact(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invFact[N] = modInverse(fact[N], MOD);
    for (int i = N - 1; i >= 1; --i) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
    invFact[0] = 1;

    // Process each K from 1 to N
    for (int K = 1; K <= N; ++K) {
        long long P = S * fact[N] % MOD * invFact[K] % MOD * invFact[N - K] % MOD;
        long long Q = N;
        
        // Calculate the result as (P * Q^(-1)) % MOD
        long long Q_inv = modInverse(Q, MOD);
        long long result = P * Q_inv % MOD;
        
        cout << result << endl;
    }
    
    return 0;
}
