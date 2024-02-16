#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLeastNumOfUniqueInts(std::vector<int>& arr, int k) {
        // Step 1: Count the frequency of each number
        std::unordered_map<int, int> frequencyMap;
        for (int num : arr) {
            frequencyMap[num]++;
        }
        
        // Step 2: Sort the frequencies in ascending order
        std::vector<int> frequencies;
        for (const auto& pair : frequencyMap) {
            frequencies.push_back(pair.second);
        }
        std::sort(frequencies.begin(), frequencies.end());
        
        // Step 3: Traverse through the sorted frequencies and remove elements
        int uniqueIntegers = frequencyMap.size(); // Initial count of unique integers
        for (int frequency : frequencies) {
            if (k >= frequency) {
                k -= frequency;
                uniqueIntegers--; // Decrease unique integer count
            } else {
                break;
            }
        }
        
        // Step 4: Return the number of unique integers remaining after removal
        return uniqueIntegers;
    }
};
