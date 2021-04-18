#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include <algorithm>

#include<vector>
using namespace std;
struct readStruct {
	int n;
	int a;
	int b;
};
readStruct readFile(string path) {
	readStruct buf;
	ifstream in(path);
	in >> buf.n;
	in >> buf.a;
	in >> buf.b;
	in.close();
	return buf;
}
long countOfPathes(vector<int> levels, int a, int b,int n) {
	int count = 0;
	int sum = 0;
	int levelsSize = levels.size();
	if (levelsSize == 0) {
		if (abs(1-n) >= a && abs(1-n) <= b) {
			return 1;
		}
		else {
			return 0;
		}
	}
	sum = abs(1 - levels[0]);
	for (int i = 0; i < levelsSize -1; i++) {
		sum += abs(levels[i] - levels[i + 1]);
	}
	sum += abs(levels[levelsSize - 1] - n);
	if (sum >= a && sum <= b) {
		count++;
	}
	while (next_permutation(levels.begin(), levels.end()))
	{
		sum = abs(1 - levels[0]);
		for (int i = 0; i < levelsSize - 1; i++) {
			if (sum > b) {
				break;
			}
			sum += abs(levels[i] - levels[i + 1]);
		}
		sum += abs(levels[levelsSize - 1] - n);
		if (sum >= a && sum <= b) {
			count++;
		}
	}
	return count;
}
void writeFile(string path,long text) {
	ofstream out(path);
	out << text;
	out.close();
	return;
}
int main(void) {
	readStruct buf = readFile("game.in");
	vector<int> levels;
	for (int i = 2; i <= buf.n - 1; i++) {
		levels.push_back(i);
	}

	long a = countOfPathes(levels, buf.a,buf.b,buf.n);
	writeFile("game.out", a);

	return 0;
}