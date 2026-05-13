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


    int n, w, x, y;
    cin >> n >> w;

    vector<int>arr[w + 1];
    vector<pair<int,int>>vp;

    for(int i = 0; i < n; i++){
    	cin >> x >> y;
    	arr[x].push_back(y);
    	vp.push_back({x, y});
    }
    map<pair<int,int>, int>mp;
    int sz = 1e9;
    for(int i = 1; i <= w; i++){
    	sort(arr[i].begin(), arr[i].end());
    	sz = min(sz, (int)arr[i].size());
    }
    for(int i = 1; i <= w; i++){
    	for(int j = 0; j < arr[i].size(); j++){
    		mp[{i , arr[i][j]}] = INT_MAX;
    	}
    }

    for(int j = 0; j < sz; j++){
    	int mx = 0;
    	for(int i = 1; i <= w; i++){
    		mx = max(arr[i][j], mx); 
   		}
   		for(int i = 1; i <= w; i++){
    		mp[{i, arr[i][j]}] = mx;
   		}
    }

    int q;
    cin >> q;
    while(q--){
    	int i, t;

    	cin >> t >> i;

    	debug(vp[i - 1], mp[vp[i - 1]], t);

    	if(mp[vp[i - 1]] > t){
    		cout << "Yes" << endl;
    	}else{
    		cout << "No" << endl;
    	}
    }
    
    return 0 ;

    runtime();

}
