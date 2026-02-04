with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Iterative is
   function Gcd (A,B : Integer) return Integer;
   
   A : Integer := 20;
   B : Integer := 15;
   Result : Integer;
begin
   --  Put ("Enter A and B for GCD(A, B): ");
   --  Get (A); Get (B);
   Result := Gcd(A, B);
   Put_Line("GCD: " & Integer'Image(Result));
end Iterative;

seperate(Iterative)
function Gcd (A,B : Integer) return Integer is
   Temp: Integer;
   X: Integer := A;
   Y: Integer := B;
begin
   while Y /= 0 loop
      Temp := X mod Y;
      X := Y;
      Y := Temp;
   end loop;
   return X;
end Gcd;
