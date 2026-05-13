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
    	int n, m;
    	cin >> n >> m;

    	int arr[n + 1][m + 1];

    	map<int,int>mp;

    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			cin >> arr[i][j];
    			mp[arr[i][j]] = 1;
    		}
    	}
    	for(int i = 1; i <= n; i++){
    		for(int j = 1; j <= m; j++){
    			if(i - 1 >= 1 && arr[i - 1][j] == arr[i][j])
    				mp[arr[i][j]] = 2;
    			if(i + 1 <= n && arr[i + 1][j] == arr[i][j])
    				mp[arr[i][j]] = 2;
    			if(j - 1 >= 1 && arr[i][j - 1] == arr[i][j])
    				mp[arr[i][j]] = 2;
    			if(j + 1 <= m && arr[i][j + 1] == arr[i][j])
    				mp[arr[i][j]] = 2;
    		}
    	}


    	bool tw = 0;
    	int ans = 0;

    	for(auto i : mp){
    		ans += i.second;
    		tw |= (i.second == 2);
    	}

    	cout << ans - tw - 1 << endl;


    }
    return 0 ;

    runtime();

}
	