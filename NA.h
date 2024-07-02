#ifndef NA_H
#define NA_H
#include <iostream>
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.
using namespace std;

struct Data // Define a structure to hold candidate data
{
    string Name, Gender, Address; // Define member variables for the structure
};

struct CANDIDATE // Define a structure to hold candidate details
{
    Data Candidate;                     // Nested structure to store candidate data
    int ID;                             // Member variable to store the id of candidate
    string Symbol, Party, Constituency; // Member variables for other candidate details
};

// Function prototypes to manage the details of National Assembly candidates
void NAC_Menu();
void Add_NAC();
void View_NAC();
void Search_NAC();
void SearchByPartyNA();
void SearchByGenderNA();

// NAC_Menu function to manage menu options for National Assembly candidates
void NAC_Menu() // Function definition for managing National Assembly candidate details
{
    int choice; // Declare a variable to store the choice of user
    do
    {
        cout << "****************************** NATIONAL ASSEMBLY CANDITATE MENU******************************" << endl; // Display menu title

        cout << " 1. ADD NATIONAL ASSEMBLY CANDIDATE " << endl;    // Display option to add candidate
        cout << " 2. VIEW NATIONAL ASSEMBLY CANDIDATE " << endl;   // Display option to view candidate details
        cout << " 3. SEARCH NATIONAL ASSEMBLY CANDIDATE " << endl; // Display option to search for candidates
        cout << " 0. BACK TO MAIN MENU " << endl;                  // Display option to go back to the main menu
        cout << " Enter choice " << endl;                          // Prompt the user to enter their choice
        cin >> choice;                                             // User enters choice from the above choices
        switch (choice)                                            // switch statement based on the choice of the user
        {
        case 1:        // If user chooses to add a candidate
            Add_NAC(); // Call the function to add a candidate
            break;
        case 2:         // If user chooses to view candidate details
            View_NAC(); // Call the function to view candidate details
            break;
        case 3:           // If user chooses to search for candidates
            Search_NAC(); // Call the function to search for candidates
            break;
        case 0:                                             // If user chooses to go back to the main menu
            cout << " Returning to the Main Menu " << endl; // Following message displayed
            break;
        default:                                                     // If user enters an invalid choice
            cout << "Invalid Choice. Enter a valid Choice " << endl; // Display's Following error message
        }

    } while (choice != 0); // Continue the loop until user chooses to exit
}

void Add_NAC() // Function to add a National Assembly candidate
{
    CANDIDATE NAC;                                                            // Declare a variable of type CANDIDATE to store candidate details
    ofstream OutputFile;                                                      // Declare an output file stream object
    OutputFile.open("NAC.txt", ios::app);                                     // Open the file "NAC.txt" in append mode
    cout << "***** ENTER NATIONAL ASSEMBLY CANDIDATE DETAILS: *****" << endl; // Prompt user to entercandidate details
    cout << " ID: ";                                                          // Prompt user for candidate ID
    cin >> NAC.ID;                                                            // user enter ID of candidate
    cout << " Name: ";                                                        // Prompt user for candidate name
    cin >> NAC.Candidate.Name;                                                // user enter ID of candidate
    cout << " Gender: ";                                                      // Prompt user for candidate gender
    cin >> NAC.Candidate.Gender;                                              // user enter gender of candidate

    cout << " Symbol: ";          // Prompt user for candidate symbol
    cin >> NAC.Symbol;            // user enter symbol for the candidate
    cout << " Party: ";           // Prompt user for candidate party
    cin >> NAC.Party;             // user enter candidate's party name
    cout << " NA Constituency: "; // Prompt user for candidate constituency
    cin >> NAC.Constituency;      // user enter Constituency (NA)
    cout << " Address: ";         // Prompt user for candidate address
    cin >> NAC.Candidate.Address; // user enter address of the candidate
    // Storing candidate details to the output file
    OutputFile << left << setw(20) << NAC.ID << setw(15) << NAC.Candidate.Name << setw(15) << NAC.Candidate.Gender << setw(15) << NAC.Symbol << setw(15) << NAC.Party << setw(15) << NAC.Constituency
               << setw(15) << NAC.Candidate.Address << endl;
    cout << "***** Details Of NATIONAL ASSEMBLY Candidate Added Successfully *****" << endl;
    OutputFile.close(); // Close the output file
}
// Function to view National Assembly candidates
void View_NAC()
{
    CANDIDATE NAC; // Declare a variable of type CANDIDATE to store candidate details
    try            // Start a try block to catch any exceptions
    {
        ifstream fin;        // Declare an input file stream object
        fin.open("NAC.txt"); // Open the file "NAC.txt" for reading
        if (!fin)            // If file opening fails
        {
            throw runtime_error(" File Not Found. "); // Throw a runtime error
        }
        // Display header for candidate details
        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "NA-Constituency" << setw(20) << "Address" << endl;
        // Read candidate details from the file and display them
        while (fin >> NAC.ID >> NAC.Candidate.Name >> NAC.Candidate.Gender >> NAC.Symbol >> NAC.Party >>
               NAC.Constituency >> NAC.Candidate.Address)
        {
            cout << left << setw(20) << NAC.ID << setw(15) << NAC.Candidate.Name << setw(15) << NAC.Candidate.Gender << setw(15) << NAC.Symbol << setw(15) << NAC.Party << setw(20) << NAC.Constituency << setw(20) << NAC.Candidate.Address << setw(20) << endl;
        }
        fin.close(); // Close the file that is opened
    }
    catch (runtime_error &e) // Catch and handle runtime error if file operation fails

    {
        cout << "Error" << e.what() << endl; // display the error
    }
}
void Search_NAC() // Define a function to search for National Assembly candidates
{
    // Declare a variable to store user's choice
    int choice;
    do // Start a do-while loop to repeatedly display the menu until the user chooses to exit
    {
        cout << "***** SEARCHING NATIONAL ASSEMBLY CANDIDATE: *****" << endl; // Display search menu title
        cout << "1. Search BY Party: " << endl;                               // Display option to search by party
        cout << "2. Search BY Gender: " << endl;                              // Display option to search by gender
        cout << "0. Back To NA Menu: " << endl;                               // Display option to go back to the NA menu
        cout << " Enter choice " << endl;                                     // Prompt the user to enter their choice
        cin >> choice;                                                        // Read user's choice
        switch (choice)                                                       // Start a switch statement based on user's choice
        {
        case 1:                // If user chooses to search by party
            SearchByPartyNA(); // Call the function to search by party
            break;
        case 2:                 // If user chooses to search by gender
            SearchByGenderNA(); // Call the function to search by gender
            break;
        case 0:                                       // If user chooses to go back to the NA menu
            cout << " Returning to NA Menu " << endl; // Display message
            break;
        default:                                                      // If user enters an invalid choice
            cout << " Invalid choice. Enter a valid choice " << endl; // Display error message
        }
    } while (choice != 0); // Continue the loop until user chooses to exit
}
void SearchByPartyNA() // Define a function to search National Assembly candidates by party
{
    CANDIDATE NAC;           // Declare a variable of type CANDIDATE to store candidate details
    int candidate_count = 0; // Initialize candidate count to zero
    try                      // Start a try block to catch any exceptions
    {
        ifstream fin; // Declare an input file stream object
        fin.open("NAC.txt");
        if (!fin)
        {

            throw runtime_error(" File Not Found. ");
        }
        string Search_Party;                                // Declare a string variable to store the party to search for
        cout << " Enter Party you want to search " << endl; // Prompt user to enter the party to search for
        cin >> Search_Party;
        bool found = false;
        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "NA-Constituency" << setw(20) << "Address" << endl;
        // Read candidate details from the file and display those matching the specified party
        while (fin >> NAC.ID >> NAC.Candidate.Name >> NAC.Candidate.Gender >> NAC.Symbol >> NAC.Party >>
               NAC.Constituency >> NAC.Candidate.Address)
        {
            if (NAC.Party == Search_Party) // If the candidate's party matches the search party
            {
                found = true;
                // Display the candidate details
                cout << left << setw(20) << NAC.ID << setw(15) << NAC.Candidate.Name << setw(15) << NAC.Candidate.Gender << setw(15) << NAC.Symbol << setw(15) << NAC.Party << setw(20) << NAC.Constituency << setw(20) << NAC.Candidate.Address << setw(20) << endl;

                candidate_count++; // Increment the candidate count
            }
        }
        if (candidate_count > 0) // If candidates were found for the specified party
        {
            cout << " Total Candidates in " << Search_Party << " are " << candidate_count << endl; // Display total candidate count
        }
        else // If no candidates were found for the specified party
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
void SearchByGenderNA() // Define a function to search National Assembly candidates by gender
{

    CANDIDATE NAC;        // Declare a variable of type CANDIDATE to store candidate details
    int Male_count = 0;   // Initialize male candidate count to zero
    int Female_count = 0; // Initialize female candidate count to zero
    try
    {
        ifstream fin("NAC.txt");
        if (!fin)
        {
            throw runtime_error("File Not Found.");
        }
        string Search_Gender; // Declare a string variable to store the gender to search for
        cout << "***** Enter Gender to search (Male/Female): *****" << endl;
        cin >> Search_Gender;
        bool found = false; // Boolean flag to indicate if candidates are found
        cout << left
             << setw(20) << "ID" << setw(15) << "Name" << setw(15) << "Gender" << setw(15) << "Symbol" << setw(15) << "Party" << setw(20) << "NA-Constituency" << setw(20) << "Address" << endl;
        // Read candidate details from the file and display those matching the specified gender
        while (fin >> NAC.ID >> NAC.Candidate.Name >> NAC.Candidate.Gender >> NAC.Symbol >> NAC.Party >>
               NAC.Constituency >> NAC.Candidate.Address)
        {
            if (NAC.Candidate.Gender == Search_Gender) // If the candidate's gender matches the search gender
            {
                found = true;
                // Display candidate details
                cout << left << setw(20) << NAC.ID << setw(15) << NAC.Candidate.Name << setw(15) << NAC.Candidate.Gender << setw(15) << NAC.Symbol << setw(15) << NAC.Party << setw(20) << NAC.Constituency << setw(20) << NAC.Candidate.Address << setw(20) << endl;

                if (Search_Gender == "Male") // If the search gender is male
                {
                    Male_count++; // Increment male candidate count
                }
                else if (Search_Gender == "Female") // If the search gender is female
                {
                    Female_count++; // Increment female candidate count
                }
            }
        }
        // Display the total number of male or female candidates found
        if (Search_Gender == "Male" && Male_count > 0)
        {
            cout << " Total Male Candidates: " << Male_count << endl;
        }
        else if (Search_Gender == "Female" && Female_count > 0)
        {
            cout << " Total Female Candidates: " << Female_count << endl;
        }
        else
        {

            cout << "No candidates found " << Search_Gender << endl; // Display message if no candidates f
        }
        fin.close(); // Close the file
    }
    catch (runtime_error &e) // Catch and handle runtime error if file operation fails
    {
        cout << "Error: " << e.what() << endl; // Display the error message
    }
}
#endif