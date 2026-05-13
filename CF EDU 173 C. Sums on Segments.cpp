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
    	int n;
    	cin >> n;
    	vector<ll>arr(n);
    	int indx = n/2 ;
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		if(abs(arr[i]) != 1)
    			indx = i;
    	}
    	set<ll>ans;
    	ll sum = 0, mx_sum = -inf, mn_sum = inf;

    	for(int i = 0; i < indx; i++){
    		if(sum + arr[i] <= 0)
    			sum = 0;
    		sum += arr[i];
    		mx_sum = max(mx_sum, sum);
    	}
    	sum = 0;
    	for(int i = 0; i < indx; i++){
    		if(sum + arr[i] >= 0)
                sum = 0;
            sum += arr[i];
            mn_sum = min(mn_sum, sum);

    	}

        debug(mx_sum, mn_sum);

    	for(int i = mn_sum ; i <= mx_sum; i++)
    		ans.insert(i);
    	sum = 0, mx_sum = -inf, mn_sum = inf;
    	for(int i = indx + 1; i < n; i++){
    		if(sum + arr[i] <= 0)
    			sum = 0;
    		sum += arr[i];
    		mx_sum = max(mx_sum, sum);
    	}
    	sum = 0;
    	for(int i = indx + 1; i < n; i++){
    		if(sum + arr[i] >= 0)
                sum = 0;
            sum += arr[i];
            mn_sum = min(mn_sum, sum);
    	}

    	for(int i = mn_sum ; i <= mx_sum; i++){
    		ans.insert(i);
        }

    	sum = 0;

        ll suff_min = 0, suff_max = 0, pref_min = 0, pref_max = 0;

        for(int i = indx - 1; i >= 0; i--){
            sum += arr[i];
            suff_min = min(suff_min, sum);
            suff_max = max(suff_max, sum);
        }
        sum = 0;
        debug(indx);
        for(int i = indx + 1; i < n; i++){
            sum += arr[i];
            pref_min = min(pref_min, sum);
            pref_max = max(pref_max, sum);
        }
    
        ll mn = suff_min + pref_min + arr[indx];
        ll mx = suff_max + pref_max + arr[indx];

        debug(mn, mx, suff_max,suff_min,pref_max, pref_min);

        for(ll i = mn; i <= mx; i++){
            ans.insert(i);
        }
        ans.insert(0);

    	cout << ans.size() << endl;
    	for(auto i : ans){
    		cout << i << " ";
    	}
    	cout << endl;

    	
    }
   
    runtime();
    return 0 ;

}
