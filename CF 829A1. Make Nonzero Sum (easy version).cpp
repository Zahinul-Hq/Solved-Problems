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

        vector<int>a(n+1,0);

        for(int i=1 ; i<=n ;i++){
        	cin>>a[i];
        }

        if(n%2==1){
        	cout<<-1<<endl;
        	continue;
        }

        

        vector<pair<int,int>>ans;

        

        for(int i=2 ; i<=n ; i+=2){

        	if(a[i]== a[i-1])
        		ans.pb({i-1,i});
        	else{
        		ans.pb({i-1 ,i-1});
        		ans.pb({i,i});
        		
        	}
        }

        cout<<ans.size()<<endl;

        for(auto i : ans){

        	cout<<i.first<<" "<<i.second<<endl;
        }


    }
    return 0 ;
}
