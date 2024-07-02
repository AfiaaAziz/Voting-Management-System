#ifndef PA_H
#define PA_H
#include <iostream>
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.
#include "NA.h"    // Include the NA.h header file

using namespace std;
// Function prototypes for managing Provincial Assembly candidate details
void NAC_Menu();
void Add_PAC();
void View_PAC();
void Search_PAC();
void SearchByPartyPA();
void SearchByGenderPA();

void PAC_Menu() // Define the function PAC_Menu to manage Provincial Assembly candidate menu
{
    int choice; // Declare a variable to store user choice
    do          // Start of do-while loop for the menu
    {
        cout << "****************************** PROVINCIAL ASSEMBLY CANDITATE MENU******************************" << endl; // Display menu title
        cout << " 1. ADD PROVINCIAL ASSEMBLY CANDIDATE " << endl;                                                          // Option to add Provincial Assemblycandidate
        cout << " 2. VIEW PROVINCIAL ASSEMBLY CANDIDATE " << endl;                                                         // Option to view Provincial Assemblycandidate
        cout << " 3. SEARCH PROVINCIAL ASSEMBLY CANDIDATE " << endl;                                                       // Option to search ProvincialAssembly candidate
        cout << " 0. BACK TO MAIN MENU " << endl;                                                                          // Option to return to the main menu
        cout << " Enter choice " << endl;                                                                                  // Prompt user to enter choice
        cin >> choice;
        switch (choice) // Start of switch statement based on user choice
        {
        case 1:                                                      // If user chooses to add Provincial Assembly candidate
            Add_PAC();                                               // Call the function to add Provincial Assembly candidate
            break;                                                   // Exit the switch statement
        case 2:                                                      // If user chooses to view Provincial Assembly candidate
            View_PAC();                                              // Call the function to view Provincial Assembly candidate
            break;                                                   // Exit the switch statement
        case 3:                                                      // If user chooses to search Provincial Assembly candidate
            Search_PAC();                                            // Call the function to search Provincial Assembly candidate
            break;                                                   // Exit the switch statement
        case 0:                                                      // If user chooses to return to the main menu
            cout << " Returning to the Main Menu " << endl;          // Display message
            break;                                                   // Exit the switch statement
        default:                                                     // If user enters an invalid choice
            cout << "Invalid Choice. Enter a valid Choice " << endl; // Display message
        }

    } while (choice != 0); // Repeat the loop until the user chooses to return to the main menu
}
// Define the function to add Provincial Assembly candidate details
void Add_PAC()
{
    CANDIDATE PAC; // Declare a variable of type CANDIDATE to store Provincial Assembly candidate details
    ofstream OutputFile;
    OutputFile.open("PAC.txt", ios::app);
    cout << "***** ENTER PROVINCIAL ASSEMBLY CANDIDATE DETAILS: *****" << endl;
    cout << " ID: ";              // Prompt user for ID
    cin >> PAC.ID;                // Read ID
    cout << " Name: ";            // Prompt user for name
    cin >> PAC.Candidate.Name;    // Read name
    cout << " Gender: ";          // Prompt user for gender
    cin >> PAC.Candidate.Gender;  // Read gender
    cout << " Symbol: ";          // Prompt user for symbol
    cin >> PAC.Symbol;            // Read symbol
    cout << " Party: ";           // Prompt user for party
    cin >> PAC.Party;             // Read party
    cout << " PA Constituency: "; // Prompt user for Provincial Assembly constituency
    cin >> PAC.Constituency;      // Read constituency
    cout << " Address: ";         // Prompt user for address
    cin >> PAC.Candidate.Address; // Read address
    // Write the candidate details to the file
    OutputFile << left << setw(20) << PAC.ID << setw(15) << PAC.Candidate.Name << setw(15) << PAC.Candidate.Gender << setw(15) << PAC.Symbol << setw(15) << PAC.Party << setw(15) << PAC.Constituency
               << setw(15) << PAC.Candidate.Address << endl;
    cout << "***** Details Of PROVINCIAL ASSEMBLY Candiate Added Successfully *****" << endl;
    OutputFile.close(); // Close the file
}
void View_PAC() // Define a function to view Provincial Assembly candidates
{
    CANDIDATE PAC; // Declare a variable of type CANDIDATE to store candidate details
    try            // Start of try block to handle exceptions
    {

        ifstream fin;
        fin.open("PAC.txt"); // Open the file "PAC.txt"
        if (!fin)            // Check if the file opening failed
        {
            throw runtime_error(" File Not Found. "); // Throw a runtime error if the file is not found
        }
        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "PA-Constituency" << setw(20) << "Address" << endl;
        // Read candidate details from the file
        while (fin >> PAC.ID >> PAC.Candidate.Name >> PAC.Candidate.Gender >> PAC.Symbol >> PAC.Party >>
               PAC.Constituency >> PAC.Candidate.Address)
        {
            cout << left << setw(20) << PAC.ID << setw(15) << PAC.Candidate.Name << setw(15) << PAC.Candidate.Gender << setw(15) << PAC.Symbol << setw(15) << PAC.Party << setw(15) << PAC.Constituency
                 << setw(15) << PAC.Candidate.Address << endl;
        }
        fin.close(); // Close the file that is opened
    }
    catch (runtime_error &e) // Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; // display the error
    }
}
void Search_PAC() // Define a function to search Provincial Assembly candidates
{
    int choice; // Declare a variable to store user choice
    do          // Start of do-while loop for the search menu
    {
        cout << "***** SEARCHING PROVINCIAL ASSEMBLY CANDIDATE: *****" << endl; // Display search menu title
        cout << "1. Search BY Party: " << endl;                                 // Option to search candidates by party
        cout << "2. Search BY Gender: " << endl;                                // Option to search candidates by gender
        cout << "0. Back To PA Menu: " << endl;                                 // Option to return to the Provincial Assembly menu
        cout << " Enter choice " << endl;                                       // Prompt user to enter choice
        cin >> choice;                                                          // Read user choice
        switch (choice)                                                         // Start of switch statement based on user choice
        {
        case 1:                // If user chooses to search by party
            SearchByPartyPA(); // Call the function to search candidates by party
            break;             // Exit the switch statement

        case 2:                                                       // If user chooses to search by gender
            SearchByGenderPA();                                       // Call the function to search candidates by gender
            break;                                                    // Exit the switch statement
        case 0:                                                       // If user chooses to return to the Provincial Assembly menu
            cout << " Returning to PA Menu " << endl;                 // Display message
            break;                                                    // Exit the switch statement
        default:                                                      // If user enters an invalid choice
            cout << " Invalid choice. Enter a valid choice " << endl; // Display message
        }

    } while (choice != 0); // Repeat the loop until the user chooses to return to the Provincial Assembly menu
}

void SearchByPartyPA() // Define a function to search Provincial Assembly candidates by party
{
    CANDIDATE PAC;           // Declare a variable of type CANDIDATE to store candidate details
    int candidate_count = 0; // Initialize candidate count to zero
    try                      // Start of try block to handle exceptions
    {
        ifstream fin;
        fin.open("PAC.txt");
        if (!fin)
        {
            throw runtime_error(" File Not Found. ");
        }
        string Search_Party;                                // Declare a string variable to store the party to search for
        cout << " Enter Party you want to search " << endl; // Prompt user to enter the party to searchfor
        cin >> Search_Party;                                // Read the party to search for
        bool found = false;                                 // Initialize a boolean variable to track if candidates are found
        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "PA-Constituency" << setw(20) << "Address" << endl;
        // Read candidate details from the file
        while (fin >> PAC.ID >> PAC.Candidate.Name >> PAC.Candidate.Gender >> PAC.Symbol >> PAC.Party >>
               PAC.Constituency >> PAC.Candidate.Address)
        {
            if (PAC.Party == Search_Party) // Check if the candidate belongs to the searched party
            {
                found = true; // Set found to true

                // Display candidate details
                cout << left << setw(20) << PAC.ID << setw(15) << PAC.Candidate.Name << setw(15) << PAC.Candidate.Gender << setw(15) << PAC.Symbol << setw(15) << PAC.Party << setw(15) << PAC.Constituency
                     << setw(15) << PAC.Candidate.Address << endl;

                candidate_count++; // Increment candidate count
            }
        }
        if (candidate_count > 0) // If candidates are found for the searched party
        {
            cout << " Total Candidates in " << Search_Party << " are " << candidate_count << endl; // Display total candidates for the searched party
        }
        else
        {
            cout << " Party " << Search_Party << " Not Found " << endl; // Display message indicating party not found
        }
        fin.close(); // Close the file
    }
    catch (runtime_error &e) // Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; // display the error
    }
}
void SearchByGenderPA() // Define a function to search Provincial Assembly candidates by gender
{
    CANDIDATE PAC;        // Declare a variable of type CANDIDATE to store candidate details
    int Male_count = 0;   // Initialize male candidate count to zero
    int Female_count = 0; // Initialize female candidate count to zero
    try                   // Start of try block to handle exceptions
    {
        ifstream fin("PAC.txt");
        if (!fin)
        {
            throw runtime_error("File Not Found.");
        }
        string Search_Gender;                                                // Declare a string variable to store the gender to search for
        cout << "***** Enter Gender to search (Male/Female): *****" << endl; // Prompt user to enter the gender to search for
        cin >> Search_Gender;                                                // Read the gender to search for
        bool found = false;                                                  // Initialize a boolean variable to track if candidates are found

        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "PA-Constituency" << setw(20) << "Address" << endl;

        // Read candidate details from the file
        while (fin >> PAC.ID >> PAC.Candidate.Name >> PAC.Candidate.Gender >> PAC.Symbol >> PAC.Party >>
               PAC.Constituency >> PAC.Candidate.Address)
        {
            if (PAC.Candidate.Gender == Search_Gender) // Check if the candidate's gender matches the searched gender
            {
                found = true;
                cout << left << setw(20) << PAC.ID << setw(15) << PAC.Candidate.Name << setw(15) << PAC.Candidate.Gender << setw(15) << PAC.Symbol << setw(15) << PAC.Party << setw(15) << PAC.Constituency
                     << setw(15) << PAC.Candidate.Address << endl;

                if (Search_Gender == "Male" || Search_Gender == "male") // Check if the searched gender is male

                {
                    Male_count++; // Increment male candidate count
                }
                else if (Search_Gender == "Female" || Search_Gender == "female") // Check if the searched gender is female
                {
                    Female_count++; // Increment female candidate count
                }
            }
        }
        if (Search_Gender == "Male" && Male_count > 0) // If male candidates are found
        {
            cout << " Total Male Candidates: " << Male_count << endl; // Display the total number of male candidates
        }
        else if (Search_Gender == "Female" && Female_count > 0) // If female candidates are found
        {
            cout << " Total Female Candidates: " << Female_count << endl; // Display the total number of female candidates
        }
        else // If no candidates are found for the searched gender
        {
            cout << "No candidates found for the given gender " << Search_Gender << endl; // Display message indicating no candidates found
        }
        fin.close(); // Close the file
    }
    catch (runtime_error &e) // Catch and handle runtime error if file operation fails
    {
        cout << "Error: " << e.what() << endl; // Display the error message
    }
}

#endif
