#include <cstdlib>
#include <iostream>

using namespace std;

int classAvg(int avg);
void calcAverage(int grades[][3]);
void testAverage(int grades[][3]);

int main(int argc, char *argv[])
{
    int i, ii, inpVal, grades[10][3] = {0};
    
    for(i = 0; i < 10; ++i){
          
          for(ii = 0; ii < 3; ++ii){
                 cout << "Enter student " << i << " grade " << ii << ": ";
                 cin >> inpVal;
                 if(cin.fail() || inpVal < 0 || inpVal > 100 ){
                   cout << "You did not enter a valid value!" << endl;
                   cin.clear();
                   cin.ignore();
                   --ii;
                   continue;
                 } else{ 
                   grades[i][ii] = inpVal;
                 }
          }
    }
    
    // clear line
    cout << endl;
    
    calcAverage(grades);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

// get class average
void calcAverage(int grades[][3]){
     int i = 0, ii = 0, studentSum = 0, classSum = 0;
     
     for(i = 0; i < 10; ++i){
           
           studentSum = 0;
           
           for(ii = 0; ii < 3; ++ii){
                  studentSum += grades[i][ii];
           }
           
           classSum += studentSum;
           studentSum = studentSum / 3;
           cout << "Student " << i << " average: " << studentSum << endl;
           
     }
     
     // clear line
     cout << endl;
     
     // get test averages
     testAverage(grades);
     
     // print class average
     cout << "Class Average: " << classSum / 30 << endl;
}

// get tests average
void testAverage(int grades[][3]){
    int i = 0, ii = 0, test[3] = {0};
    
    for(i = 0; i < 10; ++i){
           
           // get test values
           test[0] += grades[i][0];
           test[1] += grades[i][1];
           test[2] += grades[i][2];
           
     }
     
     cout << "Test averages:" << endl;
     cout << "1: " << test[0] / 10 << endl;
     cout << "2: " << test[1] / 10 << endl;
     cout << "3: " << test[2] / 10 << endl << endl;
}

