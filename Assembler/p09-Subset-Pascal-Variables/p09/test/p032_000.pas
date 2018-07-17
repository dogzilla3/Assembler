{------------------------------------------------------------------------------------}
{program p032_000 exercises production #032                                          }
{statement -> IF expression THEN statement ELSE statement                            }
{------------------------------------------------------------------------------------}
{Author: Thomas R. Turner                                                            }
{E-Mail: trturner@uco.edu                                                            }
{Date: January, 2012                                                                 }
{------------------------------------------------------------------------------------}
{Copyright January, 2012 by Thomas R. Turner                                         }
{Do not reproduce without permission from Thomas R. Turner.                          }
{------------------------------------------------------------------------------------}
program p032_000;
  var cash:real;
begin{p032_000}
  writestring('How much cash do you have? ');
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
end{p032_000}.
