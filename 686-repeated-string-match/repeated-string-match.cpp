class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repeat = b.size() / a.size();
        int count = 1;

        while (count <= repeat + 2) {
            string temp = "";
            for (int i = 0; i < count; i++) {
                temp += a;
            }

            if (temp.find(b) != string::npos) {
                return count;
            } else {
                count++;
            }
        }
        return -1;
    }
};