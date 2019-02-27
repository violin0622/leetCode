import unittest

class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        peak = last_peak = 0
        peak_height = last_peak_height = 0
        valley = 0
        contain = all_contain = 0
        def is_peak(i):
            nonlocal valley
            if i==0 or i==len(height)-1:
                return True
            if height[i] <= valley:
                valley = height[i]
                return False
            return height[i]>=height[i-1] and height[i]>=height[i+1]
        def acc_contain(height):
            return peak_height-height if peak_height-height>0 else 0
        def overflow():
            overflow = 0
            for i in range(last_peak, peak):
                if height[i] < peak_height:
                    break
                overflow += (height[i] - max(height[i+1],peak_height))*(peak-i)
            return overflow

        for i,h in enumerate(height):
            contain += acc_contain(h)
            if is_peak(i): 
                last_peak, peak = peak, i
                last_peak_height, peak_height = peak_height, h
                valley = peak_height
                if peak_height < last_peak_height:
                    contain -= overflow()
                all_contain += contain
                contain = 0
        return all_contain
        

testcase = {
    4: [2,1,1,1,1,2],
    0: [1,1,1,1,1,1],
    7: [5,5,5,4,3,4,5,2,5],
    6: [0,1,0,2,1,0,1,3,2,1,2,1],
    5: [1,2,3,2,3,4,5,4,3,4,5,6,7],
    12: [6,5,4,3,4,5,4,3,4,5,4,3,2,3,4,3,2,1],
}

class test(unittest.TestCase):
    def testcase(self):
        trap = Solution().trap
        for k,v in testcase.items():
            self.assertEqual(trap(v), k, 'error:'+str(k))
