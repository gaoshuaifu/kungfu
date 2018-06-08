class Solution(object):
    def largestRectangleArea(self, heights):
        n = len(heights)
        
        stk, left = [], [0] * n
        for i in range(n):
            while stk and heights[stk[-1]] >= heights[i]:
                stk.pop()  
            if not stk:
                left[i] = i
            else:
                left[i] = i - stk[-1] - 1            
            stk.append(i)
    
        stk, right = [], [0] * n
        for i in range(n - 1, -1, -1):
            while stk and heights[stk[-1]] >= heights[i]:
                stk.pop()
            if not stk:
                right[i] = n - 1 - i
            else:
                right[i] = stk[-1] - i - 1
            stk.append(i)
            
        max_area = 0
        for i in range(n):
            area = heights[i] * (left[i] + right[i] + 1)
            max_area = max(max_area, area)

        return max_area
