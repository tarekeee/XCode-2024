import math
def min_max_guesses(N):
    # Minimum guesses: Binary search strategy
    min_guesses = int(math.ceil(math.log2(N)))
    
    max_guesses = N
    
    return min_guesses, max_guesses
t = int(input());
ans = []
for _ in range(t):
    N = int(input())
    ans.append(min_max_guesses(N));
for i in ans :
    print(i[0], i[1]);