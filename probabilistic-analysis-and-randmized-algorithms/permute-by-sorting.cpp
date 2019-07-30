#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

void permuteArray(int* a, int n){
	srand(time(0));
	pair<int, int> p[n];
	for(int i=0; i<n; i++){
		p[i].first = a[i];
		p[i].second = rand()%(n*n*n)+1;
	}
	sort(p, p+n, cmp);
	for(int i=0; i<n; i++){
		a[i] = p[i].first;
	}
}

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(a)/sizeof(a[0]);
	cout << "Original Array: ";
	for(int i=0; i<size; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	permuteArray(a, size);
	cout << "Random Permute: ";
	for(int i=0; i<size; i++){
		cout << a[i] << " ";
	}
	return 0;
}