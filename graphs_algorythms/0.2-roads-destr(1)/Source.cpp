#include<iostream>
#include<fstream>
#include <set>
#include<string>
#include<vector>
using namespace std;
int n = 0, q = 0,m=0;
int countOfComps = 0;
int maxComp = 1;
string outText = "";
void writeFile() {
	ofstream out("output.txt");
	out << outText;
	out.close();
	return;
}

int main(void) {
	ifstream in("input.txt");
	in >> n;
	in >> m;
	in >> q;
	set<int> *towns = new set<int>[n];
	int a = 0, b = 0;
	for (int i = 0; i < m; i++) {
		in >> a;
		in >> b;
		a--;
		b--;
		towns[a].links.insert(b);
		towns[b].links.insert(a);
		roads[i].first = a;
		roads[i].second = b;
	}
	for (int i = 0; i < m; i++) {
		if (maxComp > 1) {
			outText += "0";
			continue;
		}
		in >> a;
		a--;
		towns[roads[a].first].links.erase(roads[a].second);
		towns[roads[a].second].links.erase(roads[a].first);
		countOfComp(towns);
		updateFlags(towns);
	}
	in.close();
	writeFile();

	return 0;
}