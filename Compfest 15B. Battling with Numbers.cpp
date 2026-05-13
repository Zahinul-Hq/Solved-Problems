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
	
	 int n, m,x , mod=998244353;

        cin>>n ;

        vector<ll>a(n,0) ;
        map<ll,ll>mp ;

        for(int i=0; i<n ; i++){
        	cin>>a[i];
        }

        for(int i=0; i<n ; i++){
        	cin>>x ;
        	mp[a[i]]=x ;
        	
        }

        cin>>m ;
        vector<ll>b(m,0) ;

        ll ans= 1 ,eq=0; 
        bool flag=1 ,ev=0;

        for(int i=0; i<m ; i++){
        	cin>>b[i];
        }

        for(int i=0; i<m ; i++){
        	cin>>x ;
        	
        	if(mp[b[i]]==0 || mp[b[i]]<x)
        		flag=0 ;

        	if(mp[b[i]]-x>0)
        		eq++ ;
        }

        for(int i=0 ; i<eq+(n-m); i++){
        	ans=ans*2LL%mod;
        } 

        if(!flag){
        	cout<<0<<endl;
        }
        else{
        	cout<<ans<<endl;
        }

    
    return 0 ;
}
