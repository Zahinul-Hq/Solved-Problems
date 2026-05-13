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
        string s ;

        cin>>n>>s ;

        ll ans =0 ;

        for(int i=0 ; i<n ; i++){
        	vector<int>oc(100, 0) ;

        	int dt = 0 , mx=0 ;

        	for(int j=i ; j<min(n,i+100) ; j++){

        		if(oc[s[j]]==0)
        			dt++ ;

        		oc[s[j]]++ ;

        		mx= max(mx, oc[s[j]]) ;

        		if(mx<=dt)
        			ans++ ;
        	}
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
