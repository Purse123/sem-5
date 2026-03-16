package greedy is
   -- ######################################################
   --                  DATA TYPES
   -- ######################################################
   -- record defn
   type Item is record
      Weight : Float;
      Value : Float;
      Ratio : Float;
      Index : Integer;
   end record;
     
   -- Arr defn
   type Int_Array is array (Positive range <>) of Integer;
   type Item_Array is array (Positive range <>) of Item;
   
   -- ######################################################
   --                  View
   -- ######################################################
   --@method: DisplayArr
   --@param: Int_Array
   --@note: No '\n' trailing
   procedure DisplayArr (Arr : Int_Array);
   
   -- ######################################################
   --                  Methods
   -- ######################################################
   
   -- Function to get the step count
   procedure Get_Step_Count;
   
   -- Procedure to reset the step counter
   procedure Reset_Step_Count;

   --@method: Knapsack_Fractional
   --@breif: Greedy
   --@param: {Items}: Item_Array, Capactiy: Float
   --@return: Float
   --  function Knapsack_Fractional (Items: in out Item_Array; Capacity: Float) return Float;
   
private
   Count_Step : Integer := 0;
   
   --@breif: Sort item by ratio *desc*
   procedure SortByRatio(Items: in out Item_Array);
end greedy;
