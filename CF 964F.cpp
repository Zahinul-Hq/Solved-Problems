#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e6, mod = 1e9 + 7;

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
int nCr(int n, int r) {
  if (n < r or n < 0) return 0;
  return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
int nPr(int n, int r) {
  if (n < r or n < 0) return 0;
  return 1LL * f[n] * invf[n - r] % mod;
}

 
void inout()
{  
  #ifndef ONLINE_JUDGE
    freopen("input.txt" ,"r" , stdin);
    freopen("output.txt" , "w" ,stdout);
    cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
  #endif
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  inout() ;
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * i * f[i - 1] % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  }

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, k;
        cin >> n >> k;

        ll cnt1 = 0;
        ll cnt0 = 0;

        vector<int>arr(n +1, 0);

        for(int i = 0; i < n; i++){
          cin >> arr[i];
          cnt1 += arr[i];
          cnt0 += (!arr[i]);
        }

        ll ans  = 0;

        for(int i = 0; i <= (k / 2); i++){

          ll nr = nCr(cnt1, k - i);
          ll nr2 = nCr(cnt0, i);

          ll val = (nr * nr2) % mod;

          ans += val;
          ans %= mod; 

        }

        cout << ans << endl;
    }
    return 0 ;
}
