#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
vector<int> trap_cp;
queue<int> que;

void printmap(vector<vector<int>> map)
{
	for(auto& i : map)
    {
        for(auto& j : i)
            cout << j << " ";
        cout << endl;
    }
	cout << "**************************\n";
}

vector<vector<int>> init(int n, vector<vector<int>> roads)
{
	vector<vector<int>> map = vector(n + 1, vector(n + 1, 3001));
    for(size_t i = 0 ; i < roads.size() ; ++i)
    {
        if(map[roads[i][0]][roads[i][1]] > roads[i][2])
			map[roads[i][0]][roads[i][1]] = roads[i][2];
    }
	return map;
}

vector<vector<int>> flip(int i, vector<vector<int>> map)
{
	vector<vector<int>> out = map;
	for(size_t j = 0 ; j < out.size() ; ++j)
	{
		swap(out[i][j], out[j][i]);
	}
	return out;
}

int dfs(int idx, int end, vector<vector<int>> visited, int cost, vector<vector<int>> map)
{
	int answer;

	answer = 9999999;
	if(idx == end)
	{
		return cost;
	}
	if (find(trap_cp.begin(), trap_cp.end(), idx) != trap_cp.end())
	{
		map = flip(idx, map);
	}
	for(size_t i = 1 ; i < map.size() ; ++i)
	{
		if(map[idx][i] != 3001 && !visited[idx][i])
		{
 			visited[idx][i] = 1;
			answer = min(answer, dfs(i, end, visited, map[idx][i] + cost, map));
			visited[idx][i] = 0;
		}
	}
	return answer;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
	vector<vector<int>> visited = vector(n + 1, vector(n + 1, 0));
	vector<vector<int>> map;
	trap_cp = traps;
	map = init(n, roads);
	answer = dfs(start, end, visited, 0, map);
	cout << "answer : " << answer << endl;
	return answer;
}

int main()
{
	solution(3,	1,	3,	{{1, 2, 2}, {3, 2, 3}},	{2});
	// solution(4,	1,	4,	{{1, 2, 1}, {3, 2, 1}, {2, 4, 1}},	{2, 3});
}

// auto it = find(v.begin(), v.end(), num);
//     if (it == v.end()) {
//         cout << num << "은 찾을 수 없습니다.\n";
//     }
