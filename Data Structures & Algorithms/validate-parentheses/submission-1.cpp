class Solution {
public:
    bool isValid(string s) {
        vector<char> sta;
        
        // Use a range-based for loop for cleaner reading
        for (char c : s) {
            
            // BEHAVIOR 1: It is an opening bracket. Always push.
            if (c == '(' || c == '{' || c == '[') {
                sta.push_back(c);
            } 
            // BEHAVIOR 2: It is a closing bracket.
            else {
                // If the stack is empty, we have a closing bracket with no pair.
                if (sta.empty()) return false;
                
                // Look at the top of the stack
                char top = sta.back();
                
                // If it's a mismatch, the string is invalid.
                if ((c == ')' && top != '(') || 
                    (c == '}' && top != '{') || 
                    (c == ']' && top != '[')) {
                    return false;
                }
                
                // If it wasn't a mismatch, it's a perfect pair. Pop it.
                sta.pop_back();
            }
        }
        
        // If the stack is empty at the end, every bracket found its pair.
        return sta.empty();
    }
};