{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p10_02 tests rule:                                           }
{32 statement -> variable := expression                               }
{---------------------------------------------------------------------}
program p10_02;
  var a,b,c,d:integer;
begin{p10_02}
  b:=3; c:=5; d:=7;
  a:=b+c*d;
  a:=b-c div d
end{p10_02}.
