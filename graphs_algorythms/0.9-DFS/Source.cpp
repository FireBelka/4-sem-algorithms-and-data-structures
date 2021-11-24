#include<iostream>
#include<fstream>
#include <set>
#include<string>
#include<queue>
using namespace std;
int n = 0;
int* mas2;
int pos = 1;
bool* visited;
set<int>* mas;
void writeFile(int* mas) {
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		out << mas[i];
		out << " ";
	}
	out.close();
	return;
}
bool allVisited() {
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}
void recFind(int i) {
	if (visited[i]) {
		return;
	}
	visited[i] = true;
	mas2[i] = pos;
	pos++;
	for (set<int>::iterator it = mas[i].begin(); it != mas[i].end(); it++) {
		recFind(*it);
	}
	return;
}
void printMas(int* mas) {
	for (int i = 0; i < n; i++) {
		cout << mas[i];
		cout << " ";
	}
	cout << endl;
}
int main(void) {
	ifstream in("input.txt");
	int a;
	in >> n;
	mas = new set<int>[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> a;
			if (a == 1) {
				mas[i].insert(j);
			}
			
		}
	}
	queue<int> q1;
	mas2 = new int[n];
	visited = new bool[n];
	for (int i = 0; i < n; i++) {
		mas2[i] = 0;
		visited[i] = false;
	}
	q1.push(0);
	while (!q1.empty() || !allVisited()) {
		if (q1.empty()) {
			for (int i = 0; i < n; i++) {
				if (!visited[i]) {
					q1.push(i);
					break;
				}
			}
			continue;
		}
		int buf = q1.front();
		q1.pop();
		recFind(buf);
	
	}
    writeFile(mas2);

	return 0;
}