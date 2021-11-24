#include<iostream>
#include<fstream>
#include <set>
#include<string>
using namespace std;
int n = 0, q = 0;
int countOfComps ;

int main(void) {
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> n;
	in >> q;
	countOfComps = n;
	int* mas2 = new int[n];
	for (int i = 0; i < n; i++) {
		mas2[i] = i;
	}
	int a = 0, b = 0,par1,par2,buf;
	for (int i = 0; i < q; i++) {
		in >> a;
		in >> b;
		a--;
		b--;
		if (mas2[a]!=mas2[b]) {
			par1 = mas2[a];
			par2 = mas2[b];
			while (par1 != mas2[par1]) {

				par1 = mas2[par1];
			}
			while (par2 != mas2[par2]) {
				par2 = mas2[par2];
			}
			mas2[a] = par1;
			mas2[b] = par2;
			if (par2 != par1) {
				mas2[par1] = mas2[par2];
				countOfComps--;
			}
		}
		out<<countOfComps<<"\n";
	}
	in.close();
	out.close();

	return 0;
}