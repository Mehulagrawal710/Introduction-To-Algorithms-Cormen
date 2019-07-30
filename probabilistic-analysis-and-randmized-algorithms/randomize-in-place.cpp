#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randomize(int* a, int n){
	srand(time(0));
	int temp = 0, j =0;
	for(int i=0; i<n; i++){
		temp = a[i];
		j = rand()%(n-i)+i;
		a[i] = a[j];
		a[j] = temp;
	}
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Original Array: ";
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	randomize(a, n);
	cout << "Randomize: ";
	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}