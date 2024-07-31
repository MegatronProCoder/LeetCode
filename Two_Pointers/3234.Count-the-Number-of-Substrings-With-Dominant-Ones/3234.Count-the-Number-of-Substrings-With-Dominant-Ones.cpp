class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.size();

        vector<int>right = computeRightArray(s);
        int ret = 0;
        for (int len = 1; len <= 200; len++)
        {
            int j = 0, count = 0;
            for (int i=0; i<n; i++)
            {
                while (j<n && count<len)
                {
                    count+=(s[j]=='0');
                    j++;
                }
                if (count!=len) break;
                int have = j-i-count;
                if (right[j-1] + have >= count*count)
                {
                    int extra = right[j-1] - max(0, count*count-have);
                    ret += max(extra+1, 0);
                }

                count -= (s[i]=='0');
            }
        }

        for (int i=0; i<n; i++)
        {
            if (s[i]=='1')
                ret += right[i]+1;
        }
        return ret;
        
    }

    std::vector<int> computeRightArray(const std::string& s) 
    {
        int n = s.length();
        std::vector<int> right(n, 0);

        for (int i = n-2; i >=0; i--) {
            if (s[i + 1] == '1') {
                right[i] = right[i + 1] + 1;
            }
        }

        return right;
    }
};
