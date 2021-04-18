#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;
class branch
{
public:
	long int field;
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
branch * addBranch(branch* a,long value) {
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
	 else if(value > a->field){
		 a->right = addBranch(a->right, value);
	 }	
	 return a;
}
 string printTree(branch* a) {
	 string str = "";
	 if (a == nullptr) {
		 return "";
	 }
	 str = to_string(a->field);
	 if (a->left != nullptr) {
		 str+="\n"+printTree(a->left);
	 }
	 if (a->right != nullptr) {
		 str += "\n" + printTree(a->right);
	 }
	 return str;
 }
 vector<long> readFile(string path) {
	vector<long> buf ;
	long line;
	 ifstream in(path);
	 while (in>>line) {
			 buf.push_back(line);		 
	 }
	 in.close();
	 return buf;
 }
 void writeFile(string path,string text) {
	 ofstream out;
	 out.open(path);
	 out << text;
	 out.close();
 }
int main(void) {
	branch *a=nullptr;
	long int line;
	ifstream in("input.txt");
	while (in >> line) {
		a = addBranch(a, line);
	}
	in.close();
	//string text = printTree(a);
	//writeFile("output.txt",text);
	ofstream out("output.txt");
	out << a;
	out.close();
	return 0;
}