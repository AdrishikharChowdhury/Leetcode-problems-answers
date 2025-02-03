class Solution(object):
    def checkInclusion(self, s1, s2):
        if len(s1) > len(s2):
            return False

        freq_s1 = [0] * 26
        freq_window = [0] * 26

        # Initialize frequency arrays
        for i in range(len(s1)):
            freq_s1[ord(s1[i]) - ord('a')] += 1
            freq_window[ord(s2[i]) - ord('a')] += 1

        # Compare first window
        if freq_s1 == freq_window:
            return True

        # Sliding window
        for i in range(len(s1), len(s2)):
            freq_window[ord(s2[i]) - ord('a')] += 1  # Add new char to window
            freq_window[ord(s2[i - len(s1)]) - ord('a')] -= 1  # Remove old char

            if freq_s1 == freq_window:
                return True

        return False
