
Program GibralfaroCastle;

Uses math;
Function LevenshteinDistance(Const str1, str2: String): integer;

Var 
  len_str1, len_str2, i, j, cost: integer;
  matrix: array Of array Of integer;
Begin
  len_str1 := Length(str1) + 1;
  len_str2 := Length(str2) + 1;

  // Create a matrix to store the distances between substrings
  SetLength(matrix, len_str1, len_str2);

  // Initialize the matrix with values corresponding to the length of substrings
  For i := 0 To len_str1 - 1 Do
    matrix[i, 0] := i;
  For j := 0 To len_str2 - 1 Do
    matrix[0, j] := j;

  // Populate the matrix with minimum distances
  For i := 1 To len_str1 - 1 Do
    For j := 1 To len_str2 - 1 Do
      Begin
        If str1[i] = str2[j] Then
          cost := 0
        Else
          cost := 1;

        matrix[i, j] := Min(
                        matrix[i - 1, j] + 1,
                        min(         // Deletion
                        matrix[i, j - 1] + 1,         // Insertion
                        matrix[i - 1, j - 1] + cost   // Substitution
                        )
                        );
      End;

  LevenshteinDistance := matrix[len_str1 - 1, len_str2 - 1];
End;

Var 
  string1, string2: string;
  distance: integer;
Begin
  ReadLn(string1);

  ReadLn(string2);

  // Calculate Levenshtein distance and display the result
  distance := LevenshteinDistance(string1, string2);
  WriteLn('distance between ''', string1, ''' and ''', string2,
          ''': ', distance);
End.
