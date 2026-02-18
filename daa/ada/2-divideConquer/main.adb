with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with DivideConquer; use DivideConquer;

procedure Main is
   BS_Idx : Integer;
   BS_Size : Positive := 5;
   BS_Key : Positive := 20;
   BS_Arr : Int_Array(1..BS_Size) := (10, 20, 30, 40, 50);
   
   MinMax_Size : Positive := 5;
   MinMax_Arr : Int_Array(1..MinMax_Size) := (5, 2, 8, 1, 9);
   MinMax_Result : MinMax_Res;
begin
   -- Binary Search
   BS_Idx := BinarySearch (BS_Arr, 0, BS_Size, BS_Key);
   if (BS_Idx = -1) then
      Put_Line("Key not found");
   else
      --            page no: 244          TRIM  vvvvvvvv
      Put_Line("Key found on index: " & Integer'Image(BS_Idx));
   end if;
   Get_Step_Count;
   Reset_Step_Count;
   New_Line;
   
   -- Min Max Search
   Put("Array: ");
   DisplayArr(MinMax_Arr);
   New_Line;
   
   MinMax_Result := MinMax(MinMax_Arr, MinMax_Arr'First, MinMax_Arr'Last);
   Put_Line("Minimum: " & Integer'Image(MinMax_Result.Min));
   Put_Line("Maximum: " & Integer'Image(MinMax_Result.Max));
   
   Get_Step_Count;
   Reset_Step_Count;
   New_Line;

end Main;
