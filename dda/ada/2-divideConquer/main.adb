with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with DivideConquer; use DivideConquer;

procedure Main is
   BS_Idx : Integer;
   
   BS_Size : Positive := 5;
   BS_Arr : Int_Array(1..BS_Size) := (10, 20, 30, 40, 50);

begin
   -- Binary Search
   BS_Idx := BinarySearch (BS_Arr, 0, BS_Size, 20);
   if (BS_Idx = -1) then
      Put_Line("Key not found");
   else
      --            page no: 244          TRIM  vvvvvvvv
      Put("Key found on index: " & Integer'Image(BS_Idx));
   end if;
   New_Line;
     
   
end Main;
