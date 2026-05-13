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

        vector<int>arr(n , 0) ;

        int mx=0 , mn = INT_MAX;

        map<int , int>mp ;

        for(int i=0 ; i<n ; i++){

        	cin>>arr[i] ;

        	mx=max(mx , arr[i]);
        	mn=min(mn , arr[i]);

        	mp[arr[i]]++ ;
        }

        int cnt1 = mp[mx] ,cnt2=mp[mn];

        ll ans ;

        if(mx==mn)
        	ans= 1ll*n*(n-1) ;
        else
        	ans= 2ll*cnt1*cnt2 ;

        cout<<ans<<endl;

    }
    return 0 ;
}
