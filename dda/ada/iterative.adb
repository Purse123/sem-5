with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body Iterative is
   function Gcd (A, B : Integer) return Integer is
      Temp: Integer;
      X: Integer := A;
      Y: Integer := B;
   begin
      if X < 0 then X := -X; end if;
      if Y < 0 then Y := -Y; end if;
      
      while Y /= 0 loop
	 Temp := X mod Y;
	 X := Y;
	 Y := Temp;
      end loop;
      return X;
   end Gcd;
   
   procedure Fibonacci (N : Integer) is
      A: Integer := 0;
      B: Integer := 1;
      Temp: Integer;
   begin
      if N <= 0 then Put_Line("Expected input: unsigned number"); return; end if;
      
      Put("Fibonacci sequence upto " & Integer'Image(N) & ": ");
      if N >= 1 then Put(Integer'Image(A)); end if;
      if N >= 2 then Put(Integer'Image(B)); end if;
      
      for I in 3 .. N loop
	 Temp := A + B;
	 Put(Integer'Image(Temp));
	 A := B;
	 B := Temp;
      end loop;
      
      New_Line;
   end Fibonacci;
   
   function SequentialSearch (Arr: Int_Array; Key: Integer) return Integer is
   begin
      for I in Arr'Range loop
	 if Arr(I) = Key then return I; end if;
      end loop;
      
      return -1;
   end SequentialSearch;
   
   procedure Swap (A, B : in out Integer) is
      Temp : Integer := A;
   begin
      A := B;
      B := Temp;
   end Swap;
   
   procedure BubbleSort (Arr : in out Int_Array) is
   begin
      for J in 1 .. Arr'Last - 1 loop
	 for I in Arr'First..Arr'Last - J loop
	    if Arr(I) > Arr(I + 1) then 
	       Swap(Arr(I), Arr(I + 1)); 
	    end if;
	 end loop;
      end loop;
   end BubbleSort;
   
end Iterative;
