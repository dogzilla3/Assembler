{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_05 tests rule 31                                         }
{variable -> id (boolean function)                                    }
{---------------------------------------------------------------------}
program p09_05;
  var a:boolean;
  function b:boolean;
  begin{b}
    b:=false
  end{b};
begin{p09_05}
  a:=b
end{p09_05}.
