emotional coding
6021

파일명이랑 똑같은 클래스만 public을 가질 수 있다.

람다는 인터페이스만


프라이빗 인스턴스 만들고
생성자 막아놓고
인스턴스 받아갈 수 있는 함수 생성


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int column, row;
int maxHour = INT_MIN;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

typedef struct {
	int startX;
	int startY;
	vector<vector<int>> map;
} Info;

//typedef struct {
//	int startX;
//	int startY;
//	int endX;
//	int endY;
//} Pos;

int dfs(Info info, int hour = 0) {

}

int solution(vector<vector<int>>& map) {
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < row; j++) {
			Info info;
			int hour;

			if (map[i][j] == 0)
				continue;

			info.startY = i;
			info.startX = j;
			copy(map.begin(), map.end(), info.map.begin());
			info.map[i][j] = -1;
			hour = dfs(info);
			if (hour < maxHour)
				maxHour = hour;
		}
	}
	return (maxHour);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> column >> row;

	vector<vector<int>> map(column, vector<int>(row));
	for (int i = 0; i < column; i++)
		for (int j = 0; j < row; j++) {
			char tmp;

			cin >> tmp;
			if (tmp == 'W')
				map[i][j] = 0;
			else if (tmp == 'L')
				map[i][j] = 1;
		}
	
	cout << solution(map);
}
