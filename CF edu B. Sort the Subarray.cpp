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

    	cin>>n;

    	vector<int>a(n+2,0);
    	vector<int>b(n+2,0) ;

    	for(int i=1 ; i<=n ; i++){
    		cin>>a[i];
    	}
    	for(int i=1 ; i<=n ; i++){
    		cin>>b[i];
    	}

    	int mx=1, left=n , right= 0 ,j=1 ,last=0 ,cnt=0;

    	for(int i=1 ; i<=n ; i++){

    		if(a[i]!=b[i]){
    			left= min(left ,i);
    			right = max(right ,i) ;
    		}
    	}

    	while(left-1>=1 && b[left]>=b[left-1])
    		left-- ;
    	while(right+1<=n && b[right]<=b[right+1])
    		right++ ;

    	cout<<left<<" "<<right<<endl;        
    }
    return 0 ;
}
