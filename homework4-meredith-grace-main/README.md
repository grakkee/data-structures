# Homework 4

## Project Goals
The goal of this project is to:
1.	Familiarize students with **sorting**
2.  Familiarize students with the **time complexity**.

## Program
First choose TWO sorting algorithms from the following list:
- selection sort
-	insertion sort
-	bubble sort  

and ONE algorithm from the following list:
-	merge sort
-	quick sort 

Case 1: Randomly generate [1,000, 10,000, and 100,000] integer values (in the range of 0 to 106) to be inserted into the data structures. NOTE that this list (i.e., the input values) itself should not be sorted AND all algorithms should use the same input file when the input size is the same. 

Case 2: Also, test the speed of algorithms when the input array is already sorted (for the same input data). 

The following output should be provided for an average of 10 sorts of each algorithm and input size:
-	the CPU time (use the same machine)
-	the number of comparisons
-	the number of swaps 

Note: You can only use (i.e., copy) code from the book and slides. You need to develop the rest of the code yourself. 

Deliverables:
-	Source code for your classes (one for each sort algorithm for a total of 3)
-	A main file that tests the classes with randomly generated data.
-	The data input files (there should be 6 of them – best and worst cases for each input size)
- Test output of your algorithms (with a tabular of each run and their averages for each of the metrics listed above)
  -	Tables
    - Include data for individual runs
    - 6 tables per algorithm (so 18 total)
    - Algorithm – metric – scenario
    - Example: 
      - Algorithm 1 - CPU time - Best Case
      - Algorithm 1 - CPU time - Worst Case
      - Algorithm 1 - Comparisons - Best Case
      - Algorithm 1 - Comparisons - Worst Case
      - Algorithm 1 - Swaps - Best Case
      - Algorithm 1 - Swaps - Worst Case
    - Include data for each run and input size
      - 3 columns: 1,000; 10,000; 100,000
      - 10 rows: one for each run
  - Graphs
    - Use averages of the 10 runs
    - 6 graphs
      - Metric + scenario 
    - Example:
      - CPU time – Best Case
    - Graph averages for each algorithm
      - Algorithm 1
      - Algorithm 2
      - Algorithm 3 
    - input size should be the x-axis
    - time/comparison/swaps should be the y-axis

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
