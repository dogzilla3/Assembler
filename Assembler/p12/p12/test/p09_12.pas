{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_12 tests rule 32                                         }
{variable -> id[expression] (real elements)                           }
{---------------------------------------------------------------------}
program p09_12;
  var a:array[5..14] of real;
  var b:real;
  var i:integer;
begin{p09_12}
  i:=3;
  b:=3.14159e1;
  a[i+3]:=b;
  b:=a[i+2]
end{p09_12}.
