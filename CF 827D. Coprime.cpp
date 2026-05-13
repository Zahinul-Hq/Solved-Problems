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
const int N = 1e3 +7 ;
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
        int n ,x;

        cin>>n ;

        set<int>st ;

        vector<int>mark(N,0);

        for(int i = 1 ; i<=n ; i++){
        	cin>>x;
        	st.insert(x);
        	mark[x]=i;
        }

        int ans= -1 ;

        for(auto i : st){
        	for(auto j : st){
        		if(__gcd(i,j)==1){
        			ans = max(ans , mark[i]+mark[j]);
        		}
        	}
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
