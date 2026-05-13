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
int cost_matrix[25][4], n;

ll dp[25][4];
ll total_cost(int indx , int prev_indx){

	if(indx == n+1)
		return 0;

	if(dp[indx][prev_indx] != -1)
		return dp[indx][prev_indx];

	ll ans = inf;


	if(indx == 1){

		for(int i = 1 ;i <= 3; i++){
			ans = min(ans, cost_matrix[indx][i] + total_cost(indx + 1, i ));
		}
	}else{

		for(int i = 1 ;i <= 3; i++){

			if(i != prev_indx)
				ans = min(ans, cost_matrix[indx][i] + total_cost(indx + 1, i ));
		}

	}


	return dp[indx][prev_indx] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , c = 1 ;
    cin>>t ;

    
    
    while (t--)
    {
    	cin.ignore();
        cin >> n;

        for(int i = 1; i <= n; i++){
        	cin >> cost_matrix[i][1] >> cost_matrix[i][2] >> cost_matrix[i][3];
        }

        memset(dp, -1, sizeof dp);

        cout <<"Case "<< c++ << ": " << total_cost(1, 1) << endl;
    }
    return 0 ;
}
