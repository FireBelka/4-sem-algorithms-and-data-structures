#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
struct branch
{
	long field;
	long numberOfStr;
	bool linkR_true_L_false;
};
vector<branch> readFile(string path) {
	vector<branch> buf;
	string line;
	ifstream in(path);
	getline(in, line);
	getline(in, line);
	branch b;
	b.field=atol(line.c_str());
	b.numberOfStr = NULL;
	b.linkR_true_L_false = false;
	buf.push_back(b);
	while (in>>line) {
		b.field = atol(line.c_str());
		in >> line;
		b.numberOfStr= atol(line.c_str());
		in >> line;
		if (line == "R")
			b.linkR_true_L_false = true;
		else
			b.linkR_true_L_false = false;
		buf.push_back(b);
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
	vector<branch> buf = readFile("bst.in");
	bool isSTree = true;
	for (int i = 1; i < buf.size(); i++) {
		branch tmp;
		tmp.field = buf[i].field;
		tmp.linkR_true_L_false = buf[i].linkR_true_L_false;
		tmp.numberOfStr = buf[i].numberOfStr;
		int g = 40;
		while (tmp.numberOfStr != 0 && g>0) {
			g--;
			long valueOfParent = buf[tmp.numberOfStr - 1].field;
			if (buf[tmp.numberOfStr - 1].linkR_true_L_false != tmp.linkR_true_L_false) {
				if (valueOfParent > tmp.field && tmp.linkR_true_L_false) {
					writeFile("bst.out", "NO");
					return 0;
				}
				else if (valueOfParent <= tmp.field && !tmp.linkR_true_L_false) {
					writeFile("bst.out", "NO");
					return 0;
				}
			}
			tmp.linkR_true_L_false = buf[tmp.numberOfStr - 1].linkR_true_L_false;
			tmp.numberOfStr = buf[tmp.numberOfStr - 1].numberOfStr;
		}
	}
	writeFile("bst.out", "YES");
	return 0;
}