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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int N = 4e5 + 7;
struct node_val{
	ll a, b;
};
struct Q{
	char ch;
	ll pos, len;
};

node_val t[4*N];
ll lazy[4*N];
ll arr[N];

void push(int node, int start, int end){

	if(lazy[node] == 0){
		return;
	}
	t[node] = {t[node].a + lazy[node], t[node].b + lazy[node]};
	
	if(start != end){

		lazy[node * 2] += lazy[node] ;
		lazy[node * 2 + 1] += lazy[node] ;

	}
	lazy[node] = 0;
}

node_val combine(node_val l_node, node_val r_node){
	node_val res = {max(l_node.a, r_node.a), min(l_node.b, r_node.b)};
	return res;
}

void build(int node, int start, int end){
	lazy[node] = 0;
	if(start == end){
		t[node] = {arr[start], arr[start]};
		return ;
	}
	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
void update(int node, int start, int end, int i, int j, int value){

	push(node, start, end);

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		lazy[node] = value;
		push(node, start, end);
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, i, j, value);
	update(node * 2 + 1, mid + 1, end, i, j, value);

	t[node] = combine(t[node * 2], t[(node * 2) + 1]);
}
node_val query(int node, int start, int end, int i, int j){

	push(node, start, end);

	if(start > j || end < i)
		return {0,0};

	if(i <= start && end <= j){
		return t[node];
	}
	int mid = (start + end) / 2;

	return combine(query(node * 2, start, mid, i, j),
				query(node * 2 + 1, mid + 1, end, i, j));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n;
    cin >> n;
    map<ll,ll>mp;

    vector<Q>queries;
    vector<ll>positions;
    Q val;
    for(int i = 0; i < n; i++){
    	cin >> val.ch >> val.len >> val.pos;
    	queries.push_back(val);
    	if(val.ch == '|')
    		positions.push_back(val.pos);
    }
    sort(positions.begin(), positions.end());
    int p = 1;
    mp[positions[0]] = 1;

    for(int i = 1; i < positions.size(); i++){
    	if(mp.find(positions[i]) != mp.end())
    		continue;
    	if(positions[i] == positions[i - 1] + 1){
    		mp[positions[i]] = ++p;
    	}else{
    		arr[++p] = low;
    		mp[positions[i]] = ++p;
    	}
    }

    build(1, 1, p);








    if(c == '|'){
    		update(1, 1, n, pos, pos, len);
    		cout << "S"; 
    	}else{
    		node_val val = query(1, 1, n, pos, pos + len - 1);

    		debug(val.a ,val.b);

    		if(val.a == val.b){
    			cout << "S" ;
    			update(1, 1, n, pos, pos + len - 1, 1);
    		}else{
    			cout << "U";
    		}

    	}

    cout << endl;
    return 0 ;

    runtime();

}
