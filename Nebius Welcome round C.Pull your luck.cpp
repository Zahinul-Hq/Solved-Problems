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

    	int n ,x, k ;
        cin>>n>>x>>k ;

        int p=0 ;

        
        bool flag=0 ;
        for(ll i=1 ; i<=min(k ,2*n) ;i++){

        	ll ans = i*(i+1)/2 +x ;

        	if(ans%n==0){
        		flag=1 ;
        		break;
        	}

        }

        if(flag)
        	cout<<"Yes"<<endl;
        else
        	cout<<"No"<<endl;
    }
    return 0 ;
}
