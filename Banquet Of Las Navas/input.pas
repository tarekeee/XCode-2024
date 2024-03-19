program AndalusianBanquet;

var
  T, c: Integer;
  P, L, i: Int64;
  divisors: array of Int64;

begin
  ReadLn(T);

  for c := 1 to T do
  begin
    ReadLn(P, L);

    SetLength(divisors, 0);

    for i := 1 to (P - L) do
    begin
      if ((P - L) mod i = 0) and (i > L) then
      begin
        SetLength(divisors, Length(divisors) + 1);
        divisors[High(divisors)] := i;
      end;
    end;

    Write('Case ', c, ':');
    if Length(divisors) = 0 then
      WriteLn(' impossible')
    else
    begin
      for i := 0 to High(divisors) do
        Write(' ', divisors[i]);
      WriteLn;
    end;
  end;
end.
