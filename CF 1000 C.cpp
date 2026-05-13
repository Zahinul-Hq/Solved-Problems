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
    	int n; 
	    cin >> n;

	    vector<vector<int>> tree(n + 1);
	    vector<int> degree(n + 1, 0);

	    for (int i = 0; i < n - 1; ++i) {
	        int u, v;
	        cin >> u >> v;
	        tree[u].push_back(v);
	        tree[v].push_back(u);
	        degree[u]++;
	        degree[v]++;
	    }
	    vector<int>arr;
	    for(int i = 1; i <= n; i++){
	    	arr.push_back(degree[i]);
	    }
	    sort(arr.rbegin(), arr.rend());

	    vector<int>fn;
	    map<int,int>sn;
	    int mx = 0;

	    for(int i = 1; i <= n; i++){
	    	if(arr[0] == degree[i]){
	    		fn.push_back(i);
	    	}
	    	if(arr[1] == degree[i])
	    		sn[arr[1]]++;
	    }
	    sn[arr[0]] -= (arr[0] == arr[1]);

	    bool found = 1;

	    for(int i = 0; i < fn.size(); i++){
	    	int cnt = sn[arr[1]];

	    	for(auto x : tree[fn[i]]){
	    		if(degree[x] == arr[1])
	    			cnt--;
	    	}
	    	found &= ( cnt == 0);
	    }

	    cout << arr[0] + arr[1] - 1 - found << endl;

	    




    }
    return 0 ;

    runtime();

}
