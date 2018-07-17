{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_08 tests rule 31                                         }
{variable -> id (real function)                                       }
{---------------------------------------------------------------------}
program p09_08;
  var a:real;
  function b:real;
  begin{b}
    b:=3.14159
  end{b};
begin{p09_08}
  a:=b
end{p09_08}.
