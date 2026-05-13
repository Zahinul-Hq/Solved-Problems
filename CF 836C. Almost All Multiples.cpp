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
        int n , k;

        cin>>n>>k ;

        if((n%k)!=0){
        	cout<<-1<<endl;
        	continue;
        }


        vector<int>ans(n+1,0), p ;

        iota(ans.begin() ,ans.end(), 0) ;

        ans[1]=k ;
        ans[n]=1 ;

        int x= (n/k) , pos= k;

        p.pb(k) ;

        for(int i=2 ; i<=(n/k) ; i++){
            while(x%i==0){
                p.pb(p.back()*i);
                x=x/i ;
            }
        }

        for(int i=0 ; i<p.size()-1 ; i++){
            
            ans[p[i]] = p[i+1]; 
        }

        for(int i=1 ; i<=n ; i++){
            cout<<ans[i];
            if(i==n)
                cout<<endl;
            else
                cout<<" ";
        }










    }
    return 0 ;
}
