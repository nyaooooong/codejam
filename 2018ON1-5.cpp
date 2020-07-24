/*
 * Start Time:2020. 07. 02. (목) 15:20:22 KST
 */
#include <iostream>
#include <cstring>
#include <climits>
#include <map>
#include <set>
#include <list>

int N;
int H[100000];
std::map<int, int> hCount;
std::map<int, int>::iterator cntItor;

std::list<int> hList;

std::map<int, std::set<int>> hMap;
std::map<int, std::set<int>>::iterator mapItor;

void hMapInsert(int height, int position)
{
	std::set<int> iSet;
	iSet.insert(position);
	auto ret = hMap.insert(std::pair<int, std::set<int>>(height, iSet));
	if (!ret.second) {
		ret.first->second.insert(position);
	}	
}

void hCountInsert(int n)
{
	auto ret = hCount.insert(std::pair<int, int>(n, 1));
	if (!ret.second) {
		ret.first->second++;
	}
}

void getInput()
{
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;

		H[i] = tmp;

		hList.push_back(tmp);
		hMapInsert(tmp, i+1);
		hCountInsert(tmp);
	}
}

void getDirection()
{
	std::map<int, std::set<int>>::iterator itor;
	while (itor != hMap.end()) {
		std::set<int> iSet = itor->second;
		std::set<int>::iterator  
	}

}

void getOutput() 
{
	std::map<int, std::set<int>>::iterator itor1 = hMap.begin();
	while (itor1 != hMap.end()) {
		std::cout << std::endl << itor1->first << ']';
		std::set<int> iSet = itor1->second;
		std::set<int>::iterator itor2 = iSet.begin();
		while (itor2 != iSet.end()) {
			std::cout << *itor2 << ' ';
			itor2++;
		}
		itor1++;
	}

	std::map<int, int>::iterator itor3 = hCount.begin();
	while (itor3 != hCount.end()) {
		std::cout << itor3->first << ',' << itor3->second << std::endl;
		itor3++;
	}
}


int solve()
{
	int ret = 0;
	std::list<int>::iterator pCurP = hList.begin();
	std::map<int, int>::iterator pCurH = hCount.begin();

	while (!hList.empty()) {
		int curH = pCurH->first;
		int moveCnt = 0;
		std::cout << "Begin " << pCurH->first << "(" << pCurH->second << ")" << std::endl;
		while (1) {
			ret++;
			if (*(pCurP + moveCnt) == curH) {
				pCurP = hList.erase(pCurP + moveCnt);
				pCurH->second--;
				break;
			}
			else if (*(pCurP - moveCnt) == curH) {
				pCurP = hList.erase(pCurP - moveCnt);
				pCurH->second--;
				break;
			}
			moveCnt++;
		}
		if (!pCurH->second) {
			pCurH++;
		}
	}
	
	return ret;
}

int main()
{
	getInput();

	int ret = solve();

	std::cout << ret << std::endl;

	return 0;
}
/*
 * End Time: from LGE CodeJam site
 */
