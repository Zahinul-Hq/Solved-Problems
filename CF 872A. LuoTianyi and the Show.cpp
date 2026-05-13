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
        int n ,m, left=0 ,  right=0, x;

        set<int>st ; 

        cin>>n>>m ;

        for(int i=0 ; i<n ; i++){
        	cin>>x ;

        	if(x==-1)
        		left++ ;
        	else if(x==-2)
        		right++ ;
        	else
        		st.insert(x) ;
        }

        x= st.size() ;

        int ans = max(left+x , right+x), taken=0 ;

        for(auto i : st){

        	int lfcnt = min(left , i - (taken+1)) ;
        	int rtcnt = min(right , m-i-(x-(taken+1))) ;

        	taken++ ;

        	ans= max(ans , x+lfcnt+rtcnt) ;
        }

        ans= min(ans , m ) ;


        cout<<ans<<endl;

    }
    return 0 ;
}
