def battle_outcome(rows, cols, army1, army2):
    

    Battle1 = 0
    Battle2 = 0



    for i in range(rows):
      
        score1 = 0
        score2 = 0
        for j in range(cols):
            soldier1 = army1[rows - 1 - i][j]
            soldier2 = army2[i][j]
            
            
            if (rows - 1 - i) != 0: 
                

                if (soldier1 - soldier2) > 0:
                    army1[rows - 2 - i][j] += (soldier1 - soldier2)


                if (soldier2 - soldier1)>0:
                    army2[i+1][j] += (soldier2 - soldier1)
                
                
           

            if soldier1 > soldier2:
                score1 += 2
            elif soldier1 < soldier2:
                score2 += 2
            else:
                score1 += 1
                score2 += 1



        if score1 > score2:
            Battle1 += 2
        elif score2 > score1:
            Battle2 += 2
        else:
            Battle1 += 1
            Battle2 += 1
            



    if Battle1 > Battle2:
        return 'C'
    elif Battle2 > Battle1:
        return 'M'
    else:
        return 'D'

'''
army1_1 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]
army2_1 = [
    [9, 8, 7],
    [6, 5, 4],
    [3, 2, 1]
]'''
'''
army1_1 = [
    [5, 8, 9],
    [4, 6, 7],
    [2, 3, 1]
]
army2_1 = [
    [6, 5, 4],
    [8, 2, 1],
    [9, 3, 7]
]'''
'''
army1_1 = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]
army2_1 = [
    [2, 2, 2],
    [2, 2, 2],
    [2, 2, 2]
]'''



rows, cols = map(int, input().split())

Christians = []

for _ in range(rows):
        row = list(map(int, input().split()))
        Christians.append(row)

Muslims = []
for _ in range(rows):
        row = list(map(int, input().split()))
        Muslims.append(row)




print(battle_outcome(rows, cols, Christians, Muslims))
