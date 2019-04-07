import unittest
import collections
from math import isclose

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        if isclose(x, 0.0, abs_tol=1e-9) and n>=0:
            return 0
        if n < 0:
            n = -n
            x = 1/x
        return self.myPow(x**2, n//2) * (x if n%2 else 1)

testcase = [
    (0,0, 1),
    (1,0, 1),
    (0,1, 0),
    (-1,0, 1),
    (-1,-1, -1),
    (2,2, 4),
    (2.0,3, 8),
    (3.0,2, 9),
    (2, -1, 1/2),
    (2, -2, 1/4),
    (-2, -2, 1/4),
    (-2, -3, -1/8)
]

class TestSolution(unittest.TestCase):
    def test_myPow(self):
        with self.assertRaises(ZeroDivisionError):
            Solution().myPow(0, -1)
        for x, n, expect in testcase:
            self.assertEqual(expect, Solution().myPow(x,n), '%d %d' % (x,n))
