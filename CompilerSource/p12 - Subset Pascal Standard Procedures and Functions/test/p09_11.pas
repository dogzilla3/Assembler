{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_11 tests rule 32                                         }
{variable -> id[expression] (integer elements)                        }
{---------------------------------------------------------------------}
program p09_11;
  var a:array[5..14] of integer;
  var b:integer;
  var i:integer;
begin{p09_11}
  i:=3;
  b:=13;
  a[i+3]:=b;
  b:=a[i+2]
end{p09_11}.
