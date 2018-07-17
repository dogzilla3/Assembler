{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p10_07 tests rule:                                           }
{35 statement -> while expression do statement                        }
{---------------------------------------------------------------------}
program p10_07;
  var count:integer;
begin{p10_07}
  count:=10;
  while count>=0 do count:=count-1
end{p10_07}.

