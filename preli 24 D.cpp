#include<bits/stdc++.h>
using namespace std;

const int N = 3e6 + 7,  MOD = 998244353, mod = 998244353 ;

__int128 a;

int power(long long n, long long k) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}
int f[N], invf[N];
int nCr(long long n, long long r) {
  if (n < r or n < 0) return 0;
  return 1LL * f[n] * invf[r] % MOD * invf[n - r] % mod;
}
long long modInverse(long long x) {
    return power(x, mod - 2);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * i * f[i - 1] % MOD;
  }
  invf[N - 1] = power(f[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % MOD;
  }


  long long m;
    cin >> m;
    
    vector<long long> red(m), green(m);
    for (int i = 0; i < m; ++i) {
        cin >> red[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> green[i];
    }
    
    long long S = 0;
    for (int i = 0; i < m; ++i) {
        S = (S % MOD + (red[i] % MOD + green[i] % MOD)) % MOD;
    }
    

    for (int K = 1; K <= m; ++K) {
        long long P = S * K ;
        long long Q =  2 * m;
        

        long long Q_inv = modInverse(Q);

        long long result = (P % MOD * Q_inv % MOD) % MOD;
        
        cout << result;
        if(K != m)
          cout << " ";
    }

    cout << endl;

  return 0;
}