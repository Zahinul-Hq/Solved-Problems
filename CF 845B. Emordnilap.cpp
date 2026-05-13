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
	#endif
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin>>t ;

    int mod = 1e9 +7 ;
    
    while (t--)
    {
        ll n  ,sum = 1;
        cin>>n ;

        ll x = n ;

        while(x>1)
        {
        	sum = ((sum%mod) *(((x%mod)*(x%mod))%mod))%mod;

        	x-- ; 
        }

        if(n>1)
        	cout<<sum<<endl ;
        else
        	cout<<"0"<<endl ;

    }
    return 0 ;
}