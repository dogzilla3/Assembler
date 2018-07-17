{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p09_15 tests rule 34                                         }
{procedure_statement -> id(expression_list)                           }
{---------------------------------------------------------------------}
program p09_15;
  var i:integer;
  var r:real;
  procedure p(i:integer;r:real);
  begin{p}
  end{p};
begin{p09_15}
  i:=17;
  r:=1.602e-19;
  p(i+7,r+3.14159)
end{p09_15}.
