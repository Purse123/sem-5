with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with greedy; use greedy;

procedure Main is
   FKnap_Capacity : Float := 50.0;
   FKnap_Size : Integer := 3;
   -- {Weight, Value, Ratio} : Float; Index : Integer;
   FKnap_Items : Item_Array (1..FKnap_Size) := (
     (Weight => 10.0, Value => 60.0, Ratio => 0.0, Index => 0),
     (Weight => 20.0, Value => 100.0, Ratio => 0.0, Index => 0),
     (Weight => 30.0, Value => 120.0, Ratio => 0.0, Index => 0)
   );
   
begin
   --#######################################################
   --                 FRACTIONAL KNAPSACK
   --#######################################################
   Put_Line("Fractional Knapsack Problem");
   Put_Line("Capacity: " & Float'Image(FKnap_Capacity));
   New_Line;
   
   Put_Line("Available Items:");
   for I in FKnap_Items'Range loop
      Put("Item " & Integer'Image(I) & ": ");
      Put("Weight=" & Float'Image(FKnap_Items(I).Weight));
      Put(", Value=" & Float'Image(FKnap_Items(I).Value));
   New_Line;
   end loop;
   
   New_Line;
end Main;
