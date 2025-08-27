//Author: Jonathan Leibrant     Date: 8/26/2025
//Project: Add two numbers represented as linked lists
//Start Time: 6:20pm    End Time: 8:29am 8/27/2025
//I got caught up learning about concave optimization and finally some bugs tripped me up early in the morning
//The following code leaves much room for optimization.
#include<iostream>
#include<unordered_map>
using namespace std;

int maxSubstr(string s){
    unordered_map<char, int> map;
    int max = 0;
    int runningMax = 0;
    for(int i = 0; i < s.size(); i++){
        if(auto it = map.find(s[i]); it != map.end()){
            cout << "i is: " << i << "." << endl;
            cout << "The first " << s[i] << " is at " << map[s[i]] << "." << endl;
            cout << "The start of the count is: " << i - runningMax << "." << endl;

            if(map[s[i]] < i - runningMax){
                runningMax++;
            }else{
                cout << "MAX: " << max << ".    RUNNING MAX: " << runningMax << "." << endl;
                //Notice, the max is set to the running max if the running max is greater, the running max is the #of 
                //digits past the first occurence of the s[i] character. 
                if(max < runningMax){
                    max = runningMax;
                    cout << "as runningmax is greater than max" << endl;
                    cout << "MAX: " << max << ".    RUNNING MAX: " << runningMax << "." << endl;
                }
                //when you've determined if the max needs reset, set the running max to the #of 
                //chars after the sum of the intersected digit
                runningMax = i-map[s[i]];
                cout << "Finally, as the first " << s[i] << " occurs at " << map[s[i]] << " and i is at " << i << endl;
                cout << "Runningmax is set to " << i-map[s[i]] << endl;
                cout << "The start of the count is: " << i - runningMax << "." << endl;
                //When you're done with the map value, reset it to the new vals. Note, this will always track the new char
                //position
                map[s[i]] = i;
            }
        }else{
            //if the character is not mapped or a new character, map its location, and increment running max. 
            map[s[i]] = i;
            runningMax++;
            cout << "CHARACTER NOT FOUND. RUNNINGMAX IS: " << runningMax << "." << endl;
        }
    }
    cout << "MAX: " << max << ".    RUNNING MAX: " << runningMax << "." << endl;
    if(max < runningMax) {
        max = runningMax;
    }
    return max;
}

int main(){
    string s1 = "abcbdefghijklmnop";   // Answer = 15
    string s2 = "qwertyqazwsxedcrfv";  // Answer = 14
    string s3 = "abcdefghijklmnoabc";  // Answer = 15
    string s4 = "zzzzzzzzzzzzzzzzz";   // Answer = 1
    string s5 = "anviajklmnopqrstuv";  // Answer = 15


    maxSubstr(s1);
    cout << endl;
    maxSubstr(s2);
    cout << endl;
    maxSubstr(s3);
    cout << endl;
    maxSubstr(s4);
    cout << endl;
    maxSubstr(s5);
    cout << endl;
    

    return 0;
}
