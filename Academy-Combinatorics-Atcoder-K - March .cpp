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

    map<char ,int>mp ;
    string s2="MARCH";

    cin>>t ;

    while(t--){

    	string s   ;
    	cin>>s ;
    	mp[s[0]]++ ;

    }

    ll ans=0 ;
    for(int i=0 ; i<=2; i++)
    	for(int j=i+1; j<=3 ;j++)
    		for(int k=j+1 ; k<=4 ;k++)
    			ans+=(1ll * mp[s2[i]]*mp[s2[j]]*mp[s2[k]] );


    cout<<ans<<endl;

    		
    return 0 ;
}
