/*
 * Start Time:2020. 07. 09. (목) 18:27:57 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>

int N;
int R[1000];
int C[1000];

template <class BidirectionalIterator>
bool next_partial_permutation(
		BidirectionalIterator first,
		BidirectionalIterator middle,
		BidirectionalIterator last)
{
	std::cout << "reverse " << *middle << " to " << *last << std::endl;
	std::reverse(middle, last);
	return std::next_permutation(first, last);
}

void getInput()
{
	std::cin >> N;
	/*
	for (int i = 0; i < N; i++) {
		std::cin >> R[i] >> C[i];
	}
	*/
}

int solve(int n)
{
	int max = 0;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(i);

//	int x = 1;
	do {
		bool valid = true;
		int tmp = 0;
		/* for log
		std::cout << '[' << x++ << ']';
		for (int i = 0; i < n; i++) {
			std::cout << v[i] << ' ';
		}
		std::cout << ':'; */
		// for cal
		tmp = R[v[0]] * C[v[n-1]];
		if (max < tmp) {
			for (int i = 1; i < n; i++) {
				if (C[v[i-1]] != R[v[i]]) {
					valid = false;
					break;
				}
			}
			if (valid)
				max = tmp;
		}
		/*
		std::cout << '(';
		for (int i = 0; i < N; i++) {
			std::cout << v[i] << ' ';
		}
		std::cout << ')';
		*/

		//std::cout << tmp << std::endl;
	} while (next_permutation(v.begin(), v.end()));
//	} while (next_partial_permutation(v.begin(), v.begin() +n, v.end()));

	return max;
}

int permutation(std::vector<int>&v, int i, int n, int m)
{
	int j, tmp;
	if (i == m) {
		for (j=0; j<=n; j++) std::cout << v[j] << ' ';
		std::cout << std::endl;
		return 0;
	}
	for (j = i; j <= n; j++) {
		int tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
		permutation(v, i+1, n, m);
		tmp = v[i];
		v[i] = v[j];
		v[j] = tmp;
	}
	return 0;
}

int solve2(int n)
{
	for (int i = 0; i < n; i++) {
	}

	return 0;
}

int main()
{
	getInput();

	std::vector<int> v;
	for (int i = 0; i < N; i++)
		v.push_back(i);


//	for (int i = 1; i <= N; i++) {
		permutation(v, 0, N-1, 3);
//		std::cout << solve2(i) << std::endl;
//	}

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */
