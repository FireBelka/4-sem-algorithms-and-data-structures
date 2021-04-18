#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
int sizeOfBuf;
int * readFile() {
	ifstream in("input.txt");
	
	int count;
	in >> count;
	sizeOfBuf = count;
	int* buf = new int[count];
	int a;
	for (int i = 0; i < count; i++) {
		in >> a;
		buf[i] = a;
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
int funkt(int* kuvsh, int pos,int sizeOfKuvsh) {

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
int funkt2(int* kuvsh) {
	for (int i = 0; i < sizeOfBuf; i++) {
		if (i == 0) {

		}
		else if (i == 1) {
			kuvsh[i] = -1;
		}
		else if (i == 2) {
			kuvsh[i] += kuvsh[0];
		}
		else {
			if (kuvsh[i - 2] > kuvsh[i - 3]) {
				kuvsh[i] += kuvsh[i - 2];
			}
			else {
				kuvsh[i] += kuvsh[i - 3];
			}
		}
	}
	return kuvsh[sizeOfBuf-1];
}
int main(void) {
	int * kuvsh;
	kuvsh = readFile();
	if (sizeOfBuf == 2 || sizeOfBuf==0) {
		writeFile(-1);
		return 0;
	}
	else if (sizeOfBuf == 1) {
		writeFile(kuvsh[0]);
		return 0;
	}
	int numb = funkt2(kuvsh);
	//int numb = funkt(kuvsh, 0, sizeOfBuf);
	writeFile(numb);
	return 0;
}