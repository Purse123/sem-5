with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body Iterative is
   -- ######################################################
   --                  Member
   -- ######################################################
   -- Page no: 101
   type Int_Array is 
     array (Positive range <>) of Integer;
   
   -- ######################################################
   --                  Methods
   -- ######################################################
   --@method: GCD
   --@breif: To find gcd
   --@param: a:int, b:int
   --@reutrn: int
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
   
   --@method: Fibonacci
   --@breif: print nth sequence of fib
   --@param: n:int nth term of seq
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
   
   --@method: SequentialSearch
   --@breif: Search array
   --@param: arr:(int*)array, key:int _search_item_
   --@reutrn: int _index_
   function SequentialSearch (Key : constant Integer) is
   begin
   end SequentialSearch;

end Iterative;

