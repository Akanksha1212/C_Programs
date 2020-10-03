<ins>Bitwise Operators</ins>

- AND(&) : Outputs 1 if both the inputs 1 otherwise 0
- OR(|)  : Outputs 1 if either of the inputs are 1 otherwise 0
- XOR(^) : Outputs 1 if both the inputs are different(0-1 or 1-0) otherwise 0<br><br>
<ins>Properies of XOR operator</ins><br>
  1. X^0 = X
  2. X^Y = Y^X
  3. X^(Y^Z) = (X^Y)^Z
  4. X^X = 0
- Left Shift Operator(<<) : Left shifts the bit by given value<br><br>Ex: X<<1 and x=3 then X is left shifted by 1, i.e,<br> 0011 becomes 0110<br><br>
<ins>Property of Left Shift</ins><br> x<<y => X*2^y (When X is left shifted by Y then X is incresed by 2 to the power of Y times)<br><br>
- Right Shift Operator(>>) : Right shifts the bits by given value<br><br>Ex: X>>1 and X = 33 then X is right shifted by 1, i.e, <br> 100001 becomes 010000<br><br>
<ins>Property of Right Shift</ins><br>X>>Y => X/2^y (When X is right shifted by Y then X is decresed by 2 to the power of Y times)<br><br>
- Bitwise Not(~) : Toggles each bit of the number.

<br><ins>Check if Kth Bit is set or not</ins><br> if N is the number to be checked and K is the position to be checked,<br>(N & (1<<(K-1))) should not be 0 if Kth bit is set as the operation (1<<(K-1)) sets 1 at the Kth position.

<br><ins> Counting Set bits</ins><br>
Using Brain-Kernighan's Algorithm,<br>
1. While Number>0: 
2. Turn off Right most set bit
3. Increase count 

Turning off Right most set bit: N = (N&(N-1));<br>(N-1): When we substract 1 from a number we reverse all the digits from right most set bit.<br>So, N & (N-1) will unset that set bit.<br> Ex: N: 101000, (N-1): 100111, Doing AND Operation will give: 100000

<br><ins>Check if N is power of 2 or not</ins><br>
All the numbers which are power of 2 has only 1 bit set.
So if we turn off right most set bit then the number becomes zero,i.e,
X&(X-1) should return 0.
