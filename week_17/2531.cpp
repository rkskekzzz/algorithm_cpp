#include <iostream>
#include <vector>

int N, d, k, c, result;
std::vector<int> chqkq;
std::vector<int> ajrdma;

void output()
{
	std::cout << result;
}

void solution()
{
	for (int left = 0; left < N ; ++left)
	{
		int cnt = 0;
		std::fill(ajrdma.begin(), ajrdma.end(), 0);
		for (int right = left; std::abs(right - left) < k ; ++right)
		{
			if (!ajrdma[chqkq[(right % N)]])
			{
				++cnt;
				ajrdma[chqkq[(right % N)]] = 1;
			}
		}
		if (ajrdma[c] == 0)
			++cnt;
		result = std::max(result, cnt);
	}
}

void input()
{
	int n;

	std::cin >> N >> d >> k >> c;
	ajrdma.resize(d + 1);
	for(int i = 0 ; i < N ; ++i)
	{
		std::cin >> n;
		chqkq.push_back(n);
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
