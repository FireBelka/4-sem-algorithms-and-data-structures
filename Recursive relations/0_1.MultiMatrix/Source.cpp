#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
int sizeOfBuf;
pair<int,int>* readFile() {
	ifstream in("input.txt");

	int count;
	in >> count;
	sizeOfBuf = count;
	pair<int,int>* buf = new pair<int,int>[count];
	int a;
	for (int i = 0; i < count; i++) {
		in >> a;
		buf[i].first = a;
		in >> a;
		buf[i].second = a;
	}
	in.close();
	return buf;
}
void writeFile(int num) {
	ofstream out("output.txt");
	out << num;
	out.close();
	return;
}
int funkt(vector<int> kuvsh, int pos, int sizeOfKuvsh) {

	if (pos == sizeOfKuvsh - 2 || pos >= sizeOfKuvsh) {
		return 0;
	}
	int numb = kuvsh[pos];
	if (pos == sizeOfKuvsh - 1) {
		return kuvsh[pos];
	}
	int a = funkt(kuvsh, pos + 2, sizeOfKuvsh);
	int b = funkt(kuvsh, pos + 3, sizeOfKuvsh);
	if (a > b) {
		numb += a;
	}
	else {
		numb += b;
	}
	return numb;
}
int main(void) {
	pair<int,int>* matrix;
	matrix = readFile();
	int sizeOfMatrixBuf = sizeOfBuf;
	int numb = funkt(matrix, 0, sizeOfMatrixBuf);
	writeFile(numb);
	return 0;
}