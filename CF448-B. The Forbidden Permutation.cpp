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
    	int n , m , d ;
        cin>>n>>m>>d ;

        vector<int>pos(n+1,0);

        for(int i=1 ;i<=n ; i++){
        	int x ;
        	cin>>x ;
        	pos[x]=i ;
        }

        vector<int>a(m,0);

        for(int i=0 ; i<m; i++){
        	cin>>a[i] ;
        }

        int ans= 10000000 ;

        for(int i=0 ; i<m-1 ; i++){

        	if((pos[a[i]]>pos[a[i+1]])|| (pos[a[i+1]]>(pos[a[i]]+d))){
        		ans = 0 ;
        		break ;
        	}else{

        		ans= min(ans , pos[a[i+1]]-pos[a[i]]) ;
        		int move = d+1-pos[a[i+1]]+pos[a[i]];

        		if(move<= pos[a[i]]-1 +n-pos[a[i+1]])
        			ans = min(ans , move) ;
        	}


        }

        cout<<ans<<endl;
    }
    return 0 ;
}
