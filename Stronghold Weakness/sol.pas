program ConnectedOnes;

const
  SIZE = 5;

type
  TGrid = array[0..SIZE-1, 0..SIZE-1] of Integer;
  TVisited = array[0..SIZE-1, 0..SIZE-1] of Boolean;
  TDirection = array[0..7] of Integer;

const
  dx: TDirection = (-1, -1, -1, 0, 0, 1, 1, 1);
  dy: TDirection = (-1, 0, 1, -1, 1, -1, 0, 1);

// Function to check if two grid coordinates are within bounds
function IsValid(x, y: Integer): Boolean;
begin
  IsValid := (x >= 0) and (x < SIZE) and (y >= 0) and (y < SIZE);
end;

// Depth-first search procedure to mark connected cells as visited
procedure DFS(var grid: TGrid; x, y: Integer; var visited: TVisited);
var
  i, newX, newY: Integer;
begin
  // Mark the current cell as visited
  visited[x][y] := true;

  // Explore the adjacent cells
  for i := 0 to 7 do
  begin
    newX := x + dx[i];
    newY := y + dy[i];

    // Check if the adjacent cell is valid and contains a '1' and has not been visited
    if IsValid(newX, newY) and (grid[newX][newY] = 1) and (not visited[newX][newY]) then
    begin
      // Recursively call DFS for the adjacent cell
      DFS(grid, newX, newY, visited);
    end;
  end;
end;

// Function to check if all '1's are connected in the grid
function IsConnected(var grid: TGrid): Boolean;
var
  visited: TVisited;
  i, j, startX, startY: Integer;
begin

  for i := 0 to SIZE - 1 do
    for j := 0 to SIZE - 1 do
      visited[i][j] := False;

  startX := -1;
  startY := -1;
  for i := 0 to SIZE - 1 do
  begin
    for j := 0 to SIZE - 1 do
    begin
      if grid[i][j] = 1 then
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
    IsConnected := True;
    Exit;
  end;

  DFS(grid, startX, startY, visited);
  for i := 0 to SIZE - 1 do
  begin
    for j := 0 to SIZE - 1 do
    begin
      if (grid[i][j] = 1) and (not visited[i][j]) then
      begin
        IsConnected := False; 
        Exit;
      end;
    end;
  end;

  IsConnected := True; 
end;

var
  grid: TGrid;
  i, j, errorCode: Integer;
  inputLine: string;
begin
  // Input grid initialization
  for i := 0 to SIZE - 1 do
  begin
    ReadLn(inputLine); 
    for j := 0 to SIZE - 1 do
    begin
      Val(inputLine[j+1], grid[i][j], errorCode); 
    end;
  end;

  // Check if all '1's are connected
  if IsConnected(grid) then
    WriteLn('there are no weaknesses')
  else
    WriteLn('there are weaknesses');
end.
