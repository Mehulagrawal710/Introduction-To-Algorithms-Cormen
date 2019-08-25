#include<iostream>
using namespace std;

/*THE maxHeapify PROCEDURE IS USED TO MAINTAIN THE PROPERTY OF MAX HEAP IN THE ARRAY.
THE METHOD STARTS WITH NODE i AND RECURSIVELY CHECKS FOR THE CHILDREN NODES THAT IF
THEY SATISFY THE MAX HEAP PROPERTY OR NOT, UP TILL THE RECURSIVE CONDITION FAILS OR UP TILL
THE i COMES TO ONE OF THE LEAF NODES.
n - TOTAL SIZE OF HEAP
Time Complexity of maxHeapify() - O(log n)
*/
void maxHeapify(int A[], int i, int n){
	int l = i*2;
	int r = i*2 + 1;
	int largest = i;
	if(l<=n && A[l-1] > A[i-1]) largest = l;
	if(r<=n && A[r-1] > A[largest-1]) largest = r;
	if(largest != i){
		int temp = A[i-1];
		A[i-1] = A[largest-1];
		A[largest-1] = temp;
		maxHeapify(A, largest, n);
	}	
}

int main(){
	int a[] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
	int n = sizeof(a)/sizeof(*a);
	maxHeapify(a, 3, n);
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}