#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   1e9
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




#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bfs(ll A, ll B, ll K) {
    if (A == B) return 0;

    queue<pair<ll, ll>> q;
    unordered_set<ll> visited;

    q.push({A, 0});
    visited.insert(A);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == B) return steps;

        // Perform the +1 operation
        if (current + 1 <= B && visited.find(current + 1) == visited.end()) {
            q.push({current + 1, steps + 1});
            visited.insert(current + 1);
        }

        // Perform the *K operation
        if (current * K <= B && visited.find(current * K) == visited.end()) {
            q.push({current * K, steps + 1});
            visited.insert(current * K);
        }

        // Perform the /K operation, to handle the large multiplier cases
        if (current % K == 0 && visited.find(current / K) == visited.end()) {
            q.push({current / K, steps + 1});
            visited.insert(current / K);
        }
    }

    return -1;  // This line should not be reached with the given problem constraints
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
    	ll a, B, K;

        cin >> a >> B >> K;

        ll ans = bfs(a, B, K);

        cout << ans << endl;


    }
    return 0 ;
}
