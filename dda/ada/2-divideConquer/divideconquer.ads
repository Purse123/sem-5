package divideConquer is
   -- ######################################################
   --                  Member
   -- ######################################################
   -- Page no: 101
   type Int_Array is array (Positive range <>) of Integer;
   
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
   --@method: BinarySearch
   --@breif: Searching algo
   --@param: {Arr}:Array,
   --    {left, right, key}:int
   --@return: int
   function BinarySearch (Arr : Int_Array; Left, Right, Key: Integer) return Integer;
   
private
   -- vector data_
   
end DivideConquer;
