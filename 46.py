import copy
def permute(nums):
    if nums==None:
        return []

    result = []
    permutation(nums, 0, result)
    print(result)



# nums: copy of source list,with elements exchanged
# left: [0,left) is confirmed elements
def permutation(nums, left, result):
    if len(nums)==0:
        return
    if left >= len(nums):
        result.append(nums)
        return

    for i in range(left,len(nums)):
        nums[left], nums[i] = nums[i], nums[left]
        permutation(nums[:], left+1, result)


nums = [
        [],
        [0],
        [1,2,3]
    ]
for case in nums:
    print('case:',case)
    permute(case)
