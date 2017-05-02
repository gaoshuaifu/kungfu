import sys

def shortest_range(arrays):
  n = len(arrays)
  indices = [0] * n
  res = (-sys.maxint, sys.maxint)
  while True:
    values = [array[i] for array, i in zip(arrays, indices)]
    min_val = min(values)
    max_val = max(values)
    if max_val - min_val < res[1] - res[0]:
      res = (min_val, max_val)
    min_index = values.index(min_val)
    indices[min_index] += 1
    if indices[min_index] == len(arrays[min_index]):
      break
  return res

def main():
  arrays = [
    [10, 15, 21, 31, 33],
    [7, 16, 20, 27],
    [12, 22, 29, 34],
  ]

  print shortest_range(arrays)

main()
