class Solution {
public:
    int divisorSubstrings(int num, int k) {
        if(num == 0) return 0;
        string num_str = to_string(num);
        //int n = num_str.size();

        int count = 0;
        string s = "";
        for(int high=k-1;high<num_str.size();high++) {
            s = num_str.substr(high-k+1, k);
            int m = stoi(s);
            if(m!=0 && num % m == 0) count++;
            //low++;
        }
        return count;
    }
};