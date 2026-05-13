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
        ll  n ;

        cin>>n ;

        vector<ll>a(n+1,0), sum(n+1 ,0 ) ;

        int li=-1 ;
        bool allzero=1 ;

        for(int i=1 ; i<=n ; i++){
        	cin>>a[i] ;
        }

        bool flag=0, vis=0 ;

        for(int i=1; i<=n ; i++){

        	sum[i]=sum[i-1]+a[i] ;

        	if(sum[i]<0)
        		flag=1;
        	
        }

        if(flag || sum[n]!=0){
        	cout<<"No"<<endl;
        	continue ;
        }

        for(int i=1;i<=n ; i++){

        	if(sum[i]==0)
        		vis=1;
        	else if(vis)
        		flag=1 ;

        }

        if(flag)
        	cout<<"No"<<endl;
        else
        	cout<<"Yes"<<endl;


    }
    return 0 ;
}
