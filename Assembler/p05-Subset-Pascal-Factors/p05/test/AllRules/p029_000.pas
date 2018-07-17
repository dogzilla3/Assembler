{------------------------------------------------------------------------------------}
{program p029_000 exercises production #029                                          }
{statement -> variable := expression                                                 }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p029_000;
  function max(a,b:integer):integer;
  begin{max}
    if a>b then max:=a else max:=b
  end{max};
  procedure print(a:integer;b:integer);
  begin{print}
    write('The maximum of ');
    write(a);
    write(' and ');
    write(b);
    write(' is ');
    write(max(a,b));
    writeln
  end{print};
begin{p029_000}
  print(2,3)
end{p029_000}.
