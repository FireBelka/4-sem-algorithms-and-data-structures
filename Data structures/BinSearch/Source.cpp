#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct request {
	int find;
	int position_of_moreOrEqual;
	int position_of_more;
};
request binSearch(int *mas, int key,int sizeOfMas) {
	request buf;
	int leftBorder = 0;
	int rightBorder = sizeOfMas - 1;
	int g ;
	buf.find = 0;
	buf.position_of_more = sizeOfMas;
	buf.position_of_moreOrEqual = 0;
	while (leftBorder<=rightBorder) {		
		g = (leftBorder + rightBorder) / 2;
		if (mas[g] == key) {
			buf.find = 1;
			break;
		}
		if (key < mas[g]) {
			rightBorder = g - 1;
		}
		else if (key > mas[g]) {
			leftBorder = g + 1;
		}
	}
	int pos = g;
	leftBorder = g; rightBorder = sizeOfMas -1;
	while (leftBorder <= rightBorder) {
		g = (leftBorder + rightBorder) / 2;
		if (mas[g] <= key) {
			leftBorder = g+1;
		}
		else {
			rightBorder = g - 1;
		}
	}
	buf.position_of_more = leftBorder;
	if (buf.find == 0) {
		buf.position_of_moreOrEqual = buf.position_of_more;
	}
	else {
		leftBorder = 0; rightBorder = pos;
		while (leftBorder <= rightBorder) {
			g = (leftBorder + rightBorder) / 2;
			if (mas[g] >= key) {
				rightBorder = g-1;
			}
			else {
				leftBorder = g + 1;
			}
		}
		buf.position_of_moreOrEqual = leftBorder;
	}
	return buf;
}
int main(void)
{
	int masSize;
	scanf("%d", &masSize);
	int* mas=new int[masSize];
	for (int i = 0; i < masSize; i++) {
		int buf;
		scanf("%d", &buf);
		mas[i] = buf;
	}
	int countOfRequests;
	scanf("%d", &countOfRequests);

	for (int i = 0; i < countOfRequests; i++) {
		int req;
		scanf("%d", &req);
		request a=binSearch(mas, req,masSize);
		printf("%d %d %d\n", a.find, a.position_of_moreOrEqual, a.position_of_more);
	}
	return 0;
}