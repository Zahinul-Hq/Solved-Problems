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
//int arr[N];
ll t[4 * N];
ll lazy[4 * N];

void push(int node, int start, int end){

	if(lazy[node] == 0)
		return;

	t[node] = t[node] + (lazy[node] *(end - start + 1));

	if(start != end){

		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
 	} 

 	lazy[node] = 0;
}

void build(int node ,int start, int end){

	lazy[node] = 0;

	if(start == end){
		t[node] = 0;
		return;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node  * 2 + 1, mid + 1, end);

	t[node] = t[node * 2] + t[node * 2 + 1];
}
void update(int node, int start, int end, int l, int r, int val){

	push(node, start, end);

	if(start > r || end < l)
		return ;

	if(start >= l && end <= r){

		lazy[node] += val;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, l, r, val);
	update(node  * 2 + 1, mid + 1, end, l, r, val);

	t[node] = t[node * 2] + t[node * 2 + 1];

}
ll query(int node, int start, int end, int l ,int r){

	push(node, start, end);

	if(start > r || end < l)
		return 0;

	if(start >= l && end <= r){

		return t[node];
	}

	int mid = (start + end) / 2;

	return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
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
        int n, q;

        cin >> n >> q;

        build(1, 1, n);

        int x , lf , rt, v;

        while(q--){

        	

        	cin >> x ;

        	

        	if(x == 0){
        		cin >> lf >> rt >> v;
        		update(1, 1, n, lf, rt, v);

         	}else if (x == 1){

        		cin >> lf >> rt ;

        		ll ans = query(1, 1, n, lf, rt);

        		cout << ans << endl;


        		
        	}
        	
        	//cout << tp << endl;
        }
    }
    return 0 ;
}
