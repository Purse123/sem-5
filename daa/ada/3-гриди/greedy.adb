with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

package body greedy is
   procedure Get_Step_Count is begin Put_Line("Steps: " & Integer'Image(Count_Step)); 
   end Get_Step_Count;
   procedure Reset_Step_Count is begin Count_Step := 0; end Reset_Step_Count;
   
   procedure DisplayArr (Arr : Int_Array) is
   begin
      Put("[");
      
      for I in Arr'Range loop
	 Put(Arr(I), Width => 3);
	 if I < Arr'Last then Put(", "); end if;
      end loop;
      
      Put("]");
   end DisplayArr;

   function BinarySearch (Arr : Int_Array; Left, Right, Key: Integer) return Integer is
      Mid, Result: Integer;
   begin

      Count_Step := Count_Step + 1;	--  comparison
      if Right < Left then 
	 Count_Step := Count_Step + 1;
	 return -1;
      end if;
      
      Mid := Left + (Right - Left) / 2;
      Count_Step := Count_Step + 4;
      
      Count_Step := Count_Step + 1;
      if Arr(Mid) = Key then 
	 Count_Step := Count_Step + 1;
	 return Mid;
      end if;
      
      Count_Step := Count_Step + 1;	--  comparision
      if Arr(Mid) < Key then 
	 Result := BinarySearch(Arr, Mid + 1, Right, Key);
	 Count_Step := Count_Step + 2;	--  assign & return
	 return Result;
      else
	 Result := BinarySearch(Arr, Left, Mid - 1, Key);
	 Count_Step := Count_Step + 2;	--  assign & return
	 return Result;
      end if;
   end BinarySearch;
   
   function MinMax (Arr : Int_Array; Left, Right : Integer) return MinMax_Res is
      Mid : Integer;
      Lres, Rres, Res : MinMax_Res;
   begin
      -- single element handler
      Count_Step := Count_Step + 1;
      if Left = Right then
	 Res.Min := Arr(Left);
	 Res.Max := Arr(Left);
	 Count_Step := Count_Step + 2; -- above \2$
	 Count_Step := Count_Step + 1; -- return
	 return Res;
      end if;
      
      -- two element handler
      Count_Step := Count_Step + 1;
      if Left + 1 = Right then
	 Count_Step := Count_Step + 1;
	 
	 if Arr(Left) < Arr(Right) then
	    Res.Min := Arr(Left);
	    Res.Max := Arr(Right);
	    Count_Step := Count_Step + 2;
	 else
	    Res.Max := Arr(Left);
	    Res.Min := Arr(Right);
	    Count_Step := Count_Step + 2;
	 end if;
	 Count_Step := Count_Step + 1;
	 return Res;
      end if;
      
      --  divide
      Mid := (Left + Right) / 2;
      Count_Step := Count_Step + 3;
      
      -- subproblem
      Lres := MinMax(Arr, Left, Mid);
      Count_Step := Count_Step + 1;
      Rres := MinMax(Arr, Mid + 1, Right);
      Count_Step := Count_Step + 1;
      
      -- combine
      Count_Step := Count_Step + 1;
      if (Rres.Max > Lres.Max) then 
	 Res.Max := Rres.Max;
	 Count_Step := Count_Step + 1;
      else Res.Max := Lres.Max; end if;
      
      Count_Step := Count_Step + 1;
      if (Rres.Min > Lres.Min) then 
	 Res.Min := Lres.Min;
	 Count_Step := Count_Step + 1;
      else Res.Min := Rres.Min; end if;
      
      Count_Step := Count_Step + 1;
      return Res;
   end MinMax;
   
end greedy;
