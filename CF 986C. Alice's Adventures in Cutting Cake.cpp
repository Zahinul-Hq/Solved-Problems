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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, m, v;

    	cin >> n >> m >> v;

    	vector<int>arr(n + 1);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	vector<ll>pref(n + 1), suff(n + 3), pfx_sum(n + 2, 0);

    	ll sum = 0;
    	for(int i = 1; i <= n; i++){
    		sum += arr[i];
    		if(sum >= v){
    			pref[i] = pref[i - 1] + 1;
    			sum = 0;
    		}
    		pref[i] = max(pref[i - 1], pref[i]);
    		pfx_sum[i] = pfx_sum[i - 1] + arr[i];
    	}
    	pfx_sum[n + 1] = pfx_sum[n];
    	sum = 0;
    	for(int i = n; i >= 1; i--){
    		sum += arr[i];
    		if(sum >= v){
    			suff[i] = suff[i + 1] + 1;
    			sum = 0;
    		}
    		suff[i] = max(suff[i + 1], suff[i]);
    	}

    	debug(pref, suff);

    	if(pref[n] < m){
    		cout << -1 << endl;
    		continue;
    	}

    	ll ans = 0;

    	for(int l = 0, r = 1; l <= n; l++){
    		while(r <= n && pref[l] + suff[r + 1] >= m)r++;
    		if(pref[l] + suff[r] >= m ){
    			debug(l, r, pfx_sum[r - 1] - pfx_sum[l], suff[r]);
    			ans = max(ans, pfx_sum[r - 1] - pfx_sum[l]);
    		} 
    	}

    	cout << ans << endl;






    }
    return 0 ;

    runtime();

}
