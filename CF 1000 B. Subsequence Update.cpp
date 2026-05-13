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
    	int n, l, r;
    	cin >> n >> l >> r;

    	vector<ll>arr(n + 1), pref, suff;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		if(i <= r){
    			pref.push_back(arr[i]);
    		}
    		if(l <= i){
    			suff.push_back(arr[i]);
    		}
    	}

    	int cnt = r - l + 1;

    	ll pf = 0, sf = 0;

    	sort(pref.begin(), pref.end());
    	sort(suff.begin(), suff.end());


    	for(int i  = 0; i < pref.size(); i++){
    		if(i < cnt)
    			pf += pref[i];
    	}
    	for(int i  = 0; i < suff.size(); i++){
    		if(i < cnt)
    			sf += suff[i];
    	}

    	cout << min (sf, pf) << endl;


    }
    return 0 ;

    runtime();

}
