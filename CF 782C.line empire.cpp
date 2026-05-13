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
        ll n , a, b;

        cin >> n >> a >> b;

        vector<ll>x(n + 1, 0);

        for(int i = 1; i <= n; i++){
        	cin >> x[i];
        }

        ll capital = 0, total_cost = b * x[1];

        for(int i = 2; i <= n; i++){


        	if((n - i + 1) * b >= a){

                total_cost += (a * (x[i - 1] - capital));
        		capital = x[i - 1];

                

        		
        	}


        	total_cost += (b * (x[i] - capital));
        }


        cout << total_cost << endl;
    }
    return 0 ;
}
