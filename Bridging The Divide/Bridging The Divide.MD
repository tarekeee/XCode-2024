# Statment
In the bustling city of Córdoba, beneath the shade of orange groves, lived a young scholar named Ibn Rushd, better known to the West as Averroës. Curiosity crackled in his eyes, his mind a labyrinth of logic and philosophy. Though famed for his mastery of medicine, his true passion lay in the intricate dance of reason and argument.

You are given the task of helping Ibn Rushd analyzing logical formulas and determining their height. A logical formula is a representation of logical relationships between variables using logical operators "and" (&) , "or" (|) , and the unary operator "not" (~), The height of the logical formula is a crucial metric in understanding its structural complexity, a logical expression should be fully parenthesised

In the context of logical formulas, the height represents the depth or level of nesting in the formula's syntactic tree. The syntactic tree is constructed based on the arrangement of logical operators and parentheses within the formula. The height is defined as the length of the longest path from the root of the tree to a leaf node.

Example : ((A and not (B or C)) or (not D and E)) = ((A & (B | C)) | (D & E))

                or
             /      \
           and       and
          /   \     /   \
         A    not  not    E
               |    |
               or   D
              /  \
             B    C

the height of this tree is 4 , therfore the height of ((A & (B | C)) | (D & E)) is 4

# Input
the logical formula
# Output
the height of the logical formula



# Sample
| Input | Output |	
| ----- | ------ |
| ~~~A | 3










  