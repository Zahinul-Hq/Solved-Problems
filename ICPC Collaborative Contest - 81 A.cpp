#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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

    string s;

    cin >> s;

    int year = (s[0] - '0')*1000 +  (s[1] - '0') * 100 +  (s[2] - '0') * 10 + (s[3] -'0');
    int month = (s[5] -'0') * 10 + (s[6] - '0');
    int day = (s[8] - '0') * 10 + (s[9] - '0');

    if(year > 2019){
    	cout << "TBD" << endl;
    	return 0;
    }else if(year == 2019){
    	if(month > 04){
    		cout << "TBD" << endl;
    		return 0;
    	}else if(month == 04){
    		if(day > 30){
    			cout << "TBD" << endl;
    			return 0;
    		}
    	}
    }

    cout << "Heisei" << endl;
    return 0 ;
}
