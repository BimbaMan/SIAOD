program laba4;   //обратная польская запись

uses
  System.SysUtils;

type
  TPNote = ^TNote;
  TNote = record
    ch: Char;
    next: TPNote;
  end;

const chs: Set of Char = ['+','-','*','/','^', 'a' .. 'z','(',')'];
var head: TPNote;
    statement, res: String;
    c: Char;
    pr1, pr2, i, rank: Integer;

procedure AddElem(ch: Char);
var x,tmp: TPNote;
begin
  if Head = nil then
  begin
    tmp:=New(TPNote);
    Head:=tmp;
    Head^.Next:=nil;
  end
  else
  begin
    tmp:=Head;
    x:=Head;
    tmp:=New(TPNote);
    tmp^.next:=Head;
    Head:=tmp;
  end;
  tmp^.ch:=ch;
end;

function Take: char;
var tmp: TPNote;
begin
  tmp:=Head.next;
  result:=Head^.ch;

  case result of
      '+','-','*','/','^': dec(rank);
      'a' .. 'z': inc(rank);
  end;

  Dispose(Head);
  Head:=tmp;
end;

procedure Stack_prior;
begin
  if Head <> nil then
    begin
      case Head^.ch of    //В стеке
        '+','-': pr2:=2;
        '*','/': pr2:=4;
        '^': pr2:=5;
        'a' .. 'z': pr2:=8;
        '(': pr2:=0;
      end;
    end
  else pr2:=0;
end;

begin
  readln(statement);
  statement:=AnsiLowerCase(statement);
  res:='';
  rank:=0;

  i:=1;
  while i <= length(statement) do
  begin
    if statement[i] = ')' then
    begin
      while Head^.ch <> '(' do res:=res+Take;
      Take;
      inc(i);
      continue
    end;

    case statement[i] of    //Относительный
      '+','-': pr1:=1;
      '*','/': pr1:=3;
      '^': pr1:=6;
      'a' .. 'z': pr1:=7;
      '(': pr1:=9;
    end;

    Stack_prior;

    if pr1 > pr2 then AddElem(statement[i])
    else
    begin
      repeat
        res:=res+Take;
        Stack_prior;
      until pr1 > pr2;
      AddElem(statement[i]);
    end;

    inc(i);
  end;

   while Head <> nil do
   begin
    res:=res+Take;
   end;

  writeln(res);
  writeln(rank);
  readln;
end.

//  a+b*c-d/e*h
//  ((a+b)*d-k^x^y)/(m+n)
//  (a*(b-c^((d+e)/(g-h)))+i*(j+k-m/n))^(q-r*(s+t))
