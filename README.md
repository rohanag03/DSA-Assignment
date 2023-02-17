# DSA Assignment Questions

Q-1: Create three database using header linked list<br><br>
 	Student (Roll No, Name, Branch ID, CGPA)<br>
	University (University ID, University Name, University Location, Year of start)<br>
	Branch (Branch ID, University ID, Branch Name)<br>
Implement the following modules/ sub-modules using menu driven approach:<br><br>
 -Keep the Roll No, University ID and Branch ID Unique (Duplicated entry should not be allowed and prompted)<br>
 -Student can take a University ID/ Branch ID only if it is available in the University/ Branch database.<br>
 -Student Name, University Name and Branch Name should all be in Capital Letters. (If user has not entered accordingly, then the program must convert it into Capital       Letters and store.)<br>
 -Display the entire  student list/ University list/  Branch List<br>
 -Delete all students whose CGPA<6.0 and store them in another list. They will come back to original student list if their CGPA>=6.0(Update function)<br>
 -Display the list of students reading in KIIT University<br>
 -ADD/ MODIFY/DELETE/UPDATE using key value in any of the database as per requirement.<br>
 -Display the student details who are reading at KIIT University with branch CSE.<br>
 -Display the list of Branches available in any given University<br>
 -Display the University details in ascending order of their year of starting<br><br>
 -Display the all Student name/ all University name for a given name substring entered by the user.<br>

<hr>
Q-2: Create one database using header linked list and file system to store the details of a shopping card given by the Shopping Mall.<br>
 Shopping Card( Card_ID, Customer_Name, Points, Date_of_Birth, Last_date_of_trasaction, address)<br>
  Item (Item_ID, Item_Name, Price, Quantity)<br>
  Implement the following modules/ sub-modules using menu driven approach:<br>
   -Keep the Card_ID and Item_ID Unique (Duplicated entry should not be allowed and prompted)<br>
   -Update function to update the address only (if required).  Other fields can’t be updated by the customer.<br>
   -A customer can buy different products listed and accordingly points will be assigned as follows:<br><br>
    <p align="center"><img alt="Table" width="350" src="https://github.com/rohanag03/DSA-Assignment/blob/main/q3.png"></p>
   -When the manager of the shopping mall decides (decides a date), a discount of 10% can be given to 10 customers those who have first accumulated 1000 points. The       customer may immediately redeem the points and get 10% discount and its points will be reset to zero, else keep it for later use.  The next 10 customer will get       the discount in the next month same date. This process continues.<br>
   -When the manager of the shopping mall decides (decides a date), a discount of 15% can be given to 5 customers those who have first accumulated 1000 points and are     senior citizens (age>60). The customer may immediately redeem the points and get 10% discount and its points will be reset to zero, else keep it for later use.         This process is repeated in every month.<br>
   -Display the customer details and item details as per requirements.<br>
   -Add new customer as well as new items.<br>
   -Delete existing customer if the last transaction date is before one year.<br>
   -The system should show the items out of stock during the purchase.<br>
 
 <hr>
Q-3: In a vaccination centre people make queue. But due to unavailability of space in the same queue, people make a parallel queue (second queue following the first one), then people make another parallel queue (third queue following the second one) and further no queues can be made due to unavaipability of space. The case can be shown diagrammatically as follows. The arrow shows the direction in which people can be added. The box shows the space available for waiting. The size of the three boxes is equal where the size will be decided by the user.<br><br>
 <p align="center"><img alt="Structure" width="350" src="https://github.com/rohanag03/DSA-Assignment/blob/main/q4.png"></p>
  -Implement the queues (Insertion and deletion) operations. Whenever the first people get into the centre, all peoples will move one step forward.<br>
  -Write functions to handle when no one is present to get the vaccine and when no further people can be added to the queue due to unavailability of space.<br>
  
  <hr>
Q-4: Write a program to implement four numbers of D-queues in an array.
  
  <hr>
Q-5: Write a program to implement round robin scheduling concept using a linked list. Each node represents a process with attributes as <PID, CPU_time>. A quantum time T will be input by the user. A process will be executed (when user wants) for quantum time T and the CPU_time will be updated with CPU_time T, and the current process node is deleted from the beginning and added to the end of the list. If the updated CPU_time is <=0, then the process is deleted from the list. After a process is executed for T time, the the next process in the queue is executed upon user choice. The entire process gets completed when all process nodes are deleted.
 
 <hr>
Q-6: Write a program to construct a binary tree from given sequence of preorder and inorder traversal of the tree.

<hr>
Q-7: Write a program to check that the left sub-tree of an binary tree is a mirror image of its right sub-tree.

<hr>

Q-8: Write a program to implement a graph ADT and traverse the graph in bread first search and depth first search for a given node.
<hr>

Q-9: Suppose the locations of ATMs of different banks are represented by nodes in a graph with information: <ATM ID, BANK ID, CITY ID, LOCATION ID>. Write a pseudo code/ algorithm to find the nearest ATM of a given Bank from a given location. Then, find the subsequent neighbouring ATMSs as per user’s requirement.
