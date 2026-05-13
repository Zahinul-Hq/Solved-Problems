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

pair<int,int> check(char c){
	if(c == 'N')
		return {0, 1};
	if(c == 'S')
		return {0, -1};
	if(c == 'E')
		return {1, 0};
	if(c == 'W')
		return {-1, 0};

	return {0,0};

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n; 

        string s;

        cin >> n >> s;

        int x = 0, y = 0;

        for(int i = 0 ; i < n; i++){

        	pair<int,int> val = check(s[i]);
        	x += val.first;
        	y += val.second;

        }

        cout << x << " " << y << endl;

        /*if(abs(x) % 2 != 0 || abs(y) % 2 != 0)
        	cout << x << endl;
        else
        	cout << "ok" << endl;*/
    }
    return 0 ;
}
