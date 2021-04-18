#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
/*
Реализован обход с конца массива;
Программа берет каждую строку, начиная с n-1 позиции, и проходя по каждому элементу забирая минимальный элемент из трех со следующей строки;
Генерируются отдельные случаи для первого, крайнего и средних элементов
*/
using namespace std;
int n_s;
int m_s;
int** readFile(string path) {
	ifstream in(path);
	int** mas;
	int n;
	int m;
	in >> n;
	in >> m;
	n_s = n;
	m_s = m;
	int tmp;
	mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[m];
		for (int j = 0; j < m; j++) {
			in >> tmp;
			mas[i][j] = tmp;
		}
	}

	in.close();
	return mas;
}
void writeFile(string path, string text) {
	ofstream out;
	out.open(path);
	out << text;
	out.close();
}
void printMas(int ** mas,int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<<to_string(mas[i][j])+" ";
		}
		cout << endl;
	}
}
int min(int a, int b) {
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}
void updateFirst(int** mas,int n,int m){
	if (m == 1) {
		mas[n][0] += mas[n + 1][0];
		return;
	}
	mas[n][0] += min(mas[n + 1][0], mas[n + 1][1]);
	return;
}
void updateMiddle(int** mas, int n, int m) {
	if (m <= 2) {
		return;
	}
	for (int i = 1; i < m - 1; i++) {
		mas[n][i] += min(min(mas[n + 1][i], mas[n + 1][i+1]),mas[n+1][i-1]);
	}
	return;
}
void updateLast(int** mas, int n, int m) {
	if (m == 1) {
		return;
	}
	mas[n][m - 1] += min(mas[n + 1][m - 2], mas[n + 1][m - 1]);
	return;
}

int main(void) {
	int ** mas=readFile("input.txt");
	//printMas(mas, n_s, m_s);
	for (int i = n_s-2; i >=0; i--) {	
			updateFirst(mas, i, m_s);
			updateMiddle(mas, i, m_s);
			updateLast(mas, i, m_s);
	}
	int min = mas[0][0];
	for (int i = 0; i < m_s; i++) {
		if (mas[0][i] < min) {
			min = mas[0][i];
		}
	}
	writeFile("output.txt", to_string(min));
	return 0;
}