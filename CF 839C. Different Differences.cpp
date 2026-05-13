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

        cin>>k>>n ;


        if(k==n){

        	for(int i=1; i<=n ; i++){
        		cout<<i<<" " ;
        	}
        	cout<<endl;
        	continue ;
        } 

        set<int>st ;

        int sum=1 ;

        for(int i=1 ; i<=n ; i++){

        	if(st.size()<k && sum<=n){
        		st.insert(sum);
        		sum= sum+i ;
        		continue ;
           	}

        	break ;
        } 

        for(int i=n ; i>=1 ; i--){

        	if(st.size()<k){
        		st.insert(i);
        		continue ;
        	}
        	break ;

        }

        for(auto i : st){

        	cout<<i<<" " ;
        }

        cout<<endl;

        
    }
    return 0 ;
}
