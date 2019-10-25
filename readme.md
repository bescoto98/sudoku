> Brenda Escoto;
> escot105@mail.chapman.edu

Files:
- main.cpp
- testfile.txt

This program takes as command line input the name of a file that has a sudoku grid. From the main function, four threads are then kicked off. The first thread calls the function inputFile, which takes as an argument an empty 9x9 array of strings, and the name of the file. The file is opened, and the array is filled with these values. After this function is finished, three more threads are created, one to show the user the grid obtained from the specified file, one to check each row for errors, and one to check each column for errors. When all threads have finished, the missing values are shown to the user.

To run the program, enter
> g++ *.cpp -o main -pthread

Output will look like this


        SUDOKU GRID
 6  2  4  5  3  9  1  7  7
 5  1  9  7  2  8  6  3  4
 8  3  7  6  1  4  2  9  5
 1  4  3  8  6  5  7  2  9
 9  5  8  2  4  7  3  6  1
 7  6  2  3  9  1  4  5  8
 3  7  1  9  5  6  8  4  2
 4  9  6  1  8  2  5  7  3
 2  8  5  4  7  3  9  1  6
        ---
Error on ROW: 1 COLUMN: 8
Missing value: 8

