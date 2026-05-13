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
        int n , m ;

        cin>>n>>m ;

        vector<int>a(n+1 ,0) ;

        while(m--){

        	int u , v ;
        	cin>>u>>v ;

        	a[u]++ ;
        	a[v]++ ;
        }

        map<int,int>mp ;

        for(int i=1 ; i<=n ; i++){

        	mp[a[i]]++;
        }

        vector<int>cnt ;

        for(auto p : mp){
        	cnt.pb(p.second) ;
        }

        sort(cnt.begin() ,cnt.end()) ;

        if(cnt.size()==3){

        	cout<<cnt[1]<<" "<<cnt[2]/cnt[1]<<endl;
        }else{

        	cout<<cnt[0]-1<<" "<<(cnt[1])/(cnt[0]-1)<<endl;
        }
    }
    return 0 ;
}
