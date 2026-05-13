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
const int N = 1e5;
vector<bool>is_prime(N, true);
vector<int>prime;
vector<int>dis(N,0);

int first, last;
vector<int>graph[N];


void seive(){

	is_prime[1] = false ;

	for(int i = 2; i*i <= N; i++)
		if(is_prime[i])
			for(int j = 2 * i; j <= N; j += i)
				is_prime[j] = false;

	for(int i = 1000; i <= 9999; i++)
    	if(is_prime[i])
    		prime.push_back(i); 
}

bool check(int s_val, int d_val){

	int diff = 0;

	while(s_val > 0){
		if(s_val % 10 != d_val % 10){
			diff++;
		}
		s_val /= 10 , d_val /= 10;
	}

	return diff == 1;
}
void build_graph(){

	for(int i = 0; i < prime.size(); i++){
        for(int j = 0; j < prime.size(); j++){
        	if(check(prime[i], prime[j])){
        		graph[prime[i]].push_back(prime[j]);
        		graph[prime[j]].push_back(prime[i]);
        	}
        }
    }
}


void bfs(){

	vector<bool>used(N,0);
	queue<int>Q;

	Q.push(first);
	used[first] = true;

	while(!Q.empty()){

		int v = Q.front();
		Q.pop();

		for(auto u : graph[v]){

			if(!used[u]){
				Q.push(u);
				used[u] = true;
				dis[u] = dis[v] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;

    seive();
    build_graph();

    while (t--)
    {
        cin >> first >> last;

        if(first == last){
        	cout << 0 << endl;
        	continue;
        }

        dis.assign(N,0);

        bfs();

        if(dis[last] == 0){
        	cout << "Impossible" << endl;
        }else{
        	cout << dis[last] << endl;
        }

    }
    return 0 ;
}
