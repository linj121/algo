from collections import defaultdict
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq: List[int, int] = defaultdict(int)
        bucket: List[List[int]] = [[] for _ in range(len(nums) + 1)]

        for num in nums:
            freq[num] += 1
        for key, val in freq.items():
            bucket[val].append(key)
        
        result: List[int] = []
        for i in reversed(range(len(nums) + 1)):
            for j in bucket[i]:
                result.append(j)
                if len(result) == k:
                    return result

if __name__ == "__main__":
    sol = Solution()
    input = [[1,1,1,2,2,3], 2]
    output = sol.topKFrequent(*input)
    print(output)