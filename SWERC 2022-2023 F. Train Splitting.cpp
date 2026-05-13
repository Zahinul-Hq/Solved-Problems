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
    	int n, m, u, v;

    	cin >> n >> m;
    	vector<int>deg(n + 1, 0);
    	vector<pair<int,int>>vp;

    	for(int i = 0; i < m; i++){
    		cin >> u >> v;
    		vp.push_back({u, v});
    		deg[u]++, deg[v]++;
    	}
    	debug(deg);
    	int c2 = 0;
    	for(int i = 1; i <= n; i++){
    		if(deg[i] < n - 1)
    			c2 = i;
    	}
    	debug(c2);

    	if(c2){
    		cout << 2 << endl;
    		for(int i = 0; i < m; i++){
    			if(c2 == vp[i].first || c2 == vp[i].second){
    				cout << 2 << " ";
    			}else{
    				cout << 1 << " ";
    			}
    		}
    		cout << endl;
    	}else{
    		c2 = 1;
    		bool f = 1;
    		cout << 3 << endl;
    		for(int i = 0; i < m; i++){
    			if(c2 == vp[i].first || c2 == vp[i].second){
    				cout << (f ? 3 : 2) << " ";
    				f = 0;
    			}else{
    				cout << 1 << " ";
    			}
    		}
    		cout << endl;
    	}




    }
    return 0 ;

    runtime();

}
