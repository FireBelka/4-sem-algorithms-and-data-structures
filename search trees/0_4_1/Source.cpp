#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
#include <algorithm>
using namespace std;
class branch
{
public:
	long field = NULL;
	branch* right;
	branch* left;
	vector<int> leftBranchVec;
	vector<int> rightBranchVec;
	vector<int> top;
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
		if (buf != "")
			str += "\n" + buf;
	}
	if (a->right != nullptr) {
		string buf = printTree(a->right);
		if (buf != "")
			str += "\n" + buf;
	}
	return str;
}
branch* rightRemove(branch* a, long value) {
	if (a == nullptr) {
		return a;
	}
	if (a->field == value) {
		branch* tmp;
		if (a->right == nullptr && a->left == nullptr) {
			tmp = nullptr;
		}
	     else if (a->right == nullptr) {
			tmp = a->left;
		}
		else if (a->left == nullptr) {
			tmp = a->right;
		}
		else {
			branch* buf = a->right;
			if (buf->left == nullptr) {
				buf->left = a->left;
				tmp = buf;
			}
			else
			{
				branch* minRight = buf->left;
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
	else if (value > a->field) {
		a->right = rightRemove(a->right, value);
	}
	return a;
}
void UpdatePathes1(branch* a) {
	if (a == nullptr) {
		return;
	}
	if (a->left != nullptr) {
		UpdatePathes1(a->left);
		for (int i = 0; i < a->left->leftBranchVec.size(); i++) {
			a->leftBranchVec.push_back(a->left->leftBranchVec[i] + 1);
		}
		for (int i = 0; i < a->left->rightBranchVec.size(); i++) {
			a->leftBranchVec.push_back(a->left->rightBranchVec[i] + 1);
		}
	}
	if (a->right != nullptr) {
		UpdatePathes1(a->right);
		for (int i = 0; i < a->right->leftBranchVec.size(); i++) {
			a->rightBranchVec.push_back(a->right->leftBranchVec[i] + 1);
		}
		for (int i = 0; i < a->right->rightBranchVec.size(); i++) {
			a->rightBranchVec.push_back(a->right->rightBranchVec[i] + 1);
		}
	}
	if (a->left == nullptr && a->right==nullptr) {
		a->leftBranchVec.push_back(0);
		a->rightBranchVec.push_back(0);
	}	
	return;
}
void UpdatePathes2(branch* a) {
	if (a == nullptr) {
		return;
	}
	if (a->right != nullptr) {
		for (int i = 0; i < a->leftBranchVec.size(); i++) {
			a->right->top.push_back(a->leftBranchVec[i]+1);
		}
		for (int i = 0; i < a->top.size(); i++) {
			a->right->top.push_back(a->top[i]+1);
		}
		UpdatePathes2(a->right);
	}
	if (a->left != nullptr) {
		for (int i = 0; i < a->rightBranchVec.size(); i++) {
			a->left->top.push_back(a->rightBranchVec[i] + 1);
		}
		for (int i = 0; i < a->top.size(); i++) {
			a->left->top.push_back(a->top[i] + 1);
		}
		UpdatePathes2(a->left);
	}

}
vector<long> readFile(string path) {
	vector<long> buf;
	string line;
	ifstream in(path);
	while (getline(in, line)) {
		buf.push_back(stol(line));
	}
	in.close();
	return buf;
}
void writeFile(string path, branch* a) {
	ofstream out(path);
	if (a == nullptr) {
		out << "Empty";
	}
	else
	{
		out << a;
	}

	out.close();
}
vector<branch*> retAllBranches(branch* a) {//a-корень
	vector<branch*> buf;
	if (a == nullptr) {
		return buf;
	}
	buf.push_back(a);
	vector<branch*>tmp = retAllBranches(a->left);
	buf.insert(buf.end(), tmp.begin(), tmp.end());
	tmp = retAllBranches(a->right);
	buf.insert(buf.end(), tmp.begin(), tmp.end());
	return buf;
}
bool check_isMaxDistanceLowerThanK(branch* a, int k) {
	int a1=0, b=0, c=0;
	if (a == nullptr) {
		return false;
	}
	for (int i = 0; i < a->leftBranchVec.size(); i++) {
		if (a->leftBranchVec[i] > a1) {
			a1 = a->leftBranchVec[i];
		}
	}
	for (int i = 0; i < a->rightBranchVec.size(); i++) {
		if (a->rightBranchVec[i] > b) {
			b = a->rightBranchVec[i];
		}
	}
	for (int i = 0; i < a->top.size(); i++) {
		if (a->top[i] > c) {
			c = a->top[i];
		}
	}
	if (a1 >= k ||  c >= k || b >= k) {
		return false;
	}
	return true;
}
void clearAllDistances(branch* a) {
	if (a == nullptr) {
		return;
	}
	a->top.clear();
	a->leftBranchVec.clear();
	a->rightBranchVec.clear();
	clearAllDistances(a->left);
	clearAllDistances(a->right);
	return;
}
bool check_noConsistOnHalfWaysWithKLong(branch* a, int k) {
	if (a == nullptr) {
		return false;
	}
	for (int i = 0; i < a->leftBranchVec.size(); i++) {
		for (int j = 0; j < a->rightBranchVec.size(); j++) {
			if (a->leftBranchVec[i] + a->rightBranchVec[j] == k) {
				return false;
			}
		}
	}
	for (int i = 0; i < a->leftBranchVec.size(); i++) {
		for (int j = 0; j < a->top.size(); j++) {
			if (a->leftBranchVec[i] + a->top[j] == k) {
				return false;
			}
		}
	}
	for (int i = 0; i < a->top.size(); i++) {
		for (int j = 0; j < a->rightBranchVec.size(); j++) {
			if (a->top[i] + a->rightBranchVec[j] == k) {
				return false;
			}
		}
	}
	return true;
}
int main(void) {
	branch* a = nullptr;
	vector<long> buf = readFile("input.txt");
	for (int i = 1; i < buf.size(); i++) {
		a = addBranch(a, buf[i]);
	}
	vector<branch*> allBranches ;
	branch* branchToDel=nullptr;
		allBranches = retAllBranches(a);
		clearAllDistances(a);
		if (a != nullptr) {
			a->top.push_back(0);
		}
		UpdatePathes1(a);
		UpdatePathes2(a);
		for (int i = 0; i < allBranches.size(); i++) {
			if (check_isMaxDistanceLowerThanK(allBranches[i], buf[0]) && check_noConsistOnHalfWaysWithKLong(allBranches[i],buf[0])) {
				if (branchToDel == nullptr) {
					branchToDel = allBranches[i];
				}
				else if (branchToDel->field < allBranches[i]->field) {
					branchToDel = allBranches[i];
				}
			}
		}
		if (branchToDel != nullptr) {
			a = rightRemove(a, branchToDel->field);
		}
		
	
	writeFile("output.txt", a);
	return 0;
}