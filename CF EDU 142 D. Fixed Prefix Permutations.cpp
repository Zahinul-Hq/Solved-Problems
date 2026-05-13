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
    	int n, m,x;
    	cin >> n >> m;

    	vector<int>arr[n];
    	map<vector<int>,int>mp;

    	for(int i = 0; i < n; i++){
    		vector<int>indx(m + 1, 0), tmp(m + 1, 0);
    		for(int j = 1; j <= m; j++){
    			cin >> x;
    			arr[i].push_back(x);
    			indx[x] = j ;
    		}
    		for(int j = 1; j <= m; j++){
    			tmp[indx[j]] = j;
    			mp[tmp]++;
    		}
    	}

    	for(int i = 0; i < n; i++){
    		vector<int>temp, inv(m + 1, 0);
    		int cnt = 0;
    		for(int j = 1; j <= m; j++){
    			inv[arr[i][j - 1]] = j;
    			if(mp[inv])
    				cnt++;
    			else
    				break;
    		}
    		cout << cnt << " ";
    	}
    	cout << endl;


    }
    return 0 ;

    runtime();

}
