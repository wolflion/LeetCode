#include "test.h"

class UF {
public:
	string find(string word, bool create = false) {
		if (!parents.count(word)) {
			if (!create)
				return word;
			return parents[word] = word; //lionel，不是太懂这个
		}

		string w = word;
		while (w != parents[w]) {
			parents[w] = parents[parents[w]];
			w = parents[w];
		}
		return parents[w];
	}

	bool merge(string s1, string s2) {
		string p1 = find(s1,true);  //lionel，忘记写这个
		string p2 = find(s2,true);

		if (p1 == p2)
			return false;
		parents[p1] = p2;
		return true;
	}
private:
	unordered_map<string, string> parents;
};

void od_a06() {
	UF a;

	vector<pair<string, string>> inputs{ {"a1","a2"},{"a5","a6"},{"a2","a3"} };
	for (auto c : inputs) {
		a.merge(c.first, c.second);
	}

	vector<string> found{ "a5","a2" };
	for (auto c : found) {
		cout << a.find(c) << endl;
	}
}