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
        int l ,r , x , a,b ;

        cin>>l>>r>>x>>a>>b ;

        if(a==b){
        	cout<<0<<endl;
        }else if( abs(a-b)>=x){
        	cout<<1<<endl;
        }else if((r-max(a,b)>=x)||(min(a,b)-l)>=x){
        	cout<<2<<endl;
        }else if(((r-b)>=x && (a-l)>=x)|| ((r-a)>=x && (b-l)>=x)){
        	cout<<3<<endl;
        }else{
        	cout<<-1<<endl;
        }

    }
    return 0 ;
}
