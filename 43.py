class Solution:
    result = list('0')     # reverse of number
    def multiply(self, num1: 'str', num2: 'str') -> 'str':
        from functools import reduce
        if num1=='0' or num2=='0':
            return '0'
        result = [0 for i in range(len(num1)+len(num2))]
        carry = 0
        for index1, i in enumerate(num2[::-1]):
            for index2, j in enumerate(num1[::-1]):
                i,j = int(i), int(j)
                n = result[-index1-index2-1] + i*j
                carry = n // 10
                result[-index1-index2-1] = n % 10
                result[-index1-index2-2] += carry
        i=0
        while result[i]==0 :
            i+=1
        return reduce(lambda x,y: x+str(y), result[i:], '')

testcase = [
        [999,99],
        [0,0],
        [0,123],
        [123,0],
        [123,123],
        [4,5],
        [123,456],
        [112341235132512341234,11],
        [999,999],
    ]

clz = Solution()
for case in testcase:
    res = clz.multiply(str(case[0]), str(case[1]))
    print(res, str(case[0]*case[1]))
