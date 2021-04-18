#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<set>
#include<queue>
using namespace std;
int waterInThird = 0;
int Solution = -1;
class probirki {
public:
	int first;
	int second;
	int perelivan;
	probirki(int first,int second,int pereliv) {
		this->first = first;
		this->second = second;
		this->perelivan = pereliv;
	}
	probirki() {
		this->first = 0;
		this->second = 0;
		this->perelivan = 0;
	}
private:
	friend bool operator==(const probirki& left, const probirki& right) {
		return (left.first==right.first && left.second==right.second);
	}
	friend bool operator>(const probirki& left, const probirki& right) {
		return (left.first > right.first && left.second > right.second );
	}
	friend bool operator<(const probirki& left, const probirki& right) {
		return (left.first < right.first && left.second < right.second);
	}
};
vector<probirki> allStates;
vector<int> pometki;
probirki readFile() {
	ifstream in("in.txt");
	in >> waterInThird;
	probirki buf;
	in >> buf.first;
	in >> buf.second;
	buf.perelivan = 0;
	int bf;
	while (in >> bf) {
		pometki.push_back(bf);
	}
	in.close();
	return buf;
}
void writeFile(string text) {
	ofstream out("out.txt");
	out << text;
	out.close();
	return;
}
int main(void) {
	probirki firstStatement=readFile();
	queue <probirki> probQueue;
	sort(pometki.begin(), pometki.end());
	probQueue.push(firstStatement);
	while (!probQueue.empty()) {
		probirki buf = probQueue.front();
		probQueue.pop();
		auto it = find(allStates.begin(), allStates.end(), buf);
		if (it != allStates.end()) {
			continue;
		}
		probirki bf(buf.second, buf.first, buf.perelivan);
		it = find(allStates.begin(), allStates.end(), bf);
		if (it != allStates.end()) {
			continue;
		}
		allStates.push_back(buf);
		if (100 - buf.first - buf.second == waterInThird) {
			Solution = buf.perelivan;
			break;
		}
		bf.perelivan = buf.perelivan + 1;
		for (int i = 0; i < pometki.size(); i++) {  //¬ыливаем из первой
			if (pometki[i] < buf.first) {
				bf.first = pometki[i];
				bf.second = buf.second + (buf.first - pometki[i]);
				probQueue.push(bf);// во вторую
				bf.second = buf.second;
				probQueue.push(bf);// в третью
			}
			else {
				break;
			}
		}
		for (int i = pometki.size()-1; i>=0; i--) {  //¬ливаем в первую
			if (pometki[i] > buf.first) {
				bf.first = pometki[i];
				if (buf.second >= (pometki[i] - buf.first))
				{
					bf.second = buf.second-(pometki[i] - buf.first);
					probQueue.push(bf);// из второй
				}
				if ((100-buf.second-buf.first) >= (pometki[i] - buf.first))
				{
					bf.second = buf.second;
					probQueue.push(bf);// из третьей
				}			
			}
			else {
				break;
			}
		}



		for (int i = 0; i < pometki.size(); i++) {  //¬ыливаем из второй
			if (pometki[i] < buf.second) {
				bf.first = buf.first + (buf.second-pometki[i]);
				bf.second = pometki[i];
				probQueue.push(bf);// в первую
				bf.first = buf.first;
				probQueue.push(bf);// в третью
			}
			else {
				break;
			}
		}
		for (int i = pometki.size() - 1; i >= 0; i--) {  //¬ливаем в первую
			if (pometki[i] > buf.second) {
				bf.second = pometki[i];
				if (buf.first >= (pometki[i] - buf.second))
				{
					bf.first = buf.first - (pometki[i] - buf.second);
					probQueue.push(bf);// из первой
				}
				if ((100 - buf.second - buf.first) >= (pometki[i] - buf.second))
				{
					bf.first= buf.first;
					probQueue.push(bf);// из третьей
				}
			}
			else {
				break;
			}
		}
		//выливаем все
		bf.first = 0;
		bf.second = buf.first + buf.second;
		probQueue.push(bf);
		bf.first = 0;
		bf.second = buf.second;
		probQueue.push(bf);
		bf.first = buf.first;
		bf.second =0;
		probQueue.push(bf);
		bf.first = buf.first + (100 - buf.first - buf.second);
		bf.second = buf.second;
		probQueue.push(bf);
		bf.first = buf.first ;
		bf.second = buf.second + (100 - buf.first - buf.second);
		probQueue.push(bf);
	}
	if (Solution > -1) {
		writeFile(to_string(Solution));
	}
	else {
		writeFile("No solution");
	}
	return 0;
}