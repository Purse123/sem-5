package divideConquer is
   -- ######################################################
   --                  Member
   -- ######################################################
   -- Page no: 101
   type Int_Array is array (Positive range <>) of Integer;
   
   -- Chapter:6, pg-no:65
   type MinMax_Res is record
      Min, Max : Integer;
   end record;
   -- seems like this Scheiße
   -- type Point (X, Y : Natural) is record null; end record; -- pg: 102
   
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

   --@method: BinarySearch
   --@breif: Searching algo
   --@param: {Arr}:Array,
   --    {left, right, key}:int
   --@return: int
   function BinarySearch (Arr : Int_Array; Left, Right, Key: Integer) return Integer;
   
   --@method: MinMax
   --@breif: Find the Min and Max by using partitioning like merge sort
   --@param: {Arr}:Array,
   --    {left, right, key}:int
   --@return: @{MinMax_Res}: record
   --@see: @member
   function MinMax (Arr : Int_Array; Left, Right : Integer) return MinMax_Res;
private
   Count_Step : Integer := 0;
end DivideConquer;
