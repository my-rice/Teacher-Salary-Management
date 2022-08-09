# Teacher-Salary-Management
## Exercise description 
Write a salary management program for university teachers. Teachers can belong to 3 different types:
- Full Professor (PO);
- Associate Professor (PA);
- Researcher (RI);

The data relating to each teacher are:
- Tax Code (A 16-character string), key field.
- Topology (PO / PA / RI).
- Surname (A string of 15 characters)
- Name (A string of 15 characters)
- Monthly Salary (A real)
- Number of courses (A whole)

## Tasks
The program stores the data relating to the teachers in a binary tree, ordered according to the key, and carries out the following functions:

- Insertion of a new teacher.
- Promotion of a teacher.
- Search for a teacher with a salary immediately above a given figure.
- On-screen printing of teachers' information. (Functionality already provided)

## Given files
For the implementation of the application, the student has at his disposal:
- The files needed to create the entire project;
- The standard functions for the management of the binary tree that must be used without making any changes to them -(neither to the prototypes nor to their implementation provided);
- The definition of the prototypes of the functions to be implemented.

The files provided are as follows:
- info.h (to be completed)
Contains the definition of the TInfo type and the prototypes of the functions for its management. The student will have to create the SSatellite structure.

- info.c (not to be changed)
Contains the implementation of the functions for the management of TInfo.

- tree.h (not to be modified)
Contains the definition of the TTree type and the prototypes of the functions for the management of TTree (standard functions)

- tree.c (not to be modified)
Contains the implementation of the TTree management functions (standard functions)

- menu.h (not to be changed)
Contains prototypes of user interface functions.

- menu.c (not to be changed)
Contains the implementation of the user interface functions.
- teacher_management.h (not to be modified)
Contains the prototypes of the functions required by the application:
> int insert_docente (TTree * university);

- The function reads the TInfo data and inserts a new node in the binary tree. The function returns 1 if the insertion is successful, -1 otherwise.
> int promotion_docente (TTree universita);

- The function reads the teacher's tax code. Then it looks for the node related to the teacher, if it is not found, -1 is returned. If the node is found, the type of teacher is verified, if the teacher belongs to the type RI, the type is set to PA, the salary is increased by 5% and 1 is returned; if the teacher belongs to the PA type, the type is PO, the salary is increased by 10% and 2 is returned; if the teacher belongs to the PO type, no operation is performed and 0 is returned.
> TNode * search_salary_superior (University TTree, float stip);

- The function searches for the teacher who has a salary immediately higher than stip. The function returns the found (recursive) node.
> void stampa_docenti (University TTree);

- The print function, the information of all the teachers in the archive. The function does not return any value. (The function is already provided)

- teacher_ management.c (to be completed);  
Contains the implementation of the functions required by the application

- teachers.c (to be completed);  
Contains the main of the program.