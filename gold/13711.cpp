#include <iostream>
#include <vector>

int N;
std::vector<int> up;
std::vector<int> down;
int max;
int idx;
int cnt;
int tmp;
void output()
{
	std::cout << max;
}

void solution()
{
	int j;

	for (int k = 0; k < N; k++)
	{
		if (max > (N >> 1))
			break;
		for (int i = k; i < N; i++)
		{
			for (j = tmp; j < N; j++)
			{
				if (down[i] == up[j])
				{
					// std::cout << "같다 !! " << down[i] << std::endl;
					++cnt;
					tmp = j;
					break;
				}
			}
		}
		// std::cout << "cnt : " << cnt << std::endl;
		max = std::max(cnt, max);
		tmp = 0;
		cnt = 0;
	}
}

void input()
{
	std::cin >> N;
	up.resize(N);
	down.resize(N);
	for (int i = 0; i < N; i++)
		std::cin >> up[i];
	for (int i = 0; i < N; i++)
		std::cin >> down[i];
	// std::cout << "test\n";
	// for (int i = 0 ; i < N ; i++)
	// 	std::cout << up[i] << " ";
	// std::cout << '\n';
	// for (int i = 0 ; i < N ; i++)
	// 	std::cout << down[i] << " ";
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

/*
test case
5
1 3 2 4 5
3 4 1 2 5


*/
