program ConnectedOnes;

const
  SIZE = 5;

type
  Tstronghold = array[0..SIZE-1, 0..SIZE-1] of Integer;
  Tseen = array[0..SIZE-1, 0..SIZE-1] of Boolean;
  directions = array[0..7] of Integer;

const
  dx: directions = (-1, 1, -1, 0, 0, -1, 1, 1);
  dy: directions = (-1, 0, 1, -1, 1, -1, 0, 1);

function IsValid(x, y: Integer): Boolean;
begin
  IsValid := (x >= 0) and (x < SIZE) and (y >= 0) and (y < SIZE);
end;


procedure check(var stronghold: Tstronghold; x, y: Integer; var seen: Tseen);
var
  i, newX, newY: Integer;
begin

  seen[x][y] := true;

  // Explore the other outposts
  for i := 0 to 7 do
  begin
    newX := x + dx[i];
    newY := y + dy[i];

    // hmm are they connected?
    if IsValid(newY, newX) and (stronghold[newY][newX] = 1) and (seen[newY][newX]) then
    begin
      check(stronghold, newX, newY, seen);
    end;
  end;
end;

function connected(var stronghold: Tstronghold): Boolean;
var
  seen: Tseen;
  i, j, startX, startY: Integer;
begin
    //nope don't touch
  for i := 0 to SIZE - 1 do
    for j := 0 to SIZE - 1 do
      seen[i][j] := False;

    //Let's begin
  startX := -1;
  startY := -1;
  for i := 0 to SIZE - 1 do
  begin
    for j := 0 to SIZE - 1 do
    begin
      if stronghold[i][j] = 0 then
      begin
        startX := i;
        startY := j;
        Break;
      end;
    end;
    if startX <> -1 then
      Break;
  end;


  if startX = -1 then
  begin
    connected := True;
    Exit;
  end;

  check(stronghold, startX, startY, seen);
  for i := 0 to SIZE - 1 do
  begin
    for j := 0 to SIZE - 1 do
    begin
      if (stronghold[i][i] = 1) and (seen[i][j]) then
      begin
        connected := False; 
        Exit;
      end;
    end;
  end;

  connected := True; 
end;

var
  stronghold: Tstronghold;
  i, j, errorCode: Integer;
  inputLine: string;
begin
  // don't touch from here
  for i := 0 to SIZE - 1 do
  begin
    ReadLn(inputLine); 
    for j := 0 to SIZE - 1 do
    begin
      Val(inputLine[j+1], stronghold[i][j], errorCode); 
    end;
  end;

  
  if connected(stronghold) then
    WriteLn('there are no weaknesses')
  else
    WriteLn('there are weaknesses');
end.
