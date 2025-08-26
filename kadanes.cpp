//Author: Jonathan Leibrant     Date: 8/26/2025
//Total Time: Approximately 9.5 hours
//Project: Solve the Maximum SubArray problem--develop a Sum of Subarray's map to minimize calculation. 
/*
In trying to solve this problem, I began by writing down facts about an array and attempting to understand the mathematical 
underpinnings of the optimal solution. Hashmaps, binary search trees, arrays of sums, and brute force 
methods were all considered, but after designing a useful subalgorithm, I opted for a recursive approach

I had the idea that a hashmap would reduce the total computations, and 
with the idea in mind that I might need to request S(a to b) repeatedly, I built a function that finds the sum of the
interval and stores it in a hashmap. In the process of doing this it will leverage similar interval calculations and store 
all results in the map. This overall greatly minimizes the amount of calculations necessary to sum a subarray.

The function labeled maxSubArr is my final solution to the problem. Note that it does not take inspiration from kadane's 
solution and that any overlap with his solution is strictly coincidental. 
*/

#include<iostream>
using namespace std;
#include<unordered_map>

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1,T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

//{a,b} refers to arr[a] + arr[a+1] + arr[a+2] + ... + arr[b]
//{a,b} where b = a refers to arr[a]
//{0,n-1} refers to all elements in a list from arr[0] to arr[n-1]. the magnitude is n
//The below function has n calls to map getSum(0, n-1)
int getSum(unordered_map<pair<int, int>, int, PairHash>& map, int * arr, int a, int b){
    if(map.find({a,b}) != map.end()){
        return map[{a,b}];
    }
    
    if(a == b){
        return map[{a, b}] = arr[a];
    }

    if(a == 0){
        int sum = 0;
        for(int i = 0; i < b + 1; i++){
            sum = sum + arr[i];
            map[{a, i}] = sum;
        }
        return map[{a, b}];
    }

    if(a < b){
        return map[{a, b}] = getSum(map, arr, 0, b) - getSum(map, arr, 0, a-1);
    }
}

int maxSubArr(int*arr, int&j, int size, int max = 0, int runningSum = 0){
    if(j == size) return max;

    while(arr[j] <= 0 && j < size){
        runningSum = runningSum + arr[j];
        j++;
    }

    if(runningSum < 0) {
        runningSum = 0;
    }

    while(arr[j] >= 0 && j < size){
        runningSum = runningSum + arr[j];
        j++;
    }

    if(runningSum > max) max = runningSum;

    return maxSubArr(arr, j, size, max, runningSum);
}

int main() {
    int arr1[35] = {20, -13, -19, 27, -3, -5, -6, -12, 27, -14, 23, 27, 14, -15, 17, 7, -18, -19, -15, -7, -6, 12, 18, -19, 15, -8, 25, 21, 24, 14, 6, -6, 8, 17, -3};
    int arr2[35] = {-20, 28, -10, 24, 7, 1, -3, -11, -7, 28, 1, -14, -15, 4, -14, 2, 2, 18, -4, -18, 26, 9, 14, -13, 4, -15, 15, -2, 20, 19, 3, 16, -8, 25, -16};
    int arr3[35] = {-18, 22, -6, 29, -2, -15, -6, -14, 4, -3, 9, 20, 3, -10, 3, 2, -7, 22, -3, 24, 23, 21, -16, 18, 20, -10, 14, 26, -5, -10, 9, 4, -3, 20, 24};
    int arr4[35] = {15, -6, 23, 0, 29, 29, -17, -6, -18, 0, 5, -3, -16, -7, 16, 25, 0, -7, 21, 11, 5, 21, 9, -11, -4, -12, -5, 27, 15, 14, -4, 27, 17, 7, 17};
    int arr5[35] = {5, 3, -6, -12, 12, 11, -15, 28, -17, -13, -11, 20, -10, 30, 23, 7, 18, -16, 4, 4, 18, 9, 13, -4, 15, -20, 23, 26, -13, 23, 14, 28, -3, 29, 21};

    int j = 0;
    int max = 0;
    int a = 0;
    int b = 0;


    int maxSum1 = maxSubArr(arr1, j, 35, 0, 0);
    j = 0;
    int maxSum2 = maxSubArr(arr2, j, 35, 0, 0);
    j = 0;
    int maxSum3 = maxSubArr(arr3, j, 35, 0, 0);
    j = 0;
    int maxSum4 = maxSubArr(arr4, j, 35, 0, 0);
    j = 0;
    int maxSum5 = maxSubArr(arr5, j, 35, 0, 0);
    j = 0;

    cout << "THE MAX CONTIGUOUS SUM FOR ARRAY 1 IS: " << maxSum1 << "." << endl;
    cout << "THE MAX CONTIGUOUS SUM FOR ARRAY 2 IS: " << maxSum2 << "." << endl;
    cout << "THE MAX CONTIGUOUS SUM FOR ARRAY 3 IS: " << maxSum3 << "." << endl;
    cout << "THE MAX CONTIGUOUS SUM FOR ARRAY 4 IS: " << maxSum4 << "." << endl;
    cout << "THE MAX CONTIGUOUS SUM FOR ARRAY 5 IS: " << maxSum5 << "." << endl;

    return 0;
}
