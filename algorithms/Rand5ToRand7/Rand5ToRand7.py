# Given rand5 (1 ~ 5), implement rand7 (1 ~ 7)

def rand7():
  while True:
      a = rand5();
      b = rand5();

      # num 1 ~ 25
      num = (a - 1) * 5 + (b - 1) + 1
  
      # num 1 ~ 21    
      if num < 22:
          break
  
  return num % 7 + 1

