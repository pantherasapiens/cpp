/*Implement recursive binary search and linear search and determine the time required to search
an element. Repeat the experiment for different values of n, the number of elements in the list
to be searched and plot a graph of the time taken versus n.*/
#include<iostream>
#include<string>
using namespace std;
class search{
	public:
    string n;
    string list[5] = {"ape","bull","cat","dog","elephant"};
    void run(){
    	cout << "Enter the element to search";
    	cin >> n;
	}
    bool poll(string n){
        for(int i=0;i<list.size();i++){
            if (n==list[i]){
                return true;
            }
        }
        return false;
    }
};
int main(){
    cout << "To find if the searched element exist in the given list.";
    search s1;
    if(s1.poll()){
        cout << "Element is available in the given list.";
    }
    else{
        cout << "Element is not available in the given list.";
    }
    return 0;
}
