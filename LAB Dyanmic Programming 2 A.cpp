#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#include<bits/stdc++.h>
using namespace std;

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
const int NN = 105;
vector<int>arr(NN, 0);
ll dp[NN][100007];
int n, k;
ll solve(int i, int c){

	int left = n - (i + 1 );

	dp[i][c] = (((f[left - 1 + c] % mod * invf[left - 1] % mod) % mod )* invf[c] % mod) % mod;

	return dp[i][c];
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

    cin >> n >> k;

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }

    ll ans = 0;

    for(int i = 0; i <= arr[0]; i++){
    	ans += solve(0, i);
    	ans %= mod;
    }

    cout << ans << endl;



    

    return 0 ;
}
