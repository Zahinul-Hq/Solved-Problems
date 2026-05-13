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
const int N = 1005 ;
int n,soaps[N] ,flag ;

ll dp[N][2][2];

ll total_soaps(int indx, int last_taken, int first_taken){
	
	if(indx == n + 1)
		return 0;
	
	if(dp[indx][last_taken][first_taken] != -1)
		return dp[indx][last_taken][first_taken];

	ll ans = total_soaps(indx + 1, 0, first_taken);

	if(!last_taken){
		if(!(indx == n && first_taken))
			ans = max(ans, soaps[indx] + total_soaps(indx + 1, 1,first_taken));
	}

	return dp[indx][last_taken][first_taken] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t, cs=0 ;
    cin >> t ;
    
    while (t--)
    {
    	cin >> n;
    	
        for(int i = 1; i <= n ;i++)
        	cin >> soaps[i];

        memset(dp , -1 ,sizeof dp) ;

        ll ans = total_soaps(1, 0,1) ;

        ans = max(ans, total_soaps(2,0,0));

        cout << "Case " << ++cs << ": " << ans << endl;
    }
    return 0 ;
}
