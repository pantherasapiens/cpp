#include<iostream>
#include<string>
using namespace std;

class Search {
public:
    string list[5] = {"ape", "bull", "cat", "dog", "elephant"};

    // Linear search
    bool linearSearch(string element) {
        for (int i = 0; i < 5; i++) {
            if (list[i] == element) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Search s;

    bool linearResult = s.linearSearch("cat");

    cout << "Linear Search Result: " << (linearResult ? "Found" : "Not Found") << endl;

    return 0;
}

