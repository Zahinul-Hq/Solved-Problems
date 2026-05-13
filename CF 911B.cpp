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
        int a , b , c;

        cin>>a>>b>>c ;

        vector<int> mark(3,0) ;

        if((a+b)%2==0){
        	mark[2]=1;
        }
        if((c+b)%2==0){
        	mark[0]=1;
        }
        if((a+c)%2==0){
        	mark[1]=1;
        }

        for(int i=0 ; i<3 ;i++){
        	cout<<mark[i]<<" ";
        }

        cout<<endl;
    }
    return 0 ;
}
