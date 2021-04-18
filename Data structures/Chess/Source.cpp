#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<string>
using namespace std;
int n = 0, m = 0,x2=0,y2=0;
class position
{
public:
	int x;
	int y ;
	int turns;
	friend bool operator==(const position& left, const position& right) {
		return (left.x == right.x && left.y == right.y);
	}
};
position start;
int** readFile() {
	ifstream in("in.txt");
	in >>n;
	in >> m;
	int** buf = new int* [n];
	for (int i = 0; i < m; i++) {
		buf[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			in >> buf[i][j];
		}
	}
	in >> start.x;
	start.x--;
	in >> start.y;
	start.y--;
	in >> x2;
	x2--;
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
int main(void) {
	vector<position> allPos;
	int** mas = readFile();
	priority_queue<position, vector<position>, compare> positions;
	positions.push(start);

	int solution = -1;
	while (!positions.empty()) {
		position buf = positions.top();
		positions.pop();
		if (find(allPos.begin(), allPos.end(), buf) != allPos.end()) {
			continue;
		}
		allPos.push_back(buf);
		//cout << to_string(buf.x) + " " + to_string(buf.y) + " " + to_string(buf.turns) << endl;;
		if (buf.x == x2 && buf.y == y2) {
			solution = buf.turns;
			break;
		}
		if (buf.x + 2 < m) {//вправо
			if (buf.y + 1 < n) {
				if (mas[buf.x + 2][buf.y + 1] != -1) {
					position bf;
					bf.x = buf.x + 2;
					bf.y = buf.y + 1;
					bf.turns = buf.turns + 1;
					if (mas[buf.x + 2][buf.y + 1] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
			if (buf.y - 1 >= 0) {
				if (mas[buf.x + 2][buf.y - 1] != -1) {
					position bf;
					bf.x = buf.x + 2;
					bf.y = buf.y - 1;
					bf.turns = buf.turns + 1;
					if (mas[buf.x + 2][buf.y - 1] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
		}

		if (buf.x - 2 >=0) {//влево
			if (buf.y + 1 < n) {
				if (mas[buf.x - 2][buf.y + 1] != -1) {
					position bf;
					bf.x = buf.x - 2;
					bf.y = buf.y + 1;
					bf.turns = buf.turns + 1;
					if (mas[buf.x - 2][buf.y + 1] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
			if (buf.y - 1 >= 0) {
				if (mas[buf.x - 2][buf.y - 1] != -1) {
					position bf;
					bf.x = buf.x - 2;
					bf.y = buf.y - 1;
					bf.turns = buf.turns + 1;
					if (mas[buf.x - 2][buf.y - 1] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
		}

		if (buf.y - 2 >= 0) {//вверх
			if (buf.x + 1 < m) {
				if (mas[buf.x +1][buf.y -2] != -1) {
					position bf;
					bf.x = buf.x +1;
					bf.y = buf.y -2;
					bf.turns = buf.turns + 1;
					if (mas[buf.x +1][buf.y -2] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
			if (buf.x - 1 >= 0) {
				if (mas[buf.x - 1][buf.y - 2] != -1) {
					position bf;
					bf.x = buf.x - 1;
					bf.y = buf.y - 2;
					bf.turns = buf.turns + 1;
					if (mas[buf.x - 1][buf.y - 2] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
		}

		if (buf.y + 2<n ) {//вниз
			if (buf.x + 1 < m) {
				if (mas[buf.x + 1][buf.y + 2] != -1) {
					position bf;
					bf.x = buf.x + 1;
					bf.y = buf.y + 2;
					bf.turns = buf.turns + 1;
					if (mas[buf.x + 1][buf.y + 2] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
			if (buf.x - 1 >= 0) {
				if (mas[buf.x - 1][buf.y + 2] != -1) {
					position bf;
					bf.x = buf.x - 1;
					bf.y = buf.y + 2;
					bf.turns = buf.turns + 1;
					if (mas[buf.x - 1][buf.y + 2] == 1) {
						bf.turns++;
					}
					positions.push(bf);
				}
			}
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