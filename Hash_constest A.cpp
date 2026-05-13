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

const int MX = 200005;
 
const ll MOD[2] = {127657753, 1000000007};
ll BASE[2] = {0, 0};
 
ll POW[2][MX];
ll IPOW[2][MX];
 
ll power(ll a, ll p, ll m) {
  ll ans = 1;
  a %= m;
 
  while (p) {
    if (p & 1ll) ans = (ans*a) % m;
    p >>= 1ll;
    a = (a*a) % m;
  }
 
  return ans;
}
 
void hash_pre() {
  ll b1, b2, i, j, inv;
 
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  b1 = (500 + (rnd() % (MOD[0]-500*2+1)));
  b2 = 0;
  do {
    b2 = (500 + (rnd() % (MOD[1]-500*2+1)));
  } while (b1 == b2);
  BASE[0] = 31;
  BASE[1] = b2;
 
  for (i = 0; i < 2; ++i) {
    ll *pw = POW[i], *ipw = IPOW[i], x = BASE[i], m = MOD[i];
 
    pw[0] = 1;
    ipw[0] = 1;
    inv = power(x, m-2, m);
    for (j = 1; j < MX; ++j) {
      pw[j] = (pw[j-1] * x) % m;
      ipw[j] = (ipw[j-1] * inv) % m;
    }
  }
}
 
template<typename T>
struct DoubleHash {
  int n;
  T s;
  vector<pair<ll,ll>> h;
 
  DoubleHash() {}
  DoubleHash(T s) : s(s) {
    n = s.size();
    h.resize(n+1);
 
    ll *pw0 = POW[0], m0 = MOD[0];
    ll *pw1 = POW[1], m1 = MOD[1];
    int i = 0;
 
    h[i] = {0, 0};
    
    for (i = 1; i <= n; ++i) {
      h[i] = {
        (h[i-1].first + (s[i-1] * pw0[i]) % m0) % m0,
        (h[i-1].second + (s[i-1] * pw1[i]) % m1) % m1,
      };
    }
  }
 
  pair<ll,ll> get_hash(int l, int r) {
    assert((0 <= l) && (l <= r) && (r < n));
    ++l; ++r;
 
    ll *ipw0 = IPOW[0], m0 = MOD[0];
    ll *ipw1 = IPOW[1], m1 = MOD[1];
    return {
      ((h[r].first - h[l-1].first + m0) * ipw0[l]) % m0,
      ((h[r].second - h[l-1].second + m1) * ipw1[l]) % m1,
    };
  }
 
  pair<ll,ll> get_hash() {
    return get_hash(0, n-1);
  }
 
  pair<ll,ll> merge_hash(int l1, int r1, int l2, int r2) {
    assert((0 <= l1) && (l1 <= r1) && (r1 < l2) && (l2 <= r2) && (r2 < n));
 
    pair<ll,ll> p1 = get_hash(l1, r1);
    pair<ll,ll> p2 = get_hash(l2, r2);
 
    ll *pw0 = POW[0], m0 = MOD[0];
    ll *pw1 = POW[1], m1 = MOD[1];
    int len = r1-l1+1;
 
    return {
      (p1.first + (p2.first * pw0[len]) % m0) % m0,
      (p1.second + (p2.second * pw1[len]) % m1) % m1,
    };
  }
};

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

    int t ;
    cin >> t ;

    hash_pre();
    
    while (t--)
    {
    	int n;
	    string s;
	    //cin >> n >> s;
	 
	    DoubleHash <string> hash(s);
	    set<pair<ll,ll>> st;


	 
	    cout << st.size() << endl;
        
    }
    return 0 ;
}
