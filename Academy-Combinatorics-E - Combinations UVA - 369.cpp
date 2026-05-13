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
ll comb[101][101] ;

void pascal(){
	
	comb[0][0]=1 ;
	for(int i=1 ; i<101 ;i++){
		comb[i][0]=1 ;
		for(int j=1 ; j<=i ;j++){
			comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;
	pascal() ;

	 int n , m ;
    
    while (cin>>n>>m && n && m){

        cout<<n<<" things taken "<<m<<" at a time is "<<comb[n][m]<<" exactly."<<endl;
    }
    return 0 ;
}
