#include<iostream>
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

	ll n  , m ;
    
    while (1 )
    {
    	cin>>n>>m ;
        if(n==0 && m==0)
        	break;

        ll mn= min(n,m) ;
        ll mx=max(n,m) ;
        ll tot = n+m;
        ll ans1=1;
        ll ans2=n ;
        ll ans3;

        for(int i=1; i<=mn ; i++){

        	ans1=ans1*(tot-i+1);
        	ans1=ans1/i ;
        }
     
        cout<<ans1<<endl;



    }
    return 0 ;
}
