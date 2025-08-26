//Author: Jonathan Leibrant     Date: 8/26/2025
//Project: Two Sum--Find the indices of two numbers in an array that add up to a target.
//Start Time: 2:05pm
#include<iostream>
using namespace std;
#include<unordered_map>

int* twoSum(int*arr, int target, int size, unordered_map<int, int>& map){
    int* indexArr = new int[2];
    for(int i = 0; i < size; i++){
        if(auto it = map.find(target - arr[i]); it != map.end()){
            indexArr[0] = i;
            indexArr[1] = it->second;
            return indexArr;
        }else{
            map[target - arr[i]] = i;
        }
    }
    delete [] indexArr;
    return nullptr;
}
