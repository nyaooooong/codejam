#include <iostream>
#include <queue>
#include <cstring>

int N, M;
int len;
char str[101];
char map[100][100];

class StrP {
	int r;
	int c;
	int dr[8] = { 0, -1, -1, -1, 0, 1, 1,  1 };
	int dc[8] = {-1, -1,  0,  1, 1, 1, 0, -1 };

public :
	StrP(int tmpi, int tmpj) : r(tmpi), c(tmpj) {}
	StrP operator[] (int n) { return StrP(r + dr[n], c + dc[n]); }
	bool isValid() { if (r < 0 || c < 0 || r >= N || c >= M) return false; return true; }
	bool isMatch(int n) { if (map[r][c] == str[n]) return true; return false; }
};

std::queue<StrP> startQ;

static void getInput() 
{
    std::cin >> str;
	len = strlen(str);
    std::cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> map[i][j];
			if (map[i][j] == str[0])
				startQ.push(StrP(i, j));
        }
    }
}

int solve()
{
	int ret = 0;

	if (startQ.empty())
		return ret;

	while (!startQ.empty()) {
		StrP startP = startQ.front();
		startQ.pop();
		for (int i = 0; i < 8; i++) {
			bool find = true;
			StrP curP = startP[i];
			for (int j = 1; j < len; j++) {
				if (!curP.isValid()) { find = false; break; }
				if (!curP.isMatch(j)) { find = false; break; }
				curP = curP[i];
			}
			if (find) {
				ret = 1;
				break;
			}
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
 * End Time:2020-06-26 08:57:26 KST
 */
