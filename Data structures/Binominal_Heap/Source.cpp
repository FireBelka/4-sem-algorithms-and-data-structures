#include<iostream>
#include<vector>
#include<fstream>
#include <bitset>
#include<string>
using namespace std;
long long readFile() {
	ifstream in("input.txt");
	long long a;
	in >>a;
	in.close();
	return a;
}
void writeFile(string text) {
	ofstream out("output.txt");
	out << text;
	out.close();
	return;
}
int main(void) {
	long long a = readFile();
	bitset<64> b = a;
	string text = "";
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == 1) {
			text += to_string(i)+"\n";
		}
	}
	writeFile(text);
	return 0;
}