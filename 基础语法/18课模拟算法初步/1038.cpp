#include<bits/stdc++.h>
using namespace std;

bool f[15];
int main() {
	int an = 0;
	for (int i = 1; i <= 1000; i++) {
		an += i;
        an--;
		an %= 10;
        //cout<<an<<" ";
		f[an] = 1;
	}
	for (int i = 0; i <10; i++) {
		if(!f[i]) cout << i+1 << " ";
	}
	return 0;
}