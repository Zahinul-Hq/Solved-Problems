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

ll fn(ll n){

	return n*(n+1)/2 ;


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        ll n , x ,y ,a,b;

        ll ans , sumx , sumy  , lcm;

        cin>>n>>x>>y ;

        lcm = (x*y)/__gcd(x,y);

        sumx = n/x - n/lcm ;
        sumy = n/y - n/lcm ;


        ans = fn(n) - fn(n-sumx)-fn(sumy) ;

        cout<<ans<<endl;

        


    }
    return 0 ;
}
