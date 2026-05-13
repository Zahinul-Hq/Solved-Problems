#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = 65, mod = 998244353;

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

ll rec(int n, bool toggle){

	if(n == 2){
		if(toggle)
			return 1;
		return 0;
	}


	ll ans = 0;

	if(toggle){
		ans = nCr(n - 1, (n/2) - 1);
		ans += rec(n - 2, toggle ^ 1) ;
		ans %= mod;
	}else{
		ans = nCr(n - 2, (n/2) - 2);
		ans += rec(n - 2, toggle ^ 1) ;
		ans %= mod;

	}


	return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  inout();
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * i * f[i - 1] % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  }

	int t;
	cin >> t;

	while(t--){

		int x ;

		cin >> x;


		cout << rec(x, 1) << " " << rec(x, 0)<< " " << 1 << endl;

		//cout << 1 << endl;



	}
  
  return 0;
}