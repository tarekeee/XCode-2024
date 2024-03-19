Uses math;

function distance(const str1, str2: string): integer;
begin
  // Base case: if either string is empty, return the length of the other string
  if str1 = '' then
    Exit(Length(str2));

  if str2 = '' then
    Exit(Length(str1));

  // If the last characters are the same, no edit is needed for this position
  if str1[Length(str1)] = str2[Length(str2)] then
    Exit(distance(Copy(str1, 1, Length(str1) - 1), Copy(str2, 1, Length(str2) - 1)));

  // Otherwise, consider three possible operations: insertion, deletion, and substitution
  distance := 1 + min(
    distance(str1, Copy(str2, 1, Length(str2) - 1)),        // Insertion
    min(distance(Copy(str1, 1, Length(str1) - 1), str2),       // Deletion
    distance(Copy(str1, 1, Length(str1) - 1), Copy(str2, 1, Length(str2) - 1))) // Substitution
  );
end;

// Example usage
var
  string1, string2: string;
  result: integer;
begin 
  readln(string1);
  readln(string2);
  result := distance(string1, string2);
  writeln('distance between ''', string1, ''' and ''', string2, ''': ', result);
end.