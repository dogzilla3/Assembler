{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p10_04 tests rule:                                           }
{33 statement -> procedure_statement                                  }
{---------------------------------------------------------------------}
program p10_04;
  var k:integer;
  var c:boolean;
  procedure p(i:integer;b:boolean);
  begin{p}
  end{p};
begin{p10_04}
  k:=39; c:=true;
  p(k+5,not c)
end{p10_04}.

