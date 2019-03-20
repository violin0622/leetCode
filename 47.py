class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        if nums==None:
            return []

        result = []
        nums.sort()
        self.permutation(nums, result, [])
        return result

# nums: copy of source list,with elements exchanged
# left: [0,left) is confirmed elements
    def permutation(self, nums, result, lis):
        if len(nums)==0:
            result.append(lis)
            return

        for i in range(len(nums)):
            if i>0 and nums[i] == nums[i-1]:
                continue
            self.permutation(nums[:i] + nums[i+1:], result, lis+[nums[i]])
