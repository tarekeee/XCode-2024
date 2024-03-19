# Statment 
The Battle of Guadalete marked a pivotal moment in the history of Europe and North Africa. Led by the conqueror Tarek Ibn Zyad, the Muslim forces faced the Christian Visigoths under King Roderic, resulting in the Muslim conquest of the Iberian Peninsula and the establishment of the great civilization of Andalusia.

In this challenge, we aim to assist historians in understanding the potential outcomes of this historic battle, considering various strategic and power levels.


# Input: 
The input begins with the dimensions of the armies represented as an n*m matrix. Each army, Christian and Islamic, is of equal size.

## Army Representation: 
The Christian army is represented by the first matrix, and the Islamic army is represented by the second one. Each cell in the matrix represents a soldier and their power.

## Battle Procedure: 
The last row of the Christian army confronts the first row of the Muslim army, with each soldier engaging their counterpart in the opposing army.

## Scoring: 
During each round, if a soldier's power exceeds that of their opponent, their army earns 2 points for that round. If the powers are equal, both armies receive 1 point. Otherwise, neither side earns a point.

## Round Resolution:
 After each round, the rows involved in the battle are removed. The remaining power of each soldier (after accounting for losses) is added to the soldier in the same column of the next row. If a soldier's remaining power is less than zero, no points are added or removed.

## Battle Outcome:
 The battle continues until all rows have been engaged. At the end, the army with the higher total points is declared the winner. If both armies have the same total points, the outcome is a draw.

# Objective: 
You're tasked to write a code which simulates the battle based on the provided rules and determines the outcome - whether the Christian army (C), the Islamic army (M), or a draw (D).



# Sample
| Input | Output |	
| ----- | ------ |
| 3 3| D
| 1 2 3| 
| 4 5 6| 
| 7 8 9| 
| 9 8 7| 
| 6 5 4| 
| 3 2 1| 


| Input | Output |	
| ----- | ------ |
| 3 3| C
| 5 8 9| 
| 4 6 7| 
| 2 3 1| 
| 6 5 4| 
| 8 2 1| 
| 9 3 7| 

