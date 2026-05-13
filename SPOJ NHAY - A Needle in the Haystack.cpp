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

vector<int> prefix_function(string s){

	int n = s.size();
	vector<int> pi(n);

	for(int i = 1; i < n; i++){
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j] )
			j = pi[j - 1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;


    int n;

    while (cin >> n)
    {
        

        string f, s;

        cin >> f >> s;



        vector<int> pos;

        vector<int> res = prefix_function(f);

        int j = 0, i = 0 ;

        while(i < s.size()){

        	if(s[i] == f[j]){
        		i++;
        		j++;
        	}else if(j != 0){
        		j = res[j - 1];
        	}else
        		i++;

        	if(j == n){
        		pos.push_back(i - j);
        		j = res[j - 1];
        	}

        }

        if(pos.size() == 0){

        	cout << endl << endl;

        	continue;
        }


        for(auto i : pos){
        	cout << i << endl;
        }


    }
    return 0 ;
}
