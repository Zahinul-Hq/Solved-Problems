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
        int n , a, b;

        cin>>n>>a>>b ;

        int arr[n+1] ;

        for(int i=1 ; i<=n ; i++)
        	arr[i]=i ;


        if(a+b+2>n || abs(a-b)>1){
        	cout<<-1<<endl;
        	continue ;
        }

        if(a==b){

        	for(int i=1 ; i<=a ; i++){
        		swap(arr[2*i] ,arr[2*i+1]);
        	}
        }else if(a<b){

        	for(int i=1 ; i<=b ; i++){
        		swap(arr[2*i-1] ,arr[2*i]);
        	}
        }
        else{

        	for(int i=1 ; i<=a ; i++){
        		swap(arr[n-2*i+2] ,arr[n-2*i+1]);
        	}
        }

        for(int i=1 ; i<=n ; i++){
        	cout<<arr[i]<<" ";
        }



    }
    return 0 ;
}
