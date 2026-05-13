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


        for(int i=2 ; i*i<=n ; i++){

        	int c=0 ;

        	while(n%i==0){
        		c++ ;
        		if(mp[c]==0){
        			mp[c]=i;
        		}else{
        			mp[c]*=i ;
        		}
        		n=n/i ;
        	}
        }

        if(!mp[1])
        	mp[1]=n;
        else
        	mp[1]*=n ;

        int ans=0 ;


        for(auto it : mp){
        	ans+=it.second ;
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
