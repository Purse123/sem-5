package Iterative is
   -- ######################################################
   --                  Member
   -- ######################################################
   -- Page no: 101
   type Int_Array is array (Positive range <>) of Integer;
   
   -- ######################################################
   --                  Methods
   -- ######################################################
   --@method: GCD
   --@breif: To find gcd
   --@param: a:int, b:int
   --@reutrn: int
   function Gcd (A, B : Integer) return Integer;
   
   --@method: Fibonacci
   --@breif: print nth sequence of fib
   --@param: n:int nth term of seq
   procedure Fibonacci (N : Integer);
   
   --@method: SequentialSearch
   --@breif: Search array O(n)
   --@param: Count:int key:int _search_item_, Arr: Int_Array(positive range<>)
   --@reutrn: int _index_
   function SequentialSearch (Arr: Int_Array; Key: Integer) return Integer;
   
   --@method: BubbleSort
   --@breif: Sort array O(n**2)
   --@param: 
   --  Arr : in Int_Array      -- read-only  **default: const&**
   --  Arr : out Int_Array     -- write-only **uninitialized output buffer**
   procedure BubbleSort (Arr : in out Int_Array);
   
private
   -- vector data_
   procedure Swap (A, B : in out Integer);
end Iterative;
