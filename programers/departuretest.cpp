#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	long long left = 0, right = n * (long long)*max_element(times.begin(), times.end());

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (size_t i  = 0 ; i < times.size() ; ++i)
			sum += mid / times[i];
		if (sum >= n)
			right = mid - 1;
		else
			left = mid + 1;
	}
	answer = left;
	std::cout << answer;
	return answer;
}


int main()
{
	int N;

	std::cin >> N;
	std::vector<int> t = {1000000000, 1, 1};
	solution(N, t);
}
