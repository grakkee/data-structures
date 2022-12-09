# Homework 2

## Project Goals
The goal of this project is to:
1.	Familiarize students with **stacks**
2.  Familiarize students with the **using Data Structures**.

## Program
We commonly write arithmetic expressions in the so-called infix form. That is, with each operator placed between its operand, as below:  
<p align="center">
(5+6)\*(4/3)  </p>

Although we are comfortable writing expressions in this form, infix form has the disadvantage that parentheses must be used to indicate the order in which operators
are to be evaluated. These parentheses, in turn, complicate the evaluation process. Evaluation is much easier if we can simply evaluate operators from left to right.
Unfortunately, this evaluation will not work with the infix form of arithmetic expressions. However, it will work if the expression is in postfix form. In the postfix form of an arithmetic expression, each operator is placed immediately after its operands. The expression above is written in postfix form as
<p align="center">
56+43/*  </p>

Note that both forms place the numbers in the same order (reading from left to right). The order of the operators is different, however, because the operators in the postfix form are positioned in the order that they are evaluated. The resulting postfix expression is hard to read at first, but it is easy to evaluate programmatically. We will do so with stacks. Suppose you have an arithmetic expression in postfix form that consists of a sequence of single digit, nonnegative integers and the four basic arithmetic operators (+,-,\*,/). This expression can be evaluated using the following algorithm in conjuction with a stack of floating-point numbers.

Read the expression character-by-character. As each character is read in:
*	If the character corresponds to a single digit number (characters ‘0’ to ‘9’), then push the corresponding floating-point number onto the stack.
*	If the character corresponds to one of the arithmetic operators (characters ‘+’, ‘-‘, ‘\*’, ‘/’), then 
    * Pop a number off of the stack. Call it operand1.
    * Pop a number off of the stack. Call it operand 2.
    * Combine these operands using the arithmetic operator, as follows
      * Result = operand2 operator operand1
  * Push result onto the stack.

When the end of the expression is reached, pop the remaining number off the stack. This number is the value of the expression. Applying this algorithm to the arithmetic expression  
<p align="center">
34+52/*  </p>

Results 17.5 as expected.  

Create a program that reads the infix form of an arithmetic expression, evaluates it, outputs the postfix expression, and outputs the result. Assume that the expression consists of single-digit, nonnegative integers (‘0’ to ‘9’) and the four basic arithmetic operators (‘+’,’-‘,’\*’,’/’). Further assume that the arithmetic expression is input from the keyboard with all the characters separated by white space on one line. Save your program in a file called postfix.cpp

## Submission details
To submit your project, you will have to use git on your VirtualBox installation:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “your commit message”
git push
```
## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
