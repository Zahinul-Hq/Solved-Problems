#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

       int n, m;
        cin >> n >> m;
        int grid[n + 1][m + 1];

        int res = 0;
        vector<int>ans;

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		cin >> grid[i][j];
        	}
        	res ^= grid[i][0];
        	ans.push_back(0); 
        }
        if(res == 0){
        	for(int i = 0; i < n; i++){
	        	for(int j = 1; j < m ; j++){
	        		res ^= grid[i][j - 1];
	        		res ^= grid[i][j];
	        		if(res){
	        			ans [i] = j;
	        			break;
	        		}
	        	}
	        	if(res)
	        		break;
        	} 
        }
        if(res == 0){
        	cout << "NIE" << endl;
        }else{
        	cout << "TAK" << endl;
        	for(auto i : ans){
        		cout << i + 1 << " ";
        	}
        }
        cout << endl;


      return 0 ;  
    }
    

