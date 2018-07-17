{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p10_06 tests rule:                                           }
{35 statement -> if expression then statement else statement          }
{---------------------------------------------------------------------}
program p10_06;
  var cash:real;
  var i_will_go_out_with_you:boolean;
begin{p10_06}
  cash:=95.0;
  if cash<100.00 then 
    i_will_go_out_with_you:=true
  else
    i_will_go_out_with_you:=false
end{p10_06}.

