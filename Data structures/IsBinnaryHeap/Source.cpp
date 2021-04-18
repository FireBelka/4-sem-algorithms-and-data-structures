#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
bool isHeap=true;
int masSize;
int * readFile() {
	ifstream in("input.txt");
	in >> masSize;
	int* buf = new int[masSize];
	for (int i = 0; i < masSize; i++) {
		in >> buf[i];
	}
	in.close();
	return buf;
}
void writeFile() {
	ofstream out("output.txt");
	if (isHeap) {
		out << "Yes";
	}
	else {
		out << "No";
	}
	out.close();
	return;
}
void checkMas(int* mas,int pos) {
	if (pos >= masSize) {
		return;
	}
	if (2 * pos + 1 < masSize) {
		if (mas[pos] > mas[2 * pos + 1]) {
			isHeap = false;
			return;
		}
		else {
			checkMas(mas, 2 * pos + 1);
		}
	}
	if (2 * pos + 2 < masSize) {
		if (mas[pos] > mas[2 * pos + 2]) {
			isHeap = false;
			return;
		}
		else {
			checkMas(mas, 2 * pos + 2);
		}
	}

	return;
}
int main(void) {
	int* mas = readFile();
	checkMas(mas, 0);
	writeFile();
	return 0;
}