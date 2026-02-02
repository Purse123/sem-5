with Ada.Text_IO; use Ada.Text_IO;
with Iterative; use Iterative;

procedure Main is
   GCD_A : Integer := 20;
   GCD_B : Integer := 16;
   
   FIB_N: Integer := 8;
   
   SeqSearch_Size : Positive := 20;
   SeqSearch_Arr : Int_Array(0..SeqSearch_Size) := (10, 20, 30, 40, 50);
   
begin
   -- print array
   -- search and return key index
   return;
   Fibonacci(FIB_N);
   
   Put_Line("GCD(" & Integer'Image(GCD_A) & "," & Integer'Image(GCD_B) & ")= " & Integer'Image(Gcd(GCD_A, GCD_B)));
   
end Main;

-- array: page 71
