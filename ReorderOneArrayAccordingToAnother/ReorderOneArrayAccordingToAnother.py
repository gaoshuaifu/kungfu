# O indicates the position of the corresponding element in A
def reorder(A, O):
  i = 0
  while i < len(A):
    if O[i] == i:
      i += 1
    else:
      A[O[i]], A[i] = A[i], A[O[i]]
      O[O[i]], O[i] = O[i], O[O[i]]

def main():
  A = ['E', 'A', 'B', 'D', 'C']
  O = [4, 0, 1, 3, 2]
  reorder(A, O)
  print A
  print O

main()
