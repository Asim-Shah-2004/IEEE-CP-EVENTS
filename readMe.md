# Competitive Programming Solutions
A collection of algorithmic problem solutions implemented in C++, featuring detailed explanations and optimized approaches.

## 🎯 Current Problems
1. **Maximum Water Container** (Container With Most Water)
   - Dynamic approach for optimizing container area
   - Time Complexity: O(n)
   - [View Solution](solutions/maximum_water_container.cpp)

2. **Minimum Cost Cake Cutting**
   - Greedy algorithm for optimal cutting strategy
   - Time Complexity: O(m log m + n log n)
   - [View Solution](solutions/cake_cutting.cpp)

3. **Travel Content Creator Score**
   - Dynamic programming for optimal path finding
   - Time Complexity: O(k × n²)
   - [View Solution](solutions/travel_content.cpp)

4. **Array GCD to Ones**
   - GCD-based transformation problem
   - Time Complexity: O(n² × log M)
   - [View Solution](solutions/gcd_to_ones.cpp)

## 🚀 Getting Started

### Prerequisites
- C++ compiler (C++11 or later)
- Git

### Running the Solutions
1. Clone the repository
```bash
git clone https://github.com/yourusername/cp-solutions.git
cd cp-solutions
```

2. Compile a solution
```bash
g++ solutions/problem_name.cpp -o solution
```

3. Run with input
```bash
./solution < input.txt
```

## 📝 Contributing Guidelines

### Before Contributing
- Check if the problem solution already exists
- Review the code structure and style guide below
- Test your solution with multiple test cases

### Code Structure
Solutions should follow this template:
```cpp
class Solution {
public:
    // Method documentation
    returnType methodName(parameters) {
        // Implementation
    }
private:
    // Helper methods if needed
};

int main() {
    // Input handling
    // Solution execution
    // Output formatting
    return 0;
}
```

### Style Guide
1. **Naming Conventions**
   - Use camelCase for method names
   - Use snake_case for file names
   - Use descriptive variable names

2. **Comments and Documentation**
   - Add method documentation explaining:
     * Purpose
     * Parameters
     * Return value
     * Time/Space complexity
   - Comment complex logic
   - Include example usage

3. **Code Organization**
   - Group related functions
   - Keep methods focused and single-purpose
   - Use appropriate access modifiers

### Submission Process
1. Fork the repository
2. Create a new branch
```bash
git checkout -b feature/problem-name
```

3. Add your solution
   - Create new file in solutions/
   - Follow code structure template
   - Add comprehensive comments
   - Include problem statement at top

4. Test thoroughly
   - Test with example cases
   - Test with edge cases
   - Verify time complexity

5. Create Pull Request
   - Descriptive title
   - Complete problem information
   - Complexity analysis
   - Example usage

### Pull Request Template
```markdown
## Problem Information
- Name: [Problem Name]
- Difficulty: [Easy/Medium/Hard]
- Time Complexity: O(?)
- Space Complexity: O(?)

## Solution Approach
Brief explanation of the algorithm/approach used

## Example Usage
Input/Output examples

## Checklist
- [ ] Code follows style guide
- [ ] Comprehensive comments added
- [ ] All test cases pass
- [ ] Complexity analysis included
```
## ⭐ Support
If you find this helpful, please star the repository!