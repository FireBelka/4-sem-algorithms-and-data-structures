#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int sizeOfBuf;
string readFile() {
	ifstream in("input.txt");
	string buf;	
	getline(in,buf);
	in.close();
	return buf;
}
void writeFile(string text) {
	ofstream out("output.txt");
	out << text;
	out.close();
	return;
}
int maxOf(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
void PrintMas(int** mas, int n, int m) {
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << to_string(mas[i][j]) + " ";
		}
		cout << endl;
	}
	return;
}
int main(void) {
	string str = readFile();
	if (str.length() == 0) {
		string text = "0\n";
		text += str;
		writeFile(text);
		return 0;
	}
	if (str.length() == 1) {
		string text = "1\n";
		text += str;
		writeFile(text);
		return 0;
	}
	if (str.length() == 2) {
		string text="";
		if (str[0] == str[1]) {
			text += "2\n";
			text += str;
		}
		else {
			text += "1\n";
			text += str[0];
		}
		writeFile(text);
		return 0;
	}
	int** mas = new int*[str.length()];
	for (int i = 0; i < str.length(); i++) {
		mas[i] = new int[str.length()];
		mas[i][i] = 1;
	}
	for (int i = 1; i < str.length(); i++) {
		if (str[i - 1] == str[i]) {
			mas[i - 1][i] = 2;
		}
		else {
			mas[i - 1][i] = 1;
		}
	}
	for (int i = 2; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			if (str[j - i] == str[j]) {
				mas[j - i][j] = mas[j - i + 1][j - 1]+2;
			}
			else {
				mas[j - i][j] = maxOf(mas[j - i + 1][j], mas[j - i][j - 1]);
			}	
		}
	}
	//PrintMas(mas, str.length(), str.length());
	int i = 0, j = str.length() - 1;
	string front = "", forward = "";
	while (i != j) {
		if (j < i) {
			break;
		}
		if (str[i] == str[j]) {
			front += str[i];
			forward = str[i] + forward;
			i++;
			j--;
		}
		else {
			if (mas[i][j - 1] < mas[i + 1][j]) {
				i++;
			}
			else {
				j--;
			}
		}
	}
	string text ="";
	if (i == j) {
		text = front + str[i] + forward;
	}
	else {
		text = front  + forward;
	}
	text = to_string(text.length()) + "\n" + text;
	writeFile(text);
	//cout << str << endl << text;
	return 0;
}