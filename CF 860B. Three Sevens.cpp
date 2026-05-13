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
        int n , m ,x;

        cin>>n;

        map<int,int>mp ;

        vector<int>v[n+2],vec;

        for(int i=1 ; i<=n ; i++){

        	cin>>m ;

        	while(m--){

        		cin>>x ;
        		mp[x]=i ;
        		v[i].pb(x) ;

        	}
        }

       	bool flag=0 ;

        for(int i=1 ; i<=n ; i++){

        	bool ff=0 ;

        	for(int j : v[i]){

        		if(mp[j]==i){
        			ff=1;
        			vec.pb(j) ;
        			break;
        		}
        	}

        	if(!ff){
        		flag=1 ;
        		break;
        	}
        }


       	if(!flag){
       		for(int i=0 ; i<vec.size() ;i++){
       			cout<<vec[i]<<" " ;
       		}
       	}else
       		cout<<"-1" ;

       	cout<<endl;




    }
    return 0 ;
}
