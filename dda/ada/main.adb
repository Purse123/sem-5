with Ada.Text_IO; use Ada.Text_IO;
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

begin
   -- Fibonacci
   Fibonacci(FIB_N);
   New_Line;
   
   -- GCD
   Put_Line("GCD(" & Integer'Image(GCD_A) & "," & Integer'Image(GCD_B) & ")= " & Integer'Image(Gcd(GCD_A, GCD_B)));
   New_Line;
   
   -- Sequential search
   for I in SeqSearch_Arr'Range loop
      Put (Integer'Image(SeqSearch_Arr(I)));
   end loop;
   New_Line;
   
   -- search and return key index
   SeqSearch_Pos := SequentialSearch(SeqSearch_Arr, SeqSearch_Key);
   if SeqSearch_Pos /= -1 then
      Put_Line("Key" & Integer'Image(SeqSearch_Key) & " found at position " & Integer'Image(SeqSearch_Pos));
   else Put_Line("Key not found");
   end if;
   New_Line;
   
   -- Bubble sort
   BubbleSort (Bubble_Arr);
   for I in Bubble_Arr'Range loop
      Put (Integer'Image(Bubble_Arr(I)));
   end loop;
   New_Line;
   
end Main;

-- array: page 71
