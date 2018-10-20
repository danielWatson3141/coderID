#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

template <class T>
class Array2D
{
    T**    strings;
    int*   lengths;
    int    numElem;
    int    allocated;
    
    public:
           
    Array2D()
    {
        numElem = 0;
        strings = new T*[50];
        lengths = new int[50];
        allocated = 50;
    }
    
    bool add(T* str,unsigned int len)      
    {
        int i;
        if (numElem == allocated)
        {
            T** stringsNew = new T*[allocated+50];
            int* lengthsNew = new int[allocated+50];
            if (stringsNew == NULL)
            {
                printf("BAJ VAN");
                return false;
            }
            for (i=0; i<allocated; i++)
            {
                stringsNew[i] = strings[i];
                lengthsNew[i] = lengths[i];
            } 
            allocated = allocated + 50;
            delete[] strings;
            delete[] lengths;
            strings = stringsNew;
            lengths = lengthsNew;
            //printf("%d %s | ",allocated,strings[0]);
        }
        strings[numElem] = new T[len];
        lengths[numElem] = len;
        for (i=0; i<len; i++)
        {
            strings[numElem][i] = str[i];
        }
        //printf("added: %d\r\n",strings[numElem][0]);
        numElem++;
        return true;
    }
    
    T* get(int i)
    {
        return strings[i];      
    }
    
    int length(int i)
    {
        return lengths[i];    
    }
    
    int find(T* str)
    {
        int i,i2;
        for (i=0; i<numElem; i++)
        {
            for (i2 = 0; strings[i][i2] == str[i2] && str[i2] && strings[i][i2] ; i2++);
            if (str[i2] == '\0' && strings[i][i2] == '\0')
                return i+1;
        }
        return 0;
    }
    
    int clear()
    {
        int i;
        for (i = 0; i<numElem; i++)
        {
            delete[] strings[i];
        }    
        delete[] strings;
        delete[] lengths;
        
        numElem = 0;
        strings = new T*[50];
        lengths = new int[50];
        allocated = 50;
    }
    
    ~Array2D()
    {
        int i;
        for (i = 0; i<numElem; i++)
        {
            delete[] strings[i];
        }    
        delete[] strings;
        delete[] lengths;
    }
};

class StringArray: public Array2D<char>
{
  public:
    StringArray():Array2D<char>()
    {}     
         
    bool add(char* str)
    {
        //printf("added: %s\n",str);       
        return Array2D<char>::add(str,strlen(str)+1);   
    }      
};

class FileManager
{
    char* filename;
    FILE* f;
    
    int testcases;
    
  public:
         
    FileManager()
    {
        filename = new char[50];
        f = NULL;             
    }
    
    FILE* getPointer()
    {
    	return f;
    }
         
    bool open2read(const char* fname)
    {
        strcpy(filename,fname);    
        f = fopen((const char*)filename,"r");
        if (f == NULL)
           return false;
        return true;
    }

    bool open2write(const char* fname)
    {
        strcpy(filename,fname);    
        f = fopen((const char*)filename,"w");
        if (f == NULL)
           return false;
        return true;
    }
    
    bool close()
    {
        fclose(f);
        return true;
    }
    
    int readArray(int *array)
    {
        int  num = 0;
        char c = ' ';
        
        for (num=0; c!='\r' && c!='\n'; num++)
        {
            if (fscanf(f,"%d%c",&array[num],&c) != 2) break;
//            printf("read: %d ",array[num]);
        }
        
        return num;
    }
    
    int readArray(double *array)
    {
        int  num = 0;
        char c = ' ';
        
        for (num=0; c!='\r' && c!='\n'; num++)
        {
            if (fscanf(f,"%lf%c",&array[num],&c) != 2) break;
        }
        
        return num;
    }
        
    bool readString(char* str, int n)
    {
         if (fgets(str,n,f) != NULL)
         {
             int size = strlen(str);
             if (size > 0 && (str[size-1] == '\r' || str[size-1] == '\n')) 
                 str[size-1] = '\0';
             if (size > 1 && (str[size-2] == '\r' || str[size-2] == '\n')) 
                 str[size-2] = '\0';
             return true;
         }
         return false;
    }
    
    bool readNum(int* pnum)
    {
         if (fscanf(f,"%d",pnum) > 0)  
             return true;
         return false;
    }
    
    bool writeResult(int * result,int n)
    {
         for (int i=0; i<n; i++)
         {
             fprintf(f,"Case #%d: %d\n",i+1,result[i]);    
         }
    }     

    bool writeResult(Array2D<int>& result,int n)
    {
         int *array,num;
         for (int i=0; i<n; i++)
         {
             fprintf(f,"Case #%d: ",i+1);
             array = result.get(i);
             num   = result.length(i);
             for (int i2 = 0; i2 < num; i2++)
                 fprintf(f,"%d ",array[i2]);
             fprintf(f,"\n");    
         }
    }     

    bool writeResult(StringArray& result,int n)
    {
         for (int i=0; i<n; i++)
         {
             fprintf(f,"Case #%d: %s\n",i+1,result.get(i));    
         }
    }     
    
    ~FileManager()
    {
        if (f != NULL)
        fclose(f);              
    }
};

int decide(StringArray& outlets, StringArray& devices, int N, int L, int bit,char* pattern, char* temp)
{
    char *outlet;
    if (bit == L)
    {
        int found = 0;
                  //printf("%s\n",pattern);
              for (int i3 = 0; i3< N ; i3++)
              {
                  outlet = outlets.get(i3);
                  for (int i4=0; i4<L; i4++)
                  {
                      if (outlet[i4] == '1' && pattern[i4] == '1') temp[i4] = '0'; 
                      if (outlet[i4] == '1' && pattern[i4] == '0') temp[i4] = '1'; 
                      if (outlet[i4] == '0' && pattern[i4] == '1') temp[i4] = '1'; 
                      if (outlet[i4] == '0' && pattern[i4] == '0') temp[i4] = '0'; 
                  }
                  //printf(" %s/%s\n",outlet,temp);
                  if (devices.find(temp) == 0)
                  {
                      break;
                  }
                  else
                  {
                      found++;
                  }
              }
         if (found == N)
         {
             int switched = 0;
                  for (int i4=0; i4<L; i4++)
                        if (pattern[i4] == '1') switched++;
             return switched;             
         }
         else
         {
             return L+1;
         }   
    }
    else
    {
        pattern[bit] = '0';
        int num1 = decide(outlets,devices,N,L,bit+1,pattern,temp);    
        pattern[bit] = '1';
        int num2 = decide(outlets,devices,N,L,bit+1,pattern,temp);
        return ((num1 < num2) ? num1 : num2);   
    }
}

int main()
{
     FileManager     input,output;
     int header[10];
     Array2D<int>    dataset1;
     //Array2D<long>   dataset;
     //Array2D<double> dataset;
     StringArray     dataset2;
     StringArray     dataset3;
     int testcases;
     //Array2D<int>    result;
     //Array2D<long>   result;
     //Array2D<double> result;
     StringArray     result;
     
     
     printf("START");
     
     int temp[500];
     int N,L;
     int array[2];
     char* outlets;
     char str[200]; 
     char *pattern, *tmpstr;
     
 	 if (!input.open2read("input.txt")) printf("error at file opening!");
     input.readArray(header);
     testcases = header[0];

     for (int i=0; i<testcases; i++)
     {
//         dataset1.add(temp,input.readArray(temp));
//         dataset2.add(temp,input.readArray(temp));
//         dataset3.add(temp,input.readArray(temp));
          input.readArray(array);
          N = array[0]; L = array[1];
          //printf("[%d]",L);
          //str[L] = '\0';
          for (int i2 = 0; i2< N ; i2++)
          {
              fgets(str,L+1,input.getPointer());
              fgetc(input.getPointer());
              dataset2.add(str);
          }
          for (int i2 = 0; i2< N ; i2++)
          {
              fgets(str,L+1,input.getPointer());
              fgetc(input.getPointer());
              dataset3.add(str);
          }
          
          int found = 0;
              for (int i3 = 0; i3< N ; i3++)
              {
                  if (dataset3.find(dataset2.get(i3)))
                  {
                     found++;                                
                  }
                  else
                  {
                     break;    
                  }
              }
          
          if (found == N)
          {
          sprintf(str,"0");
          result.add(str);     
          }
          else
          {
              pattern = new char[L+1];
              tmpstr = new char[L+1];
              pattern[L] = '\0';
              tmpstr[L]  = '\0';
              found = decide(dataset2,dataset3,N,L,0,pattern,tmpstr);
              if (found > L)
              {
                  sprintf(str,"NOT POSSIBLE");
                  result.add(str);          
              }
              else
              {
                  sprintf(str,"%d",found);
                  result.add(str);          
              }
          }
          
          dataset2.clear();
          dataset3.clear();
         
     }
     input.close();
     
/*----------------------------------------------------------*/

     output.open2write("output.txt");
     output.writeResult(result,testcases);     
     output.close();
     
     printf("READY!");
     
     char c;
     scanf("%c",&c);
     
     return -1;
}
