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
vector<int>arr(105,0) ;
vector<int>depth(105 ,0 ) ; 

void build(int l , int r , int dep){

	if(l>r)
		return ;

	int mx= l ;

	for(int i=l  ; i<=r ;i++){

		if(arr[i]>arr[mx])
			mx=i ;
	}
	depth[mx]=dep ;

	build(l , mx-1 , dep+1) ;
	build(mx+1 , r , dep+1) ;
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

        cin>>n;

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i] ;
        }

        build(0 , n-1 , 0) ;

        for(int i=0 ; i<n ; i++){
        	cout<<depth[i]<<" " ;
        }

        cout<<endl; 

        arr.assign(105 , 0) ;


    }
    return 0 ;
}
