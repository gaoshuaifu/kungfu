class Solution(object):
    def findRestaurant(self, list1, list2):
        d1 = {x:i for i, x in enumerate(list1)}
        d2 = {x:i for i, x in enumerate(list2)}
        d = {x:d1[x]+d2[x] for x in d1 if x in d2}
        return [x for x, i in d.items() if i == min(d.values())]
