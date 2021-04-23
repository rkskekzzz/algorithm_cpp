#include <iostream>
#include <queue>

int N, K;
std::queue<int> yos;
std::vector<int> res;
void output()
{
	std::cout << "<";
	for(auto& i : res)
	{
		std::cout << i;
		if (i == res[N - 1])
			break;
		std::cout << ", ";
	}
	std::cout << ">";
}

void solution()
{
	int tmp;

	while(!yos.empty())
	{
		for(int i = 0 ; i < K - 1 ; ++i)
		{
			tmp = yos.front();
			yos.pop();
			yos.push(tmp);
		}
		res.push_back(yos.front());
		yos.pop();
	}
}

void input()
{
	std::cin >> N >> K;
	for (int i = 1 ; i <= N ; ++i)
		yos.push(i);
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
