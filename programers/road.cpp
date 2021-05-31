#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
vector<vector<int>> b_copy;
vector<vector<int>> visited;
int result;
int N;

int dfs(int x, int y, pair<int, int> save_dir)
{
	if (b_copy[x][y] == 1)
		return 0;
	if (x == N - 1 && y == N - 1)
		return 1;
	for (auto &i : dir)
	{
		int _x = x + i.first;
		int _y = y + i.second;
		if (_x < 0 || _y < 0 || _x >= N || _y >= N || b_copy[_x][_y] == 1 || visited[x][y] + 100 > visited[_x][_y])
			continue ;
		visited[_x][_y] = visited[x][y] + 100;
		if (save_dir != i)
		{
			visited[_x][_y] += 500;
		}
		if (dfs(_x, _y, i))
		{
			result = min(result, visited[_x][_y]);
		}
	}
	return 0;
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int r1, r2;
	N = board.size();
	b_copy = board;

	result = 20000;
	visited = vector(N, vector(N, 20000));
	visited[0][1] = 100;
	dfs(0, 1, { 0, 1 });
	for(auto &i : visited)
	{
		for (auto &j : i)
			cout << j << "\t\t\t";
		cout << endl;
	}
	r1 = result;
	cout << endl;
	result = 20000;
	visited = vector(N, vector(N, 20000));
	visited[1][0] = 100;
	dfs(1, 0, { 1, 0 });
	for(auto &i : visited)
	{
		for (auto &j : i)
			cout << j << "\t\t\t";
		cout << endl;
	}
	r2 = result;
	answer = min(r1,r2);


	cout << "answer : " << answer << endl;
	return answer;
}

int main()
{
	solution({
		{ 0, 0, 0},
		{ 1, 0, 1},
		{ 0, 0, 0}
	});
	// solution({
	// 	{ 0, 0, 0, 0, 0, 0, 0, 1 },
	// 	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	// 	{ 0, 0, 0, 0, 0, 1, 0, 0 },
	// 	{ 0, 0, 0, 0, 1, 0, 0, 0 },
	// 	{ 0, 0, 0, 1, 0, 0, 0, 1 },
	// 	{ 0, 0, 1, 0, 0, 0, 1, 0 },
	// 	{ 0, 1, 0, 0, 0, 1, 0, 0 },
	// 	{ 1, 0, 0, 0, 0, 0, 0, 0 }
	// });
	solution({
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 1 },
		{ 1, 0, 0, 0 }
		});
}
