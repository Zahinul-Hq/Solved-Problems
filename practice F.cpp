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

    int n,x ;

    cin>>n ;

    vector<ll>a(n+1,0) ;

    ll sum= 0  ,ans=0;

    for(int i=1 ; i<=n ; i++){
    	cin>>a[i];

    	sum+=a[i] ;
    }



    for(int i=0 ; i<n ; i++){

    	cin>>x ;

    	sum= (sum-a[x]);

    	

    	if(sum%10==0){
    		ans+=sum ;
	    }
	    else if((sum%10)>=5){
	    	
	    	ans+=(sum-(sum%10));
	    	ans+=10 ;

	    	cout<<sum<<endl;
	    }else{

	    	
	    	ans+=(sum-(sum%10));
	   		
	    }
	    
	    


    	
    	
    }


    cout<<ans<<endl;


   

    return 0 ;
}
