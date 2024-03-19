
from collections import deque
n = int(input())
i = []
for _ in range(n):
    l , k = map(int, input().split())
    i.append((l, k))

for j in range(n):
    a = deque(list(range(1, i[j][0]+1)))
    index = 0
    while a:
        # index = (index + i[j][1]-1) % len(a)
        a.rotate(1-i[j][1])
        item = a.popleft()
    print(item)
