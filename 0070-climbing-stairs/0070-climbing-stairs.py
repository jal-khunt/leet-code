class Solution:
    def climbStairs(self, n: int) -> int:
        if(n <= 3):
            return n

        steps, a, b = 0, 2, 3

        for _ in range(4, n+1):
            steps = a + b
            a = b
            b = steps

        return steps
        