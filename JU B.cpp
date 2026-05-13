#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}
int LongSubarrSeq(int arr1[], int arr2[], int M, int N)
{

	// to store final result
	int maxL = 0;

	vector<int> DP(N + 1, 0);

	for (int i = 1; i <= M; i++) {
		int prev = 0;
		for (int j = 1; j <= N; j++) {
			// Store current DP[j] value
			int temp = DP[j];
			if (arr1[i - 1] == arr2[j - 1]) {
				DP[j] = 1 + prev;
				maxL = max(maxL, DP[j]);
			}
			else {
				DP[j] = DP[j - 1];
			}

			prev = temp;
		}
	}

	return maxL;
}

int main()
{

	inout() ;
	int t;

	cin>>t ;

	while(t--){


        int n ;
        cin>>n ;
        int arr1[n] , arr2[n] ;

        for(int i=0 ; i<n; i++){
            cin>>arr1[i];
        }
        for(int i=0 ; i<n; i++){
            cin>>arr2[i];
        }

        cout <<LongSubarrSeq(arr1, arr2, n, n)<<endl;
	}
	return 0;
}