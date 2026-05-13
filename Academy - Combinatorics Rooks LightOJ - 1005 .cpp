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
const int N = 35;
ll C[N][N];

void pascal_triangle(){

	for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      cout << C[i][j] << " ";
    }

    cout << endl;
  }

  
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t , cs =  1;
    cin >> t ;

    pascal_triangle();
    
    while (t--)
    {
    	int n , k ;

    	cin >> n >> k ;

      cout << n << " " << k << endl;

    	cout << "Case " << cs++ << ": "; 
    	if(n < k){
    		cout << 0 << endl;
    		continue;
    	}
    	ll  f = 1;
    	for(int i = 1; i <= k; i++){
    		f *= i;
    	}

    	ll ans  = C[n][k];
      cout << ans << endl;
    	cout << 1LL * ans * ans* f << endl;
        
    }
    return 0 ;
}
