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

        vector<int>a(n,0) ;
        map<int,int>cnt ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;

        	cnt[a[i]]++ ;
        	
        }

        ll ans = 1 , s=0; 

        for(auto [i , j] : cnt){
        	s+=j ;
        	ans = max(ans , (s*(n-s)));
        }

        if(cnt.size()==1)
        	cout<<n/2<<endl;
        else
        	cout<<ans<<endl;


        
    }
    return 0 ;
}
