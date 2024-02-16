import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeastNoOfUniqueIntegerAfterRemovingK {
    // Step 1: Count the frequency of each number
    Map<Integer, Integer> frequencyMap = new HashMap<>();
    for (int num : arr) {
        frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
    }
    
    // Step 2: Sort the frequencies in ascending order
    List<Integer> frequencies = new ArrayList<>(frequencyMap.values());
    Collections.sort(frequencies);
    
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
