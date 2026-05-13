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
ll rec(int pos, vector<ll>&arr){

	ll sum = 0, mn = inf;

	for(int i = pos; i >= 0; i--){
		mn = min(mn, arr[i]);
		sum += mn;
	}
	mn = inf;
	for(int i = pos + 1; i < arr.size(); i++){
		mn = min(mn, arr[i]);
		sum += mn;
	}

	return sum;
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
    	int n, h;
    	cin >> n >> h;

    	vector<ll>arr(n);

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    		arr[i] = h - arr[i];
    	}

    	int mx_indx = 0;
    	ll mx_sum = 0;


    	for(int i = 0; i < n; i++){
    		ll sum = rec(i, arr);
    		if(sum > mx_sum){
    			mx_indx = i;
    			mx_sum = sum;
    		}
    	}
    	ll mn = inf;

    	for(int i = mx_indx; i >= 0; i--){
			mn = min(mn, arr[i]);
			arr[i] -= mn;
		}
		mn = inf;
		for(int i = mx_indx + 1; i < n; i++){
			mn = min(mn, arr[i]);
			arr[i] -= mn;
		}
		ll mx = 0;
		for(int i = 0; i < n; i++){
    		ll sum = rec(i, arr);

    		mx = max(sum, mx);
    		
    	}

    	cout << mx + mx_sum << endl;



    }
    return 0 ;

    runtime();

}
