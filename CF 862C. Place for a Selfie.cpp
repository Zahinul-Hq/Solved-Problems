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
        ll n, m , a, b ,c ;

        cin>>n>>m ;

        vector<ll>k(n) ;

        for(int i=0  ; i<n ; i++){
        	cin>>k[i];
        }

        sort(k.begin() ,k.end());

        while(m--){

        	cin>>a>>b>>c ;

        	int ind = lower_bound(k.begin(), k.end() , b)-k.begin() ;

        	if(ind<n && ((k[ind]-b)*(k[ind]-b))<(4*a*c)){
        		cout<<"Yes"<<endl<<k[ind]<<endl;
        		continue ;
        	}

        	if(ind>0 && ((k[ind-1]-b)*(k[ind-1]-b))<(4*a*c)){
        		cout<<"Yes"<<endl<<k[ind-1]<<endl;
        		continue ;
        	}


        	cout<<"No"<<endl;
        }

    }
    return 0 ;
}
