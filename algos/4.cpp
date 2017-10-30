#include <iostream>
#include <map>
#include <vector>
using namespace std;


	vector<pair<int, int> > briges;
	map<int, vector<int> > graph;
	int numberOfCC;
//удалить этот элемент из векторов других элементов
	void removeVertex(int a) {
		map<int, vector<int> >::iterator it;
		for (it = graph.begin(); it != graph.end(); it++) {
			for (int i = 0; i < (*it).second.size(); i++) {
				if ((*it).second[i] == a) (*it).second.erase((*it).second.begin() + i);
			}
		}
	}
//удалять те элементы у кого лишь один сосед
	void brigeFind() {
		map<int, vector<int> >::iterator it;
		numberOfCC = 1;
		for (it = graph.begin(); it != graph.end(); it++) {
			if ((*it).second.size() == 1) {
				briges.push_back(make_pair((*it).first, (*it).second[0]));
				graph.erase(it);
				removeVertex((*it).first);
				numberOfCC++;
			}
		}
		while (numberOfCC != 1)
			brigeFind();
	}





	int main() {
		freopen("input.txt", "r", stdin);
		int n, m;
		cin >> n >> m;
		int f, s;

		for (int i = 1; i <= m; i++) {
			cin >> f >> s;
			if (n - m == 1) cout << f << " " << s << endl;
			else {
				graph[f].push_back(s);
				graph[s].push_back(f);
			}
		}




		map<int, vector<int> >::iterator it;

		brigeFind();

		for (int i = 0; i < briges.size(); i++) {
			cout << briges[i].first << " " << briges[i].second << endl;
		}

		return 0;
	}
