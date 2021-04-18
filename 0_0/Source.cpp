#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
vector<double> readFile(string path) {
	vector<double> buf;
	string line;
	ifstream in(path);
	while (getline(in,line)) {
		buf.push_back(stod(line));
	}
	in.close();
	return buf;
}
void writeFile(string path, string text) {
	ofstream out;
	out.open(path);
	out << text;
	out.close();
}
int main(void) {
	vector<double> buf = readFile("input.txt");
	double sum = 0;
	for (int i = 0; i < buf.size(); i++) {
		for (int j = i+1; j < buf.size(); j++) {
			if (buf[i] == buf[j]) {
				buf[j] = 0;
			}
		}
	}
	for (int i = 0; i < buf.size(); i++) {
		cout << buf[i]<<endl;
		sum += buf[i];
	}
	cout << endl << endl << sum;
	writeFile("output.txt", to_string((long)sum));
	return 0;
}