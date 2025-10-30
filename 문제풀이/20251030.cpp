//2025.10.30.
//15666. N과 M(12)

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int result[10];

void Func(int idx) {
	// base condition: 인덱스가 m일 경우
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
		// 결과 수열 출력
		return;
	}

	int prev = 0; // 이전 수 저장(초기값 0)
	for (int i = 0; i < n; i++) {
		// 만약 숫자가 이전 수와 같지 않고, 배열의 이전 인덱스의 수보다 크거나 같을 경우
		if (num[i] != prev && num[i] >= result[idx - 1]) {
			result[idx] = num[i]; // 수 삽입
			prev = num[i]; // prev 값 갱신
			Func(idx + 1); // 인덱스 1 증가한 함수
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n); // 수 오름차순 정렬

	Func(0); // 백트래킹 시작, 길이 인덱스 0
	return 0;
}
