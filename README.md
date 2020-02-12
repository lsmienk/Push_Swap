# Push_Swap
A sorting algorithm plus a checker

## <b> Introduction: </b><br>
Push swap is the sixth 42 assignment when going to the algorithm branch. It consists of a sorting algorithm in which we can only use two stacks: stack a and stack b. And 11 movements:

sa, sb and ss: to swap the two first integers of stack a, stack b, or both.
pa and pb: to push the first integer of stack a to stack b, or the the other way around.
ra, rb and rr: to send the first integer in stack a, stack b, or both to the end of its respective stack.
rra, rrb and rrr: to send the last integer in stack a, stack b, or both to the start of the its respective stack.
<br> <br>
For this project we made two programs, push swap, which takes a list of integers as parameters and prints all necessary moves to sort it. The other one is checker, that takes the same list of integers, reads the moves written by push swap, and checks if it is sorted or not. if it is sorted it returns OK, otherwise it returns KO. Both checker and push swap have error management, where if you input the same integers twice, a non numeric number, or a value above MAX or below MIN integer value, it will display Error right away.

```
- Usage:
./push_swap "integer stack"
./checker "integer stack"
```
