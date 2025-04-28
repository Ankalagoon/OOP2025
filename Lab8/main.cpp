#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

struct dub {
	int x;
	string s;
	bool operator <(const dub& a) const{
		if (x == a.x) return s > a.s;
		return x < a.x;
	}
};

int main() {
	map<string,int> M;
	priority_queue<dub> pq;
	int i, j;
	char c;
	string text;
	getline(cin, text);
	i = 0;
	j = 0;
	for (i=0;i<text.size();i++){
		c = text[i];
		if (c >= 65 && c <= 90) text[i] += 32;
		if (c == ' ' || c == ',' || c == '!' || c == '?' || c == '.') {
			if (j != i) {
				M[text.substr(j, i - j)]++;
			}
			j= i + 1;
		}
	}
	if (j != i) {
		M[text.substr(j, i - 1)]++;
	}
	for (auto w : M) {
		pq.push({ w.second,w.first });
	}
	while (!pq.empty()) {
		cout << pq.top().s << " => " << pq.top().x << "\n";
		pq.pop();
	}
}
