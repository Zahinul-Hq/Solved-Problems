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
const int N = 1e5 + 7;

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

pair<int,int> string_hash(string s){

	ll hash_value1 = 0, hash_value2 = 0;

	for(int i = 1; i <= s.size(); i++){
		hash_value1 += (1LL * s[i - 1] * pwr1[i]);
		hash_value1 %= mod1;
		hash_value2 += (1LL * s[i - 1] * pwr2[i]) ;
		hash_value2 %= mod2;
	}
	return {hash_value1, hash_value2};
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
pair<int,int> merge_hash(int l1, int r1, int l2, int r2, int n){
	assert(0 <= l1  && l1 <= r1 && r1 < l2 && l2 <= r2 && r2 < n);
	
	pair<int,int> h1 = get_hash(l1, r1, n);
	pair<int,int> h2 = get_hash(l2, r2, n);

	int pw = r1 - l1 + 1;

	int hash_value1 = (h1.first + ((1LL * pwr1[pw] * h2.first) % mod1))% mod1;
	int hash_value2 = (h1.second + ((1LL * pwr2[pw] * h2.second) % mod2)) % mod2;

	return {hash_value1, hash_value2};

}
//must call precalculate and build_hash first and Change N ;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	precalculate();
    int n, k;

    cin >> n >> k;
    string s, str, str2;

    cin >> s;

    str = str2 = s;

    for(int i = 0; i < k; i++){
    	str += s[i];
    }
    reverse(str2.begin(), str2.end());
    build_hash(str);
    set<pair<int,int>>st;

    for(int i = 0; i < str.size() - k; i++){

    	auto hsh = get_hash(i, i + k - 1, str.size());
    	st.insert(hsh);

    }
    for(int i = 0; i < k; i++){
    	str += s[i];
    }
    reverse(str2.begin(), str2.end());
    build_hash(str);

    cout << st.size() << endl;




    
    return 0 ;

    runtime();

}
