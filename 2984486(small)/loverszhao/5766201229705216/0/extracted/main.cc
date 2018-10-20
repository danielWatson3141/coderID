#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::fstream;
using std::map;
using std::stringstream;
using std::string;
using std::vector;

fstream fs("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

int
get_int_from_next_line();

string
get_string_from_next_line();

int
get_result(vector<vector<int> > _matrix);

int
get_max(vector<vector<int> > _matrix, int _row);

int main(int argc, char *argv[])
{
  if (fs.good())
  {
    const int case_amount = get_int_from_next_line();
    
    for (int i = 0; i < case_amount; ++i)
    {
      const int N = get_int_from_next_line();

      vector<vector<int> > matrix(N, vector<int>(N, 0));

      for (int j = 0; j < N - 1; ++j)
      {
        const string line = get_string_from_next_line();

        stringstream _stream(line);
        int row = 0, column = 0;
        _stream >> row >> column;

        matrix[row - 1][column - 1] = 1;
        matrix[column - 1][row - 1] = 1;
      }

      int result = get_result(matrix);
      
      fout << "Case #" << 1 + i << ": " << N - result -1 << endl;
    }
  }

  fs.close();
  fout.close();
  
  return 0;
}

int
get_int_from_next_line()
{
  string line = "";
  getline(fs, line);      
  stringstream stream(line);
  int temp = 0;
  stream >> temp;
  return temp;
}

string
get_string_from_next_line()
{
  string line = "";
  getline(fs, line);
  return line;
}

int
get_result(vector<vector<int> > _matrix)
{
  int max = 0;

  for (int i = 0; i < _matrix.size(); ++i)
  {
    vector<int> row_vec = _matrix[i];

    const int count = std::count(row_vec.begin(), row_vec.end(), 1);

    int result = 0;
    
    if (2 <= count)
    {
      result = 2;

      int top2[2] = {0};
      
      for (int j = 0; j < row_vec.size(); ++j)
      {
        if (1 == row_vec[j])
        {
          vector<vector<int> > temp_matrix = _matrix;
          temp_matrix[i][j] = 0;
          temp_matrix[j][i] = 0;
          int max = get_max(temp_matrix, j);
          if (max > top2[1])
          {
            top2[1] = max;
          }
          
          if (top2[0] < top2[1])
          {
            int temp = top2[0];
            top2[0] = top2[1];
            top2[1] = temp;
          }
        }
      }
      result += top2[0] + top2[1];
    }

    if (result > max)
    {
      max = result;
    } 
  }

  return max;
}

int
get_max(vector<vector<int> > _matrix, int _row)
{
  int max = 0;

  {
    vector<int> row_vec = _matrix[_row];

    const int count = std::count(row_vec.begin(), row_vec.end(), 1);

    int result = 0;
    
    if (2 <= count)
    {
      result = 2;

      int top2[2] = {0};
      for (int j = 0; j < row_vec.size(); ++j)
      {
        if (1 == row_vec[j])
        {
          vector<vector<int> > temp_matrix = _matrix;
          temp_matrix[_row][j] = 0;
          temp_matrix[j][_row] = 0;
          int max = get_max(temp_matrix, j);
          if (max > top2[1])
          {
            top2[1] = max;
          }
          
          if (top2[0] < top2[1])
          {
            int temp = top2[0];
            top2[0] = top2[1];
            top2[1] = temp;
          }
        }
      }
      result += top2[0] + top2[1];
    }
    
    if (result > max)
    {
      max = result;
    }
  }

  return max;
}
