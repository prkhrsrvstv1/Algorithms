#include<bits/stdc++.h>
using namespace std;

/*

	num1 = a*10^(n/2) + b
	num2 = c*10^(n/2) + d
	num1 * num2 = ac*10^n + (ad + bc)*10^(n/2) + bd

	ad + bc = ad + bc + ac + bd - (ac + bd)
					= (a + b) * (c + d) - (ac + bd)
					= tmp - ac - bd
*/

int join(int n1, int n2, int n3, int n) {
	// cout << "join(" << n1 << ", " << n2 << ", " << n3 << ") called\n";
	string _n1 = to_string(n1), _n2 = to_string(n2), _n3 = to_string(n3);
	for(int i = 0; i < n/2; ++i)
		_n2 += "0";
	for(int i = 0; i < n; ++i)
		_n1 += "0";
	// cout << "returning " << stoi(_n1) + stoi(_n2) + stoi(_n3) << "\n";
	return stoi(_n1) + stoi(_n2) + stoi(_n3);
}

int karastuba(int num1, int num2) {
	// cout << "karastuba(" << num1 << ", " << num2  << ") called\n";
	string _num1 = to_string(num1), _num2 = to_string(num2);
	if(_num1.length() != _num2.length()) {
		while(_num1.length() < _num2.length())
			_num1 = "0" + _num1;
		while(_num2.length() < _num1.length())
			_num2 = "0" + _num2;
	}
	int n = _num1.length();
	if(n % 2) {
		_num1 = "0" + _num1;
		_num2 = "0" + _num2;
		++n;
	}
	// cout << "After padding 0s : " << _num1 << ", " << _num2 << "\n";
	if(n <= 2) {
		// cout << "returning " << num1 * num2 << "\n";
		return num1 * num2;
	}
	int a = stoi(_num1.substr(0, n/2));
	int b = stoi(_num1.substr(n/2, n-n/2));
	int c = stoi(_num2.substr(0, n/2));
	int d = stoi(_num2.substr(n/2, n-n/2));
	// cout << "After splitting :\n";
	// cout << a << " " << b << "\n";
	// cout << c << " " << d << "\n";
	int ac = karastuba(a, c);
	int bd = karastuba(b, d);
	int tmp = karastuba(a+b, c+d);
	int ad_p_bc = tmp - ac - bd;
	int ans = join(ac, ad_p_bc, bd, n);
	// cout << "returning " << ans << "\n";
	return ans;
}

int main() {
	int num1 = 25548, num2 = 32258;
	cout << num1 << " * " << num2 << " = " << karastuba(num1, num2) << "\n";
	return 0;
}
