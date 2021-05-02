#include <algorithm>
#include <iostream>
#include <vector>

int T, N;
std::vector<std::pair<int, int>> tcase;
std::vector<int> result;

void output()
{
	for(auto& i : result)
		std::cout << i << '\n';
}

bool comp(std::pair<int, int> &a, std::pair<int, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

void solution()
{
	auto cnt = N, m = N;

	std::sort(tcase.begin(), tcase.end(), comp);
	for (int i = 1; i < N; ++i)
	{
		m = std::min(m, tcase[i - 1].second);
		if (m < tcase[i].second)
			--cnt;
	}
	result.push_back(cnt);
}

void input()
{
	std::cin >> T;
	while (T--)
	{
		std::cin >> N;
		tcase = std::vector(N, std::pair<int, int>());
		for (auto &i : tcase)
			std::cin >> i.first >> i.second;
		solution();
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
	output();
}
