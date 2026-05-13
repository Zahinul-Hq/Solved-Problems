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
void print(int i , int n, int t){

	cout << t << " " << i << " ";

        for(int k = 1; k <= n; k++)
        	cout << k << " ";

    cout << endl;

	
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
        int n; 

        cin >> n;

        ll sum = 0;

        for(ll i = 1; i <= n; i++){

        	sum += ((2*i - 1) * i);

        }

        cout << sum << " " << 2*n << endl;


        for(int i = 1, j = n; i <= n; i++, j--){

        	print(j, n, 1);
        	print(j, n, 2);
        }

    }
    return 0 ;
}
