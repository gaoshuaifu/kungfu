def arithmetic_sequence1(a):
  diff = (a[-1] - a[0]) / len(a)
  for i in range(len(a) - 1):
    if a[i] + diff != a[i + 1]:
      return 'arithmetic', a[i] + diff

def arithmetic_sequence2(a):
  diff1 = a[1] - a[0]
  diff2 = a[2] - a[1]
  diff = min(diff1, diff2)
  for i in range(len(a) - 1):
    if a[i] + diff != a[i + 1]:
      return 'arithmetic', a[i] + diff

def arithmetic_sequence3(a):
  diff1 = a[1] - a[0]
  diff2 = a[2] - a[1]
  div1 = a[1] / a[0]
  div2 = a[2] / a[1]

  if diff1 == diff2:
    type = 'arithmetic'
    diff = diff1
  elif div1 == div2:
    type = 'geometrical'
    div = div1
  else:
    diff3 = a[3] - a[2]
    div3 = a[3] / a[2]
    if diff3 == diff1 or diff3 == diff2:
      type = 'arithmetic'
      diff = diff3
    elif div3 == div1 or div3 == div2:
      type = 'geometrical'
      div = div1
  for i in range(len(a) - 1):
    if type == 'arithmetic' and a[i] + diff != a[i + 1]:
      return 'arithmetic', a[i] + diff
    if type == 'geometrical' and a[i] * div != a[i + 1]:
      return 'geometrical', a[i] * div

def main():
  a = [1, 2, 3, 4, 6]
  print arithmetic_sequence1(a)
  print arithmetic_sequence2(a)
  print arithmetic_sequence3(a)

  a = [1, 3, 27, 81]
  print arithmetic_sequence3(a)

main()
