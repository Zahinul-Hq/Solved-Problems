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
const int N=3033;
string a , b ;
int n , m ,dp[N][N];
int lcs(int i ,int j){

	if(i>=a.size() or j>=b.size())
		return 0 ;

	if(dp[i][j]!=-1)
		return dp[i][j] ;

	int ans=lcs(i+1,j);

	ans=max(ans,lcs(i ,j+1));

	if(a[i]==b[j]){
		ans=max(ans, 1+lcs(i+1, j+1)) ;
	}

	return dp[i][j]=ans; 
}

void print(int i, int j){

	if(i>=a.size() or j>=b.size())
		return ;

	if(a[i]==b[i]){
		cout<<a[i];
		print(i+1 ,j+1);
		return ;
	}

	int x=lcs(i+1 ,j);
	int y=lcs(i ,j+1);

	if(x>=y){
		print(i+1 ,j);
	}
	else{
		print(i, j+1);
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin>>a>>b ;

   	memset(dp,-1, sizeof dp) ;

    print(0,0) ;

    return 0 ;
}
