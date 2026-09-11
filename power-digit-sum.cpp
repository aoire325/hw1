#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

bool check(string a) {
    if (a.empty()) return false;
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] < '0' || a[i] > '9') {
            return false;
        }
    }
    return true;
}

bool check_value(string a, string b) {
    int v = stoi(a);
    int l = stoi(b);
    double vkl = l * log10(v);
    double lim = 64 * log10(2);
    return vkl < lim;
}

unsigned long long power(unsigned int a, unsigned int b) {
    long long res = 1;
    for (int i = 1; i <= b; i++) {
        res *= a;
    }
    return res;
}

vector<int> vectorize_digits(unsigned long long a){
    vector<int> v;
    if (a == 0) return {0};
    while (a != 0) {
        v.push_back(a % 10);
        a = a / 10;
    }
    return v;
}

int sum_vector(vector<int> a) {
    int res = 0;
    for (size_t i = 0; i < a.size(); i++) {
        res += a[i];
    }
    return res;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
        cout << "Usage: ./pds <base> <exponent>\n";
        return 1;
    }
    
	string a,b;
    a = argv[1];
    b = argv[2];

	if(!check(a) or !check(b) or a.empty() or b.empty()){
		cout << "integer only";
		return 0;
	}
	
    if(a[0] == '-' or b[0] == '-'){
		cout << "value can not be negative";
		return 0;
	}
	
    if (!check_value(a, b)) {
        cout << "value too large";
        return 0;
    }
    
	unsigned int n,m;
    n = stoi(a);
    m = stoi(b);

    long long tmp = power(n, m);
    
    cout << a << "^" << b << " = " << tmp << endl;
    
    cout << "Sum Of Digits: " << sum_vector(vectorize_digits(tmp)) << endl;
    
    return 0;
	
}
