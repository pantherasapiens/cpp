#include <iostream>
#include <vector>

using namespace std;

// Function to find subsets with a given sum
void findSubsetsWithSum(vector<int>& S, vector<int>& subset, int index, int sum, int d) {
    if (sum == d) {
        // If the current subset has the desired sum, print it
        cout << "Solution: ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    if (index >= S.size() || sum > d) {
        return;  // Base case: stop if the index exceeds the size or the sum is greater than d
    }

    // Include the current element and recursively search
    subset.push_back(S[index]);
    findSubsetsWithSum(S, subset, index + 1, sum + S[index], d);

    // Exclude the current element and recursively search
    subset.pop_back();
    findSubsetsWithSum(S, subset, index + 1, sum, d);
}

int main() {
    vector<int> S = {1, 2, 5, 6, 8};
    int d = 9;

    vector<int> subset;
    findSubsetsWithSum(S, subset, 0, 0, d);

    if (subset.empty()) {
        cout << "No solution found." << endl;
    }

    return 0;
}
