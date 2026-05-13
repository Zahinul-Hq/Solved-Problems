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

        vector<int>vec(n,0);

        for(int i=0 ; i<n ; i++){
            cin>>vec[i] ;
        }


        sort(vec.begin() , vec.end()) ;

        int g=vec[0] ;

        for(int i=1 ; i<n ; i++){
            g= __gcd(g ,vec[i]);

        }
        cout<<(vec[n-1]/g)<<endl;



        
    }
    return 0 ;
}
