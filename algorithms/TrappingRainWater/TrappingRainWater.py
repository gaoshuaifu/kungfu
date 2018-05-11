class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height:
            return 0
        
        max_height = max(height)
        max_index = height.index(max_height)
        
        area_left, max_left = 0, height[0]
        for i in range(1, max_index):
            max_left = max(max_left, height[i])
            area_left += max_left - height[i]
            
        area_right, max_right = 0, height[-1]
        for i in range(len(height) - 2, max_index, -1):
            max_right = max(max_right, height[i])
            area_right += max_right - height[i]
        
        return area_left + area_right
