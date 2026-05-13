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

        vector<int>arr(n,0);

        ll sum= 0 ;

        for(int i=0 ; i<n ; i++){
        	cin>>arr[i];

        	if(arr[i]<0)
        		sum+= (-1*arr[i]);
        	else
        		sum+=arr[i] ;

        }

        int cnt=0 ,i=0 ;

        while(i<n){

        	if(arr[i]<0){
        		cnt++ ;
        		while(arr[i]<=0 && i<n)
        			i++ ;

        		continue ;
        	}

        	i++ ;
        }


        cout<<sum<<" "<<cnt<<endl;


    }
    return 0 ;
}
