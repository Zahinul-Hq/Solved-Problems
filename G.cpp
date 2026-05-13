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
        int n ;

        cin>>n ;

        vector<int>st(n,0) , en(n,0) , stmp(n,0) ; 


        vector<int>ans[n];

        vector<pair<int,int>>vp ;

        for(int i=0 ; i<n ; i++){

        	cin>>st[i] ;

        	stmp[i]=st[i] ;

        }
        for(int i=0 ; i<n ; i++){

        	cin>>en[i] ;

        }

        for(int i=0 ; i<n ; i++){

        	vp.pb({st[i] , en[i]}) ;

        }



        sort(stmp.begin() , stmp.end()) ;
        sort(vp.begin() , vp.end()) ;

        for(int i=0 ; i<n ; i++){

        	int val = st[i] ;
        	ans[i].pb(i+1) ;
	        while(1){
	        	int pos = upper_bound(stmp.begin() ,stmp.end(), val )-stmp.begin();
	        	if(pos>=n)
	        		break ;
	        	val = vp[pos].second ;

	        	
	        	ans[i].pb(pos+1) ;
	        }

	    }


	    int x = 0 ,sz=0 ;


	    for(int i=0 ; i<n ; i++){

	    	if(sz<ans[i].size())
	    		x=i ;

	    }

	    for(int i=0 ; i<ans[x].size() ; i++){
	    	cout<<ans[x][i]<<" " ;
	    }


	    cout<<endl;

    }
    return 0 ;
}
