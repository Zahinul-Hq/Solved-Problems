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
 
int main (){
    
    inout() ;

    int t ;
 
    cin>>t ;
 
    while(t--){
 
        int n , q , x;
 
        cin>>n>>q;
 
        map<int,int>mp ;
 
        vector<long long int>a(n) ;
 
        for(int i=0 ; i<n ; i++){
            cin>>a[i] ;
        }


        while(q--){

            cin>>x ;

            if(mp[x]>0)
                continue;

            for(int i=0 ; i<n ; i++){

                if(a[i]%(1<<x)==0)
                    a[i]+=(1<<x-1) ;
            }
            mp[x]++ ;
        }
 
        for(int i=0 ; i<n ; i++){
            cout<<a[i]<<" " ;
        }
 
        cout<<endl ;
    }
 
 
}