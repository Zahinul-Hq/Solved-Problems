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
    
    for(int tt = 1; tt <= test_cases; tt++)
    {
    	ll n, h, k;
    	cin >> n >> h >> k;

    	vector<ll>arr(n + 1, 0);

    	ll tot = 0, rem = 0, t = 0;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		tot += arr[i];
    	}
    	t = ((h / tot) * k) + ((h / tot) * n);

    	debug(t);

    	rem = (h % tot);

    	if(rem == 0){
    		cout << t - k << endl;
    		continue;
    	}

    	debug(rem);

    	int tmn = n + 2;

    	vector<ll>pref_min(n + 1, INT_MAX), suff_max(n + 2, 0), pref_sum(n + 1, 0);

    	for(int i = 1; i <= n; i++){
    		pref_min[i] = min(pref_min[i - 1], arr[i]);
    		pref_sum[i] = pref_sum[i - 1] + arr[i];
    	}

    	for(int i = n; i >= 1; i--){
    		suff_max[i] = max(suff_max[i + 1], arr[i]);
    	}
    	debug(pref_min, suff_max);

    	for(int i = 1; i <= n; i++){

    		if(pref_sum[i] - pref_min[i] + suff_max[i + 1] >= rem || pref_sum[i] >= rem){
    			tmn = i;
    			break;
    		}
    	}
    	cout << t + tmn << endl;
    }
    return 0 ;

    runtime();

}
