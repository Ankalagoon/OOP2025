#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>
using namespace std;

ifstream fin("input.txt");

class Comp 
{
public:
	bool operator() (const pair<int,string>& x, const pair<int, string>& y)const {
		if (x.first == y.first) return x.second > y.second;
		return x.first < y.first;
	}
	
};



int main() {
	map<string,int> M;
	priority_queue<pair<int,string>,vector<pair<int, string>>,Comp> pq;
	int i, j;
	char c;
	string text;
	getline(fin, text);
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
		cout << pq.top().second << " => " << pq.top().first << "\n";
		pq.pop();
	}
}
