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
        vector<int>a(n+1);
        for(int i=1 ; i<=n ; i++)
        	cin>>a[i] ;

        int cnt=0 ;
        if(a[n]){
        	cout<<"NO"<<endl;
        	continue ;
        }

        vector<int>ans ;
        for(int i= n ; i>=1 ; i--){

        	if(a[i]==1)
        		cnt++ ;

        	if(a[i]==1 && (a[i-1]==0 ) ){
	        		ans.pb(cnt ) ;
	        		cnt=0 ;
	        		continue ;
        	}

        	ans.pb(0) ;
        }

        

        if(ans.size()>0){
        	cout<<"YES"<<endl;
	        for(int i= ans.size()-1 ; i>=0 ;i--){
	        	cout<<ans[i]<<" " ;
	        }

	        cout<<endl;
        }
    }
    return 0 ;
}
