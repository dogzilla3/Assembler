{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_06 tests rule 31                                         }
{variable -> id (character function)                                  }
{---------------------------------------------------------------------}
program p09_06;
  var a:char;
  function b:char;
  begin{b}
    b:='b'
  end{b};
begin{p09_06}
  a:=b
end{p09_06}.
