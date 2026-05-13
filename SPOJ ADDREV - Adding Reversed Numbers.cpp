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
        string a, b;

        int s1 = 0, s2 = 0 , ans = 0;

        cin >> a >> b;

        ll mul = 1;

        for(int i = 0; i < a.size(); i++){

        	s1 += ((a[i] - '0') * (mul));
        	mul *= 10;
        }

        mul = 1;

        for(int i = 0; i < b.size(); i++){

        	s2 += ((b[i] - '0') * (mul));
        	mul *= 10;
        }

        ans = s1 + s2;


        bool zero = 0;

        while( ans > 0 ){

        	if(ans % 10 != 0)
        		zero = 1;

        	if(zero)
        		cout << ans % 10 ;
        	
        	ans = ans /10;
        }


        cout << endl;




    }
    return 0 ;
        
}
