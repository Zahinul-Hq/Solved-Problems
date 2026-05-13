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

        ll now = 0;


        cout << n * m << endl;

        ll v[n + 3][m + 3];

         for(int i = 0; i < n; i += 2)
            for(int j = 0; j < m; j += 2){
                v[i][j] = now;
                v[i][j + 1] = now + 1;
                v[i + 1][j] = now + 2;
                v[i + 1][j + 1] = now + 3;
                now += 4;
            }
    

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		cout << v[i][j] << " \n"[j + 1 == m];
        	}
        	
        }

       
       // cout << x << endl;
    }
    return 0 ;
}
