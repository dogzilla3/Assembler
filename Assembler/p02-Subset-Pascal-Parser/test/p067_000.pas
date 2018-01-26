{------------------------------------------------------------------------------------}
{program p067_000 exercises production #067                                          }
{factor -> NOT factor                                                                }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p067_000;
  var a,b:boolean;
begin{p067_000}
  a:=false;b:=false;
  write(not(a and b));
  write(' = ');
  write(not a or not b);
  writeln
end{p067_000}.
