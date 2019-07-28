#include<iostream>
using namespace std;

int matrixMultiplication(int a[2][2], int ar1, int ar2, int ac1, int ac2, int b[2][2], int br1, int br2, int bc1, int bc2){
	if(ar1 == ar2){return a[ar1][ac1] * b[br1][bc1];}
	else{
		int r_mid = (ar1+ar2)/2;
		int c_mid = (ac1+ac2)/2;
		int c11 = matrixMultiplication(a, ar1, r_mid, ac1, c_mid, b, br1, r_mid, bc1, c_mid) + matrixMultiplication(a, ar1, r_mid, c_mid+1, ac2, b, r_mid+1, br2, bc1, c_mid);
		int c12 = matrixMultiplication(a, ar1, r_mid, ac1, c_mid, b, br1, r_mid, c_mid+1, bc2) + matrixMultiplication(a, ar1, r_mid, c_mid+1, ac2, b, r_mid+1, br2, c_mid+1, bc2);
		int c21 = matrixMultiplication(a, r_mid+1, ar2, ac1, c_mid, b, br1, r_mid, bc1, c_mid) + matrixMultiplication(a, r_mid+1, ar2, c_mid+1, ac2, b, r_mid+1, br2, bc1, c_mid);
		int c22 = matrixMultiplication(a, r_mid+1, ar2, ac1, c_mid, b, br1, r_mid, c_mid+1, bc2) + matrixMultiplication(a, r_mid+1, ar2, c_mid+1, ac2, b, r_mid+1, br2, c_mid+1, bc2);
		return c11*c22 - c12*c21;
	}
}

int main(){
	int a[2][2]= {1, 2, 3, 4};
	int b[2][2]= {1, 2, 3, 4};
	int n = sizeof(a)/sizeof(a[0]);
	int ans = matrixMultiplication(a, 0, n-1, 0, n-1, b, 0, n-1, 0, n-1);
	cout << ans << endl;
	return 0;
}