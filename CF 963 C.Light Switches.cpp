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
    	ll n, k;
    	cin >> n >> k;

    	vector<ll>arr(n),b(n), c(n), d(n);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}
    	sort(arr.begin(), arr.end());

    	for(int i = 0; i < n ; i++){

    		ll hi = 1e9, lo = 0, ans = 1e9;

    		while(hi >= lo){
    			ll mid = (hi + lo) / 2;

    			if(arr[n - 1] <= (mid * 2LL * k) + arr[i]){
    				hi = mid - 1;
    				ans = min(mid, ans);
    			}else{
    				lo = mid + 1;
    			}
    		}
    		b[i] = max(arr[i], arr[i] + (k * 2LL * (ans - 1)));
    		c[i] = arr[i] + (k * 2LL * ans);

    	}

    	for(int i = 0; i < n; i++){
    		if(arr[n - 1] - b[i] < k)
    			d[i] = b[i];
    		else
    			d[i] = c[i];

    	}
    	ll mx = *max_element(d.begin(), d.end());
    	ll mn = *min_element(d.begin(), d.end());

    	if(mx - mn >= k){
    		cout << -1 << endl;
    	}else{
    		cout << mx << endl;
    	}




    }
    return 0 ;

    runtime();

}
