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
    
    for (int t = 1; t <= test_cases; t++)
    {
    	ll n, Ax, Ay, Bx, By, x, y;
    	cin >> n >> Ax >> Ay >> Bx >> By;

    	vector<ll> arr[2];
    	map<int, pair<ll,ll>>mp;

    	vector<int>xx(n), yy(n);


    	for(int i = 0; i < n; i++){
    		cin >> xx[i];
    	}
    	for(int i = 0; i < n; i++){
    		cin >> yy[i];
    	}

    	for(int i = 0; i < n; i++){
    		x = xx[i] , y = yy[i];
    		if(mp.find(x) == mp.end()){
    				mp[x] = {y, y};
    		}else{
    			mp[x] = {min(mp[x].first, y), max(mp[x].second, y)};
    			
    		}
    	}
    	mp[Ax] = {Ay, Ay};
   		mp[Bx] = {By, By};

    	ll time = 0, prev = Ax ;

    	for(auto i : mp){
    		arr[1].push_back(i.second.first);
    		arr[0].push_back(i.second.second);

    		time += (i.first - prev);
    		prev = i.first;
    	}

    	n = (int)mp.size();
    	vector<vector<ll>>dp(2, vector<ll> (n ,inf));

    	dp[0][0] = 0;
    	dp[1][0] = 0;

    	for(int i = 1; i < n; i++){
    		for(int j = 0; j < 2; j++){
    			for(int k = 1; k >= 0; k--){
    				if(j == k){
    					dp[j ^ 1][i] = min(dp[j ^ 1][i] ,dp[j][i - 1] + abs(arr[j][i - 1] - arr[k][i]) + abs(arr[0][i] - arr[1][i]));
    				}else{
    					dp[j][i] = min(dp[j][i] ,dp[j][i - 1] + abs(arr[j][i - 1] - arr[k][i]) + abs(arr[0][i] - arr[1][i]));
    				}
    			}
    		}
    	}

    	debug(dp);

    	cout <<  time + min(dp[0][n - 1], dp[1][n - 1])  << endl;
    }

    runtime();
    return 0;
    

    

}
