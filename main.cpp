
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



const int highest = 35;
const double higest1 = 97.00;
const double  loadgenerate = 3.56;
const double driedgenerates = 2.99;
const int wash_ratio = 3;
const double dry_ratio = 17.5;
// function prototypes
void display();
double average(int* , int  );
int howManyDryerLoads(int* , int  );
double calcRevenue(int * , int  );
int profitabledays(int* , int );
bool profit(int);
void findMaxLoad(int*, int);


int main() {
    

    display();
    // ask user how many days of data to enter
    int days;
    cout << "Please enter the number of days ";
    cin >> days;
    do {
        if (days <= 0) 
        {
            cout << "Negatives are not allowed. Please re-enter: ";
            cin >> days;
       }
        
    } while (days <= 0);

    // dynamically allocate array for loads per day
    int* loads = new int[days];

    // enter loads per day and validate input
    for (int i = 0; i < days; i++) {
        cout << "Enter number of loads washed on day " << i + 1 << ": ";
        cin >> *(loads + i);
        do {
            if (*(loads + i) < 0 || *(loads + i) > highest)
            {
                cout << "The maximum loads per day is 35. please re-enter: ";
                cin >> *(loads + i);
            }
        } while (*(loads + i) < 0 || *(loads + i) > highest);
    }

    // calculate and display average loads washed per day
    double avgLoads = average(loads, days);
    cout << "\nTotal loads washed: " << avgLoads * days << endl;
    cout << "Average loads washed per day: " << setw(2) << "$" << fixed << setprecision(2) << avgLoads << endl;

    // calculate and display total loads dried and average loads dried per day
    int dryerLoads = howManyDryerLoads(loads, days);
    cout << "\nTotal loads dried: " << dryerLoads << endl;
    cout << "Average loads dried per day: " << setw(2) << "$" << fixed << setprecision(2) << (double)dryerLoads / days << endl;

    // calculate and display total revenue for period
    double revenue = calcRevenue(loads, days);
    cout << "\nTotal revenue for generated is : $" << setw(2) << "$" << fixed << setprecision(2) << revenue << endl;
    
    int profitableDays = profitabledays(loads, days);
    cout << "There were " << profitableDays << " days in which the laundromat made a profit!"<<endl << endl;


    findMaxLoad(loads, days);

  
  

    // release dynamically allocated memory
    delete[] loads;

    return 0;
}
// program information
void display() {
    cout << " Lab 7 - pointer " << endl;
    cout << "Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication probhited." << endl << endl;
    cout << setw(19) << "" << setw(50) << "Welcome to CMSY-141 Laundromat profit calculator\t" << setw(19) << "" << endl;
}
// function to calculate average loads per day
double average(int* loads, int days) {
    int totalLoads = 0;
    for (int i = 0; i < days; i++) {
        totalLoads += *(loads + i);
    }
    return (double)totalLoads / days;
}

// function to calculate number of dryer loads for period
int howManyDryerLoads(int* loads, int days) {
    int totalDryerLoads = 0;
    for (int i = 0; i < days; i++) {
        totalDryerLoads += *(loads + i) / wash_ratio;
        if (*(loads + i) % wash_ratio != 0) {
            totalDryerLoads++;
        }
    }
    return totalDryerLoads;
}

// function to calculate revenue for period
double calcRevenue(int* loads, int days)
{
    double revenue = 0.0;
    for (int i = 0; i < days; i++)
    {
        revenue += *(loads + i) * loadgenerate;
        revenue += (*(loads + i) / driedgenerates);
    }
    return revenue;
}// calculate profit 
bool profit(int loads)
{

    double revenue = loads * loadgenerate;
    return (revenue >= higest1);
}


// calculate and display number of profitable days
int profitabledays(int* loads, int days)
{
    double revenue;
    int count = 0;

    for (int i = 0; i < days; i++)
    {
        revenue = calcRevenue(loads + i, 1);
        if (profit(*(loads + i)));
        {
            ++count;
        }
    }

    return count;
}
//find max lod and days with the higest wash day
void findMaxLoad(int* loads, int days) {
    int maxLoad = *loads; // initialize maxLoad to the first element in the array
    int maxDay = 1; // initialize maxDay to the first day
    for (int i = 1; i < days; i++) {
        if (*(loads + i) > maxLoad) { // use pointer notation to access array elements
            maxLoad = *(loads + i);
            maxDay = i + 1; // add 1 to get the actual day number
        }
    }
    // print the result in the required format
  
    cout << "The day with the highest washer loads was day " << maxDay <<  " with " << maxLoad << " loads." << endl;
}



