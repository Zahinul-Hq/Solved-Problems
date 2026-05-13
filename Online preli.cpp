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

    int t ,  i=0 ;
    cin>>t ;
    
    while (i++!=t)
    {
        int n , a, b; 

        cin>>n>>a>>b;

        vector<int>arr(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i] ;
        }


        sort(arr.begin() ,arr.end()) ;

        int ans =0 ;
        
        for(int i=0 ; i<n-1; i++){

        	if(arr[i]+arr[n-1]<a || arr[i]+arr[i+1]>b)
        		break;

        	int up = upper_bound(arr.begin() , arr.end(), b-arr[i] )-arr.begin();

        	int dw = lower_bound(arr.begin() ,arr.end() , a-arr[i])- arr.begin() ;


        	if(dw<=i)
        		dw=i+1 ;

        	//cout<<up<<" "<<dw<<endl;

        	if(dw>=up)
        		break;

 			ans+=(up-dw);

        }

        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0 ;
}
