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
//#define endl  "\n"
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
const int N = 1005;
bool used[N];
set<pair<int,int>>ans;
int query(int l, int r){
	int mid;
	cout << "? " << l << " " << r << endl;
	//cout.flush();
	cin >> mid;
	return mid;
}
void solve(int a, int b){
	if(used[a] && used[b])
		return;
	int q = query(a, b);
	if(a == q){
		used[a] = used[b] = 1;
		ans.insert({a, b});
		return ;
	}
	solve(a, q);
	solve(q, b);
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
        for(int i = 0; i <= n; i++){
        	used[i] = 0;
        }
        ans.clear();
        for(int i = 1; i <= n; i++){
        	if(used[i])
        		continue;
        	for(int j = 1; j <= n; j++){
        		if(used[j] || i == j)
        			continue;
        		solve(i, j);
        	}
        }

        cout << "! ";

        for(auto i : ans){
        	cout << i.first << " " << i.second << " ";
        } 
        cout << endl;
    }
    return 0 ;
}
