#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i;
    double d;
    string s;
    cin >> i;
    cin >> d;
    cin.ignore();
    getline(cin,s);
    int intsum = i+4;
    double doublesum= d+4.0;
    cout << intsum << endl; 
    cout << fixed << setprecision(1) << doublesum << endl;
    cout << "HackerRank "+s;
    return 0;
}

