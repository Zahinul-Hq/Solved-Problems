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


//vector<int> ans[101];

vector<int>digits(ll val){

	vector<int>digs;

	while(val > 0){

		digs.push_back( val % 10);
		val /= 10;

	}
	reverse(digs.begin(), digs.end());

	return digs;

}
void pre_calc(){


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

     

        vector<ll>temp(1,1) ,ans;


        for(ll i = 1; i <= n; i++){

        	ll val = 0;
        	for(int j = temp.size() - 1; j >= 0; j--){
        		
	        	int x = (temp[j] * i) + val;
	        	ans.push_back( x % 10);
	        	val = x / 10;

        	}

        	while(val > 0){
        		ans.push_back(val % 10);
        		val /= 10;
        	}
        	reverse(ans.begin(), ans.end());
        	temp = ans;
        	ans.clear();
        }

        for(auto i : temp){
        	cout << i ;
        }

        cout << endl;


        


    }
    return 0 ;
}
