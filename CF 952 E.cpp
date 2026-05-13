#include<bits/stdc++.h>
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

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N  = 5000;
int base1 = 137, base2 = 277, mod1 = 127657753, mod2 = 987654319, mod  = 1e9 + 7;
int pref1[N], pref2[N], inv1[N], inv2[N], pwr1[N], pwr2[N];

int binary_expo(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        ll l , r, k;

        cin >> l >> r >> k;

        if(k <= 10){
        	ll ans  = (10 / k) + (10 % k >= 1);
        	

        	ll res = (binary_expo(ans, r, mod) - binary_expo(ans, l, mod) + mod) % mod;
        	cout << res << endl;

        }else{
        	cout << 0 << endl;
        }
    }
    return 0 ;
}
