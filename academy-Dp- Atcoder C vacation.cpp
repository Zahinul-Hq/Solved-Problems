#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

const int N = 1e5+9 ;
ll h[N][3], b[N], c[N], n ;

ll dp[N][3];


ll happiness(int i, int k){

	if(i > n)
		return 0;

	if(dp[i][k] != -1)
		return dp[i][k];

	ll ans = low;

	if(i == 1){

		for(int j = 0; j < 3 ; j++){

			ans = max(ans , happiness(i+1, j) + h[i][j]);
		}
	}else{

		for(int j = 0; j < 3 ; j++){

			if(j != k){
				ans = max(ans , happiness(i+1, j) + h[i][j]);
			}
		}
	}

	return dp[i][k] = ans;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin>>n ;

    memset(dp , -1 , sizeof dp) ;


    for(int i = 1 ; i <= n ; i++){
    	cin >> h[i][0] >> h[i][1] >> h[i][2] ;
    }

    cout << happiness(1,1) << endl;
    
    return 0 ;
}
