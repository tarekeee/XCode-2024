def num_islands(grid):
    if not grid:
        return 0

    def dfs(i, j):
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == '1':
            grid[i][j] = '0'
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)

    num_of_islands = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == '1':
                num_of_islands += 1
                dfs(i, j)

    return num_of_islands


grid = []
rows = int(input())
cols = int(input())
for i in range(rows):
    grid.append(input())
result = num_islands([list(row) for row in grid])
print(result)
