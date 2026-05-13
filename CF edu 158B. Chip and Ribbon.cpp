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
        int n ,x;

        cin>>n ;

        if(n==1){
        	cin>>x ;
        	cout<<x-1<<endl;
        	continue ;
        }

        vector<pair<int,int>>p ;

        vector<int>a(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>x ;

        	a[i]=x ;

        	p.pb({x,i}) ;

        }

        sort(p.begin(), p.end()) ;

        int ans=0 ,prv=0 , j=1 ;

        for(int i=0 ; i<n; i++){

        	

        	int mx=-1 , mn = INT_MAX , flag=0;

        	while(a[j-1]<=a[j] && j<n  ){

        		mx=max(mx,a[j]) ;

        		mn=min(mn,a[j]) ;

        		j++ ;
        	}
        	ans+=(mx-mn) ;

        	mx=-1 , mn = INT_MAX , flag=0;

        	while(a[j-1]>=a[j]  && j<n){

        		mx=max(mx,a[j]) ;

        		mn=min(mn,a[j]) ;

        		j++ ;
        	}

        	

        	ans+=(mx-mn) ;
        	

        	
        	if(j>=n-1)
        		break;
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
