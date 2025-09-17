#include <iostream>
#include <string>
using namespace std;

int main() {
	bool isCodingFun;
	string Coding_Is_Fun = "Coding Is Fun!";

	bool yougay;
	string YouAreGay = "You like women";

	string Userinput;

	int myAge = 0;
	int votingAge = 18;

	cout << "Type true or false to display value!" << "\n" << "Type exit To Leave.." << endl;

	while (true) {
		getline(cin, Userinput);

		if (Userinput == "exit") {
			cout << "You have exited!" << endl;
			break;
		}

		else if (Userinput == "true") {
			isCodingFun = true;
			cout << "\n" << Coding_Is_Fun << "\n" << boolalpha << "\t" << isCodingFun << "\n";
		}

		else if (Userinput == "false") {
			isCodingFun = false;
			cout << "\n" << Coding_Is_Fun << "\n" << boolalpha << "\t" << isCodingFun << "\n";
		}

		else if (Userinput == "gay") {
			yougay = true;
			cout << "\n" << YouAreGay << "\n" << boolalpha << yougay << "\n";
		}

		else {
			try {
				myAge = stoi(Userinput); // Convert only the userInput string to an integer

				if (myAge >= votingAge) {
					cout << "Old enough to vote!" << endl;
				}
				else {
					cout << "Not old enough to vote." << endl;
				}
			}
			catch (const invalid_argument& e) {
				// Catches the error if stoi fails because of non-numeric input
				cout << "Invalid input. Please enter a valid command or your age." << endl;
			}
			catch (const out_of_range& e) {
				// Catches the error if the number is too big
				cout << "Invalid input. The number you entered is out of range." << endl;
			}

			try {
				Userinput = to_string(myAge);
				if (Userinput == "exit") {
					cout << "\n" << "You have exited!" << endl;
					break;
				}
			}
			catch (const invalid_argument& e) {
				// Catches the error if stoi fails because of non-numeric input
				cout << "Invalid input. Please enter a valid command or your age." << endl;
			}
			if (Userinput == "exit") {
				cout << "\n" << "You have exited!" << endl;
				break;
			}
		}
	}

	return 0;
}