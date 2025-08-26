//Author: Jonathan Leibrant     Date: 8/26/2025
//Project: Solve the Grid Traveler problem with and without memoizataion
//Start time: 11:31am     End Time: 12:01pm

#include<iostream>
using namespace std;
#include<unordered_map>

//Pairhash borrowed from kadane
struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1,T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

//Basic gridtraveler without memoization
int gridTraveler(int m, int n, int& calls){
    calls++;
    if(m == 1 || n == 1){
        return 1;
    }
    return gridTraveler(m - 1, n, calls) + gridTraveler(m, n-1, calls);
}

//Gridtraveler with memoization
long long gridTravelerM(int m, int n, int& calls, unordered_map<pair<int, int>, long long, PairHash>& map){
    calls++;
    if(m == 1 || n == 1){
        return 1;
    }
    if(map.find({m,n}) != map.end()) return map[{m,n}];
    if(map.find({n,m}) != map.end()) return map[{n,m}];


    long long result = gridTravelerM(m - 1, n, calls, map) + gridTravelerM(m, n-1, calls, map);
    map[{m,n}] = result;
    map[{n,m}] = result;
    return result;
}

long long gridTravelerWrapper(int m, int n, int& calls){
    unordered_map<pair<int, int>, long long, PairHash> map;
    return gridTravelerM(m, n, calls, map);
}

int main(){
    int callsNoMemo = 0;
    int callsWithMemo = 0;
    int numWays1 = gridTraveler(10, 10, callsNoMemo);
    int numWays2 = gridTravelerWrapper(10, 10, callsWithMemo);

    cout << "THE NUMBER OF CALLS WITH THE GRIDTRAVELER FUNCTION FOR N = M = 10 WITHOUT MEMOIZATION IS: " << callsNoMemo << "." << endl;
    cout << "THE NUMBER OF CALLS WITH THE GRIDTRAVELER FUNCTION FOR N = M = 10 WITH MEMOIZATION IS: " << callsWithMemo << "." << endl;

    cout << "THE NUMBER OF WAYS TO TRAVEL WITH GRIDTRAVELER FUNCTION FOR N = M = 10 WITHOUT MEMOIZATION IS: " << numWays1 << "." << endl;
    cout << "THE NUMBER OF WAYS TO TRAVEL WITH GRIDTRAVELER FUNCTION FOR N = M = 10 WITH MEMOIZATION IS: " << numWays2 << "." << endl;

    callsWithMemo = 0;
    long long numWays3 = gridTravelerWrapper(30, 30, callsWithMemo);
    cout << "THE NUMBER OF CALLS WITH THE GRIDTRAVELER FUNCTION FOR N = M = 30 WITH MEMOIZATION IS: " << callsWithMemo << "." << endl;
    cout << "THE NUMBER OF WAYS TO TRAVEL WITH GRIDTRAVELER FUNCTION FOR N = M = 30 WITH MEMOIZATION IS: " << numWays3 << "." << endl;

    return 0;
}
