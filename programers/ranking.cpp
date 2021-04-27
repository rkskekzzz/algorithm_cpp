#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

std::vector<std::vector<int> > map;
std::vector<int> visited;
int n;


int cntwin(int idx)
{
	int win =0;
	visited[idx] = 1;

	for(int i = 1 ; i <= n ; ++i)
	{
		if(map[idx][i] == 2 && visited[i] != 1)
		{
			win += cntwin(i) + 1;
		}
	}
	return win;
}

int cntlose(int idx)
{
	visited[idx] = 1;
	int lose = 0;

	for(int i = 1 ; i <= n ; ++i)
	{
		if(map[idx][i] == 1 && visited[i] != 1)
		{
			lose += cntlose(i) + 1;
		}
	}
	return lose;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

	map = std::vector(n + 1, std::vector(n + 1, 0));
	visited = std::vector(n + 1, 0);
	for(auto& i : results)
	{
		map[i[0]][i[1]] = 2;
		map[i[1]][i[0]] = 1;
	}

	for(int i = 1 ; i <= n ; ++i)
	{
		visited = std::vector(n + 1, 0);
		//cout << lose << ", " <<win <<endl;
		if(cntwin(i) + cntlose(i) == n - 1)
			++answer;
	}
	return answer;
}

int main()
{
	std::cin >> n;
	std::cout << "result : " << solution(n, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}});
}
