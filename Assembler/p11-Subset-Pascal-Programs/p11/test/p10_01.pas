{---------------------------------------------------------------------}
{Author: Thomas R Turner                                              }
{E-Mail: trturner@uco.edu                                             }
{Date:   April, 2018                                                  }
{Copyright April, 2018 by Thomas R Turner                             }
{Do not reproduce without permission from Thomas R Turner             }
{---------------------------------------------------------------------}
{Program p10_01 tests rules:                                          }
{41 expression_list -> expression                                     }
{42 expression_list -> expression_list , expression                   }
{---------------------------------------------------------------------}
program p10_01;
  var a,b:integer;
  var u,v:real;
  function f(i:integer;r:real):real;
  begin{f}
    f:=i+r
  end{f};
begin{p10_01}
  a:=2; b:=3;
  u:=5.0; v:=7.0;
  u:=f(a+b*6,u+v*9.8)
end{p10_01}.
