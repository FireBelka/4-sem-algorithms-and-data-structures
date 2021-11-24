#include<iostream>
#include<fstream>
#include <set>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;
int n;
void writefile(vector<int> inv, vector<int> razd) {
	ofstream os("output.txt");
	os << inv.size();
	for (int i = 0; i < inv.size(); i++) {
		os <<" "<< inv[i];
	}
	os <<endl<< razd.size() ;
	for (int i = 0; i < razd.size(); i++) {
		os <<" "<< razd[i];
	}
	os.close();
	return;
}
void printMas(vector<int>* mas) {
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int j = 0; j < mas[i].size(); j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
}
bool isInevitable(int num, vector<int>* mas) {
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	queue<int> q1;
	
	int buf;
	q1.push(0);
	while (!q1.empty()) {
		buf = q1.front();
		q1.pop();
		if (visited[buf]) {
			continue;
		}
		if (buf == n - 1) {
			return false;
		}
		visited[buf] = true;
		for (int i = 0; i < mas[buf].size(); i++) {
			if (!visited[mas[buf][i]] && mas[buf][i]!=num) {
				q1.push(mas[buf][i]);
			}
		}
	}
	return true;
}
bool isRazdPoint(int num, vector<int>* mas) {
	bool* visited = new bool[n];
	bool* visited2 = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		visited2[i] = false;
	}
	queue<int> q1;

	int buf;
	q1.push(num);
	while (!q1.empty()) {
		buf = q1.front();
		q1.pop();
		if (visited[buf]) {
			continue;
		}
		visited[buf] = true;
		for (int i = 0; i < mas[buf].size(); i++) {
			if (!visited[mas[buf][i]]) {
				q1.push(mas[buf][i]);
			}
		}
	}
	q1.push(0);
	while (!q1.empty()) {
		buf = q1.front();
		q1.pop();
		if (visited[buf]) {
			return false;
		}
		if (visited2[buf]) {
			continue;
		}
		visited2[buf] = true;
		for (int i = 0; i < mas[buf].size(); i++) {
			if (!visited2[mas[buf][i]] && mas[buf][i]!=num) {
				q1.push(mas[buf][i]);
			}
		}
	}
	return true;
}
int main(void) {
	ifstream in("input.txt");
	in >> n;
	if (n == 0) {
		writefile(vector<int>(),vector<int>());
		return 0;
	}
	vector<int>* mas = new vector<int>[n];
	int a;
	for (int i = 0; i < n; i++) {
		in >> a;
		while (a != -2) {
			if (a != i) {
				mas[i].push_back(a);
			}
			in >> a;
		}
		sort(mas[i].begin(), mas[i].end());
	}
	in.close();
	//printMas(mas);
	vector<int> inv;
	vector<int> razdPoint;
	for (int i = 1; i < n-1; i++) {
		if (isInevitable(i, mas)) {
			inv.push_back(i);
		}
	}
	for (int i = 0; i < inv.size(); i++) {
		if (isRazdPoint(inv[i], mas)) {
			razdPoint.push_back(inv[i]);
		}
	}
	writefile(inv, razdPoint);
	/*for (int i = 0; i < inv.size(); i++) {
		cout << inv[i] << endl;
	}*/
}