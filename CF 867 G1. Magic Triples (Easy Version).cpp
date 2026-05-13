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
const int N = 1e6 + 7;
//vector<ll>mp(N, 0);
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
    	map<int,int>mp;
    	
    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		mp[arr[i]]++;
    	}
    	ll ans = 0;

    	int max_val = 1e6;

    	for(int i = 0; i < n; i++){
    		
    			ans += (mp[arr[i]] - 1) * (mp[arr[i]] - 2);
    		
    		for(ll b = 2; arr[i] * b * b <= max_val; b++){
    			if(mp.find(arr[i] * b * b) == mp.end() || mp.find(arr[i] * b) == mp.end())
    				continue;
    			ans += mp[arr[i] * b] * mp[arr[i] * b * b];
    		}
    	
    	}

    	for(int i = 0; i < n; i++){
    		mp[arr[i]]--;
    	}

    	cout << ans << endl;
    	
    }
    return 0 ;

    runtime();

}
