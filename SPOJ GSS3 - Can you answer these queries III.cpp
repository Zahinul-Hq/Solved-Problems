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
struct nd{
	ll sum , pref, suff, mx_val;
};
int arr[N];
nd t[4 * N];




nd merge(nd l , nd r){

	nd p;

	p.sum = l.sum + r.sum;

	p.pref = max(l.pref, l.sum + r.pref);
	p.suff = max(r.suff, r.sum + l.suff);

	p.mx_val = max({l.mx_val, r.mx_val, l.suff + r.pref});

	return p;
}


void build(int node ,int start, int end){

	if(start == end){
		t[node].sum = t[node].suff = t[node].pref = t[node].mx_val = arr[start];
		return;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node  * 2 + 1, mid + 1, end);

	t[node] = merge(t[node * 2], t[node * 2 + 1]);

	
}
void update(int node, int start, int end, int l, int r, int val){

	

	if(start > r || end < l)
		return ;

	if(start >= l && end <= r){

		t[node].sum = t[node].suff = t[node].pref = t[node].mx_val = val;
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, l, r, val);
	update(node  * 2 + 1, mid + 1, end, l, r, val);

	t[node] = merge(t[node * 2], t[node * 2 + 1]);

}
nd query(int node, int start, int end, int l ,int r){



	if(start > r || end < l)
		return  {-100000,-100000,-100000,-100000};

	if(start >= l && end <= r){

		return t[node];
	}

	int mid = (start + end) / 2;

	return merge(query(node * 2, start, mid, l, r) , query(node * 2 + 1, mid + 1, end, l, r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

        int n, q;

        cin >> n ;

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }

        cin >> q;


        build(1, 1, n);

        int x , lf , rt, v;

        while(q--){

        	cin >> x ;

        	if(x == 0){
        		cin >> lf >>  v;
        		update(1, 1, n, lf, lf, v);

         	}else if (x == 1){

        		cin >> lf >> rt ;

        		nd answer = query(1, 1, n, lf, rt);

        		cout << answer.mx_val << endl;	
        	}
        	
        	//cout << tp << endl;
        }
    
    return 0 ;
}
