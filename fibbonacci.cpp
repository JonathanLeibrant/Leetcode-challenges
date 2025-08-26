//Author: Jonathan Leibrant   Date: 8/25/2025
//Project: Create a function that generates the fibbonacci sequence and utilizes memoization
//Time: 2.8 hours. 
//Spent a significant period of time learning about maps, memoization, and keys. The size of the ints caused some bugs 
//and it took a minute to source them.

#include<iostream>
using namespace std;

#include<unordered_map>

long long fibbonaci(int n, unordered_map<int, long long>& map){

    if(n == 0) return 0;
    if(n == 1) return 1;

    if(auto it = map.find(n); it != map.end()) return it->second;
    else{
        long long value = fibbonaci(n - 1, map) + fibbonaci(n-2, map);
        map[n] = value;
        return value;
    }
}

int main(){
    unordered_map<int, long long> map;
    cout << "The 10th fibbonaci number is: " << fibbonaci(10, map) << endl;
    return 0;
}
