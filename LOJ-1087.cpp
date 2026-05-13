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
const int N = 150007;

int t[4*N];
int arr[N];

void build(int node, int start, int end){

	if(start == end){
		t[node] = (arr[start] != 0);
		return ;
	}

	int mid = (start + end) / 2;

	build(node * 2, start, mid);
	build(node * 2 + 1, mid + 1, end);

	t[node] = (t[node * 2] + t[(node * 2) + 1]);
}
void update(int node, int start, int end, int i, int j, int value){

	if(start > j || end < i)
		return;

	if(start >= i && j >= end){
		t[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	update(node * 2, start, mid, i, j, value);
	update(node * 2 + 1, mid + 1, end, i, j, value);

	t[node] = (t[node * 2] + t[(node * 2) + 1]);
}
int query(int node, int start, int end, int i, int j){

	if(start > j || end < i)
		return 0;

	if(i <= start && end <= j){
		return t[node];
	}

	int mid = (start + end) / 2;

	return (query(node * 2, start, mid, i, j) +
				query(node * 2 + 1, mid + 1, end, i, j));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases, cs =1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

    	cin.ignore();
    	int n, q;

    	cin >> n >> q;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}

    	build(1, 1, N - 2);

    	int l = n;	


    	cout << "Case " << cs++ << ":" << endl;

    	while(q--){
    		char ch ; cin >> ch;
    		if(ch == 'c'){
    			int pos ; cin >> pos;

    			int hi = l, lo = 1, ans = -1 ;

    			while(hi >= lo){

    				int mid = ( hi + lo) / 2;
    				int r = query(1, 1, N - 2, 1, mid);

    				if(pos <= r){
    					hi = mid - 1;

    					if(pos == r){
    						ans = mid;
    					}
    				}else{
    					lo = mid + 1;
    				}
    				debug(q, r, mid, ans);
    			}
    			
    			if(ans != -1){
    				cout << arr[ans] << endl;
    				update(1, 1, N - 2, ans, ans, 0);
    			}else{
    				cout << "none" << endl;
    			}
    		}else{

    			int val; cin  >> val;
    			arr[++l] = val;


    			update(1, 1, N - 2, l, l, 1);
    			debug(query(1,1, N - 2, 10, l), l);
    		}
    	}
    }
    return 0 ;

    runtime();

}
