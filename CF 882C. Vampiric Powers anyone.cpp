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

        cin>>n; 

        vector<int>a(n,0) ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }

        int ans=0 ;

        for(int i=0 ; i<(1<<8) ; i++){
        	int cur = 0 ;
        	vector<int>vis(1<<8 , 0);
        	for(int j=n-1 ; j>=0 ; j--){

        		cur^=a[j] ;

        		vis[cur^i] = 1 ;

        		ans = max(ans ,cur) ;

        		if(vis[cur]){
        			ans=max(ans, i) ;
        		}
        	}
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
