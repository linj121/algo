from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numsSet = set(nums)
        longest: int = 0

        for num in nums:
            if num - 1 not in numsSet:
                nextNum = num + 1
                currentLength = 1
                while nextNum in numsSet:
                    nextNum += 1
                    currentLength += 1
                longest = max(longest, currentLength)

        return longest
      

if __name__ == "__main__":
	sol = Solution()
	input: List[int] = [100,4,200,1,3,2]
	res = sol.longestConsecutive(input)
	print(res)