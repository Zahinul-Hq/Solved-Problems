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

        map<int,int>mp ;

        for(int i=0 ; i<n ; i++){
        	int x ;
        	cin>>x;

        	for(int j=2 ; j*j<=x ;j++ ){

        		while(x%j==0){
        			x=x/j ;
        			mp[j]++ ;
        		}
        	}

        	if(x!=1)
        		mp[x]++ ;
        }

        int res=0 ,rem=0 ;

        for(auto p : mp){

        	int cnt = p.second ;

        	res+=cnt/2 ;
        	rem+=cnt%2 ;
        }

        int ans = res+(rem/3) ;

        cout<<ans<<endl;
    }
    return 0 ;
}
