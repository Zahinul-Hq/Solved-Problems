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

    vector<int>a[6] ;

    a[1].pb(2) ;
    a[2].pb(3) ;
    a[2].pb(4) ;
    a[3].pb(1) ; 
    a[3].pb(5) ;
    a[4].pb(3) ;
    a[4].pb(5) ;

    for(int i=1 ; i<=5 ; i++){

    	cout<<i<<" : ";

    	for(int j : a[i])
    		cout<<j<<" " ;

    	cout<<endl;
    }


    return 0 ;
}
