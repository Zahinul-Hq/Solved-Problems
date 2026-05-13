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
    
    for(int t = 1; t <= test_cases; t++)
    {

    	int n;
    	cin >> n;

    	vector<vector<int>>arr(2, vector<int>(n + 1, 0));

    	vector<int>pref_max(n + 1, 0), pref_min(n + 1, INT_MAX), suff_max(n + 2, 0), suff_min(n + 2, INT_MAX), maxr(n + n + 1, 0);


    	for(int i = 0; i < 2; i++){
    		for(int j = 1; j <= n; j++){
    			cin >> arr[i][j];
    		}
    	}

    	for(int i = n; i >= 1; i--){
    		suff_max[i] = max(suff_max[i + 1], arr[1][i]);
    		suff_min[i] = min(suff_min[i + 1], arr[1][i]);
    	}
    	for(int j = 1; j <= n; j++){
    		pref_max[j] = max(pref_max[j - 1], arr[0][j]);
    		pref_min[j] = min(pref_min[j - 1], arr[0][j]);

    		if(maxr[max(suff_max[j], pref_max[j])] < min(pref_min[j], suff_min[j]))
    			maxr[max(suff_max[j], pref_max[j])] = min(pref_min[j], suff_min[j]);
    	}

    	int l = 0;
    	ll ans = 0;

    	for(int r = 1; r <= n + n; r++){
    		l = max(l, maxr[r]);
    		ans += l;
    	}

    	cout << ans << endl;

    }
    return 0 ;

    runtime();

}
