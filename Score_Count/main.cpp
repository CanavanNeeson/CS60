#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

typedef map<int, pair<int, vector<string>>> mapType;

void readScores(istream&, mapType&);
void printHist(ostream&, const mapType&);
void printUsers(int, mapType&);

int main() {
	ifstream in("scores.txt");
	if (in.fail()) {
		std::cout << "Error opening score file.\n";
		exit(1);
	}

	mapType scores;
	readScores(in, scores);
	printHist(std::cout, scores);
	printUsers(10, scores);

// 	std::cout << scores.size();

	in.close();
	return 0;
}

void readScores(istream& in, mapType& scoreMap) {
	int score;
	string name;
	while (in >> score && getline(in, name)) {
		scoreMap[score].first++;
		scoreMap[score].second.push_back(name);
	}
	for (int i = 0; i < scoreMap.size(); i++) {
		if (scoreMap[i].first == 0) {
			scoreMap[i].second = vector<string>(0);
		}
	}
}

void printHist(ostream& out, const mapType& scoreMap) {
	for (auto e:scoreMap) {
		out << e.first << '\t';
		for (int i = 0; i < e.second.first; i++)
			out << 'x';
		out << '\n';
	}
}

void printUsers(int score, mapType& scoreMap) {
	for (auto i:scoreMap[score].second) {
		std::cout << i << ", ";
	}
	std::cout << "\b\b  \n";
}
