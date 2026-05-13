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


    	int n, q;
    	cin >> n >> q;

    	vector<ll>arr(n, 0);

    	ll and_val = (1 << 22) - 1;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];

    		and_val &= arr[i];
    	}

    	while(q--){

    		ll k , ans = 0;
    		cin >> k;

    		vector<ll>temp_arr(n , 0);
    		temp_arr = arr;

    		for(int i = 60; i >= 0; i--){
    			vector<bool>marked(n + 1, 0);
    			ll del = 0;
    			for(int j = 0; j < n; j++){

    				if((temp_arr[j] & (1LL << i))){
    					continue;
    				}
    				marked[j] = 1;
    				if(i > 0)
    					del += ((1LL << i ) - (temp_arr[j] & ((1LL << i) - 1)));
    				else
    					del += 1;

    				if(del > k)
    					break;
    			}

    			if(del <= k){

    				if(i > 0){
	    				for(int j = 0; j < n; j++){
	    					if(marked[j]){
	    						temp_arr[j] += ((1LL << i ) - (temp_arr[j] & ((1LL << i) - 1))) ;
	    					}
	    				}
	    			}
    				debug(del, marked, temp_arr, k, i);

    				k -= del;

    				ans += (1LL << i);
    			}

    			if(k == 0)
    				break;
    		}
    		cout << max(and_val, ans) << endl;

    	}
    	
    
    return 0 ;

    runtime();

}
