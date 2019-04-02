# 42 algorithmic project: push_swap

The push_swap project is a number sorting program in C, using two stacks. The goal of the assignment is to create a program able to **sort** any amount of (different) numbers using a **given set of operations** on two number stacks. There is also another constraint: the sorting has to be done in the **least amount of moves possible**.

## How it works

When I tried implementing any of the well-known pre-existing sorting algorithms (i.e *bubble sort*, *insertion sort*, etc..), with the constraints from the subject, the results were less than satisfying, especially concerning the amount of moves.

Instead, I decided to use three different *kinda* simple algorithms, covering **three cases**. I couldn't find an algorithm that was appropriate to single-handedly cover all three cases.

* ### Three numbers or less

In the case where there are only three or two numbers, the first algorithm will very efficiently sort the numbers in less than three moves, by applying the appropriate combination of *swaps* and *rotations* on the first stack, never using the second.

* ### Small amount of numbers (less than 8)

In this case, the second algorithm will push the *smallest* number to the second stack, and will continue to do so until there are only three numbers left. The second stack is thus *reverse-sorted*. It will then apply the algorithm from the first case on the first stack, then push everything from the second stack back to the first.

* ### Every other case

In the case where there are more than 8 numbers, my algorithm will calculate which number requires the *least amount of moves* to be pushed to the second stack while keeping the second stack *reverse-sorted*. That means it will simulate at **every** cycle, pushing **each** number from the first stack to the second, at the right spot to keep it *reverse-sorted*, and decide to push the one that took the **least amount of moves**. When that awful idea is over, it then pushes everything from the second stack back to the first.

Doing so takes an **enormous amount of time**, compared to using usual predetermined algorithms that do the same thing for every case. However, the assignment was asking us to sort the numbers in the least amount of *moves*, not the least amount of *time*, and my program does that quite nicely.
<br><br>
During future changes, I plan on implementing every known sorting algorithm, and the user might choose which one he wants to use by specifying it with a flag when launching the program.

## The checker program

The checker program simply checks if the instructions we feed it on the standard input manage to sort the given numbers. It is very useful when checking if the push_swap program outputs a valid answer; simply by using it like <br> `./push_swap x x x x | ./checker x x x x`
