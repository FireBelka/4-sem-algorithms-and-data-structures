#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
int n = 0, m = 0, x2 = 0, y2 = 0;
class position
{
public:
	int x;
	int y;
	int turns;
	friend bool operator==(const position& left, const position& right) {
		return (left.x == right.x && left.y == right.y);
	}
};
position start;
int** readFile() {
	ifstream in("in.txt");
	in >> n;
	in >> m;
	int** buf = new int* [n];
	for (int i = 0; i < m; i++) {
		buf[i] = new int[m];
	}
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> a;
			buf[i][j] = a;
		}
	}
	in >> start.x;
	start.x -= 1;
	in >> start.y;
	start.y -= 1;
	in >> x2;
	x2 -= 1;
	in >> y2;
	y2--;
	start.turns = 0;
	in.close();
	return buf;
}
void writeFile(string text) {
	ofstream out("out.txt");
	out << text;
	out.close();
	return;
}
class compare {
public:
	bool operator()(position& a, position& b)
	{
		return (a.turns > b.turns);
	}
};
int main(void) {//Возможно ли x1 x2 =0?
	vector<position> allPos;

	int** mas = readFile();

	priority_queue<position, vector<position>, compare> positions;
	positions.push(start);
	if (start.x >= n || start.y >= m) {
		writeFile("No");
	}
	int solution = -1;
	int xDif[8] = { 1,1,-1,-1,2,2,-2,-2 };
	int yDif[8] = { 2,-2,2,-2,1,-1,1,-1 };
	while (!positions.empty()) {
		position buf = positions.top();
		positions.pop();
		if (buf.x >= n || buf.y >= m || buf.x < 0 || buf.y < 0) {
			continue;
		}
		if (mas[buf.x][buf.y] < 0) {
			continue;
		}

		//cout << to_string(buf.x) + " " + to_string(buf.y) + " " + to_string(buf.turns) << endl;;
		if (buf.x == x2 && buf.y == y2) {
			solution = buf.turns;
			break;
		}
		mas[buf.x][buf.y] = -2;
		for (int i = 0; i < 8; i++) {
			if (buf.x + xDif[i] >= n || buf.x + xDif[i] < 0 || buf.y + yDif[i] >= m || buf.y + yDif[i] < 0) {
				continue;
			}
			position bf;
			bf.x = buf.x + xDif[i];
			bf.y = buf.y + yDif[i];
			if (mas[bf.x][bf.y] < 0) {
				continue;
			}
			if (mas[bf.x][bf.y] == 1) {
				bf.turns = buf.turns + 2;
			}
			else {

				bf.turns = buf.turns + 1;
			}
			positions.push(bf);
		}
	}
	if (solution != -1) {
		writeFile(to_string(solution));
	}
	else {
		writeFile("No");
	}
	return 0;
}