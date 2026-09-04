#include <iostream>
using namespace std;
string a,b;
int n,m;

bool check(string a){
	for(int i=0; i<a.size(); i++){
		if(a[i] < '0' or a[i] > '9'){
			return false;
		}
	}
	return true;
}

bool check_value(string a){
	if(a.size() > 4) return false;
	return true;
}

int power(int a, int b){
	int res = 1; 
	for (int i=1; i<=b; i++){
		res *= a;
	}
	return res;
}

int sum_digits(int a){
	int res = 0;
	while(a!=0){
		res += a%10;
		a = a/10;
	}
	return res;
}

int main(){
	cin >> a >> b;
	if(!check(a)){
		cout << "Integer only and no negatives allowed!";
		return 0;
	}
	if(!check(b)){
		cout << "Integer only and no negatives allowed!";
		return 0;
	}
	if(!check(a)){
		cout << "value too large";
		return 0;
	}
	if(!check(b)){
		cout << "value too large";
		return 0;
	}
	n = stoi(a);
	m = stoi(b);
	cout << sum_digits(power(n,m));
 }
