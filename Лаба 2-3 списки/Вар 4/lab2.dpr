program lab2;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils;

type
  TPNote = ^TNote;
  TNote = record
    num: Integer;
    prev,next: TPNote;
  end;

var s: string;     k, min, i : integer;
    n,cod: integer;
    head,head2,tail,tmp: tpnote;

procedure AddRec(num: Integer);
var l,tmp: TPNote;
begin
  if Head = nil then
  begin
    tmp:=New(TPNote);
    Head:=tmp;
    Head^.Next:=nil;
    Head^.Prev:=nil;
  end
  else
  begin
    tmp:=Head;
    while tmp^.Next <> nil do
      tmp:= tmp^.Next;
    l:=tmp;
    tmp:= New(TPNote);
    l^.Next:=tmp;
    tmp^.Prev:=l;
    tmp^.Next:=nil;
  end;
  tail:=tmp;
  tmp^.num:=num;
end;

procedure AddRec2(num: Integer);
var x,tmp: TPNote;
begin
  if Head2 = nil then
  begin
    tmp:=New(TPNote);
    Head2:=tmp;
    Head2^.Next:=nil;
  end
  else
  begin
    tmp:=Head2;
    x:=Head2;
    if num < Head2^.num then
      begin
        tmp:=New(TPNote);
        tmp^.next:=Head2;
        Head2:=tmp;
      end
    else
    begin
      while tmp^.Next <> nil do
      begin
        if num > tmp^.num then x:=tmp;
        tmp:= tmp^.Next;
      end;
      tmp:=New(TPNote);
      tmp^.next:=x^.next;
      x^.next:=tmp;
    end;
  end;
  tmp^.num:=num;
end;

begin
  repeat
    write('������� �����: ');
    readln(S);

    if S = 'q' then break;

    val(S,n,cod);
    if ((length(S) <> 3) and (length(S) <> 7)) or (cod <> 0) or (S[1] = '0') then writeln('try again')
    else AddRec(n);

   // writeln;
  until false;

  writeln(#13#10,'������: ');
  tmp:=tail;
  repeat
    writeln(tmp^.num);
    if length(inttostr(tmp^.num)) = 7 then AddRec2(tmp^.num);
    tmp:=tmp.prev;
  until tmp=nil;

  writeln(#13#10,#13#10,'���������������� ������: ');
  tmp:=head2;  k:=0;
  while tmp <> nil do
  begin
    k := k + 1;
    writeln(tmp^.num);
    tmp:=tmp^.next;
  end;
//  tmp := head2;
//  min := tmp.num;
//  while k<>0 do
//  begin
//   if tmp.num<min then
//    begin
//     min := tmp.num;
//    end;
//  tmp := tmp.next;
//   if tmp = nil then
//    begin
//     writeln(min);
//     tmp := head2;
//     k:=k-1;
//     min := tmp.num;
//    end;
//  end;
  readln;
end.
