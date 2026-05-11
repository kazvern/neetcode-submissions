class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.empty() || s.size() == 1) return s.size();
        // find most frequent letter in s first
        vector<int> freqs(26, 0);

        for (char c : s) {
            freqs[c - 'A']++;
        }

        pair<char, int> max_freq = {'A', -1};
        for (int i = 0; i < 26; i++) {
            if (freqs[i] > max_freq.second) max_freq = {i + 'A', freqs[i]};
        }
        cout << max_freq.first << " " << max_freq.second << endl;

        int left = 0, right = 0;
        int longest = 0;
        while (left <= right && right < s.size()) {
            int uses = k;

            while (left <= right && right < s.size()) {
                cout << s[right] << " " << uses << endl;
                if (s[right] != max_freq.first && uses > 0) uses--;
                else if (s[right] != max_freq.first && uses <= 0) break;
                right++;
            }

            longest = max(longest, right - left);
            left = ++right;
        }

        return longest;
    }
};
