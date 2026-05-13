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
        string s;
        cin >> n >> s;

        int sq = sqrt(n);

        s = "#" + s;

        if((sq * sq) != n){
        	cout << "No" << endl;
        	continue;
        }
        int r = 1, c = 0;
        bool ok = 1;
        char arr[sq + 1][sq + 1];

        for(int i = 1; i <= n; i++){
        	if(c == sq){
        		r++;
        		c %= sq;
        	}
        	//cout << r << " " << c << endl;
        	arr[r][c++] = s[i];

        }
        for(int i = 1; i <= sq; i++){
        	for(int j = 0; j < sq; j++){
        		if(i == 1 || i == sq || j == 0 || j == sq - 1){
        			if(arr[i][j] != '1')
        				ok = 0;
        		}else{
        			if(arr[i][j] == '1')
        				ok = 0;
        		}

        	}
        }

        if(ok ){
        	cout << "Yes" << endl;
        }else{
        	cout << "No" << endl;
        }
    }
    return 0 ;
}
