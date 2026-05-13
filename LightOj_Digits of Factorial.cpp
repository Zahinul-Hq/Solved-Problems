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

const int N =1e6+7 ;
vector<double>base(N,0);
void precalc(){

	for(int i = 1; i <= N; i++){
		base[i] = base[i-1]+log10(i) ;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	precalc() ;

    int t , c=1;
    cin>>t ;

    while (t--)
    {

    	int n, b;

    	cin >> n >> b;

    	int ans = (int)((base[n])/(log10(b)))+1 ;

    	cout<<"Case "<<c++<<": "<<ans<<endl;
        
    }
    return 0 ;
}
