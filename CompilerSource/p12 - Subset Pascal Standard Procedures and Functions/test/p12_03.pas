{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{---------------------------------------------------------------------}
program p12_03;
  var count:integer;
begin{p12_03}
  count:=10;
  while count>=0 do
  begin
    writeinteger(count,2);
    writestring(', ');
    count:=count-1
  end;
  writestring(' Blast Off!');
  writeln
end{p12_03}.
