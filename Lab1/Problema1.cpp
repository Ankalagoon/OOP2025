#include <iostream>

using namespace std;

int main(){
	FILE* fin;
	if (fopen_s(&fin, "ini.txt", "r")) {
		printf("Eroare deschidere fisier");
		return 0;
	}
	char s[100];
	int i = 0,x=0,sol=0;
	while (fgets(s, 100, fin) != NULL) {
		i = 0; x = 0;
		while (s[i] != NULL and s[i] != '\n') {
			x *= 10;
			x += (s[i] - '0');
			i++;
		}
		sol += x;
	}
	printf("%d", sol);
}
