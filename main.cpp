/**
Brenda Escoto
escot105@mail.chapman.edu
March 26, 2019
**/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

void printMatrix(string a[9][9])
{
  cout << "\n\n\tSUDOKU GRID\n";
  for(int i=0;i<9;i++)
  {

    for(int j=0;j<9;j++)
    {
      cout << " " << a[i][j] << " ";

    }
    cout <<"\n";
  }
  cout << "\t---\n";
}

int string2Int(string q)
{
  int p=0;
  if(q=="1")
  {
    p=1;
  }
  else if(q=="2")
  {
    p=2;
  }
  else if(q=="3")
  {
    p=3;
  }
  else if(q=="4")
  {
    p=4;
  }
  else if(q=="5")
  {
    p=5;
  }
  else if(q=="6")
  {
    p=6;
  }
  else if(q=="7")
  {
    p=7;
  }
  else if(q=="8")
  {
    p=8;
  }
  else if(q=="9")
  {
    p=9;
  }
  return p;

}

void checkRows(string a[9][9], int errR[20], int missValR[20])
{
  bool row[9];//indexes: 0-8
  int temp=0;
  int errIndx=0;
  int missValIndx=0;



  for(int r=0;r<9;r++)
  {
    for(int i=0;i<9;i++)//set bool array to false for each new row
    {
      row[i]=false;
    }
    for(int c=0;c<9;c++)//for checking rows
    {
      temp=string2Int(a[r][c]);
      if(!row[temp-1])
      {
          row[temp-1]=true;
      }
      else
      {
        errR[errIndx]=r;//not one based Yet
        errIndx++;

      }
    }



    for(int j=0;j<9;j++)//set bool array to false for each new row
    {

      if(!row[j])
      {

        j++;
        missValR[missValIndx]=j;
        missValIndx++;
        j--;

      }
    }
  }
}

void checkCols(string a[9][9], int errC[20], int missValC[20])
{

  bool col[9];
  int temp=0;
  //int value=0;
  int errIndx=0;
  int missValIndx=0;

  for(int c=0; c<9;c++)
  {
    for(int j=0;j<9;j++)//set bool array to false for each column
    {
      col[j]=false;
    }
    for(int r=0;r<9;r++)
    {
      temp=string2Int(a[r][c]);
      if(!col[temp-1])
      {
        col[temp-1]=true;
      }
      else
      {
        errC[errIndx]=c;
        errIndx++;
      }
    }

    for(int q=0;q<9;q++)
    {
      if(!col[q])
      {
        q++;
        missValC[missValIndx]=q;
        missValIndx++;
        q--;
      }
    }
  }


}

void inputFile(string a[9][9], string fName)
{
  int linecount=0;
  string line="";
  int rCount=0;
  int cCount=0;

  ifstream myfile (fName);

  if(myfile.is_open())
  {
    while(getline(myfile, line))
    {
      cCount=0;
      for(int j=0;j<line.length();j++)
      {
        if(line[j]!=',')
        {
          a[rCount][cCount]=line[j];
          cCount++;
        }
        if(line[j]=='\n'||cCount>8)
        {
          break;
        }

      }
      rCount++;
    }
  }
  else
  {
    cout << "error opening file" << endl;
  }
}


int main(int argc, char **argv)//g++ *.cpp -o main -pthread
{
  string enteredFile = argv[1];

  string matrix[9][9];

  int temp=0;

  int errR[20];//checkrows will only record row w/ error
  int errC[20];//checkcols will only record col w/ error

  //to check if the values are the same
  int missValR[20];
  int missValC[20];

  for(int i=0;i<20;i++)//in order to know how many errors there are-no values given by functions will be >0
  {
    errR[i]=-1;
    errC[i]=-1;
    missValC[i]=-1;
    missValR[i]=-1;
  }

  thread file (inputFile,matrix,enteredFile);
  file.join();


  thread show (printMatrix,matrix);
  thread row (checkRows,matrix,errR,missValR);
  thread col (checkCols, matrix, errC, missValC);


  show.join();
  row.join();
  col.join();

  //print out results based on values in arrays
  for(int j=0;j<20;j++)
  {
    if(errR[j]==-1)
    {
      if(j==0)
      {
        cout << "No errors found in file" << endl;
      }
      break;
    }
    else
    {
      temp=errR[j]+1;//for one based answer
      cout << "Error on ROW: " << temp;
      temp=errC[j]+1;
      cout << " COLUMN: " << temp << endl;
      if(missValC[j]==missValR[j])
      {
        cout << "Missing value: " << missValR[j] <<"\n"<< endl;
      }
      else//if values do not match then taking the value missing from column will be more correct
      {
        cout << "Missing value: " << missValC[j] << endl;
      }
    }
  }

}
