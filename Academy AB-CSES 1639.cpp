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
const int N=5005 , infi=1e9 ;
string a, b ;
int n , m  ;

int dp[N][N] ;

int rec(int i , int j ){

	if(i==n){
		if(j==m){
			return 0; 
		}

		return m-j ;
	}
	if(j==m){
		return n-i ;
	}

	int &ans = dp[i][j];
	if(ans!=-1){
		return ans ;
	}

	 ans = infi;

	if(a[i]==b[i]){
		ans=min(ans , rec(i+1 ,j+1)) ;
	}

	ans= min(ans , 1+rec(i+1, j+1)) ;
	ans= min(ans , 1+rec(i,j+1)) ;
	ans= min(ans , 1+rec(i+1 ,j)) ;

	return ans ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    cin>>a>>b ;

    n = a.size() ;
    m = b.size() ;

   	memset(dp , -1, sizeof dp) ;

   	cout<<rec(0,0)<<endl;
    return 0 ;

}
