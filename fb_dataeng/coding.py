
################################################################################
""" Returns number of unique words from the input string """

def count_words(input):
    words = [word for word in input.split(' ') if word]
    return len(set(words))

print 'Count Unique Words:'
print count_words('')
print count_words('  ')
print count_words('hello')
print count_words('hello world')
print

################################################################################
""" Implement histogram(input) function """

def histogram(input):
    d = {}
    for x in input:
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    return d

print 'Histogram:'
print histogram([])
print histogram(['a'])
print histogram(['a', 'a'])
print histogram(['a', 'b'])
print histogram(['a', 'a', 'b'])
print histogram(['a', 'a', 'b', 'b'])
print

################################################################################
""" Given a list of integers, returns a list with duplicates removed """

def dedup(nums):
    return list(set(nums))

print 'List Dedup:'
print dedup([])
print dedup([1])
print dedup([1, 1])
print dedup([1, 2])
print dedup([1, 1, 2])
print dedup([1, 1, 2, 2])
print

################################################################################
""" Given a list of lists, return a list after removing all the nested lists """

def flatten1(list_of_list):
    res = []
    for l in list_of_list:
        res += l
    return res

print 'List Flatten:'
print flatten1([])
print flatten1([[]])
print flatten1([[], [1]])
print flatten1([[1], [2]])
print flatten1([[1, 2], [3, 4]])
print

def flatten2(list_of_list):
    return reduce(lambda x, y: x + y, list_of_list, [])

print 'List Flatten:'
print flatten2([])
print flatten2([[]])
print flatten2([[], [1]])
print flatten2([[1], [2]])
print flatten2([[1, 2], [3, 4]])
print

################################################################################
""" Given a list of integers, return top N largest """

def top_n1(nums, n):
    return sorted(nums, reverse=True)[:n]

print 'Top N:'
print top_n1([], 0)
print top_n1([], 1)
print top_n1([1, 2], 0)
print top_n1([1, 2], 1)
print top_n1([1, 2], 2)
print top_n1([1, 2], 3)
print

def top_n2(nums, n):
    import heapq
    return heapq.nlargest(n, nums)

print 'Top N:'
print top_n2([], 0)
print top_n2([], 1)
print top_n2([1, 2], 0)
print top_n2([1, 2], 1)
print top_n2([1, 2], 2)
print top_n2([1, 2], 3)
print

################################################################################
""" Count number of occurrences of a given substring in a string """

def count_substr1(input_str, sub_str):
    res = 0
    for i in range(len(input_str) - len(sub_str) + 1):
        if input_str[i:i+len(sub_str)] == sub_str:
            res += 1
    return res

print 'Count Substring:'
print count_substr1('','')
print count_substr1('','a')
print count_substr1('a','')
print count_substr1('a','a')
print count_substr1('aa','a')
print count_substr1('aaa','aa')
print count_substr1('abcdabcd','abc')
print

################################################################################
""" Sample n numbers from a list """

def sample1(nums, n):
    import random
    return random.sample(nums, n)

print 'List Random Sample:'
print sample1([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 4)
print sample1([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 4)
print

def sample2(nums, n):
    import random
    res = nums[:n]
    for i in range(n, len(nums)):
        rand_idx = random.randint(0, i)
        if rand_idx < n:
            res[rand_idx] =  nums[i]
    return res

print 'List Random Sample:'
print sample2([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 4)
print sample2([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 4)
print

################################################################################
""" Find all possible pairs of from input list """

def find_pairs(input):
    import itertools
    return list(itertools.combinations(input, 2))

print 'Find All Pairs:'
print find_pairs([1, 2, 3, 4])
print

################################################################################
""" Find the percentile of a list of values """

def percentile(nums, percent):
    import math
    if not nums:
        return None
    nums = sorted(nums)
    k = (len(nums) - 1) * percent
    f = math.floor(k)
    c = math.ceil(k)
    if f == c:
        return nums[int(k)]
    d0 = nums[int(f)] * (c-k)
    d1 = nums[int(c)] * (k-f)
    return d0 + d1

print 'Percentile:'
print percentile([1, 2, 3, 4, 5], 0.25)
print percentile([1, 2, 3, 4, 5, 6], 0.25)
print percentile([1, 2, 3, 4, 5], 0.5)
print percentile([1, 2, 3, 4, 5, 6], 0.5)
print percentile([1, 2, 3, 4, 5], 0.75)
print percentile([1, 2, 3, 4, 5, 6], 0.75)
print

################################################################################
""" Given an array of numbers, return the median number """

def median(nums):
    nums = sorted(nums)
    l = len(nums)
    if l % 2 == 1:
        return nums[l / 2]
    else:
        return (nums[l / 2 - 1] + nums[l / 2]) * 1.0 / 2

print 'Median:'
print median([1, 2, 3, 4, 5])
print median([1, 2, 3, 4, 5, 6])
print

################################################################################
""" Given an array of numbers, return the most frequent number """

def most_frequent(items):
    d = {}
    max_count = 0
    most_frequent_item = None
    for item in items:
        if item in d:
            d[item] += 1
        else:
            d[item] = 1
        if d[item] > max_count:
            max_count = d[item]
            most_frequent_item = item
    return most_frequent_item

print 'The Most Frequent Item:'
print most_frequent([])
print most_frequent([1])
print most_frequent([1, 1, 2])
print most_frequent([1, 1, 2, 2])
print

################################################################################
""" Given a list of numbers, find the smallest absolute difference between two numbers """

def min_absolute_difference(nums):
    import sys
    nums = sorted(nums)
    min_diff = sys.maxint
    for i in range(len(nums) - 1):
        min_diff = min(nums[i + 1] - nums[i], min_diff)
    return min_diff

print 'Smallest Absolute Difference'
print min_absolute_difference([-6, -3, 2, 4, 7])
print

################################################################################
""" Given a list of numbers, return the first non-recurring number """

def first_nonrecurring1(nums):
    d = {}
    for i in range(len(nums)):
        num = nums[i]
        if num in d:
            d[num][0] += 1
        else:
            d[num] = [1, i]


    min_index = len(nums)
    for k, v in d.items():
        if v[0] == 1:
            min_index = min(min_index, v[1])

    return nums[min_index] if min_index < len(nums) else None

print "First Non-recurring:"
print first_nonrecurring1([1, 2, 3, 4, 5, 1, 2, 3, 4])
print first_nonrecurring1([1, 2, 3, 4, 5, 1, 2, 3, 4, 5])
print

def first_nonrecurring2(nums):
    d = {}
    for num in nums:
        if num in d:
            d[num] += 1
        else:
            d[num] = 1

    for num in nums:
        if d[num] == 1:
            return num

    return None

print "First Non-recurring:"
print first_nonrecurring2([1, 2, 3, 4, 5, 1, 2, 3, 4])
print first_nonrecurring2([1, 2, 3, 4, 5, 1, 2, 3, 4, 5])
print

################################################################################
""" Given a list of numbers, find the least common multiple """
def lcm(a, b):
    value = a if a > b else b
    step = value
    while True:
        if value % a == 0 and value % b == 0:
            return value
        value += step

def list_lcm(nums):
    return reduce(lambda x, y: lcm(x, y), nums)

print 'Least Common Multiple:'
print list_lcm([3, 7, 11])
print list_lcm([4, 6, 8])
print

################################################################################
""" Check whether the string consists of only numeric characters """

def isnumeric(s):
    try:
        float(s)
        return True
    except:
        return False

print isnumeric('1')
print isnumeric('-1')
print isnumeric('.1')
print isnumeric('-.1')
print isnumeric('1.')
print isnumeric('-1.')
print isnumeric('1.1')
print isnumeric('-1.1')
print isnumeric('1.1e2')
print isnumeric('-1.1e2')
