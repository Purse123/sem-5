with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body DivideConquer is
   function BinarySearch (Arr : Int_Array; Left, Right, Key: Integer) return Integer is
      Mid: Integer;
   begin
      if Right < Left then 
	 return -1;
      end if;
      
      Mid := Left + (Right - Left) / 2;
      
      if Arr(Mid) = Key then return Mid;
      elsif Arr(Mid) < Key then return BinarySearch(Arr, Mid + 1, Right, Key);
      else return BinarySearch(Arr, Left, Mid - 1, Key);
      end if;
   end BinarySearch;
   
   procedure DisplayArr (Arr : Int_Array) is
   begin
      Put("[");
      
      for I in Arr'Range loop
	 Put(Arr(I), Width => 3);
	 if I < Arr'Last then Put(", "); end if;
      end loop;
      
      Put("]");
   end DisplayArr;
   
end DivideConquer;
