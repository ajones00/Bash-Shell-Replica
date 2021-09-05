#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main() {

	vector<string> historyEvents, userInput2; //historyEvents stores any command that was input into terminal, userInput2 stores new prompt that contains \! event history number bash command
	string userInput; //store user input
	string prompt = "CSC4420>"; //for non-history# prompt (prompt that does not contain \! bash command)
	int historyFlag = 0; //0 If prompt does not contain \! bash history number command, 1 if it does
	int quit = 0; //0 if quit command has not been pressed, 1 if it has
	size_t position = 0; //use for traversing the userInput vector or string, max size for any obj type
	string delimiter = "\\!"; //bash command that can be used in prompt to show history number (treat it as a "delimiter")

	while (quit != 1) {
		while (historyFlag == 0 && quit != 1) {	
			cout << prompt;
			getline(cin, userInput);
			historyEvents.push_back(userInput); //stores any input into terminal

			if (userInput == "prompt") {
				cout << "Enter new prompt" << endl;
				cout << prompt;
				getline(cin, userInput);
				historyEvents.push_back(userInput);
				if (userInput.find(delimiter) != string::npos) { //checks if user input for prompt contains the delimiter (\!) event history number command. string::npos to reach an end of a string
					historyFlag = 1;
					userInput2.clear();
					while ((position = userInput.find(delimiter)) != string::npos) { //if userInput contains delimiter, put userInput into a vector called userInput2 and insert "*" to mark delimiter location
						userInput2.push_back(userInput.substr(0, position));
						userInput2.push_back("*");
						userInput.erase(0, position + delimiter.length());
					}
					if (userInput.size() != 0) { //If any input leftover after " " then insert it into userInput vector
						userInput2.push_back(userInput);
					}
				}
				else {
					historyFlag = 0;
					userInput2.clear();
					prompt = userInput;
				}
			}
			else if (userInput == "url") {
				cout << "https://lihaoxu.eng.wayne.edu/Courses/CSC4420/" << endl;
			}
			else if (userInput == "hour") {
				cout << "Time: 11:30am to 12:45pm, Mon. Wed." << endl;
			}
			else if (userInput == "room") {
				cout << "Classroom: Teams" << endl;
			}
			else if (userInput == "desp") {
				cout << "Operating system is an essential sofeware layer to use various various computing devices. This course covers the basic components and design principles " <<
					"of modern operating systems, including process and thread, CPU scheduling, memory management, file system and others. This course also provides hand-on " <<
					"programming experiences of using Linux system calls, and design and implementation of a cloud-based file system." << endl;
			}
			else if (userInput == "text") {
				cout << "Modern Operating Systems, 4 / E, 4th Edition, Pearson, 2015." << endl;
			}
			else if (userInput == "ref") {
				cout << "Operating System Concepts, 8th Edition, Wiley, 2008." << endl << "Understanding the Linux Kernel, , 3rd Edition, O'Reilly Media, 2005." << endl
					<< "Advanced UNIX Programming , 2nd Edition, Addison-Wesley, 2004." << endl << "Advanced Programming in the UNIX Environment 1st Edition , " <<
					"Addison-Wesley, 1992 or 3rd edition, 2013." << endl;
			}
			else if (userInput == "prof") {
				cout << "Lihao Xu" << endl;
			}
			else if (userInput == "pol") {
				cout << "Office: Teams" << endl;
			}
			else if (userInput == "poh") {
				cout << "Office Hours: By appointment" << endl;
			}
			else if (userInput == "pma") {
				cout << "Email: lihao@wayne.edu" << endl;
			}
			else if (userInput == "ta") {
				cout << "Artem Komarichev" << endl;
			}
			else if (userInput == "tol") {
				cout << "Office: Teams" << endl;
			}
			else if (userInput == "toh") {
				cout << "Office Hours: by appointment" << endl;
			}
			else if (userInput == "tma") {
				cout << "Email: fn9241@wayne.edu" << endl;
			}
			else if (userInput == "history") {
				for (int i = 0; i < historyEvents.size(); i++) {
					if (i != 0) {
						cout << i + 1 << " " << historyEvents[i] << endl;
					}
					else {
						cout << "1 " << historyEvents[i] << endl;
					}
				}
			}
			else if (userInput == "help") {
				cout << "prompt" << endl << "url" << endl << "hour" << endl << "room" << endl << "desp" << endl << "text" << endl << "ref" << endl << "prof"
					<< endl << "pol" << endl << "poh" << endl << "pma" << endl << "ta" << endl << "tol" << endl << "toh" << endl << "tma" << endl << "history"
					<< endl << "help" << endl << "quit" << endl;
			}
			else if (userInput == "quit") {
				quit = 1;
			}
			else {
				cout << "Invalid command, please try again." << endl;
			}
		}

		while (historyFlag == 1 && quit != 1) {		
			for (int i = 0; i < userInput2.size(); i++) { //prints out the userInput2 vector which contains the user prompt with \! event history number
				if (userInput2[i] == "*") {
					cout << historyEvents.size()+1;
				}
				else {
					cout << userInput2[i];
				}
			}
			getline(cin, userInput);
			historyEvents.push_back(userInput); //stores any input into terminal
			
			if (userInput == "prompt") {
				cout << "Enter new prompt" << endl;
				for (int i = 0; i < userInput2.size(); i++) {
					if (userInput2[i] == "*") {
						cout << historyEvents.size()+1;
					}
					else {
						cout << userInput2[i];
					}
				}
				getline(cin, userInput);
				historyEvents.push_back(userInput); //stores input into terminal
				if (userInput.find(delimiter) != string::npos) {
					historyFlag = 1;
					userInput2.clear();
					while ((position = userInput.find(delimiter)) != string::npos) {
						userInput2.push_back(userInput.substr(0, position));
						userInput2.push_back("*");
						userInput.erase(0, position + delimiter.length());
					}
					if (userInput.size() != 0) {
						userInput2.push_back(userInput);
					}
				}
				else {
					historyFlag = 0;
					userInput2.clear();
					prompt = userInput;
				}
			}
			else if (userInput == "url") {
				cout << "https://lihaoxu.eng.wayne.edu/Courses/CSC4420/" << endl;
			}
			else if (userInput == "hour") {
				cout << "Time: 11:30am to 12:45pm, Mon. Wed." << endl;
			}
			else if (userInput == "room") {
				cout << "Classroom: Teams" << endl;
			}
			else if (userInput == "desp") {
				cout << "Operating system is an essential sofeware layer to use various various computing devices. This course covers the basic components and design principles " <<
					"of modern operating systems, including process and thread, CPU scheduling, memory management, file system and others. This course also provides hand-on " <<
					"programming experiences of using Linux system calls, and design and implementation of a cloud-based file system." << endl;
			}
			else if (userInput == "text") {
				cout << "Modern Operating Systems, 4 / E, 4th Edition, Pearson, 2015." << endl;
			}
			else if (userInput == "ref") {
				cout << "Operating System Concepts, 8th Edition, Wiley, 2008." << endl << "Understanding the Linux Kernel, , 3rd Edition, O'Reilly Media, 2005." << endl
					<< "Advanced UNIX Programming , 2nd Edition, Addison-Wesley, 2004." << endl << "Advanced Programming in the UNIX Environment 1st Edition , " <<
					"Addison-Wesley, 1992 or 3rd edition, 2013." << endl;
			}
			else if (userInput == "prof") {
				cout << "Lihao Xu" << endl;
			}
			else if (userInput == "pol") {
				cout << "Office: Teams" << endl;
			}
			else if (userInput == "poh") {
				cout << "Office Hours: By appointment" << endl;
			}
			else if (userInput == "pma") {
				cout << "Email: lihao@wayne.edu" << endl;
			}
			else if (userInput == "ta") {
				cout << "Artem Komarichev" << endl;
			}
			else if (userInput == "tol") {
				cout << "Office: Teams" << endl;
			}
			else if (userInput == "toh") {
				cout << "Office Hours: by appointment" << endl;
			}
			else if (userInput == "tma") {
				cout << "Email: fn9241@wayne.edu" << endl;
			}
			else if (userInput == "history") {
				for (int i = 0; i < historyEvents.size(); i++) {
					if (i != 0) {
						cout << i + 1 << " " << historyEvents[i] << endl;
					}
					else {
						cout << "1 " << historyEvents[i] << endl;
					}
				}
			}
			else if (userInput == "help") {
				cout << "prompt" << endl << "url" << endl << "hour" << endl << "room" << endl << "desp" << endl << "text" << endl << "ref" << endl << "prof"
					<< endl << "pol" << endl << "poh" << endl << "pma" << endl << "ta" << endl << "tol" << endl << "toh" << endl << "tma" << endl << "history"
					<< endl << "help" << endl << "quit" << endl;
			}
			else if (userInput == "quit") {
				quit = 1;
			}
			else {
				cout << "Invalid command, please try again." << endl;
			}
		}
	}
	return 0;
}