#include <iostream>
using namespace std;

int n;
int skill[20][20];
int teamA[10];
int teamB[10];
int submin=10000;
bool teamSelected[20] = {};

int getskillSub() {
	int teamAscore = 0;
	int teamBscore = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = i + 1; j < n / 2; j++) {
			teamAscore += skill[teamA[i]][teamA[j]];
			teamAscore += skill[teamA[j]][teamA[i]];
		}
	}for (int i = 0; i < n / 2; i++) {
		for (int j = i + 1; j < n / 2; j++) {
			teamBscore += skill[teamB[i]][teamB[j]];
			teamBscore += skill[teamB[j]][teamB[i]];
		}
	}
	return abs(teamAscore - teamBscore);
}

void makeTeam(int depth,int lastindex) {
	if (depth == n / 2) {
		for (int i = 0,idx = 0; i < n; i++) {
			if (!teamSelected[i])
				teamB[idx++] = i;
		}
		submin = min(submin, getskillSub());
		return;
	}
	for (int i = lastindex; i < n; i++) {
		if (teamSelected[i]) continue;
		teamA[depth] = i;
		teamSelected[i] = true;
		makeTeam(depth + 1, i);
		teamSelected[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> skill[i][j];
		}
	}
	makeTeam(0, 0);
	cout << submin;
}