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
const int N = 1e5 + 7;

ll t[4*N];
int arr[N];
int n;

void build(int node, int start, int end){


	if(start == end){
		t[node] = arr[start];
		return ;
	}

	int mid = (start + end) / 2;

	build(node*2, start, mid);
	build(node*2 + 1, mid + 1, end);

	t[node] = (t[node * 2] | t[node*2 + 1]) ;

}
ll query(int node, int start, int end, int i, int j){


	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return (query(node*2, start, mid, i, j) |
				query(node*2 + 1, mid + 1, end, i, j)) ;
}

bool possible(int k){

	ll ans = 0;
	bool st = 0;

	for(int i = 1 ; i <= n - k + 1; i++){
		ll val = query(1, 1, n, i, i + k -1);

		if(!st){
			ans = val;
			st = 1;
		}else{
			if(ans != val)
				return false;
		}
	}
	return true;
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


        cin >> n;

        for(int k = 1; k <= n; k++){
        	cin >> arr[k];
        }

        build(1, 1, n);

        int hi = n, lo = 1, mn_ans = n + 1;

        while(hi >= lo){
        	int mid = (hi + lo) / 2;

        	if(!possible(mid)){
        		lo = mid + 1;
        	}else{
        		hi = mid - 1;
        		mn_ans = min (mn_ans, mid);
        	}
        }

        cout << mn_ans << endl;
    }
    return 0 ;
}
