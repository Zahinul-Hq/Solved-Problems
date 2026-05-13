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

    
        ll a, b, c,  C;

        cin >> a >> b >> C;

        c = __builtin_popcount(C);

        if((a + b + c) % 2 != 0 || a > b + c || b > a + c || c > a + b ){
        	cout << -1 << endl;
        	return 0;
        }


        int n00 = 60 - ((a + b + c) / 2);
        int n01 = ((a + b - c) / 2);
        int n10 = ((a - b + c) / 2);
        int n11 = ((b + c -  a) / 2);

        vector<int> x(61,0), y(61,0);

        cout << n00 << " " << n11 ;

        int i = 60;

        while(n00--){
        	i--;
        }
        while(n01--){
        	x[i] = 0, y[i] = 1;
        	i--;
        }
        while(n10--){
        	x[i] = 1, y[i] = 0;
        	i--;
        	
        }
        while(n11--){
        	x[i] = 1 , y[i] = 1;
        	i--;
        }

        ll val1 = 0, val2 = 0;

        for(int j = 0; j <= 60; j++){

        	cout << x[i] << " " << y[i] << endl;

        	if(x[i] == 1)
        		val1 += (1 << j);
        	if(y[i] == 1)
        		val2 += (1 << j);

        	cout <<( 1 << j )<< endl;
        }

        cout << val1 << " " << val2 << endl;


    
    return 0 ;
}
