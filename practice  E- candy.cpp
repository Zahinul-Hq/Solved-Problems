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

/*void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}*/
ll ext_gcd ( ll A, ll B, ll *X, ll *Y ){
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
ll modInv ( ll a, ll m ) {
    ll x, y;
    ext_gcd( a, m, &x, &y );
 
    // Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	//inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        ll a , x ;

        cin>>a>>x;


        if(__gcd(a,x)!=1){
        	cout<<"IMPOSSIBLE"<<endl;
        	continue;
        }

        if(x==1){
        	cout<<a+1<<endl;
        	continue;
        }
        if(a==1){
        	cout<<2<<endl;
        	continue ;
        }


       ll ans = modInv(x,a);

       cout<<ans<<endl;

        

        
    }
    return 0 ;
}
