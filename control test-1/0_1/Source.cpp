#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
int** mas;
int n;
int m;
void readFile(string path) {
	ifstream in(path);
	in >> n;
	in >> m;
	int tmp;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
		for (int j = 0; j < m; j++) {	
			in >> tmp;
			mas[i][j] = tmp;
		}
	}
	
	in.close();
	return ;
}
void writeFile(string path, string text) {
	ofstream out;
	out.open(path);
	out << text;
	out.close();
}
void printMas() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << 1;
			cout << mas[i][j] + "_";
		}
		cout << endl;
	}
}
int main(void) {
	readFile("input.txt");
	printMas();




	return 0;
}