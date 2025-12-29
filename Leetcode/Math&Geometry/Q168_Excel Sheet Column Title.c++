class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        while(columnNumber){
            s.insert(s.begin(), 'A' + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }
        return s;
    }
};
