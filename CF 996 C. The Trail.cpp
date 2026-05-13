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

    	string s;
    	cin >>s;

    	ll grid[n][m];

    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			cin >> grid[i][j];
    		}
    	}
    	s += 'D';
    	int x = 0, y = 0;
    	for(int i = 0; i < s.size(); i++){
    		if(s[i] == 'D'){
    			ll sum = 0;
    			for(int l = 0; l < m; l++){
    				sum += grid[x][l];
    			}
    			grid[x][y] = (-1LL * sum);
    			x++;
    		}else{
    			ll sum = 0;
    			for(int l = 0; l < n; l++){
    				sum += grid[l][y];
    			}
    			grid[x][y] = (-1LL * sum);
    			y++;

    		}
    	}

    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			cout << grid[i][j] << " ";
    		}
    		cout << endl;
    	}
    }
    return 0 ;

    runtime();

}
