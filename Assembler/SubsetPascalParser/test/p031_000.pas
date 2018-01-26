{------------------------------------------------------------------------------------}
{program p031_000 exercises production #031                                          }
{statement -> compound_statement                                                     }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p031_000;
  var cash:real;
begin{p031_000}
  write('How much cash do you have? ');
  readln(cash);
  if cash<100.0 then
    begin
      writeln('You wicked and slothful person.');
      writeln('I''d never go out with you.')
    end
  else
    begin
      writeln('Come on, honey, let''s have a good time tonight!')
    end;
  writeln('See you later!')
end{p031_000}.
