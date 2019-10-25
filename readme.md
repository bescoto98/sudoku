> Brenda Escoto;
> escot105@mail.chapman.edu

Files:
  main.cpp
  testfile.txt

This program takes as command line input the name of a file that has a sudoku grid. Four threads are then kicked off. The first thread calls the function inputFile, which takes as an argument an empty 9x9 array of strings, and the name of the file. The file is opened, and the array is filled with these values. After this function is finished, three more threads are created, one to show the user the grid obtained from the specified file, one to check each row for errors, and one to check each column for errors. When all threads have finished, the missing values are shown to the user.

To run the program, enter
> g++ *.cpp -o main -pthread
