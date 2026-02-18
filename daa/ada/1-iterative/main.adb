with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Strings; use Ada.Strings;
with Ada.Strings.Fixed; use Ada.Strings.Fixed;
with Ada.Strings.Maps; use Ada.Strings.Maps;
with Iterative; use Iterative;

procedure Main is
   GCD_A : Integer := 20;
   GCD_B : Integer := 16;
   
   FIB_N: Integer := 8;
   
   SeqSearch_Size : Positive := 5;
   SeqSearch_Arr : Int_Array(1..SeqSearch_Size) := (20, 30, 10, 50, 40);
   SeqSearch_Pos : Integer;
   SeqSearch_Key : Positive := 30;
   
   Bubble_Size : Positive := 5;
   Bubble_Arr : Int_Array(1..Bubble_Size) := (20, 30, 10, 50, 40);
   Bubble_Pos : Integer;
   
   Selection_Size : Positive := 5;
   Selection_Arr : Int_Array(1..Selection_Size) := (80, 15, 0, 20, 55);
   Selection_Pos : Integer;
   
   Insertion_Size : Positive := 5;
   Insertion_Arr : Int_Array(1..Insertion_Size) := (85, 15, 18, 25, 40);
   Insertion_Pos : Integer;

begin
   -- Fibonacci
   Fibonacci(FIB_N);
   New_Line;
   
   -- GCD
   Put_Line("GCD(" & Trim(Integer'Image(GCD_A), Left) & "," 
     & Trim(Integer'Image(GCD_B), Left) & "): " 
     & Integer'Image(Gcd(GCD_A, GCD_B)));
   Get_Step_Count;
   Reset_Step_Count;
   New_Line;
   
   -- Sequential search
   DisplayArr(SeqSearch_Arr);
   New_Line;
   
   -- search and return key index
   SeqSearch_Pos := SequentialSearch(SeqSearch_Arr, SeqSearch_Key);
   if SeqSearch_Pos /= -1 then
      Put_Line("Key" & Integer'Image(SeqSearch_Key) & " found at position: " & Integer'Image(SeqSearch_Pos));
   else Put_Line("Key not found");
   end if;
   New_Line;
   
   -- Bubble sort
   Put_Line("Bubble Sort:");
   BubbleSort (Bubble_Arr); DisplayArr (Bubble_Arr);
   New_Line;
   
   -- Selection sort
   Put_Line("Selection Sort:");
   SelectionSort (Selection_Arr); DisplayArr (Selection_Arr);
   New_Line;
   
   -- Insertion sort
   Put_Line("Insertion Sort:");
   InsertionSort (Insertion_Arr); DisplayArr (Insertion_Arr);
   New_Line;
   
end Main;
