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

        cin>>n ;

        int mod = 1e9+7 ;

        vector<int>a(n+1,0), b(n+1,0), d(n+1,0), pos(n+1,0);
        vector<bool>check(n+1,false);

        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        	pos[a[i]]=i;
        }
        for(int i=0 ; i<n ; i++){
        	cin>>b[i];
        }
        for(int i=0 ; i<n ; i++){
        	cin>>d[i];
        	check[d[i]]=1 ;
        }
        ll ans=1;
        for(int i=0 ; i<n ; i++){

        	if(a[i]==b[i])
        		continue;
        	if(check[a[i]]||check[b[i]])
        		continue ;

        	vector<int>done ;
        	int curr = b[i] ;
        	done.pb(a[i]);
        	bool f=0 ;

        	while(curr!=a[i]){
        		if(check[curr])
        			f=1;
        		done.pb(curr);
        		curr = b[pos[curr]];

        		if(check[curr])
        			f=1 ;

        	}
        	
        	if(!f)
        		ans=(ans*2)%mod;

        	for(auto i : done){
        		check[i]=1;
        	}
        	

        }

        cout<<ans<<endl;
    }
    return 0 ;
}
