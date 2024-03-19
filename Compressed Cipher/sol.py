n = int(input());
s = []
for _ in range(n):
    s.append(input())
for q in s:
    sol = ""
    i=0
    while i < len(q):
        j = i
        while j < len(q)-1 and q[j] == q[j+1]:
            j += 1
        sol += q[i] + str(j-i+1)
        i = j+1
    print(sol)
