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
        int n ,ans=0 ;
        char c ;
        string s="0" , ss;

        bool ok = 0 , oook=0;

        cin>>n>>c>>ss ;

        s+=ss ;

        for(int i=1 ; i<=n ; i++){

        	if(s[i]!=c)
        		oook=1 ;
        }
        	

        if(!oook){
        	cout<<0<<endl;
        	continue ;
        }

        for(int i=1 ; i<=n ; i++){
        	ok = true ;
        	for(int j= i ; j<=n ; j+=i){

        		if(s[j]!=c)
        			ok=false;

        	}

        	if(ok){
        		ans= i;
        		break;
        	}
        }

        if(ok)
        	cout<<1<<endl<<ans<<endl;
        else
        	cout<<2<<endl<<n<<" "<<n-1<<endl;


    }
    return 0 ;
}
