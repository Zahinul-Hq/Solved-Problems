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
        int n , a ,b , x; 

        cin>>n ;

        x=n ;

        vector<pair<int, int>> vp ;

        while(x--){

        	cin>>a>>b ;

        	vp.pb({a,b}) ;

        }

        sort(vp.begin() ,vp.end()) ;

        int d=vp[0].first ,s=(vp[0].second-1)/2 ;

        int k = d+s ;

        for(int i=1 ; i<n ; i++){

        	if(vp[i].first==d){
        		s= min(s, (vp[i].second-1)/2) ;
        		continue ;
        	}

        	int sum = vp[i].first + (vp[i].second-1)/2 ;

        	k = min(sum , k );

        }

        cout<<k<<endl;
    }
    return 0 ;
}
