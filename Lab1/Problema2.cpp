#include <iostream>

using namespace std;

int main() {
	int cs[100];
	char cuv[100][100];
	char s[100];
	int n = 0;
	while (scanf_s("%s", s, (unsigned int)sizeof(s))==1) {
		int i = 0;
		while (s[i] != NULL) i++;
		cs[++n] = i;
		strcpy_s(cuv[n], s);
	}
	int ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 1;i < n;i++) {
			if (cs[i] < cs[i + 1]) {
				swap(cuv[i], cuv[i + 1]);
				ok = 1;
			}
			else if (cs[i] == cs[i + 1]) {
				for (int j = 0;j < cs[i];j++) {
					if (cuv[i][j] > cuv[i + 1][j]) {
						swap(cuv[i], cuv[i + 1]);
						ok = 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		printf("%s\n", cuv[i]);
	}
}
