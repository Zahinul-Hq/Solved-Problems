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
        int  n , k;
        cin>>n>>k ;
        vector<ll>v(n,0) ;

        ll pr=1 ;

        for(int i=0 ; i<n ; i++){
        	cin>>v[i] ;
        	pr*=v[i] ;
        }

        ll need = 2023/pr ;

        if(2023%pr!=0){
        	cout<<"No"<<endl;
        	continue ;
        }

        cout<<"Yes"<<endl;

        for(int i=0 ; i<k ; i++){
        	if(!i)
        		cout<<need<<" ";
        	else
        		cout<<1<<" " ;

        }

        cout<<endl;
    }
    return 0 ;
}
