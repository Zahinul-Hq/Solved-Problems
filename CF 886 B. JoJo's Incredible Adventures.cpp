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

    int t ;
    cin>>t ;
    
    while (t--)
    {
        string s ;

        cin>>s ;

        ll n=s.size();

        ll cnt=0 , mx=0;

        for(int i=0; i<2*n ;i++){

        	if(s[i%n]=='1'){
        		cnt++ ;
        		continue ;
        	}
        	
        	mx=max(mx,min(cnt,n)) ;
        	cnt=0 ;
        }

        mx=max(mx,min(cnt,n)) ;

        if(mx==n){
        	cout<<n*n<<endl;
        }else if(mx==1)
        	cout<<1<<endl;
        else{

	        ll col= (mx+1)/2;

	        ll ans = col*((mx+2)/2) ;

	        cout<<ans<<endl;
	    }
    }
    return 0 ;
}
