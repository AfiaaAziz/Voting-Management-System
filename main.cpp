#include <iostream> //Include library for input output operations.

#include "NA.h"     //Include header file to manage National Assembly (NA) candidates.
#include "PA.h"     // Include header file to manage Provincial Assembly (PA) candidates.
#include "Voters.h" // Include header file to manage the voting list.

using namespace std;


int main() // The main function, the entry point of the program
{
    int choice;  // Declaring a variable to store the user choice
    while (true) // Infinite loop to keep the program running until explicitly exited
    {
        cout << "****************************** VOTING MANAGEMENT SYSTEM ******************************"<< endl;                                   // Displaying the main menu.
        cout << " 1. NA Candidate Management " << endl; // Option for managing National Assembly candidates.
        cout << " 2. PA Candidate Management " << endl; // Option for managing Provincial Assemblycandidates
        cout << " 3. Voting list Management " << endl;  // Option for managing the voting list
        cout << " 4. Exit " << endl;                    // Option to exit the program
        cout << " Enter choice " << endl;               // Prompting the user to enter a choice
        cin >> choice;                                  // User enter choice from the above choices
        switch (choice)                                 // Switch statement to handle the user's choice
        {
        case 1:
            NAC_Menu(); // NAC menu for managing National Assembly candidates
            break;
        case 2:
            PAC_Menu(); // PAC menu for managing Provincial Assembly candidates
            break;
        case 3:
            Voter_Menu(); // Voter menu for managing the voting list
            break;
        case 4:
            exit(0); // If user chooses Exit, exit the program
        default:
            cout << " Invalid choice. Enter a valid choice " << endl; // Displayed when the user inputs an invalid choice.
        }
    }

    return 0;
}