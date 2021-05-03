#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(std::vector<int> a, std::vector<int> b)
{
	return (a[0] < b[0]);
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
	int right;

	std::sort(routes.begin(), routes.end());
	for(size_t i = 0 ; i < routes.size() ; ++i)
		std::cout << routes[i][0] << ", " << routes[i][1] << '\n';
	right = 30001;
	for(size_t i = 0 ; i < routes.size() ; ++i)
	{
		if (routes[i][0] > right)
		{
			++answer;
			right = routes[i][1];
		}
		else
			right = std::min(right, routes[i][1]);
	}
    return answer + 1;
}

int main()
{
	solution({{-20,15}, {-14,-5}, {-18,-13}, {-5,-3}});
}
