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


    int envelop_size, f = 0;
    
    while (cin >> envelop_size && envelop_size)
    {	
    	int t, n, val;
    	cin >> t;

    	vector<int>coins[t + 1];
    	for(int i = 0; i < t; i++){
    		cin >> n;
    		for(int j = 0; j < n; j++){
    			cin >> val;
    			coins[i].push_back(val);
    		}
    	}
    	
    	ll ansIndx = 0, max_coverage = 0;
    	for(int l = 0; l < t; l++){
    		vector<ll>dp(1001, INT_MAX);
    		dp[0] = 0;
    		for(int i = 0; i < coins[l].size(); i++){
    			for(int j = 1; j <= 1000; j++){
    				if(j >= coins[l][i] ){
    					dp[j] = min(dp[j], dp[j - coins[l][i]] + 1);
    				}
    			}
    		}
    		int m = 1;
    		while(dp[m] <= envelop_size && m <= 1000){
    			m++;
    		}
    		if(m - 1 > max_coverage){
    			ansIndx = l;
    			max_coverage = m - 1;
    		}

    		if(m - 1 == max_coverage){
    			if(coins[l].size() < coins[ansIndx].size()){
    				ansIndx = l;
    			}else if(coins[l].size() == coins[ansIndx].size()){
    				for(int i = coins[l].size() - 1; i >= 0; i--){
    					if(coins[l][i] < coins[ansIndx][i]){
    						ansIndx = l;
    						break;
    					}else if(coins[l][i] > coins[ansIndx][i]){
    						break;
    					}

    				}

    			}
    		}

    	}

    	// cout << "max coverage =   " << max_coverage << " :  ";
    	// for(int i = 0; i < coins[ansIndx].size(); i++){
    	// 	cout << coins[ansIndx][i];
    	// 	cout << (i == coins[ansIndx].size() - 1 ? endl : " ");
    	// }
    	printf("max coverage =%4d :", max_coverage);
        for(int i = 0; i < coins[ansIndx].size(); i++)
            printf("%3d", coins[ansIndx][i]);
        puts("");
        //cout << endl;
    	
    }
    return 0 ;

    runtime();

}
