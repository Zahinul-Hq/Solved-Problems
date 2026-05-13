#include<bits/stdc++.h>
using namespace std ;

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

map<int,int>mp ;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}


void printArray(int array[], int size) {

  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}



int partition(int array[], int low, int high) {

    int pivot = 0;

    int indx =low ;

    int cnt = 0 ;

    for(int i=low; i<=high ; i++){

            if(mp[array[i]]>=cnt){
                pivot=array[i] ;
                indx=i ; 
                cnt = mp[array[i]];
            }
    }


  int i = (low - 1);

  for (int j = low; j <=high; j++) {
    if (array[j] <pivot) {

      i++;

      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main() {


	inout() ;


  int n ;

  cin>>n ;

  int data[n] ;

  for(int i=0 ; i<n ; i++){
    cin>>data[i] ;

    mp[data[i]]++ ;
  }


  quickSort(data, 0, n-1 );

  printArray(data, n);
}
