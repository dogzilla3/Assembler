{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_10 tests rule 32                                         }
{variable -> id[expression] (char elements)                           }
{---------------------------------------------------------------------}
program p09_10;
  var a:array[5..14] of char;
  var b:char;
  var i:integer;
begin{p09_10}
  i:=3;
  b:='x';
  a[i+3]:=b;
  b:=a[i+2]
end{p09_10}.
