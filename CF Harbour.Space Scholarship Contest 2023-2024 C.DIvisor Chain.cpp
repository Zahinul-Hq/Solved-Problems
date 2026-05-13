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

    	int x, n; 

    	cin>>x ;

    	n=x ;

    	vector<int>mark;

	    while (x > 0) {
	 
	        mark.pb(x%2) ; 
	        x = x / 2;
	    }
	    vector<ll>ans ;

	    int pos = -1 ;

	    for(int i=0 ; i<mark.size(); i++){

	    	if(mark[i]){
	    		ans.pb(pow(2,i)) ;
	    		pos=i ;
	    	}

	    }

	    ans.pop_back() ;

	    ll val = pow(2,pos);

	    while(val>0){

	    	val=val/2 ;
	    	ans.pb(val) ;
	    }

	    cout<<ans.size()<<endl<<n<<" ";

	    for(int i=0; i<ans.size()-1 ; i++){

	    	n=n-ans[i];
	    	cout<<n<<" ";
	    }

	    cout<<endl;


    }
    return 0 ;
}
