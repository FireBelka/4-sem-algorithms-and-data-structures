#include<iostream>
#include<fstream>
#include <set>
#include<string>
using namespace std;
int n = 0;
string outText = "";
void writeFile(set<int>* mas) {
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		out << mas[i].size();
		out << " ";
		for (set<int>::iterator a = mas[i].begin(); a != mas[i].end(); a++) {
			out << (*a)+1;
			out << " ";
		}
		out << "\n";
	}
	out.close();
	return;
}

int main(void) {
	ifstream in("input.txt");
	int  m,a, b;
	in >> n;
	in >> m;
	set<int>* mas = new set<int>[n];
	for (int i = 0; i <m; i++) {
		in >> a;
		in >> b;
		a--;
		b--;
		mas[a].insert(b);
		mas[b].insert(a);
	}
	in.close();
	writeFile(mas);

	return 0;
}