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

    ll n, g = 0;
    cin >> n;
    vector<ll>arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        g = __gcd(arr[i], g);
    }
    map<ll,ll>cnt;
    priority_queue<ll ,vector<ll>,greater<ll>>pq;

    for(int i = 1; i <= n; i++){
        arr[i] /= g;
        while(arr[i] % 2 == 0){
            cnt[i]++;
            arr[i] /= 2;
        }

        pq.push(cnt[i]);
    }

    while(pq.size() != 1){

        ll c1 = pq.top();
        pq.pop();
        ll c2 = pq.top();

        pq.pop();
        pq.push( min(c1,c2)+ 1);

    }

    cout << (1LL <<pq.top()) * g << endl;

    return 0 ;

}
