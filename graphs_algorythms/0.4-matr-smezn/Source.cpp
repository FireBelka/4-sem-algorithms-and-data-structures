#include<iostream>
#include<fstream>
#include <set>
#include<string>
using namespace std;
int n=0;
void writeFile(int**mas) {
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << mas[i][j];
			out << " ";
		}
		out << "\n";
	}
	out.close();
	return;
}

int main(void) {
	ifstream in("input.txt");
	int  m, a, b;
	in >> n;
	in >> m;

	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
		for (int j = 0; j < n; j++) {
			mas[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		in >> a;
		a--;
		in >> b;
		b--;
		mas[a][b] = 1;
		mas[b][a] = 1;
	}
	in.close();
	writeFile(mas);

	return 0;
}