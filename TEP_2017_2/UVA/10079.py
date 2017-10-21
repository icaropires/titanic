from sys import stdin

for line in stdin:
  line = int(line)

  if line < 0:
    break

  if line == 0:
    print(1)

  else:
    result=(line * (line+1)) // 2 + 1
    print(result)
