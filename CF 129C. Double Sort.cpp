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

        cin>>n ;

        vector<pair<int,int>>ans ;

        vector<int>b(n,0), a(n,0) ;

        for(int i=0; i<n ; i++){
        	cin>>a[i] ;
        }
        for(int i=0; i<n ; i++){
        	cin>>b[i] ;
        }


        for(int i=0 ; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                if(a[i]>a[j] || b[i]>b[j]){
                    swap(a[i],a[j]) ;
                    swap(b[i],b[j]) ;
                    ans.pb({j+1 , i+1}) ;
                }
            }
        }

        if(!is_sorted(b.begin() ,b.end()) ||!is_sorted(a.begin() ,a.end())  ){
            cout<<-1<<endl;
            continue ;
        }

        cout<<ans.size()<<endl;

        for(auto i : ans){
            cout<<i.F<<" "<<i.S<<endl;
        }
    }
    return 0 ;
}
