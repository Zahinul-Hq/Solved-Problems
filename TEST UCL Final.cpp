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
int n, k;
vector<int>arr(N, 0);
bool ok(ll x){

	ll sum = 0, used = 1;

	for(int i = 0; i < n; i++){

		if(sum + arr[i] <= x){
			sum += arr[i];
		}else{
			used++;
			sum = arr[i];
			if(sum > x)
				return false;
		}

	}

	return used <= k;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    cin >> n >> k;

    ll sum = 0;
    
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    	sum += arr[i];
    }
    if (k > n) { 
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = sum, ans  = 0;

    while(l <= r){

    	ll mid = (l + r) / 2;

    	if(ok(mid)){
    		r = mid - 1;
    		ans = mid;
    	}else{
    		l = mid + 1;
    	}

    }

    cout << ans << endl;




    return 0 ;

    runtime();

}
