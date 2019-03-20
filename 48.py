from typing import List
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        if matrix==None or len(matrix)==0:
            return

        for i in range(len(matrix)):
            for j in range(i, len(matrix)):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range(len(matrix)):
            left, right = 0, len(matrix)-1
            while(left < right):
                matrix[i][left], matrix[i][right] = matrix[i][right], matrix[i][left]
                left+=1
                right-=1


testcase = [
    [
      [1,2,3],
      [4,5,6],
      [7,8,9]
    ],
    [
      [ 5, 1, 9,11],
      [ 2, 4, 8,10],
      [13, 3, 6, 7],
      [15,14,12,16]
    ],
    [
      [0]
    ],
]

for case in testcase:
    Solution().rotate(case)
    print(case)

