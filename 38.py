testcase = [
    '1',
    '11',
    '21',
    '1211',
    '111221',
    '312211',
    '13112221',
    '1113213211',
]
class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        lastStr = '1'
        currentStr = ''
        for i in range(n-1):
            char = prevChar = lastStr[0]
            count = 0
            for char in lastStr:
                if char != prevChar :
                    currentStr += str(count) + prevChar
                    count = 0
                count += 1
                prevChar = char
            currentStr += str(count) + char
            lastStr, currentStr = currentStr, ''
        return lastStr


for i in range(8):
    print(Solution().countAndSay(i+1),  testcase[i])
