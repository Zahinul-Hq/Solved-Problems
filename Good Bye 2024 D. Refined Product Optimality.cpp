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
const int mod = 998244353;
int binary_expo(int base, int pwr){
	int result = 1; 
	base %= mod, pwr %= mod;
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) % mod;
		}
		base = (base * 1LL * base) % mod;
		pwr >>= 1;
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, q;
    	cin >> n >> q;

    	vector<ll>a(n), b(n), c(n), d(n);

    	ll res = 1;

    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    		c[i] = a[i];
    	}
    	for(int i = 0; i < n; i++){
    		cin >> b[i];
    		d[i] = b[i];
    	}
    	sort(c.begin(), c.end());
    	sort(d.begin(), d.end());
    	for(int i = 0; i < n; i++){
    		res *= min(c[i],d[i]);
    		res %= mod;
    	}
    	cout << res << " ";


    	while(q--){
    		int o, x;
    		cin >> o >> x;
    		x--;
    		debug(res);

    		if(o == 1){
    			int pos = upper_bound(c.begin(), c.end(), a[x]) - c.begin() - 1;

    			if(c[pos] < d[pos]){
    				res = ((res * binary_expo(c[pos], mod - 2) % mod) * (c[pos] + 1)) % mod; 
    			}
    			a[x]++, c[pos]++;

    		}else{
    			int pos = upper_bound(d.begin(), d.end(), b[x]) - d.begin() - 1;
    			if(c[pos] > d[pos]){
    				res = ((res * binary_expo(d[pos], mod - 2) % mod) * (d[pos] + 1)) % mod; 

    			}
    			b[x]++, d[pos]++;
    		}

    		cout << res << " ";
    	}
    	cout << endl;
    }
    return 0 ;

    runtime();

}
