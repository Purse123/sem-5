with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with greedy; use greedy;

procedure Main is
   сйз : Positive := 5;
   арр : Int_Array(1..сйз) := (10, 20, 30, 40, 50);
begin
   DisplayArr(арр);
   New_Line;

end Main;
