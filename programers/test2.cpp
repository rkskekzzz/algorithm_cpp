#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<int, int>> dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
vector<string> tmp;
vector<vector<int>> visited;

bool dfs(int x, int y, int depth)
{
    visited[x][y] = 1;
	
    cout << x << ", " << y << endl;
	for (auto &k : dir)
	{
		int _x = k.first + x;
		int _y = k.second + y;
        if (_x < 0 || _y < 0 || _x >= 5 || _y >= 5 || visited[_x][_y] || tmp[_x][_y] == 'X' || depth == 2)
		    continue;
		if (tmp[_x][_y] == 'P' || dfs(_x, _y, depth + 1))
			return true;
	}
	return false;
}

vector<int> solution(vector<vector<string>> places)
{
	vector<int> answer;
	visited = vector(5, vector(5, 0));
	answer = vector(5, 1);
	for (size_t i = 0; i < places.size(); ++i)
	{
		for (size_t j = 0; j < places[i].size(); ++j)
		{
			for (size_t k = 0; k < places[i][j].size(); ++k)
			{
				if (places[i][j][k] == 'P')
				{
                    tmp = places[i];
                    visited = vector(5, vector(5, 0));
					if (dfs(j, k, 0))
                    {
                        answer[i] = 0;
                        break;
                    }
				}
			}
		}
	}
	return answer;
}

int main()
{
	solution({ { "POOOP",
			 	 "OXXOX",
			     "OPXPX",
				 "OOXOX",
				 "POXXP" },
			   { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" },
			   { "PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX" },
			   { "OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO" },
			   { "PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } });
}
