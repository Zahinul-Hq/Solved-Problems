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
string str, r;

int get_pos(int k){

	build_hash(str);

	int n = str.size();
	int m = r.size();

	//cout << get_hash(0, n - 1, n).first << " " <<get_hash(0, n-1, n).S <<endl;

	set<pair<int,int>>st;

	for(int i = 0; i < n - k + 1 ; i++){
		int j = i + k - 1;
		pair<int,int> p = get_hash(i, j, n);
		//cout << i << " " << j  << " " << p.F << " " << p.S << endl;
		st.insert(p);
	}

	/*for(auto i : mps){
		cout << i.first.first << " " << i.first.second << endl;
	}*/

	//cout<<k<<endl;
	
	build_hash(r);
	//cout << get_hash(3, m - 1, m).first << " " <<get_hash(3, m - 1, m).S <<endl;
	
	for(int i = 0; i < m - k + 1 ; i++){
		int j = i + k - 1;

		pair<int,int> p = get_hash(i, j, m);
		//cout << i << " " << j  << " " << p.F << " " << p.S << endl;
		if(st.find(p) != st.end()){
			return i;
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

	precalculate();

	int n;

	cin >> n;

	cin >> str >> r;

	int hi = n, lo = 1;

	pair<int,int> ans;

	while(hi >= lo){

		int mid = (hi + lo) / 2;
		int pos = get_pos(mid);

		//cout << pos << endl;



		if(pos > -1){
			lo = mid + 1;
			ans.first = pos;
			ans.second = mid;
		}else{
			hi = mid - 1;
		}
	}

	
	/*cout << string_hash(str).first << " " << string_hash(str).second << endl;
	cout << string_hash(r).first << " " << string_hash(r).second << endl;*/


	for(int i = ans.first; i <= ans.first + ans.second - 1 ; i++){
		cout << r[i];
	}

	cout << endl;

    return 0 ;
}
