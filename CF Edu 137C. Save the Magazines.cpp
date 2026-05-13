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
        int n ,x;

        

        cin>>n;

        string ss ;
        cin>>ss ;

        vector<int>b;


        for(int i=0 ; i<n ; i++){
        	cin>>x ;
        	b.pb(x);
        }

      	for(int i=0 , j=-1  ; i<n ; i++){

      		if(ss[i]=='0')
      			j=i;
      		else if( j>=0  && b[i]<b[j]){
      			swap(ss[i], ss[j]);
      			j=i ;
      		}
      	}

      	ll ans=0 ;

      	for(int i=0 ; i<n ; i++){
      		if(ss[i]=='1')
      			ans+=b[i];
        }

       cout<<ans<<endl;





    }
    return 0 ;
}
