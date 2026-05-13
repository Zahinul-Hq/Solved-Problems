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
    	int n, q;

    	cin >> n >> q;
    	vector<string>arr(n + 1);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	vector<string>vals = {"BR" , "BG", "BY", "GR", "GY", "RY"};
    	map<string,int>mp;
    	vector<int>rt(n + 1), lf(n + 1);

    	for(auto s : vals){
    		mp[s] = 0;
    	}

    	for(int i = 1; i <= n; i++){
    		int pos = 0;
    		for(string s : vals){
    			if(s != arr[i])
    				if(s[0] == arr[i][0] || s[1] == arr[i][0] || s[1] == arr[i][1] || s[0] == arr[i][1])
    					pos = max(pos, mp[s]);
    		}
    		mp[arr[i]] = i;
    		lf[i] = pos;
    	}
    	debug(mp);
    	for(auto s : vals){
    		mp[s] = INT_MAX;
    	}

    	for(int i = n; i >= 1; i--){
    		int pos = INT_MAX;
    		for(string s : vals){
    			if(s != arr[i]){
    				if(s[0] == arr[i][0] || s[1] == arr[i][0] || s[1] == arr[i][1] || s[0] == arr[i][1])
    					pos = min(pos, mp[s]);
    			}
    		}
    		mp[arr[i]] = i;
    		rt[i] = pos;
    	}

    	debug(mp);

    	

    	while(q--){
    		int l, r;
    		cin >> l >> r;

    		if(arr[l][0] == arr[r][0] || arr[l][0] == arr[r][1] || arr[l][1] == arr[r][0] || arr[l][1] == arr[r][1]){
    			cout << abs(r - l) << endl;
    			continue;
    		}
    		debug(rt, lf);
    		int ans = INT_MAX;

    		if(lf[r] != 0){
    			ans = abs(lf[r] - l) + abs(lf[r] - r);
    		}
    		if(rt[l] != INT_MAX){
    			ans = min(ans, abs(rt[l] - l) + abs(rt[l] - r));
    		}
    		if(lf[l] != 0){
    			ans = min(ans, abs(lf[l] - l) + abs(lf[l] - r));
    		}
    		if(rt[r] != INT_MAX){
    			ans = min(ans, abs(rt[r] - l) + abs(rt[r] - r));
    		}

    		if(ans == INT_MAX){
    			cout << -1 << endl;
    		}else{
    			cout << ans << endl;
    		}
    	}
    }
    return 0 ;

    runtime();

}
