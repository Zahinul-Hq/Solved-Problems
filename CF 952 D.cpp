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

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string grid[n];

        for(int i = 0; i < n; i++){
        	cin >> grid[i];
        }
        int row = 0, col = 0, r_mx = 0, c_mx = 0;

        for(int i = 0; i < n; i++){
        	int rcnt = 0;
        	for(int j = 0; j < m; j++){
        		if(grid[i][j] == '#')
        			rcnt++;
        	}
        	if(rcnt > r_mx){
        		row = i + 1;
        		r_mx = rcnt;
        	}
        }
        for(int i = 0; i < m; i++){
        	int rcnt = 0;
        	for(int j = 0; j < n; j++){
        		if(grid[j][i] == '#')
        			rcnt++;
        	}
        	if(rcnt > c_mx){
        		col = i + 1;
        		c_mx = rcnt;
        	}
        }

        cout << row << " " << col << endl;
    }
    return 0 ;
}
