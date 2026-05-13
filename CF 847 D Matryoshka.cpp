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

        vector<int>v(n) ;

        map<int , int>cnt ;
        set<int>st ;

        for(int i = 0 ; i<n ; i++){
            cin>>v[i] ;

            cnt[v[i]]++ ;
            st.insert(v[i]) ;
            st.insert(v[i]+1) ;
        }

        int last = 0 ;
        int res = 0 ;

        for(auto i : st){

            int c = cnt[i] ;
            res+= max(0 , c-last) ;
            last= c ;
        }


        cout<<res<<endl; 


        
    }
    return 0 ;
}
