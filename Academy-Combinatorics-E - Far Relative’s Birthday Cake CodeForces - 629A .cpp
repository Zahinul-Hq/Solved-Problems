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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int n; 

    cin>>n ;

    char input[n][n] ;

    for(int i=0 ; i<n ; i++){
    	for(int j=0 ; j<n ; j++){
    		cin>>input[i][j] ;
    	}
    }

    ll ans=0;
    int col=0 ,row=0;

    vector<int>v;

    for(int i=0 ; i<n ; i++){
    	for(int j=0 ; j<n ; j++){
    		if(input[i][j]=='C'){
    			col++ ;
    		}
    		if(input[j][i]=='C'){
    			row++ ;
    		}
    	}
    	col = col*(col-1)/2 ;
   		row = row*(row-1)/2 ;
   		ans+=col+row ;
    	row=0 , col=0 ;
    }

    cout<<ans<<endl;
    return 0 ;
}
