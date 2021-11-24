#include<iostream>
#include<fstream>
#include <set>
#include<string>
using namespace std;
int n = 0;
void writeFile(int* mas) {
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		out << mas[i];
		out << " ";
	}
	out.close();
	return;
}

int main(void) {
	ifstream in("input.txt");
	int  a, b;
	in >> n;

	int* mas = new int[n];
	for (int i = 0; i < n; i++) {	
			mas[i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		in >> a;
		in >> b;
		b--;
		mas[b] = a ;
	}
	in.close();
	writeFile(mas);

	return 0;
}