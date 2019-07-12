//author: Jenny Nguyen
//date: Jan.16.19
//A program that reads the data from the file into parallel arrays

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 25;    //memory constant

//prototypes
void inputData (int ary[], float ary2[], int size);
void printary(int values[], float values2[], int count);
void sortary (int ary[], float ary2[], int size);
int binsearcharray(int ary2[], int size, int search_value);
int searcharray(int values[], int size, int search_value);

int main()
{
    int location = 0;
    int search_value;
    int i = 0;

//making an array
    int ary [SIZE] = {0};
    float ary2[SIZE] = {0};


//call function
    inputData(ary, ary2, SIZE);
    //user enters student id
    cout << "Please enter the Student ID you would like to search: (-1 to exit)" << endl;
    cin >> search_value;
while (search_value!=-1){


//call functions cont.
    sortary(ary, ary2, SIZE);

    printary(ary, ary2, SIZE);

    location = binsearcharray(ary, search_value, SIZE);

//once the location is found
    if (location == i)
    {
        cout << endl << "The Student ID: " << search_value << " was not found!\n";
    }
    else
    {
        cout << endl << "The Student ID: " << search_value << " was found at location: \n" << location;
        cout << " The GPA for " << search_value << " is: " << ary2[location] << endl;
    }
//user enters student id
    cout << "Please enter the Student ID you would like to search: (-1 to exit)" << endl;
    cin >> search_value;

}
    return 0;

}

void inputData (int ary[], float ary2[], int size)
{

    //opening the file
    ifstream inFile;
    inFile.open("Student.txt");

    cout << "\n Reading file at the moment...\n";

    //if there is an error opening the file
    if (!inFile)
    {
        cout << "File open failure!";
    }
    else
    {
         for (int i = 0; i < size; i++)
            {
                inFile >> ary[i] >> ary2[i];
            }
    }
    cout << endl;

    inFile.close();

    return;
}

void sortary (int ary[], float ary2[], int size)     //allows GPA to be sorted from smallest to largest
{
    int temp;
    float tempID;
    bool swap;

for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (ary[j] > ary[j + 1])
            {
                tempID = ary[j];
                ary[j] = ary[j + 1];
                ary[j +1] = tempID;
            }
        }
    }

   {


   }
}

void printary(int values[], float values2[], int count) //displays the data in order
{
    cout << "\nStudent ID     GPA\n\n";

    //print the array using a loop to generate the print statements
        for(int i=0; i < count; i++)
    {
        cout << setw(5) << values [i] << setw(12) << values2[i] << endl;
    }
    cout << endl;
}

int searcharray(int values[], int size, int search_value)
{
    int location = 0;

    for(int i=0; i < size; i++)
    {
        if(search_value == values[i])
            location = i;
    }


    return location;
}

int binsearcharray(int values[], int search_value, int size)
{
    int first, last, middle;
    int location = 0;

    first = 0;
    last = size - 1;

    while (first < last)
    {
        if (search_value == values[first])
        {
            return first;
        }
        else if (search_value == values[last])
        {
            return last;
        }
        else
        {
            middle = (first + last) / 2;

            if (search_value > values[middle])
                first = middle + 1;

            else if (search_value < values[middle])
                last = middle - 1;
            else
            {
                location = middle;
                return location;
            }
        }
    }

    return location;
}

