#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i].first;
		nums[i].second = i;
	}
	sort(nums.begin(), nums.end());
	int l = 0, r = n - 1;
	while (l < r) {
		int sum = nums[l].first + nums[r].first;
		if (sum == x) {
			cout << nums[l].second + 1 << " " << nums[r].second + 1 << endl;
			return 0;
		} else if (sum < x) {
			l++;
		} else if (sum > x) {
			r--;
		}
	}
	if (l == r) { cout << "IMPOSSIBLE" << endl; }
}