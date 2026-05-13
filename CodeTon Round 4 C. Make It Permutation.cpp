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
        int n , c ,d ; 
        cin>>n>>c>>d ;

        vector<int>arr(n,0);


        bool One=false ;
        for(int i=0 ; i<n ; i++){
        	cin>>arr[i];
        	if(arr[i]==1)
        		One=1 ;
        }

        ll cost=0,incost=0 ,delcost=0 ; 

        if(!One){
        	arr.pb(1) ;
        	n++ ;
        	cost+=d;
        	incost=d;
        }

        sort(arr.begin() , arr.end());
        int  pos = unique(arr.begin() , arr.end())-arr.begin();

        

        for(int i=0 ; i<pos-1 ; i++){

        	int diff=arr[i+1]-arr[i];

        	if(diff>1){

        		incost+=(diff-1)*d;
        		delcost+= (pos-i-1)*c ;

        		if(incost>=delcost){
        			cost+=delcost;
        			break ;
        		}
        		cost+=incost;

        		incost=0 ,delcost=0 ;
        		
        	}
        }

        cost+=(n-pos)*c ;


        cout<<cost<<endl;


    }
    return 0 ;
}
