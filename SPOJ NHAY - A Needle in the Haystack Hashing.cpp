#include<bits/stdc++.h>
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

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
const int N = 1507;

int base1 = 137, base2 = 277, mod1 = 127657753, mod2 = 987654319;
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

void precalculate(){

	pwr1[0] = 1, pwr2[0] = 1;
	inv1[0] = 1, inv2[0] = 1;
	int in_val1 = binary_expo(base1, mod1 - 2, mod1);
	int in_val2 = binary_expo(base2, mod2 - 2, mod2);

	//cout << in_val1 << " " << in_val2 << endl;
	for(int i = 1; i <= N; i++){
		pwr1[i] = (1LL * pwr1[i - 1]  * base1) % mod1;
		pwr2[i] = (1LL * pwr2[i - 1]  * base2) % mod2;
		inv1[i] = (1LL * inv1[i - 1]  * in_val1) % mod1;
		inv2[i] = (1LL * inv2[i - 1]  * in_val2) % mod2;
	}
}

void build_hash(string s){

	for(int i = 1; i <= s.size(); i++){
		pref1[i] = (pref1[i - 1] + (1LL * s[i - 1]  * pwr1[i]) % mod1) % mod1;
		pref2[i] = (pref2[i - 1] + (1LL * s[i - 1]  * pwr2[i]) % mod2) % mod2;
	}
}
pair<int,int> get_hash(int l, int r, int n){
	assert((0 <= l) && (l <= r) && (r < n));
	l++, r++;

	int hash_value1 = ( 1LL * (pref1[r] - pref1[l - 1] + mod1) * inv1[l]) % mod1;
	int hash_value2 = ( 1LL * (pref2[r] - pref2[l - 1] + mod2) * inv2[l]) % mod2;

	return {hash_value1, hash_value2};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;
	int t;
	cin >> t;

	precalculate();

	while(t--){


		
	}

	return 0 ;
}
