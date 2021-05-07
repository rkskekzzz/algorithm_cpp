#include <iostream>
#include <vector>

int n, result;
std::vector<std::vector<int > > paper;
std::vector<std::pair<int, int> > torwhddl;


void output()
{
	for(auto &i : paper)
		for(auto &j : i)
			if(j)
				++result;
	std::cout << result;
}

void solution()
{
	for(auto &i : torwhddl)
		for (auto x = i.first ; x < i.first + 10 ; ++x)
			for (auto y = i.second ; y < i.second + 10 ; ++y)
				paper[x][y] = 1;
}

void input()
{
	std::cin >> n;
	torwhddl.resize(n);
	for(auto& i: torwhddl)
		std::cin >> i.first >> i.second;
	paper = std::vector(100, std::vector(100, 0));
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
