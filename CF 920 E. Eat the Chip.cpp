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
        int h, w, xA, yA, xB, yB;
        cin >> h >> w >> xA >> yA >> xB >> yB;

        if(abs(yA - yB) > xB - xA){
        	cout << "Draw" << endl;
        }else if( (xB - xA) % 2){
        	int step = (xB - xA + 1) / 2;
        	if(abs(yA - yB) <= 1 || (yA < yB ? w - yA : yA - 1) <= step){
        		cout << "Alice" << endl;
        	}else{
        		cout << "Draw" << endl;
        	}
        }else{
        	int step = (xB - xA) / 2;
        	if(yA == yB|| (yA < yB ? yB - 1 : w - yB) <= step){
        		cout << "Bob" << endl;
        	}else{
        		cout << "Draw" << endl;
        	}
        }
    }
    return 0 ;
}
