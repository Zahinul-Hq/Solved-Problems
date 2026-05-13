/*
ID: zahinul1
PROG: ride
LANG: C++14
*/

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    string s, ss;

    cin >> s >> ss;



    int val1 = 1, val2 = 1;


    for(int i = 0; i < s.size(); i++){
    	val1 *= ((s[i] - 'A') + 1);
    	val1 %= 47;

    }
    for(int i = 0; i < ss.size(); i++){
    	val2 *= ((ss[i] - 'A') + 1 );
    	val2 %= 47;
    }


    if(val1 == val2){
    	cout << "GO" << endl;
    }else{
    	cout << "STAY" << endl;
    }
    return 0 ;
}
