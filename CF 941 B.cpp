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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, m; 

        cin >> n >> m;

        string grid[n];

        for(int i = 0; i < n; i++){
        	
        	cin >> grid[i];
        }

        bool allb = true ,allw = true;

        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){

        		if(grid[i][j] != 'W')
        			allw = false;
        		if(grid[i][j] != 'B')
        			allb = false;
        	}
        }

        if(allb || allw){

        	cout << "Yes" << endl;
        	continue;
        }

        vector<bool> white(4, false);
        vector<bool> black(4, false);

        for(int i = 0; i < m; i++){

        	if(grid[0][i] == 'W'){
        		white[0] = true;
        	}
        	if(grid[0][i] == 'B'){
        		black[0] = true;
        	}
        }

        for(int i = 0; i < m; i++){

        	if(grid[n - 1][i] == 'W'){
        		white[1] = true;
        	}
        	if(grid[n - 1][i] == 'B'){
        		black[1] = true;
        	}
        }

        for(int i = 0; i < n; i++){

        	if(grid[i][0] == 'W'){
        		white[2] = true;
        	}
        	if(grid[i][0] == 'B'){
        		black[2] = true;
        	}
        }


        for(int i = 0; i < n; i++){

        	if(grid[i][m - 1] == 'W'){
        		white[3] = true;
        	}
        	if(grid[i][m - 1] == 'B'){
        		black[3] = true;
        	}
        }

        int sumw = 0, sumb = 0;
 	
 		for(int i = 0; i < 4; i++){

 			if(white[i]){
 				sumw++;
 			}

 			if(black[i])
 				sumb++;


 		}

 		if(sumw == 4 || sumb == 4)
        	cout << "Yes" << endl;
        else
        	cout << "No" << endl;
    }
    return 0 ;
}
