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
        string big_string, small_string;

        cin >> big_string >> small_string;

        if(big_string < small_string){
        	swap(big_string, small_string);
        }

        bool flag = 0;

        for(int i = 0; i < big_string.size(); i++){

        	if(flag  && big_string[i] > small_string[i] ){
        		swap(big_string[i], small_string[i]);

        	}
        	if(big_string[i] > small_string[i])
        		flag = 1;
        }


        cout << big_string << endl << small_string << endl;


    }
    return 0 ;
}
