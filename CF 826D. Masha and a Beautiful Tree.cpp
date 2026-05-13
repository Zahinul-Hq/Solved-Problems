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

const int N = 262144+7 ;
vector<int>arr(N,0) ;

int build(int tl , int tr) {

    if(tr-tl==1)
        return 0 ;

    int ans= 0; 

    int tm = (tl+tr)/2 ;

    int mxl = *max_element(arr.begin()+tl, arr.begin()+tm) ;
    int mxr = *max_element(arr.begin()+tm , arr.begin()+tr) ;

    if(mxl>mxr){
        ans++ ;
        for(int i=0 ; i<(tm-tl) ; i++){
            swap(arr[i+tl] , arr[tm+i]);
        }
    }

    return build(tl , tm)+build(tm, tr)+ans ;
 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t;
    cin>>t ;
    
    while (t--)
    {
        int n ;

        cin>>n ;

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i];
        }

        bool flag=0 ;

        int ans = build(0,n);

        
        if(is_sorted(arr.begin() , arr.begin()+n)){
            cout<<ans<<endl ;

            
        }else
            cout<<-1<<endl;

       


    }
    return 0 ;
}
