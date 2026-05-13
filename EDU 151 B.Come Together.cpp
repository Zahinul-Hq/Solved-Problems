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
        int ax,ay ;

        int x[2] ,y[2] ;

        cin>>ax>>ay ;
        cin>>x[0]>>y[0] ;
        cin>>x[1]>>y[1] ;

        sort(x ,x+2);
        sort(y , y+2) ;

        ll lf=0  ,rt=0;


        if(!(ax>=x[0] && ax<=x[1])){

        	lf= abs(ax - x[0]) ;
        }

        if(!(ay>=y[0] && ay<=y[1])){

        	rt= abs(ay - y[0]) ;
        }


        cout<<lf+rt+1<<endl;


        

    }
    return 0 ;
}
