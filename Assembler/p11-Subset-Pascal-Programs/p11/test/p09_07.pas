{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_07 tests rule 31                                         }
{variable -> id (integer function)                                    }
{---------------------------------------------------------------------}
program p09_07;
  var a:integer;
  function b:integer;
  begin{b}
    b:=31
  end{b};
begin{p09_07}
  a:=b
end{p09_07}.
