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
double dis(int x1 , int y1 , int x2  , int y2){

	double ds = pow( x2-x1,2)+pow(y2-y1,2) ;

	return sqrt(ds) ;
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
        int Px ,Py ,Ax,Ay , Bx,By ;

        cin>>Px>>Py>>Ax>>Ay>>Bx>>By ;

        double disAo = dis(0,0,Ax,Ay);
        double disAp = dis(Px,Py ,Ax,Ay);
        double disBo = dis(0,0,Bx,By);
        double disBp = dis(Px,Py,Bx,By);

        if(disAo<=disBo && disAp<=disBp){
        	cout<<fixed<<setprecision(7)<<max(disAo ,disAp)<<endl;
        	continue ;
        }

        if(disAo>=disBo && disAp>=disBp){
        	cout<<fixed<<setprecision(7)<<max(disBo ,disBp)<<endl;
        	continue ;
        }

        double div = dis(Ax,Ay,Bx,By) ;

        div = div/2.0 ;

        double mxo = min(disAo ,disBo);
        double mxp = min(disAp, disBp) ;

        cout<<fixed<<setprecision(7)<<max(max(mxo,mxp),div)<<endl;

    }
    return 0 ;
}
