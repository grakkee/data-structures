# Homework 6

## Project Goals
The goal of this project is to:
1.	Familiarize students with **graphs**

## Program
### Traveling Salesman Problem
Consider 5 cities of interest, namely a) Reno, b) San Francisco, c) Salt Lake City, d) Seattle, and e) Las Vegas. Use information on the road network and derive the miles from one city to the other. Assume a fixed metric of Miles Per Gallon = 40 and derive the cost of each transition **in terms of miles**. Then on that basis, conduct the following:
- Create a graph with each of its vertices corresponding to one of these cities and its edges being weighted by the associated miles for each trip. Note that if (and only if) to go from city A to B you must go through C then you must add one edge from A to C and one edge from C to B and there is no need to add an edge directly from A to B.
- Solve the Traveling Salesman Problem such that traveling salesman starts from Reno, visits all cities in the above list and returns to list. Solve this problem in the brute force-way, i.e. by identifying all possible paths.

Your submission should include 
- Your source code
- a .txt file with your initial values for the miles from one city to the other
- a .txt file which includes all possible paths and the best one selected by the algorithm

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
