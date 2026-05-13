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
        int n , k;

        cin>>n>>k ;

        vector<int>v(n,0) ;


        for(int i=0 ; i<n ; i++){
        	cin>>v[i] ;
        }

        sort(v.begin() , v.end());

        int cnt = 1 ;

        vector<int>ans ;

        for(int i=0 ; i<n-1 ; i++){

        	if(abs(v[i]-v[i+1])<=k)
        		cnt++ ;
        	else{

        		ans.pb(cnt) ;
        		cnt=1;
        	}
        }

        ans.pb(cnt) ;

        int mx= *max_element(ans.begin() ,ans.end()) ;

        cout<<(n-mx)<<endl;

    }
    return 0 ;
}
