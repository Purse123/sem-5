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
   
   procedure SortByRatio(Items: in out Item_Array) is
      Temp : Item;
   begin
      for I in Items'First .. Items'Last - 1 loop
	 for J in I + 1 .. Items'Last loop 
	    if Items(I).Ratio < Items(J).Ratio then
	       Temp := Items(I);
	       Items(I) := Items(J);
	       Items(J) := Temp;
	    end if;
	 end loop;
      end loop;
   end SortByRatio;
   
   function Knapsack_Fractional (Items: in out Item_Array; Capacity: Float) return Float is
      Current_Weight : Float := 0.0;
      Final_Value    : Float := 0.0;
      Remaining_Capacity : Float;
      Fraction : Float;
   begin
      -- Calculate ratios
      for I in Items'Range loop
	 Items(I).Ratio := Items(I).Value / Items(I).Weight;
	 Items(I).Index := I;
      end loop;
      
      SortByRatio(Items);
      
      for I in Items'Range loop
	 if Current_Weight + Items(I).Weight <= Capacity then
	    -- Take whole item
            Current_Weight := Current_Weight + Items(I).Weight;
            Final_Value := Final_Value + Items(I).Value;
            Put_Line("Taken item " & Integer'Image(Items(I).Index) & 
	      " (whole): Weight=" & Float'Image(Items(I).Weight));
         else
            -- Take fraction of item
            Remaining_Capacity := Capacity - Current_Weight;
            Fraction := Remaining_Capacity / Items(I).Weight;
            Final_Value := Final_Value + (Items(I).Value * Fraction);
            
            Put_Line("Taken item " & Integer'Image(Items(I).Index) & 
	      " (fraction): " & Float'Image(Fraction * 100.0) & "%");
            exit;
         end if;
      end loop;
      
      return Final_Value;
   end Knapsack_Fractional;
   
end greedy;
