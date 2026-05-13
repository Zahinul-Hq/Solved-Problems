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

    
        int n;
        cin >> n;
        int a[n + 1], b[n + 1], pos[n + 1];
        for(int i = 1; i <= n; i++){
        	cin >> a[i];
        	pos[a[i]] = i;
        }
        map<int,int> occ ;
        int ans = 0;
        for(int i = 1; i <= n; i++){
        	cin >> b[i];

        	int curr = pos[b[i]] - i;
        	if(curr < 0)
        		curr += n;
        	occ[curr]++;
        }
        for(auto i : occ){
        	ans = max(ans, i.S);
        }
    	cout << ans << endl;


    return 0 ;
}
