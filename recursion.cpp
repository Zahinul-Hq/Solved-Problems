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

const int N = 15 ;

ll arr[N][N] ,r, c ;
ll sum(ll i , ll j ){

	if(i==r-1 && j==c-1)
		return arr[i][j] ;



	if(i==r-1){
		return sum(i,j+1)+arr[i][j];
	}else if(j==c-1){
		return sum(i+1 , j )+arr[i][j];
	}else{
		return max(sum(i+1 , j)+arr[i][j],sum(i,j+1)+arr[i][j]);
	}
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;


	cin>>r>>c ;


	for(int i=0 ; i<r ;i++){
		for(int j=0 ; j<c ; j++){
			cin>>arr[i][j];
		}
	}


	cout<<sum(0,0)<<endl;

    
    


    return 0 ;
}
