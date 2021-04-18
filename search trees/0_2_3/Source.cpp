#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
class branch
{
public:
	long int field = NULL;
	branch* right;
	branch* left;
	friend ostream& operator << (ostream& os, branch* a) {
		if (a != nullptr) {
			os << a->field << '\n';
			os << a->left;
			os << a->right;
		}
		return os;
	}
};
branch* addBranch(branch* a, long value) {
	if (a == nullptr) {
		a = new branch;
		a->field = value;
		a->right = nullptr;
		a->left = nullptr;
		return a;
	}
	else if (value < a->field) {
		a->left = addBranch(a->left, value);
	}
	else if (value > a->field) {
		a->right = addBranch(a->right, value);
	}
	return a;
}
string printTree(branch* a) {
	string str = "";
	try {
		str = to_string(a->field);
	}
	catch (exception ex) {
		return "";
	}
	if (a->left != nullptr) {
		string buf = printTree(a->left);
		if(buf!="")
		str += "\n" + buf;
	}
	if (a->right != nullptr) {
		string buf = printTree(a->right);
		if (buf != "")
		str += "\n" + buf;
	}
	return str;
}
branch* rightRemove(branch* a, long int value) {
	if (a == nullptr) {
		return a;
	}
	if (a->field == value) {
		branch* tmp;
		if (a->left == nullptr) {
			tmp = a->right;
		}
		else if (a->right == nullptr) {
			tmp = a->left;
		}
		else {
			branch* buf = a->right;
			if (buf->left == nullptr) {
				buf->left = a->left;
				tmp = buf;
			}
			else
			{
				branch* minRight=buf->left;
				while (minRight->left != nullptr) {
					buf = minRight;
					minRight = buf->left;
				}
				buf->left = minRight->right;
				minRight->left = a->left;
				minRight->right = a->right;
				tmp = minRight;
			}
		}
		delete a;
		return tmp;
	}
	else if (value < a->field) {
		a->left = rightRemove(a->left, value);
	}
	else if(value > a->field) {
		a->right = rightRemove(a->right, value);
	}
	return a;
}
vector<long int> readFile(string path) {
	vector<long int> buf;
	string line;
	ifstream in(path);
	getline(in, line);
	buf.push_back(stol(line));
	getline(in, line);
	while (getline(in,line)) {
		buf.push_back(stol(line));
	}
	in.close();
	return buf;
}
void writeFile(string path, branch* a) {
	ofstream out(path);
	out << a;
	out.close();
}
int main(void) {
	branch* a = nullptr;
	vector<long int> buf = readFile("input.txt");
	for (int i = 1; i < buf.size(); i++) {
		a = addBranch(a, buf[i]);
	}
	a = rightRemove(a, buf[0]);
	writeFile("output.txt", a);
	return 0;
}