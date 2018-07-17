{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_09 tests rule 32                                         }
{variable -> id[expression] (boolean elements)                        }
{---------------------------------------------------------------------}
program p09_09;
  var a:array[5..14] of boolean;
  var b:boolean;
  var i:integer;
begin{p09_09}
  i:=3;
  b:=true;
  a[i+3]:=b;
  b:=a[i+2]
end{p09_09}.
