#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
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
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n;
        cin >> n;
        vector<int>x(n), t(n);
        for(int i = 0; i < n; i++){
        	cin >> x[i];
        	x[i] *= 2;

        }
        for(int i = 0; i < n; i++){
        	cin >> t[i];
        	t[i] *= 2;
        }

        int lo = -1, hi = 1e9 + 13, tm = 0;

        while(hi - lo > 1){
        	int T = (hi + lo) / 2;

        	int mxl = 0, mnr = INT_MAX;

        	for(int i = 0; i < n; i++){
        		if(t[i] > T){
        			mxl = INT_MAX;
        			mnr = 0;
        			break;
        		}else{
        			mxl = max(mxl, x[i] - (T - t[i]));
        			mnr = min(mnr, x[i] + (T - t[i]));
        		}
        	}

        	if(mxl <= mnr){
        		hi = T ;
        	}else{
        		lo = T ;
        	}
        }


        int mxl = 0, mnr = INT_MAX;
        for(int i = 0; i < n; i++){

        	mxl = max(mxl, x[i] - (hi - t[i]));
        	mnr = min(mnr, x[i] + (hi - t[i]));
        }

        cout << (mxl / 2) ;
        if(mxl % 2 != 0)
        	cout << ".5";
        cout << endl;
 

    }
    return 0 ;
}
