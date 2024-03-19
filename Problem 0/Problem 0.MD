# Statment
The year is 1031. The once mighty Umayyad Caliphate of Córdoba, center of Al Andalus, has fractured into smaller kingdoms known as taifas. These petty kingdoms vie for power and prestige in the wake of the great empire's decline. In a small taifa nestled in the rolling hills, a rivalry unfolds not with swords and armies, but over a checkered board.

Two courtiers, the cunning strategist Zayyan (who commands the black pieces) and the insightful Fatima (leading the white pieces) represent the ambitions of their respective factions. Each commands a line of pawns in a unique game of strategy and territory. They yearn to prove their cunning to their liege.

## The Challenge :

This peculiar chess variant unfolds on a board with n rows and n columns. Rows are numbered 0 to (n-1), with "0" closest to Fatima (white) and (n-1) nearest Zayyan (black).

- Each column holds only one white pawn and one black pawn.
- Pawns can move one space forward OR backward per turn.
- Pawns stop if they reach the edge of the board or if blocked by an opposing pawn.
- Players alternate turns, with Fatima (white) moving first.
- The game ends when a player cannot legally move any of their pawns.

# Input
You will receive the number of test cases T first , then the board's size then the initial setup as a list of row positions. For example:

[Starting Row Positions]: 2 0 1 1 3 2 3 2

...would indicate a 4x4 board with:

- A white pawn on the 3rd row (row 2) and a black pawn on 4th row (row 3) of the first column.  
- A white pawn in the 1st row (row 0) and a black pawn on 3rd row (row 2) of the second column.
And so on...
# Output
Your algorithm must determine the winner and return either "white" or "black" as the victor.



# Sample
| Input | Output |	
| ----- | ------ |
| 1 | Case 1: black wins
| 6 | 
| 1 3 2 2 0 1 | 
| 5 5 5 3 1 2 | 








  