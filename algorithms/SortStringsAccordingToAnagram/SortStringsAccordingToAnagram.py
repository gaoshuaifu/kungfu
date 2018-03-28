def anagramSort(words):
  def anagram(word):
    return "".join(sorted(word))

  return sorted(words, cmp=lambda w1, w2: cmp(anagram(w1), anagram(w2))) 

print anagramSort(['abc', 'xyz', 'cba'])
