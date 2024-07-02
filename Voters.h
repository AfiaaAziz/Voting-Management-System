#ifndef Voters_H
#define Voters_H
#include <iostream>
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.
#include "NA.h"    // Header file for National Assembly candidate structure

#include "PA.h" // Header file for Provincial Assembly candidate structure

struct VOTER // Define a structure for storing voter information
{
    Data Voter;
    long long int CNIC, Block_No;
    int Age;
    string Polling_Station;
    CANDIDATE PA, NA;
};
// Function prototypes
void Voter_Menu();            // Function for displaying voter menu
void Add_Voter();             // Function for adding a new voter
void CheckYourRegistration(); // Function for checking voter registration
void View_Voter();            // Function for viewing all voters
// Implementation of the voter menu function
void Voter_Menu()
{
    int choice;
    do
    {
        // Display voter menu options
        cout << "****************************** VOTER'S MENU ******************************" << endl;
        cout << " 1. ADD VOTER " << endl;
        cout << " 2. VIEW VOTER " << endl;
        cout << " 3. CHECK YOUR REGISTRATION " << endl;
        cout << " 0. BACK TO MAIN MENU " << endl;
        cout << " Enter choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_Voter(); // Call function to add a new voter
            break;
        case 2:
            View_Voter(); // Call function to view all voters
            break;
        case 3:
            CheckYourRegistration(); // Call function to check voter registration
            break;
        case 0:
            cout << " Returning to the Main Menu " << endl;
            break;
        default:
            cout << "Invalid Choice. Enter a valid Choice " << endl;
        }
    }

    while (choice != 0);
}
// Function to add a new voter
void Add_Voter()
{
    VOTER Vot;
    CANDIDATE NatAssembly, PovAssembly;
    // Open file stream to append voter data to a file
    ofstream fout;
    fout.open("Voter.txt", ios::app);
    // Prompt user to input voter details
    cout << "****** ENTER VOTER DETAILS: ******" << endl;
    cout << " CNIC: ";
    cin >> Vot.CNIC;
    cout << " Name: ";
    cin >> Vot.Voter.Name;
    cout << " Age: ";
    cin >> Vot.Age;
    cout << " Gender: ";
    cin >> Vot.Voter.Gender;
    cout << " Block No: ";
    cin >> Vot.Block_No;
    cout << " Polling Station: ";
    cin >> Vot.Polling_Station;
    // Exception handling for reading National Assembly data
    try
    {
        // Open file stream to read National Assembly data
        ifstream NAfile;
        NAfile.open("NAC.txt");
        if (!NAfile)
        {
            throw runtime_error("File Not Found");
        }
        cout << " SELECT NA CONSTITUENCY: " << endl;
        // Display available National Assembly constituencies and let the user select one

        while (NAfile >> NatAssembly.ID >> NatAssembly.Candidate.Name >> NatAssembly.Candidate.Gender >>
               NatAssembly.Symbol >> NatAssembly.Party >> NatAssembly.Constituency >> NatAssembly.Candidate.Address)
        {
            cout << NatAssembly.Constituency << endl;
        }
        cout << " ENTER: ";
        cin >> Vot.NA.Constituency;
        NAfile.close(); // closing file
    }
    catch (runtime_error &e)
    {
        cout << " Error " << e.what() << '\n';
    }
    try
    {
        // Open file stream to read Provincial Assembly data
        ifstream PAfile;
        PAfile.open("PAC.txt");
        if (!PAfile)
        {
            throw runtime_error("File Not Found");
        }
        cout << " SELECT PA CONSTITUENCY: " << endl;
        // Display available Provincial Assembly constituencies and let the user select one
        while (PAfile >> PovAssembly.ID >> PovAssembly.Candidate.Name >> PovAssembly.Candidate.Gender >>
               PovAssembly.Symbol >> PovAssembly.Party >> PovAssembly.Constituency >> PovAssembly.Candidate.Address)
        {
            cout << PovAssembly.Constituency << endl;
        }
        cout << " ENTER: ";
        cin >> Vot.PA.Constituency;
        PAfile.close(); // closing file
    }
    catch (runtime_error &e)
    {
        cout << " Error " << e.what() << '\n';
    }
    // Write data to file.
    fout << left << setw(20) << Vot.CNIC << setw(15) << Vot.Voter.Name << setw(15) << Vot.Age << setw(15)
         << Vot.Voter.Gender << setw(15) << Vot.Block_No << setw(15) << Vot.Polling_Station << setw(15) << Vot.NA.Constituency << setw(15) << Vot.PA.Constituency << endl;
    if (!fout)
    {
        cout << "Error writing to file." << endl;
    }
    else

    {
        cout << "Voter details added successfully." << endl;
    }
    fout.close(); // closing the file stream.
}
// Function to view all voters
void View_Voter()
{
    VOTER Vot;
    try
    {
        // Open file stream to read voter data
        ifstream fin;
        fin.open("Voter.txt");
        if (!fin)
        {
            throw runtime_error("File Not Found.");
        }
        cout << left
             << setw(20) << "CNIC" << setw(15) << "Name" << setw(15) << "Age" << setw(15) << "Gender" << setw(15) << "Block_No" << setw(20) << "PollingStation" << setw(20) << "NA_Constituency" << setw(20) << "PA_Constituency" << endl;
        // Display voter data in a formatted table
        while (fin >> Vot.CNIC >> Vot.Voter.Name >> Vot.Age >> Vot.Voter.Gender >> Vot.Block_No >>
               Vot.Polling_Station >> Vot.NA.Constituency >> Vot.PA.Constituency)
        {
            cout << left << setw(20) << Vot.CNIC << setw(15) << Vot.Voter.Name << setw(15) << Vot.Age << setw(15) << Vot.Voter.Gender << setw(15) << Vot.Block_No << setw(20) << Vot.Polling_Station << setw(20) << Vot.NA.Constituency << setw(20) << Vot.PA.Constituency << endl;
        }
        fin.close(); // Close the file stream
    }
    catch (runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}
// Function to check voter registration
void CheckYourRegistration()
{
    VOTER Vot;                   // Declare a variable of type VOTER to store voter information
    long long int Search_CNIC;   // Declare a variable to store the CNIC to search for
    cout << "Enter Your CNIC: "; // Prompt the user to input their CNIC
    cin >> Search_CNIC;          // Read the CNIC entered by the user
    try
    {

        // Declare a file input stream object
        ifstream fin;
        fin.open("Voter.txt"); // Open the file "Voter.txt" for reading
        if (!fin)              // Check if the file opening was successful
        {
            throw runtime_error("File Not Found."); // If file opening failed, throw a runtime error
        }
        bool found = false; // Initialize a boolean variable to track whether the voter is found
        // Loop through the voter records in the file
        while (fin >> Vot.CNIC >> Vot.Voter.Name >> Vot.Age >> Vot.Voter.Gender >> Vot.Block_No >>
               Vot.Polling_Station >> Vot.NA.Constituency >> Vot.PA.Constituency)
        {

            if (Vot.CNIC == Search_CNIC) // Check if the CNIC in the current record matches the CNIC entered by the user
            {
                found = true; // If a match is found, set the 'found' flag to true
                break;        // Exit the loop since the voter has been found
            }
        }
        fin.close(); // Close the file stream after reading
        // Display voter information if found
        if (found)
        {
            cout << "Registration Found with CNIC: " << Search_CNIC << endl;
            cout << "Name: " << Vot.Voter.Name << endl;
            cout << "Age: " << Vot.Age << endl;
            cout << "Gender: " << Vot.Voter.Gender << endl;
            cout << "Block_No: " << Vot.Block_No << endl;
            cout << "Polling Station: " << Vot.Polling_Station << endl;
            cout << "NA Constituency: " << Vot.NA.Constituency << endl;
            cout << "PA Constituency: " << Vot.PA.Constituency << endl;
        }
        else
        {
            cout << "No registration found for CNIC: " << Search_CNIC << endl; // If the registration is not found, print a message indicating so

            cout << "For Voting, contact election commission's office." << endl; // Provide guidance on what to do if the voter is not registered
        }
    }
    catch (runtime_error &e)
    {
        cout << "Error: " << e.what() << endl; // If an error occurs during file operations, print an error message
    }
}

#endif