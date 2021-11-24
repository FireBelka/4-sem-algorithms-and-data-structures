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
		mas2[i] = -1;
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
		queue<int> q2;
		q2.push(buf);
		while (!q2.empty()) {
			int bf = q2.front();
			q2.pop();
			if (visited[bf]) {
				continue;
			}
			visited[bf] = true;
			mas2[bf] = pos;
			pos++;
			for (set<int>::iterator it = mas[bf].begin(); it != mas[bf].end(); it++) {
				q2.push(*it);
			}
		}
	}

	
    writeFile(mas2);

	return 0;
}