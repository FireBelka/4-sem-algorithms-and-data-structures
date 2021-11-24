#include<iostream>
#include<fstream>
#include <set>
#include<string>
#include<queue>
#include <algorithm>
using namespace std;
int n,m;
bool* visited;
int* finalMas;
string outText = "";
class town {
public:
    vector<pair<int,int>> to_weight;
};
void writeFile() {
	ofstream out("output.txt");
	out << outText;
	out.close();
	return;
}
//bool allVisited() {
//	for (int i = 0; i < n; i++) {
//		if (!visited[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//void printMas(town* mas) {
//	for (int i = 0; i < n; i++) {
//		cout << "town# ";
//		cout << i + 1<<endl;
//		for (set<int>::iterator it = mas[i].to.begin(); it != mas[i].to.end(); it++) {
//			cout << to_string(*it) +" ";
//		}
//		cout << endl;
//		for (int j = 0; j < n; j++) {
//			cout << to_string(mas[i].weight[j]) + " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
class compare {
public:
	bool operator()(int& a, int& b)
	{
		return (finalMas[a] > finalMas[b]);
	}
};

	bool compare2(pair<int,int>& a, pair<int,int>& b)
	{
		return a.first<b.first;
	}

int main(void) {
	ifstream in("input.txt");
	in >> n;
	in >> m;
	if (n < 1) {
		outText = "0";
		writeFile();
		return 0;
	}
	town* mas = new town[n];
	finalMas = new int[n];
	visited = new bool[n];
	for (int i = 0; i < n; i++) {
		finalMas[i] = INT32_MAX;
		visited[i] = false;
	}
	pair<int, int> buf1;
	int from, to, weight;
	for (int i = 0; i < m; i++) {
		in >> from;
		from--;
		in >> to;
		to--;
		in >> weight;
		if (from == to) {
			continue;
		}
		buf1.first = to;
		buf1.second = weight;
		bool inVector = false;
		for (int i = 0; i < mas[from].to_weight.size(); i++) {
			if (mas[from].to_weight[i].first == buf1.first) {
				inVector = true;
				if (mas[from].to_weight[i].second > buf1.second) {
					mas[from].to_weight[i].second = buf1.second;
					break;
				}
				else {
					break;
				}
			}
		}
		if (!inVector) {
			mas[from].to_weight.push_back(buf1);
		}
		buf1.first = from;
		if (!inVector) {
			mas[to].to_weight.push_back(buf1);
		}
		else {
			for (int i = 0; i < mas[to].to_weight.size(); i++) {
				if (mas[to].to_weight[i].first == buf1.first) {
					if (mas[to].to_weight[i].second > buf1.second) {
						mas[to].to_weight[i].second = buf1.second;
					}
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		/*cout << "town:";
		cout << i + 1;
		cout << " ";*/
		sort(mas[i].to_weight.begin(), mas[i].to_weight.end(), compare2);
		/*for (int j = 0; j < mas[i].to_weight.size(); j++) {
			cout << to_string(mas[i].to_weight[j].first) + "-"+to_string(mas[i].to_weight[j].second)+" ";
		}
		cout << endl;*/
	}
	finalMas[0] =0;
	int vis = n;
	priority_queue<int,vector<int>,compare> q1;
	q1.push(0);
	int buf;
	while (!q1.empty()) {
		if (finalMas[n - 1] < INT32_MAX && vis<1) {
			break;
		}
		buf = q1.top();
		//cout << buf;
		q1.pop();
		
		if (visited[buf]) {
			continue;
		}
		visited[buf] = true;
		vis--;
		for (int i = 0; i < mas[buf].to_weight.size(); i++) {
			if (visited[mas[buf].to_weight[i].first]) {
				continue;
			}
			if (finalMas[mas[buf].to_weight[i].first] > finalMas[buf] + mas[buf].to_weight[i].second) {
				finalMas[mas[buf].to_weight[i].first] = finalMas[buf] + mas[buf].to_weight[i].second;
			}
			q1.push(mas[buf].to_weight[i].first);
		}
	}
	//printMas(mas);
	outText += to_string(finalMas[n - 1]);
	writeFile();
	in.close();
	return 0;
}