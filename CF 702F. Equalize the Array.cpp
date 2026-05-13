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

const int N  = 2e5 + 7;
vector<int> arr,pref(N, 0);
int n;
int total(int val){

	int sum = 0;
	int pos = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

	//cout << val << " " << pos << " " << arr[pos] << endl;

	sum = (pref[n - 1] - pref[pos ]) - (val *(n - pos));
	sum += (pref[pos ] - pref[0]);

	return sum;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t , x;
    cin >> t ;
    
    while (t--)
    {
    	int mx = -1, sum = 0, ans = N;
        cin >> n;
        map<int,int>mp;

        for(int i = 0; i < n; i++){
        	cin >> x;
        	mp[x]++;
        	mx = max(mx, mp[x]);
        }

        arr.push_back(0);
        for(auto i : mp){
        	arr.push_back(i.S);
        }

        sort(arr.begin(), arr.end());
        pref[0] = arr[0];
        //cout << 0 << " ";
        n = arr.size() ;
        for(int i = 1; i < n; i++){
        	pref[i] = pref[i - 1] + arr[i];
        	//cout << arr[i] <<" ";
        }

       // cout << endl;

        for(int i = mx; i >= 1; i--){
        	ans = min (ans, total(i));
        }

        cout << ans << endl;

        arr.clear();

    }
    return 0 ;
}
