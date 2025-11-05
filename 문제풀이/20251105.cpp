// 2025.11.05
// 백준 1932. 정수 삼각형

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int tri[502][502]; // 입력 삼각형 값 저장
int d[502][502]; // dp 배열: 각 위치까지 올 수 있는 최대 합

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j]; // 삼각형 입력
		}
	}

	// 첫 번째 줄 초기화
	d[1][1] = tri[1][1];

	// 각 줄의 가장 왼쪽, 오른쪽은 경로가 하나뿐이므로 별도 처리
	for (int i = 2; i <= n; i++) {
		d[i][1] = d[i - 1][1] + tri[i][1]; // 맨 왼쪽
		d[i][i] = d[i - 1][i - 1] + tri[i][i]; // 맨 오른쪽
	}

	// 내부 원소 처리: 위 두 칸 중 더 큰 값을 선택
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= i - 1; j++) {
			d[i][j] = tri[i][j] + max(d[i - 1][j - 1], d[i - 1][j]);
		}
	}

	// 마지막 줄에서 최대값 찾기
	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, d[n][i]);
	}

	cout << result;
	return 0;
}
