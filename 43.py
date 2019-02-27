class Solution:
    result = list('0')     # reverse of number
    def multiply(self, num1: 'str', num2: 'str') -> 'str':
        for index1, value1 in enumerate(num1[::-1]):
            cursor = index1
            for index2, value2 in enumerate(num2[::-1]):
                self._Multi(cursor+index2, value1, value2)
        res = ''.join(self.result[::-1])
        self.result = list('0')
        return res

    def _multi(self, a, b):
        num = (ord(a)-ord('0')) * (ord(b)-ord('0'))
        return str(num//10), str(num%10)

    def _add(self, a, b):
        num = ord(a)-ord('0') + ord(b)-ord('0')
        return str(num//10), str(num%10)
    
    def _Add(self, cursor, num):
        if cursor >= len(self.result) and num != '0':
            while len(self.result) <= cursor:
                self.result.append('0')

        if cursor < len(self.result):
            c, n = self._add(self.result[cursor], num)
            self.result[cursor] = n

            if c != '0':
                self._Add(cursor+1, c)

    def _Multi(self, cursor, a, b):
        c, n = self._multi(a, b)
        self._Add(cursor, n)
        if c != '0':
            self._Add(cursor+1, c)
        

testcase = [
        [0,0],
        [0,123],
        [123,0],
        [123,123],
        [4,5],
        [123,456],
        [112341235132512341234,11],

    ]

clz = Solution()
for case in testcase:
    res = clz.multiply(str(case[0]), str(case[1]))
    print(res, str(case[0]*case[1]))
