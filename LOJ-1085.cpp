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
const int N = 2e5 + 9, mod = 1e9 + 7;

int a[N];
struct ST {
  int t[4 * N];
  
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = (t[l] % mod + t[r] % mod) % mod;
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = x % mod;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = (t[l] % mod + t[r] % mod) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j) % mod;
    int R = query(r, mid + 1, e, i, j) % mod;
    return (L + R) % mod;
  }
};

bool cmp(pair<int,int>p , pair<int,int>q){
	if(p.first == q.first){
		if(p.second > q.second){
			return true;
		}
	}

	if(p.first < q.first)
		return true;

	return false;
		
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs = 1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
      ST st;
    	int n, x;
    	cin >> n;
    	vector<ll> dp(n, 0);
    	vector<pair<int,int>>arr;


    	for(int i = 0; i < n; i++){
    		cin >> x;
    		arr.push_back({x, i});
    	}

    	sort(arr.begin(), arr.end(), cmp);

    	ll ans = 0;
    	for(int i = 0; i < n; i++){

    		int pos = arr[i].second;

    		ll sum = st.query(n, 0, n - 1, 0,  pos - 1);

    		dp[pos] += (1 + sum);
        

    		dp[pos] %= mod;

    		st.upd(n, 0, n - 1, pos, dp[pos]);
    	}

    	for(int i = 0; i < n; i++){
    		ans += dp[i];
        ans %= mod;
    	}
    	cout << "Case " << cs++ << ": " << ans << endl;
    	



    	


    }
    return 0 ;

    runtime();

}
