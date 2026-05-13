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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, m;
        cin >> n >> m;

        int arr[n][m];

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		cin >> arr[i][j];
        	}
        }

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		int l = 0 ,r = 0 , u = 0, d = 0;

        		if(i)
        			u = arr[i - 1][j];
        		if(j)
        			l = arr[i][j - 1];
        		if(i < n - 1)
        			d = arr[i + 1][j];
        		if(j < m - 1)
        			r = arr[i][j + 1];
        		int mx = max({u, l, r, d});
        		if(mx < arr[i][j]){
        			arr[i][j] = mx;
        		}
        	}
        }
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		cout << arr[i][j] << " ";
        	}
        	cout << endl;
        }
    }
    return 0 ;
}
