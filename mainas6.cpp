/* 
Description: Using I/O file to calculate amount of food needed for 
the zoo, inlcuding the cost. Using loops in order to print out the 
correct data as well. 
Input: User is asked to input the file and the program calculates 
the totals based on the data provided 
Output: the output will be the data, the total for food and cost 
inlcuding the monthly total and cost, excluding leftovers. In addition 
multiple files can be used through a loop.  
*/
#include <iostream>
#include <iomanip> //library for parametric manipulators 
#include <fstream> //library for file stream 
#include <cmath> //c++ math library 
#include <string> ////library to use strigns
using namespace std; 

int main (){

const int emax = 100; 
string file; //declaring inFlie as a string to be read 
string error;  //declaring & reading error txt 
ifstream inFile; //declared infile    
double tfood = 0.0; //total amount of food per day in lbs 
double tmoney = 0.0; //total cost of food per day 
double monthsum= 0.0; //total amount of food per month 
double moneymonthly = 0.0; //total cost of food per month
char answer = '\0'; //declartion answer to inpt new data 
bool repeat= true; //conditon for a program to run again 


//welcome statment for be printed 
cout << "\n************************************************************\n";
cout << " Welcome the UNLV CS Free Range Wild Animal Park!\n";
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  
    do{ //overall do ..while loop of the program
   
        do{//do..while loop to check proper file name input 
            cout <<endl; //prompt for file input 
            cout << "Please enter an input filename. \n" << "***** ";
            cin >> file; //input of file 
            //opening the file set/ checking if file is corect 
            inFile.open(file); 
                if (!inFile.is_open()){
                    inFile.clear();//allows to repeated input 
                    inFile.ignore(emax, '\n' );
                    cout << "ERROR opening the input file.";
                    continue; //print error statement for wrong input 
                }else 
                    break ; 
        }while (true);//condtion for while statemnt 
        //prinitng the file being input 
   
        cout << "\n Input file given: " << file << '\n'; 
        string s1 = "+------------------------------------------------+\n";
        string s2 = "Animal";
        string s3 = "Food 'lbs.'";
        string s4 = "Cost '$'";
        string s5 = "++---------------+---------------+---------------+\n";
        //prints out string to make the table for the data 
        cout << endl; 
        cout << s1; 
        //headers for the data 
        cout << "  " << left << setw(18) <<s2 << setw(20) << s3 << s4<< endl; 
        cout << s5; //seperator of the header & data 
   
        //declaring file to be read as string & doubles 
        string value1; 
        double value2, value3; 
        //loop to print input file 
    
        while (inFile >> value1 >> value2 >> value3) // to only read to end of file 
        {  //checking to maksure no leftover food is calculated 
            if ((value2 > 0) & (value3 > 0))
            {
            tfood += value2; //sum of tottal food in lbs 
            tmoney += value3; //sume of cost of food 
            }
            //data to be printed in the table 
            cout << " "<< left << setw(20)<<value1 << right <<setw(8)
            << setprecision(1) << fixed << showpoint <<value2 
            << setw(13) << "" << left <<"$"<< setprecision(2) 
            << fixed<< showpoint<< value3 <<'\n';        
        } 
    
        cout << setprecision(2) << fixed<< showpoint; 
        //calculation of monthly food and cost of food 
        monthsum = tfood * 30; 
        moneymonthly = tmoney * 30; 
        cout << s1; 
        cout << endl; 
    
        //statement to print out food cost, monthly, and ending of program
        cout << "Feeding Totals\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        cout << "The total zoo food today was: " << 
        setprecision(1) << tfood << " lbs.\n";
        cout << "Estimated zoo food for a month is: " 
        << setprecision(1) << monthsum << " lbs.\n";  
        cout << endl;
        cout << "The total zoo food cost today was: " 
        << setprecision(2) << tmoney <<'\n';
        cout << "Estimated zoo food cost for a month is: "
        << setprecision(2) << moneymonthly <<'\n';
        cout << endl; 
    
        //print of ending of the zoo program 
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl; 
        cout << right << setw(49) << "Remember to always feed safely!" << endl;
        cout << "**************************************************\n"; 
        inFile.close(); //closing file 
        cout << endl; 
    
        do{ //do..while statement prompting to run another set of input files  
            cout << "Would you like to process another datafile? Y/y/N/n \n" <<"***** ";
            cin >> answer; //response to prompt 
            tfood = 0;
            tmoney = 0; 
            //if stament to check if the conditons are ture and run program
            if (answer == 'y' || answer == 'Y'){
            repeat = true; 
            }
            else if (answer == 'n' || answer == 'N') {
            repeat = false; 
            return 0; //if no, to end program 
            } 
            else{//statement to print when wrong input used for program above 
            cout<<"\nERROR: Invalid entry. Please try again." << endl;
            }//conditions in whihc the repeat runs & excludes 
        
        }while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N');

    }while(repeat); //loop to reapeat program with a new set of data


return 0; 
}


