program Div16Program;

function Div16(x: Integer): Integer;
begin
  Div16 := x shr 4;
end;

var
  test_cases, i, x: Integer;

begin
  readln(test_cases);
  for i := 1 to test_cases do
  begin
    readln(x);
    writeln('Case ', i, ': ', Div16(x));
  end;
end.
