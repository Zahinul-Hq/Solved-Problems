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
        int n, k, d;
        cin >> n >> k >> d;

        vector<int>a(n + 1),b(k + 1);
        int cnt = 0;
        for(int i = 1; i <= n; i++){
        	cin >> a[i];
        	cnt += (a[i] == i);
        }
        int mx = cnt + ((d - 1) / 2), li = 1;
        for(int i = 0; i < k; i++){
        	cin >> b[i];
        }
        for(int i = 0; i < min(2 * n , d); i++){
        	cnt = 0;
        	for(int j = 1; j <= n; j++){
        		if(j <= b[i % k])
        			a[j]++;
        		cnt += (a[j] == j);

        	}
        	if(d - i - 2 >= 0)
        		mx = max(mx, cnt + ((d - i - 2) / 2));
        	
        }
        int left = d - li;

        cout << mx  << endl;


    }
    return 0 ;
}
