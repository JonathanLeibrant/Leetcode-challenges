Author: Jonathan Leibrant     
Date: 8/26/2025
Total Time: Approximately 9.5 hours
Project: Solve the Maximum SubArray problem--develop a Sum of Subarray's map to minimize calculation. 
In trying to solve this problem, I began by writing down facts about an array and attempting to understand the mathematical 
underpinnings of the optimal solution. Hashmaps, binary search trees, arrays of sums, and brute force 
methods were all considered, but after designing a useful subalgorithm, I opted for a recursive approach

I had the idea that a hashmap would reduce the total computations, and 
with the idea in mind that I might need to request S(a to b) repeatedly, I built a function that finds the sum of the
interval and stores it in a hashmap. In the process of doing this it will leverage similar interval calculations and store 
all results in the map. This overall greatly minimizes the amount of calculations necessary to sum a subarray.

The function labeled maxSubArr is my final solution to the problem. Note that it does not take inspiration from kadane's 
solution and that any overlap with his solution is strictly coincidental. 
