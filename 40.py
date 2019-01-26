class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def dfs(remain, combo, candidate):
            if remain < 0:
                return
            if remain == 0:
                result.append(combo)
                return
            for index, num in enumerate(candidate):
                if index>0 and candidate[index-1]==num:
                    continue
                dfs(remain-num, combo+[num], candidate[index+1:])

        candy = sorted(candidates)
        result = []
        dfs(target, [], candy)
        return result

print(Solution().combinationSum2([10,1,2,7,6,1,5], 8))
l = [10,1,2,7,6,1,5]
l.sort()
print(l)

