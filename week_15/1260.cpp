#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, V, k;
std::vector<bool> visited;
std::queue<int> que;
std::vector<std::pair<int, int> > rt;

bool comp2(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.first < b.first)
		return (true);
	return (false);
}

bool comp(std::pair<int, int> a, std::pair<int, int> b)
{
	if (a.first < b.first)
		return (true);
	if (a.first == b.first && a.second < b.second)
		return (true);
	return (false);
}

void bfs(int idx)
{
	que.push(idx);
	visited[idx] = 1;
	while(!que.empty())
	{
		idx = que.front();
		que.pop();
		std::cout << idx << " ";
		for(auto i = std::lower_bound(rt.begin(), rt.end(), std::pair(idx, 0), comp2) ; i != std::upper_bound(rt.begin(), rt.end(), std::pair(idx, 0), comp2) ; ++i)
		{
			if (!visited[(*i).second])
			{
				que.push((*i).second);
				visited[(*i).second] = 1;
			}
		}
	}
}

void dfs(int idx)
{
	if (idx < 0 || idx > N || visited[idx])
		return;
	visited[idx] = 1;
	std::cout << idx << " ";
	for(auto i = std::lower_bound(rt.begin(), rt.end(), std::pair(idx, 0), comp2) ; i != std::upper_bound(rt.begin(), rt.end(), std::pair(idx, 0), comp2) ; ++i)
		dfs((*i).second);
}

void solution()
{
	dfs(V);
	std::fill(visited.begin(), visited.end(), 0);
	std::cout << std::endl;
	bfs(V);
}



void input()
{
	int from, to;

	std::cin >> N >> M >> V;
	visited.resize(N + 1);
	for(int i = 0 ; i < M ; ++i)
	{
		std::cin >> from >> to;
		rt.push_back({from, to});
		rt.push_back({to, from});
	}
	std::sort(rt.begin(), rt.end(), comp);
}

void preset()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

int main()
{
	preset();
	input();
	solution();
}
