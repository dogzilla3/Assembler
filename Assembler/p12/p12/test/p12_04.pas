{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{---------------------------------------------------------------------}
program p12_04;
  var cash:real;
begin{p12_04}
  writestring('How much cash to you have?');
  writeln;
  readreal(cash);
  readln;
  if cash<100.00 then
    begin
      writestring('You wicked and slothful person.');
      writeln;
      writestring('I''d never go out with you!');
      writeln
    end
  else
    begin
      writestring('Come on honey, let''s have a good time tonight!');
      writeln
    end;
  writestring('I''ll see you later.');
  writeln
end{p12_04}.
