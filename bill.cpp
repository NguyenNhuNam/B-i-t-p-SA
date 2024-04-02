#include <bits/stdc++.h>
using namespace std;

int unit[11] = {100, 100, 125, 100, 350, 200, 125, 1000, 1000, 1000};
int numbers[11] = {2, 3, 4, 5, 2, 4, 8, 2, 3, 11};
int a[1001], cnt = 0;
int bill_1 = 1000, bill_2 = 7000, bill_3 = 12000;
vector < int > ans_1, ans_2, ans_3;

void backtrack(int k, int x, int y, int z) {
	if(k == 0) {
		return ;
	}
	
	if(x < a[k] && y < a[k] && z < a[k]) {
		backtrack(k - 1, x, y, z);
	}
	
	if(x >= a[k]) {
		ans_1.push_back(a[k]);
		backtrack(k - 1, x - a[k], y, z);
	}
	else if(y >= a[k]) {
		ans_2.push_back(a[k]);
		backtrack(k - 1, x, y - a[k], z);
	}
	else if(z >= a[k]) {
		ans_3.push_back(a[k]);
		backtrack(k - 1, x, y, z - a[k]);
	}
}
	
int main() {
	// Mảng a chứa danh sách thành tiền của từng món
	for(int i = 0; i < 10; i++) {
		for(int j = 1; j <= numbers[i]; j++) {
			a[++cnt] = unit[i];
		}
	}
	
	// Sắp sắp tăng dần mảng a
	sort(a + 1, a + 1 + cnt);
	
	// Thực hiện đệ quy thêm từng món án từ lớn nhất trong mảng a vào từng bill cũng sắp xếp từ lớn đến nhỏ
	// Thêm đến khi còn thỏa mãn giá của món nhỏ tổng giá của bill hiện tại
	backtrack(cnt, bill_3, bill_2, bill_1);
	
	for(int i = 0 ; i < ans_1.size(); i++) {
		cout << ans_1[i] << " ";
	}
	cout << endl;
	
	for(int i = 0 ; i < ans_2.size(); i++) {
		cout << ans_2[i] << " ";
	}
	cout << endl;
	
	for(int i = 0 ; i < ans_3.size(); i++) {
		cout << ans_3[i] << " ";
	}
	cout << endl;
}
