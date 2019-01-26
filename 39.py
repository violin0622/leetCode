class Solution(object):
    def combinationSum(self, candidates, target):
        
        def dfs(remain, combo, index):
            if remain < 0:
                return
            if remain == 0:
                result.append(combo)
                return
            for i in range(index, len(candy)):                
                print(i, combo)
                dfs(remain - candy[i], combo + [candy[i]], i)
                
        candy = sorted(candidates)
        result = []
        dfs(target, [], 0)
        return result

print(Solution().combinationSum([10,1,2,7,6,1,5], 8))
