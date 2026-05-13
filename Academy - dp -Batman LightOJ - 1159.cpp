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
string a, b, c;

const int N = 55;

int dp[N][N][N];
int lcs(int i, int j, int k){

	if(a.size() <= i || b.size() <= j || c.size() <= k)
		return 0;


	if(dp[i][j][k] != -1)
		return dp[i][j][k];

	int ans = lcs(i + 1, j, k);

	ans = max(ans, lcs(i, j + 1, k));
	ans = max(ans, lcs(i, j, k + 1));

	if(a[i] == b[j] && b[j] == c[k]){
		ans = max(ans, lcs(i + 1, j + 1, k + 1) + 1);
	}

	return dp[i][j][k] = ans;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , x = 1;
    cin>>t ;
    
    while (t--)
    {

    	cin.ignore() ; 
        memset(dp, -1, sizeof dp);

        cin >> a >> b >> c;

        int ans = lcs(0, 0, 0);

        cout << "Case " << x++ << ": " << ans <<endl;
    }
    return 0 ;
}
