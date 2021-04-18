#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<fstream>
#include<string>
using namespace std;
int size_of_mas=0;
int* readFile() {
    ifstream in("input.txt");
    in >> size_of_mas;
    size_of_mas++;
    int* buf = new int[size_of_mas];
    int a;
    in >> a;
    buf[0] = a;
    in >> a;
    buf[1] = a;
    for (int i = 2; i < size_of_mas; i++) {
        in >> a;
        in >> a;  
        buf[i] = a;
    }
    in.close();
    return buf;
}
void writeFile(string text) {
    ofstream out("output.txt");
    out << text;
    out.close();
    return;
}
int main()
{
    int* data =readFile();
    size_of_mas--;
    int** mat = new int* [size_of_mas];

    for (int i = 0; i < size_of_mas; i++) {
        mat[i] = new int[size_of_mas];
        mat[i][i] = 0;
    }
    for (int g = 1; g < size_of_mas; ++g)
    {
        for (int i = 0; i < size_of_mas - g; ++i)
        {
            int j = i + g;
            mat[i][j] = INT_MAX -1;
            for (int p = i; p < j; ++p)
            {
                mat[i][j] = min(mat[i][j],
                    mat[i][p] + mat[p + 1][j] + data[i] * data[p + 1] * data[j + 1]);
            }
        }
    }
    writeFile(to_string(mat[0][size_of_mas - 1]));
    return 0;
}