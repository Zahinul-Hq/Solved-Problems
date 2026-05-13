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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 2e6 + 7;

int base1 = 127, base2 = 503, mod1 = 998244353, mod2 = 987654319;
int pref1[N], inv1[N], pwr1[N];

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

	pwr1[0] = 1;
	inv1[0] = 1;
	int in_val1 = binary_expo(base1, mod1 - 2, mod1);
	for(int i = 1; i < N; i++){
		pwr1[i] = (1LL * pwr1[i - 1]  * base1) % mod1;
		inv1[i] = (1LL * inv1[i - 1]  * in_val1) % mod1;
	}
}

void build_hash(string s){

	for(int i = 1; i <= s.size(); i++){
		pref1[i] = (pref1[i - 1] + (1LL * s[i - 1]  * pwr1[i]) % mod1) % mod1;
		
	}
}
int get_hash(int l, int r, int n){
	assert((0 <= l) && (l <= r) && (r < n));
	l++, r++;

	int hash_value1 = ( 1LL * (pref1[r] - pref1[l - 1] + mod1) * inv1[l]) % mod1;
	
	return hash_value1;
}
//must call precalculate and build_hash first and Change N ;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	precalculate();
    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	string s;
    	cin >> s;

    	string rs = s ;
    	reverse(rs.begin(), rs.end());

    	int n = s.size() - 1;

    	string temp = s + rs;
    	build_hash(temp);
    	int ans = 0;
    	for(int i = 1; i <= n; i++){
    		int x = get_hash(n - i, n, 2*n + 2);
    		int y = get_hash(n + 1 , n + 1 + i, 2*n + 2);
    		if(x == y){
    			ans = i;
    		}
    	}

    	cout << "Case " << cs++ << ": " << 2 * s.size() - ans - 1 << endl;
    }
    return 0 ;

    runtime();

}
