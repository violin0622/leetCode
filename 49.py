from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = {}
        for word in strs:
            char_set = str(sorted(word))
            if char_set in result:
                result[char_set] += [word]
            else:
                result[char_set] = [word]
        return [result[i] for i in result]

testcase = ["eat", "tea", "tan", "ate", "nat", "bat"]

print(Solution().groupAnagrams(testcase))
