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

ll lcm(ll x , ll y){

	return(x*y)/__gcd(x,y);
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
        int n ;

        cin>>n ;

        vector<ll>a(n+1,0) ,b(n+2,0); 

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }

        bool flag=1 ;

        b[1]=a[1];
        

        for(int i=2; i<=n ; i++){

        	b[i]= lcm(a[i],a[i-1]);

        }
        b[n+1]=a[n] ;

        for(int i=2; i<=n+1; i++){

        	if(__gcd(b[i-1],b[i])!=a[i-1]){
        		flag=0 ;
        		break ;
        	}
        }

        

        if(flag)
        	cout<<"YES"<<endl;
        else
        	cout<<"NO"<<endl;


    }
    return 0 ;
}
