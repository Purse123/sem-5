with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body Iterative is
   procedure Get_Step_Count is begin Put_Line(Integer'Image(Count_Step)); 
   end Get_Step_Count;
   procedure Reset_Step_Count is begin Count_Step := 0; end Reset_Step_Count;

   function Gcd (A, B : Integer) return Integer is
      Temp: Integer;
      X: Integer := A;
      Y: Integer := B;
   begin
      if X < 0 then X := -X; Count_Step := Count_Step + 2;
      else Count_Step := Count_Step + 1; end if;
      
      if Y < 0 then Y := -Y; Count_Step := Count_Step + 2; 
      else Count_Step := Count_Step + 1; end if;
      
      while Y /= 0 loop
	 Count_Step := Count_Step + 1;	--  loop condition check
	 
	 Temp := X mod Y;
	 Count_Step := Count_Step + 1;
	 
	 X := Y;
	 Count_Step := Count_Step + 1;
	 
	 Y := Temp;
	 Count_Step := Count_Step + 1;
      end loop;
      Count_Step := Count_Step + 1; 	--  false condition check
      
      return X;
   end Gcd;
   
   procedure Fibonacci (N : Integer) is
      A: Integer := 0;
      B: Integer := 1;
      Temp: Integer;
   begin
      if N <= 0 then 
	 Count_Step := Count_Step + 1;
	 Put_Line("Expected input: unsigned number"); 
	 return; 
      end if;
      
      Put("Fibonacci sequence upto " & Integer'Image(N) & ": ");
      if N >= 1 then 
	 Count_Step := Count_Step + 1;
	 Put(Integer'Image(A)); 
      end if;
      if N >= 2 then 
	 Count_Step := Count_Step + 1;
	 Put(Integer'Image(B)); 
      end if;
      
      for I in 3 .. N loop
	 Count_Step := Count_Step + 1;
	 
	 Temp := A + B;
	 Count_Step := Count_Step + 1;
	 
	 Put(Integer'Image(Temp));
	 
	 A := B;
	 Count_Step := Count_Step + 1;
	 B := Temp;
	 Count_Step := Count_Step + 1;
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
   
   procedure SelectionSort (Arr : in out Int_Array) is
      Min_Idx : Integer;
   begin
      for J in Arr'First .. Arr'Last - 1 loop
	 Min_Idx := J;
	 
	 -- Min handler
	 for I in J + 1 .. Arr'Last loop
	    if Arr(I) < Arr(Min_Idx) then
	       Min_Idx:= I;
	    end if;
	 end loop;
	 
	 if Min_Idx /= J then Swap(Arr(J), Arr(Min_Idx)); end if;
      end loop;
   end SelectionSort;
   
   procedure InsertionSort (Arr : in out Int_Array) is
      Key : Integer;
      J   : Integer;
   begin
      for I in Arr'First + 1 .. Arr'Last loop
	 Key := Arr(I);
	 J := I - 1;
	 
	 while J >= Arr'First and then Arr(J) > Key loop
	    Arr(J + 1) := Arr(J);
	    J := J - 1;
	 end loop;
	 
	 Arr(J + 1) := Key;
      end loop;
   end InsertionSort;
   
   procedure DisplayArr (Arr : Int_Array) is
   begin
      Put("[");
      
      for I in Arr'Range loop
	 Put(Arr(I), Width => 3);
	 if I < Arr'Last then Put(", "); end if;
      end loop;
      
      Put("]");
   end DisplayArr;
   
end Iterative;
