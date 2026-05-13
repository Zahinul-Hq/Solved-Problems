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

    int n;
    cin >> n;

    vector<int>arr(n + 1, 0), pref(n + 1, 0), suff(n + 2, 0);

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    	pref[i] = arr[i] + n - i;
    	suff[i] = arr[i] + i - 1 ;
    }

    for(int i = 1; i <= n; i++){
    	pref[i] = max(pref[i], pref[i - 1]);
    }

    for(int i = n ; i >= 1; i--){
    	suff[i] = max(suff[i], suff[i + 1]);
    }
	debug(pref, suff);

    int ans = INT_MAX;
    for(int i = 1; i <= n; i++){
    	ans = min (ans, max({arr[i], pref[i - 1], suff[i + 1]}));

    	debug(ans);
    }

    cout << ans << endl;


    return 0 ;

    runtime();

}
