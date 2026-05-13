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
        int n, q, mn = INT_MAX;

        cin >> n >> q;

        vector<int> a(n, 0), b(q, 0);

        for(int i = 0; i < n; i++){
        	cin >> a[i];

        	mn = min (mn , a[i]);

        }
        for(int i = 0; i < q; i++){
        	cin >> b[i];

        	if(b[i] >= mn)
        		b[i] = mn - 1;
        }


        for(int i = 0; i < q; i++){

        	cout << b[i] << " ";

        }

        cout << endl;
    }
    return 0 ;
}
