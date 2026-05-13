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

    	vector<int>a(n+1) ;

    	int mx = -21,mxin=-1,mnin=-1 , mn= 21 ;

    	for(int i=1 ; i<=n ; i++){
    		cin>>a[i] ;

    		if(a[i]>mx){
    			mx=a[i]   ;
    			mxin = i  ;
    		}
    		if(a[i]<mn){
    			mn=a[i]  ;
    			mnin = i ;
    		}
    	}
    	vector<pair<int,int>>ans ;

    	if(mn+mx>=0){

    		for(int i=1 ; i<=n ; i++){
    			if(a[i]<0){
    				a[i]+=mx ;
    				ans.pb({i , mxin});
    			}
    		}

    		for(int i=2 ; i<=n ; i++){
    			a[i]+=a[i-1] ;
    			ans.pb({i,i-1});
    		}
    	}else{

    		for(int i=1 ; i<=n ; i++){
    			if(a[i]>0){
    				a[i]+=mn;
    				ans.pb({i , mnin});
    			}
    		}

    		for(int i=n ; i>=2 ; i--){
    			a[i-1]+=a[i] ;
    			ans.pb({i-1,i});
    		}

    	}

    	cout<<ans.size()<<endl;


    	for(int i=0 ; i<ans.size() ; i++){

    		cout<<ans[i].F<<" "<<ans[i].S<<endl;

    	} 
    }
    return 0 ;
}
