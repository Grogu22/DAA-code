## Find the median of an unordered array using quickselect algorithm
The quickselect algorithm finds the k<sup>th</sup> smallest element of an array in linear time
### Algorithm :
```
// Returns the k-th smallest element of list within left..right inclusive
// (i.e. left <= k <= right).
function select(list, left, right, k) is
    if left = right then   // If the list contains only one element,
        return list[left]  // return that element
    pivotIndex  := ...     // select a pivotIndex between left and right,
                           // e.g., left + floor(rand() % (right − left + 1))
    pivotIndex  := partition(list, left, right, pivotIndex)
    // The pivot is in its final sorted position
    if k = pivotIndex then
        return list[k]
    else if k < pivotIndex then
        return select(list, left, pivotIndex − 1, k)
    else
        return select(list, pivotIndex + 1, right, k) 
```
The partition algorithm used here can be using Lomuto, Hoare or randomized
The tail recusrion can be eliminated using a loop :
```
function select(list, left, right, k) is
    loop
        if left = right then
            return list[left]
        pivotIndex := ...     // select pivotIndex between left and right
        pivotIndex := partition(list, left, right, pivotIndex)
        if k = pivotIndex then
            return list[k]
        else if k < pivotIndex then
            right := pivotIndex − 1
        else
            left := pivotIndex + 1
```
### Code :
<i><b>Note : </b>Here , we have used only the recursive quickselect algorithm<i>
