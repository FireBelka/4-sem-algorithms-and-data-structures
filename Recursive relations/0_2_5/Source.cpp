#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<vector>
#include <map>

using namespace std;

long long pow1(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		return pow1(((a % 1000000007) * (a%1000000007)) % 1000000007, b / 2) % 1000000007;
	}
	return ((a % 1000000007) * (pow1(a % 1000000007, b - 1) % 1000000007)) % 1000000007;
}
int main(void) {
	int k, n;
	scanf("%d", &n);
	scanf("%d", &k);
	if (n - k > k) {
		k = n - k;
	}
	long long chislit = 1;
	long long znam =1;
	for (int i = k +1; i <= n; i++) {
		chislit = (chislit * i ) % 1000000007;
	}
	for (int i = 1; i <=n-k; i++) {
		znam = (znam  * i ) % 1000000007;
	}
	chislit= (chislit % 1000000007 * pow1(znam, 1000000005) % 1000000007) % 1000000007;
	
	cout << chislit;
	return 0;
}