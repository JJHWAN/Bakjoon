#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES

#include <utility>
#include <cmath>.
#include <algorithm>
#include <math.h>

using namespace std;
vector <pair<double, double>> v;

double A, B, C;

void swap() {

	double tmp;
	int i;
	for (i = 0; i < 3; i++) {
		tmp = v[i].first;
		v[i].first = v[i].second;
		v[i].second = tmp;
	}
}

void get_func(pair<double, double> a, pair<double, double> b) {

	double x1 = a.first, y1 = a.second;
	double x2 = b.first, y2 = b.second;

	A = y2 - y1;
	B = x2 - x1;
	C = x1 - (x2 - x1) * y1;

}

double predict_y(double x) {
	if (!B) return -1;
	return -1 * (A * x + C) / (B);
}

bool cmp(pair<double, double> a, pair<double, double> b) {
	return a.first < b.first;
}

double get_volume(pair<double, double> start, pair<double, double> end) {
	
	double a, b, x;
	if (start.second == end.second) {
		a = pow(start.second, 2);
		b = pow(end.second, 2);
		return abs(a - b) * M_PI;
	}
	else {
		x = (start.first - end.first) / (start.second - end.second);
		a = pow(start.second, 3) * x;
		b = pow(end.second, 3) * x;
		return abs(a - b) * M_PI / 3.0;
	}
	
}

void solve() {

	int i, max_idx = 0;

	sort(v.begin(), v.end(), cmp);
	for (i = 0; i < 3; i++) {
		if (v[i].second > v[max_idx].second) {
			max_idx = i;
		}
	}

	double v1, v2, v3, result;

	switch (max_idx) {
	case 0:

		v1 = get_volume(v[max_idx], v[2]);
		v2 = get_volume(v[max_idx], v[1]);
		v3 = get_volume(v[1], v[2]);

		get_func(v[max_idx], v[2]);
		if (predict_y(v[1].first) > v[1].second)
			result = abs(v2 + v3 - v1);
		else
			result = v1 - v2 - v3;
		
		break;
	case 1:
		v1 = get_volume(v[max_idx], v[0]);
		v2 = get_volume(v[max_idx], v[2]);
		v3 = get_volume(v[0], v[2]);
		result = v1 + v2 - v3;
		break;
	case 2:
		v1 = get_volume(v[max_idx], v[0]);
		v2 = get_volume(v[max_idx], v[1]);
		v3 = get_volume(v[0], v[1]);

		get_func(v[0], v[max_idx]);
		if (v[1].second > predict_y(v[1].first))
			result = abs(v2 + v3 - v1);
		else 
			result = v1 - v2 - v3;
		break;
	}

	cout << result << " ";

}

int main(void) {

	double x, y;
	int i;
	for (i = 0; i < 3; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	cout << fixed;
	cout.precision(9);
	solve();
	swap();
	solve();

	return 0;
}