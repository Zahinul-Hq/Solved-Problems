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

        vector<int>a(n+1,0) , sum(n+1,0);

        map<int,int>mp ;

        for(int i=1 ; i<=n ; i++){

        	cin>>a[i] ;

        	if(mp[a[i]]==0){
        		sum[i]=1;
        	}

        	sum[i]=sum[i]+sum[i-1] ;
        	mp[a[i]]++ ;
        }

        ll ans =0 ;

        mp.clear() ;
        for(int i=n ; i>0  ; i--){

        	if(mp[a[i]]==0){
        		ans+=sum[i];
        	}
        	mp[a[i]]++ ;

        }
        cout<<ans<<endl;
    }
    return 0 ;
}
