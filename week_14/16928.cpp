#include <iostream>
#include <vector>
#include <queue>
#include <map>

int cnt_ladder, cnt_snake;
std::map<int, int> ladder_snake;
std::queue<int> que;
std::vector<int> visited;


void output()
{
	std::cout << visited[100] - 1;
}

void bfs()
{
	que.push(1);
	visited[1] = 1;
	while (!que.empty())
	{
		int val = que.front();
		que.pop();
		for (int i = 1 ; i <= 6 ; i++)
		{
			int next = val + i;
			if (!visited[next] && !visited[100])
			{
				visited[next] = visited[val] + 1;
				// std::cout << "next : " << next << ", visited : " << visited[next] << std::endl;
				if (ladder_snake[next] > 0)
				{
					int mv_next = ladder_snake[next];
					if (!visited[mv_next])
					{
						visited[mv_next] = visited[next];
						que.push(mv_next);
					}
					continue ;
				}
				que.push(next);
			}
		}
	}
}

void solution()
{
	bfs();
}

void input()
{
	int from, to;

	std::cin >> cnt_ladder >> cnt_snake;
	visited.resize(101);
	for (int i = 0 ; i < cnt_ladder + cnt_snake ; ++i)
	{
		std::cin >> from >> to;
		ladder_snake.insert(std::pair<int, int>(from, to));
	}
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
	output();
}
