## Searching algorithm
___
- Linear search (i from 1 -> n to find) => O(n).
- Binary search: search from SORTED ARRAY by divide array half until found value or interval empty. => O(log n).
- Jump search: search from SORTED ARRAY. Suppose that an `arr` of size `n` devide to `m` blocks.
  - Find block `k` satify that arr[first elm in block `k`] <= key value < arr[first elm in block `k+1`].
  - Linear search in block `k` to find. => O( sqrt(n) ).  
- Interpolation search:
  - calculate: pos = lo + (x - arr[lo])*(hi - lo)/( arr[hi] - arr[lo] ).
    - x : element to be search
    - lo: starting index of arr
    - hi: ending index of arr
  - if(arr[pos] == x)   return;
  - if(x < arr[pos]), calculate with left sub-arr. Else calculate with right sub-arr.
  - Repeat until found or sub-array empty.
  - Time complexity:
    - If elements are uniformly distributed : O(log log n)
    - In worst case: O(n)

## Hash
___

Hash table support only the dictionary( key -value ) operator INSERT, SEARCH, DELETE with the complexity is O(1).

### Collision
In the case: 2 keys may hash to the sames slot => collision. 
Resolve the conflict created by collisions:

    - By chaining : place all element that hash same slot into same linked list.
    - Using open addressing algorithm:
      + h(k,i), i: start 0- > ... when found location that is empty. c,d : constant number
        + Linear probing: h(k,i) = (h'(k)+ci) mod m.
        + Quadratic probing: h(k,i) = (h'(k)+c*i + d*i^2) mod m.
        + Double hashing : h(k,i) = (h'(k)+i*h"(k)) mod m.
### Hash function
Good hash function have least collison.

- Division method: h(k) = k mod m (m : size hash table).
    - m should not be a power of 2 && should be a prime not too close to an exact power of 2.
- Multiplication method: 
    - h(k) = floor( m * (k*A - floor (k*A)) ).
    - A : constant in range (0,1)
- Digit extraction : address = select digits from Key. 
    - Example: `3`7`94`52 -> `394`
- Mide-square : address = middle digits of (Key^2).
    - Key^2 can be too large => can use a portion of the key. `379`452: `379*379` = 14`364`1 => `364` is key's location in hash table.
- Folding: The key is devided into parts whose size matches the address size.
    - Example: 123||456||789 -> folding : 123+456+789 = 1`368` => `368`.