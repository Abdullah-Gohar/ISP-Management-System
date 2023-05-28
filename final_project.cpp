// Importing required libraries
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <fstream>
#include <vector>
#include <ctime>
#include <windows.h>
using namespace std;

// Declaring a global map 
map<string,string> global_map;

// Function Prototypes
void pretty_print(); 

void add_id(string); 

bool id_checker(string id);

vector<map<string,string>> get_data(string data); 

vector<map<string,string>> search_name(string id, vector<map<string,string>>); 

int admin();

bool adminPriviliges(); 

void client();

string double_string_map_to_string(map<string,string>);

void write_data(string s,string file_name = "database.txt");

string read_data(string file_name = "database.txt");

map<string,string> string_to_map(string s); 

string trim(string s, string remove);

vector<string> string_splitter(string str, string delimiter);

int connect_problem();

int power_supply();

int ont();

int unknown();

int hardware_problem();

void other_tech_issue();

void user_data();

int tech();

int bundles();

int new_bundles();

int bandwidth();

int changing_package();

int hourlybundles();

int dailybundles();

int weeklybundles();

int data();

int cold_hard_data();

int data_bundles();

void new_connec();



int main(){
    // Calling pretty print function
    pretty_print();
    // while loop to keep executing while input in invalid
    while(true){
        // Setting terminal color to blue
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        // Take user input
        char choice;
        cout << "Enter A to access as admin\nEnter C to access as client\nEnter your choice: ";
        cin >> choice;
        // Convert input to lowercase to avoid matchcase errors
        choice = tolower(choice);
        // Calling different functions based on user input
        if(choice=='a'){
            bool flag = adminPriviliges();
            if(flag){
                admin();
                break;
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << "Incorrect Credentials\n";
                continue;
            }
        }

        else if(choice == 'c'){
            client();
            break;
        }

        else{
            cout << "Please enter correct input!\n";
        }
    }
    

}


void pretty_print(){
    /*
        Function to display a pretty interface
    */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);

    cout << "********************************************************************************\n";
    cout << "********************************************************************************\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);

    cout << "*****   *    *    ****  ******   ****     *     *  *****  ****\n";
    cout << "*       *    *   *        *     *    *    * * * *  *      *   *\n";
    cout << "*       *    *    ***     *     *    *    *  *  *  *****  ****\n";
    cout << "*       *    *       *    *     *    *    *  *  *  *      *   *\n";
    cout << "*****   ******   ****     *      ****     *  *  *  *****  *    *\n";

    cout << endl;

    cout << "\t\t ****    *    *    *****     ****      ****     ****     ******\n";
    cout << "\t\t*        *    *    *    *    *   *    *    *    *   *       *\n";
    cout << "\t\t ***     *    *    *****     ****     *    *    ****        *\n";
    cout << "\t\t    *    *    *    *         *        *    *    *    *      *\n";
    cout << "\t\t****     ******    *         *         ****     *     *     *\n";

    cout << endl;

    cout << " ****    *   *    ****  *****   *****   *     *\n";
    cout << "*         * *    *        *     *       * * * *\n";
    cout << " ***       *      ***     *     *****   *  *  *\n";
    cout << "    *      *         *    *     *       *  *  *\n";
    cout << "****       *     ****     *     *****   *  *  *\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);

    cout << "********************************************************************************\n";
    cout << "********************************************************************************\n";

}


bool adminPriviliges(){
    /*
        Function to check admin credentials
    */

    // Setting terminal color to gray
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cout << endl;

    string user_name,password;
    string saved_name = "admin"; //User Name
    string saved_pass = "abc123"; // Password

    // Prompting user for user name and password and storing input using getline
    cout << "Enter admin user name: ";
    getline(cin>>ws,user_name);
    cout << "Enter password: ";
    getline(cin>>ws,password);
    // Checking if user input is correct
    if(user_name==saved_name && password==saved_pass){
        return true;
    }
    return false; 
}


int admin(){
    /*
        Function to call all admin functionality
    */
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << "Access Granted!\n";
    cout << endl;
    // Reading data from database
    string data = read_data();
    // Converting data to a vector of maps
    vector<map<string,string>> map_vec = get_data(data);
    // Loop to keep running while input is invalid
    while(true){
        cout << "Enter A to display all data or S to search by user id: ";;
        char c;
        cin >> c;
        c=tolower(c);
        if(c=='a'){
            // Set color to blue and display all data
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
            cout << "\n\nUser Data\n***\n"<<data;
            break;
        }
        else if(c=='s'){
            // Loop to keep running while the users still searches ids
            while(true){
                // Get client id from user
                string id;
                cout << "Enter the client id you want to search: ";
                cin >> id;
                // Get all maps that contain that user id
                vector<map<string,string>> new_maps = search_name(id,map_vec);
                // End function if no map is found with given id
                if(new_maps.size()!=0){
                    // Set color to blue and display all data of that particular client
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << "User Data:\n";
                    // Iterating through each map in vector
                    for(int i = 0; i<new_maps.size();i++){
                        cout << "User Request #" <<i+1<<":\n";
                        // Printing out each key value pair of map
                        for(auto it : new_maps[i]){
                            cout << it.first << " :  " << it.second << endl; 
                        }
                        cout << endl;
                    }
                }
                // Setting terminal color to green
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                // Promprting the user whether to search another id
                cout << "Do you want to search another id Y/N: ";
                char another;
                cin>>another;
                another=tolower(another);
                // Searching another id or terminating based on user input
                if(another=='y'){
                    cout << endl;
                    continue;
                }
                else{
                    break;
                }

            }
            break;
        }
        else{
            cout << "Please enter valid input\n";
            continue;
        }
    }
    return 0;
}


void client(){
    /*
        Function to call all client functionality
    */

    // Set terminal color to purple
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
    cout << endl;
    // Get user choice
    char choice;
    cout << "Enter T for tech support\nEnter B for bundles\nEnter N for new connection\nEnter your choice: ";
    cin >> choice;
    choice = tolower(choice);


    // Loop to keep running while input is invalid
    while(true){
        // Calling functions based on user input
        if (choice=='t'){
            tech();
            break;
        }
        else if(choice == 'b'){
            bundles();
            break;
        }
        else if(choice == 'n'){
            new_connec();
            break;
        }
        else{
            cout << "Invalid input \nPlease enter either t for tech support, b for bundles or n for new connection: ";
            cin >> choice;
            choice = tolower(choice);
            continue;
        }
    }
    // Storing user data in database
    write_data(double_string_map_to_string(global_map));

}


void write_data(string s,string file_name){
    /*
        Function to write data to database
    */

    // Creating ofstream object
    ofstream file;
    // Opening database file in append mode using ofstream object
    file.open(file_name,fstream::app);
    // Storing data in file
    file << s <<"\n**********\n";
    // Closing file
    file.close();
}


string read_data(string file_name){
    /*
        Function to read data from database
    */

    // Creating ifstream object
    ifstream file;
    // Opening database file using ifstream object
    file.open(file_name);
    string main_string,temp;
    // Reading all data from file and writing to string
    while(getline(file,temp)){
        main_string += temp+"\n";
    }
    // Closing file
    file.close();
    // Removing excess split identifiers from the end of data
    main_string = trim(main_string,"**********\n");
    // Returning all data
    return main_string;

}


string trim(string s, string remove){
    /*
        Function to remove all occurunces of a specific string from left and right of given string
    */

    // Finding index of first occurence of a character not in the 'remove' string
    int first = s.find_first_not_of(remove);
    // Finding index of last occurence of a character not in the 'remove' string
    int last = s.find_last_not_of(remove);
    // Returning string after removing 'remove' string from left and right of string
    return s.substr(first,last+1);

}


vector<string> string_splitter(string s, string delimiter){
    /*
        Function to split a string at any instances of a given substring
    */

    // Calling trim to remove , and newline from left and right of string
    s = trim(s," \n,");
    // Initializing vector
    vector<string> vec;
    // Loop while delimter substring still exists in the main string
    while(s.find(delimiter)!=string::npos){
        // Finding the starting index of the delimiter string
        int delimiter_ind = s.find(delimiter);
        // Getting the substring before delimiter starts and storing in data string
        string data = s.substr(0,delimiter_ind);
        // Adding data substring to vector
        vec.push_back(data);
        // Removing the data substring and the delimiter substring after data from the main string
        s=s.substr(data.length()+delimiter.length(),-1);
    }
    // Adding the last remaining substring to the vector
    vec.push_back(s);

    // Returning vector of all substrings
    return vec;
}


string double_string_map_to_string(map<string,string> m){
    /*
        Function to convert a map of type (string,string) to a string
    */

    string str = "{\n";
    //for loop which iterates though the given map
    for(auto it: m){
        //appending key value pairs from given map into the string
        str.append(string(it.first)+" = "+string(it.second)+",\n");
        
    }
    
    str.append("}");
    return str;
} 


map<string,string> string_to_map(string s){
	/*
		function for converting the string into map
	*/

	//trimming the string to remove extra substrings
    s = trim(s,"{");
    s = trim(s,"}");
    s = trim(s," \n,");
    // splitting the trimmed string and saving it in a vector of type string
    vector<string> first_split = string_splitter(s,",\n");
    // Declaring a map of type(string,string)
	map<string,string> local_map;
    // Iterating through each value in vector
    for (auto var : first_split){
        // splitting the current string by delimter '=' and storing in vector of type(string)
        vector<string> pair = string_splitter(var," = ");
        //appending the key value pair in the map from vector
        local_map[pair[0]]=pair[1];
    }
    return local_map;
}


int connect_problem(){
	/*
		function for connection problem
	*/

    cout << endl;
    // using a temporary string to store the user's input
    string temp;
    cout << "Enter issue description in less than 200 words: ";
    getline(cin, temp);
    // storing user's status in global map
    global_map["Issue Description"] = temp;
    // using while loop untill the input is valid.
    while (true){
        int choice;
        // asking user question and suggesting the solution
        cout << "Have you restarted your modem? Enter 0 if not and 1 if you have: ";
        cin >> choice;
        if(choice == 0){
            cout << "Please restart your modem and see if the issue persists\n";
            break;
        }
        else if(choice == 1){
            break;
        }
        else{
            cout << "Please enter a valid input, 0 or 1\n";
            
            // using "continue" keep going through the while loop utill a valid input is entered.
            continue;
        }
    }
    // using while loop while the input is invalid.
    while (true){
    	// confirming user's query status.
        cout << "Are you still having the issue: Y/N: ";
        char c;
        cin >> c;
        c=tolower(c);
        if(c=='n'){
            cout << "Thank you for contacting tech support!\n";
            // storing user's query status in global map.
            global_map["Issue Status"]="Handled";
            return 0;
        }
        else if(c=='y'){
            break;
        }
        else{
            cout << "Please enter a valid input, either Y/N\n";
                // using "continue" keep going through the while loop utill a valid input is entered.
            continue;
        }
    }
    // informing user about the status 
    cout << "Your issue has been sumbitted to our engineers, we will reach out to you soon!\n";
    cout << "Thank you for contacting tech support\n";
    //storing user's issue status in glo0bal map.
    global_map["Issue Status"] = "Sumbitted to Tech Team";
    return 0;
}


int power_supply(){
	/*
		function for user's problems related to power supply
	*/
    cout << endl;
    // using while loop
    while (true){
    	//asking some questions to solve the problem by giving the suggestion.
        cout << "Have you check the wall socket and properly plugged in all cables? Y/N: ";
        char c;
        cin >> c;
        c=tolower(c);
        // using if statement to react according the user's input.
        if(c=='y'){
            // printing the respponse according the user's input.
            cout << "Your issue has been forwarded to the field team, we will be in contact soon.\n";
            cout << "Thank you for contacting tech support!\n";
            // storing the user's status in the globa map.
            global_map["Issue Status"]="Sumbitted to field team";
            return 0;
        }
        else if(c=='n'){ 
            // giving some suggestions to solve the problem
            cout << "Please do so and check if the issue persists\n";
            break;
        }
        else{
            cout << "Please enter a valid input, either Y/N\n";
            
            // using "continue" keep going through the while loop utill a valid input is entered.
            continue;
        }
    }

    while (true){
    	// trying to solve the problem
        cout << "Are you still having the issue? Y/N: ";
        char c;
        cin >> c;
        c=tolower(c);
        if(c=='y'){
        	// forwawrding the user's issue to field team
            cout << "Your issue has been forwarded to the field team, we will be in contact soon.\n";
            cout << "Thank you for contacting tech support!\n";
            //storing the user's status in global map.
            global_map["Issue Status"]="Sumbitted to field team";
            return 0;
        }
        else if(c=='n'){
        	// printing out the thankng statement as issue is resolved
            cout << "Thank you for contacting customer support!\n";
            //  storing user's status in global map.
            global_map["Issue Status"]="Handled";
            break;
        }
        else{
            cout << "Please enter a valid input, either Y/N\n";
            // using "continue" keep going through the while loop utill a valid input is entered.
            continue;
        }
    }
    return 0;
}


int ont(){
	/*
		function of user's problem related to OPTICAL TERMINATION NETWORK
	*/
    cout << endl;
    //using nested while loops.
    // using while loop untill the user's issue is solved.
    while(true){                     
		// asking some  questions from user
        cout << "Are the lights on the top of ONT device flashing? Y/N: ";
        // declaring a character to store the user's ans.
        char c;
        cin >> c;
        c = tolower(c);
        //using if statement to act according to the user's input.
        if(c=='y'){
            // printing the respponse according the user's input.
            cout << "Your issue has been forwarded to technical team, we will be in contact soon.\n";
            cout << "Thank you for contacting tech support!\n";
            // storing the user's status in global map.
            global_map["Issue Status"] = "Forwarded to technical team";
            break;
        }
    
        if (c=='n'){
        	// asking more questions to solve the problem.
            cout << "Is this the device powered on? Y/N: ";
            char c1;
            cin >> c1;
            c1=tolower(c1);
			// using the while loop
            while(true){
                if(c1=='y'){
                	// responsing according the user's input.
                    cout << "Your issue has been forwarded to field team, we will be in contact soon.\n";
                    cout << "Thank you for contacting tech support!\n";
                    //storing the usr's isssue status in global map.
                    global_map["Issue Status"] = "Forwarded to field team";
                    break;
                }

                else if(c1=='n'){
                	// trying to solve the problem.by giving some instructions.
                    cout << "Please try to turn on the device\n";
                    cout << "Did it turn on? Y/N: ";
                    char c2;
                    cin >> c2;
                    while(true){
                        if(c2=='y'){
                            char c3;
                            cout << "Is the issue still there? Y/N: ";
                            cin >> c3;
                            c3=tolower(c3);
                            while(true){
                                if(c3=='y'){
                                	// printing the respponse according the user's query.
                                    cout << "Your issue has been forwarded to field team, we will be in contact soon.\n";
                                    cout << "Thank you for contacting tech support!\n";
                                    //storing the user's status in global map.
                                    global_map["Issue Status"] = "Forwarded to field team";
                                    break;
                                }
                                else if(c3=='n'){
                                	// printing out the thanking statement as the issue is resolved.
                                    cout << "Thank you for contacting tech support!\n";
                                    // storing the user's status in  global map.
                                    global_map["Issue Status"] = "Resolved";
                                    break;
                                }
                                else{
                                	// using else statement if the user enters an invalid input.
                                    cout << "Please enter a valid input! Y or N: ";
                                    cin >> c3;
                                    c3 = tolower(c3);
                                    // using "continue" keep going through the while loop utill a valid input is entered.
                                    continue;
                                }
                            }
                            break;
                        }
                        else if(c2=='n'){
                        	// responsing according the user's input.
                            cout << "Your issue has been forwarded to field team, we will be in contact soon.\n";
                            cout << "Thank you for contacting tech support!\n";
                            // storing the user's status in  global map.
                            global_map["Issue Status"] = "Forwarded to field team";
                            break;
                        }
                        else{
                        	// using else statement if the user enters an invalid input.
                            cout << "Please enter valid input, Y or N: \n";
                        }
                        
                    }
                    break;
                }
                else{
                	// using else statement if the user enters an invalid input.
                    cout << "Please enter valid input, either Y or N\n";
                    continue;
                }
            
            }
            break;
        }

        else{
        	// using "continue" keep going through the while loop utill a valid input is entered.
            cout << "Please enter valid input, Y or N: \n";
            continue;
        }

        
    }
    return 0;
} 


int unknown(){
	/*
		function of user's query that is not known to user.
	*/
    cout << endl;
    // printing out the statement for displaying it to the user.
    cout << "Your issue has been forwarded to field team, we will be in contact soon.\n";
    cout << "Thank you for contacting tech support!\n";
    // storing the user's status in the map.
    global_map["Issue Status"] = "Forwarded to field team";
    return 0;
}


int hardware_problem(){
	/*
		Function related to hardware problems
	*/
    cout << endl;
    // declaring a temporary variable
    string temp;
    cout << "Enter issue description in less than 200 words: ";
    // storing the the information written by the user in a temporary variable
    getline(cin, temp);
    // storing the temp variable in the global map's issue discription subscript
    global_map["Issue Description"] = temp;
    // using the while loop to keep running until the correct variablr is selected
    while(true){
        cout << "Which of the following is causing issues: \nEnter 1 for Power Supply \nEnter 2 for ONT router \nEnter 0 for unknown\n";
        //declaring a variable for choosing the problem related function.
        int c;
        cin >> c;
        // using if and else if function to perform the further functions according to the user input
        if(c==1){
        	// calling the function
            power_supply();
            break;
        }
        else if(c==2){
        	// calling the function
            ont();
            break;

        }
        else if(c==0){
        	// calling the function
            unknown();
            break;

        }
        else{
            cout << "Please enter valid input, either 0, 1 or 2";
            // using "continue" keep going through the while loop utill a valid input is entered.
            continue;
        }
    }
    return 0;
}


void other_tech_issue(){
	/*
		function for user's issues related to other technical issues
	*/

    cout << endl;
    // declaring a temporary variable
    string temp;
    cout << "Enter issue description in less than 200 words: ";
    // storing the the information written by the user in a temporary variable
    getline(cin, temp);
    //storing the variabl data in the global map for the user
    global_map["Issue Description"] = temp;
    // printing out the result statement
    cout << "Your issue has been forwarded to the technical team, we will contact you soon.\n";
    cout << "Thank you for contacting customer support!";
    //storng the result status in the globa map for the specific user
    global_map["Issue Status"]="Forwarded to tech team";
}


void user_data(){
    /*
        Function to get and save user data
    */
    // Declaring varaibles
    string id,name;
    // Getting and storing user id in map
    cout << "Enter user id: ";
    getline(cin>>ws,id);
    global_map["User ID"] = id;
    // Getting and storing user name in map
    cout << "Enter your full name: ";
    getline(cin>>ws,name);
    global_map["User Name"] = name;
    // Declaring time object
    time_t time_var = time(0);
    // Saving current local instance of time object in map
    global_map["Time of request"] = trim(asctime(localtime(&time_var)),"\n");
}


int tech(){
    /*
        Function to call all technical functioniality
    */
    cout << endl;
    int choice; 
	//declaring variable
    cout << "Please select your issue: \n"<<"Enter 1 for Connection Problems\nEnter 2 for Hardware Problems\nEnter 3 for Other Problem\n";
    cin >> choice;
    // Calling the function to store the data of request
    user_data();
    global_map["Request Type"] = "Technical";
    // using while loop to keep running till any of the correct choice is selected
    while (true){
        int flag = 0;
        // using switch case.
        switch (choice){
            case 1:
            	// calling the function
                connect_problem();
                break;
            case 2:
            	// calling the function
                hardware_problem();
                break;
            case 3:
            	// calling the function
                other_tech_issue();
                break;
            default:
                flag=1;
        }
        // using if statement to continue the loop if the input is invalid.
        if(flag==1){
            continue;
        }
        break;
    }
    return 0;
}


int bundles(){
	/*
	   function to call all bundle functionality
	*/

    cout << endl;
    //calling user data function 
    user_data();
    //saving key value pair in global map
    global_map["Request Type"]= "Bundles";
	int choice;
	//loop to keep running while input is invalid
	while(true)
	{
	    
		int flag=0;
	    cout<<"Enter 1 for New Bundles"<<endl;
	    cout<<"Enter 2 for Changing Existing Package"<<endl;
	    cin>>choice;
	    switch(choice)
	    {
	    	//calling functions according to user input
	    	case 1:
	    		new_bundles();
	    		break;
	    	case 2:
	    		changing_package();
	    		break;
	    	default:
	    		flag=1;
		}
		if(flag==1)
		{
			cout<<"Enter valid input"<<endl;
			continue;
		}
	    break;
   }
   return 0;
}


int new_bundles(){
	/*
	   function to assign new bundles
	*/

    cout << endl;
    int c;
    cout << "Enter 0 for Internet Data bundles \nEnter 1 for Bandwidth packages\n";
    cin >> c;
    //loop to keep running while input is invalid
    while(true){
    	//calling functions according to user input
        if(c==0){
            data();
            break;
        }
        else if(c==1){
            bandwidth();
            break;
        }
        else{
            cout << "Please enter a valid input, 0 or 1!";
            cin >> c;
            continue;
        }
    }
    return 0;
}


int bandwidth()
{
	/*
	   function to assign a bandwidth package to user
	*/

    cout << endl;
    //saving key value pair in global map
    global_map["Bundle Type"]="Bandwidth";
	int choice;
    //loop to keep running while input is invalid
	while(true)
	{
		int flag=0;
	
	    cout<<"Enter 1 for hourly bundles"<<endl;
	    cout<<"Enter 2 for daily bundles"<<endl;
	    cout<<"Enter 3 for weekly bundles"<<endl;
        cout << "Enter choice: ";
	    cin>>choice;
	    //calling functions according to user input
	    switch(choice)
	    {
	    	case 1:
	    		hourlybundles();
	    		break;
	    	case 2:
	    		dailybundles();
	    		break;
	    	case 3:
	    		weeklybundles();
	    		break;
	    	default:
	    		flag=1;
		}
	    if(flag==1)
	    {
	    	cout<<"Enter valid input"<<endl;
	    	continue;
		}
        break;
	}
    return 0;
	
}


int changing_package()
{
	/*
	   function to change user's current package
	*/

    cout << endl;
    //saving key value pair in global map
    global_map["Bundle Type"]= "Package Change";
	int choice,c;
	//loop to keep running while input is invalid
	while(true)
	{
	    int flag=0;
	
        cout<<"To which package do you want to change to"<<endl;
        cout<<"1. 10Mbps 125 GB for Rs.1500"<<endl;
        cout<<"2. 15Mbps 150 GB for Rs.1890"<<endl;
        cout<<"3. 20Mbps 175 GB for Rs.2499"<<endl;
	    cin>>c;
        if(c==1 || c==2 || c==3){
            cout << "Your new package will activated in the next month!\n";
        }
        else flag=1;
        
        if(flag==1)
        {
            cout<<"Enter valid input"<<endl;
            continue;
        }
        break;
    }
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]="Changing to package "+to_string(c);
    return 0;
	
}


int hourlybundles()
{
	/*
	   function to provide hourly bundles to user
	*/

    cout << endl;
	int c;
	//loop to keep running while input is invalid
	while(true)
	{
		
	    int flag=0;
	    cout<<"Choose the bundle you want to activate"<<endl;
	    cout<<"1. 30 Mbps for 2 hours in Rs. 200"<<endl;
	    cout<<"2. 30 Mbps for 4 hours in Rs. 350"<<endl;
	    cout<<"3. 40 Mbps for 6 hours in Rs. 600"<<endl;
        cout<<"Enter bundle number: ";
	    cin>>c;
    	if(c>=1 && c<=3)
        cout<<"You bundle will be activated in a while"<<endl;
	    else
	    flag=1;
	
	    if(flag==1)
	    {
		  cout<<"Enter valid input"<<endl;
	    }
	    break;
    }
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]="Hourly Bundle " + to_string(c);
    return 0;
}


int dailybundles(){
	/*
	   function to provide daily bundles to user
	*/

    cout << endl;
	int c;
	//loop to keep running while input is invalid
	while(true)
	{
		
	    int flag=0;
	    cout<<"Choose the bundle you want to activate"<<endl;
	    cout<<"1. 25 Mbps for 24 hours in Rs. 300"<<endl;
	    cout<<"2. 30 Mbps for 24 hours in Rs. 500"<<endl;
	    cout<<"3. 40 Mbps for 24 hours in Rs. 700"<<endl;
        cout<<"Enter bundle number: ";
	    cin>>c;
    	if(c>=1 && c<=3)
        cout<<"You bundle will be activated in a while"<<endl;
	    else
	    flag=1;
	
	    if(flag==1)
	    {
		  cout<<"Enter valid input"<<endl;
	    }
	    break;
    }
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]="Daily Bundle " + to_string(c);
    return 0;
}


int weeklybundles()
{
	/*
	   function to provide weekly bundles to user
	*/

    cout << endl;
	int c;
	//loop to keep running while input is invalid
	while(true)
	{
		
        int flag=0;
	    cout<<"Choose the bundle you want to activate"<<endl;
	    cout<<"1. 20 Mbps for 7 days in Rs. 650"<<endl;
        cout<<"2. 30 Mbps for 7 days in Rs. 750"<<endl;
	    cout<<"3. 40 MBps for 7 days in Rs. 900"<<endl;
        cout<<"Enter bundle number: ";
	    cin>>c;
	    if(c==1 || c==2 || c==3)
	        cout<<"You offer will be activated in a while"<<endl;
	    else
	        flag=1;
	
	    if(flag==1){
            cout<<"Enter valid input"<<endl;
            continue;
   	    } 
		break;
    } 
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]="Weekly Bundle " + to_string(c);
	return 0;
}


int data(){
	/*
	   function to provide data bundles to user
	*/

    cout << endl;
    //saving key value pairs to global map
    global_map["Bundle Type"]="Internet Data";
    int c;
    cout << "Enter 0 for Data Bundles \nEnter 1 for Buying Data";
    cin >> c;
    //loop to keep running while input is invalid
    while(true){
    	//calling function according to user input
        if(c==0){
            data_bundles();
            break;
        }
        else if(c==1){
            cold_hard_data();
            break;
        }
        else{
            cout << "Please enter a valid input, 0 or 1!";
            cin >> c;
            continue;
        }
    }
    return 0;
}


int cold_hard_data(){
	/*
	   function to provide data to user
	*/
    cout << endl;
    float data;
    cout<<"Choose the amount of data you want to activate"<<endl;
    cout<<"Rate is Rs.20 per GB of data\n";
    cout << "Enter amount of data required: ";
    cin>>data;
    cout << "The price for " << data << " GB of data is Rs. " << data*20 << ".\n";
    cout << "Your data will be added to your account shortly\n";
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]=to_string(data) + " GB of data";
    return 0;   
}


int data_bundles( ){
	/*
	   function to provide data bundles options to user
	*/

    cout << endl;
    int choice;
    //loop to keep running while input is invalid
    while(true)
    {
    	int flag=0;
	
   	    cout<<"1. 10 GB for 2 hours in Rs. 20"<<endl;
    	cout<<"2. 20 GB for 4 hours in Rs. 50"<<endl;
	    cout<<"3. 25 GB for 24 hours in Rs. 80"<<endl;
    	cout<<"4. 40 GB for 3 days in Rs. 150"<<endl;
    	cout<<"5. 50 GB for 3 days in Rs. 180"<<endl;
    	cout<<"6. 100 GB for 7 days in Rs. 240"<<endl;
    	cout<<"7. 120 GB for 7 days in Rs. 270"<<endl;
        cout<<"Enter the bundle number you wish to activate: ";
    	cin>>choice;
	    if(choice>=1 && choice<=7)
	    break;
	    else
	    flag=1;
	
    	if(flag==1)
     	{
		cout<<"Enter valid input"<<endl;
		continue;
		
	    }
		break;
    }
    cout << "Your bundle will activated soon!\n";
    //converting user choice into string and storing in map along with the key value
    global_map["Bundle"]="Data bundle "+to_string(choice)+".";
    return 0;
}


void new_connec(){
	/*
	   function for making new connection for user
	*/

    cout << endl;
    //prompting user to enter address and store it using getline
    cout << "Enter your address: ";
    string address;
    getline(cin>>ws,address);
    //saving key value pairs in global map
    global_map["Request Type"]="New Connection";
    global_map["User Address"]=address;
    //prompting user to enter name and store it using getline
    cout << "Enter your full name: ";
    string name;
    getline(cin>>ws,name);
    //saving key value pair in global map
    global_map["User Name"]=name;
    //getting local time and date and storing in global map
    time_t time_var = time(0);
    global_map["Time of request"] = trim(asctime(localtime(&time_var)),"\n");
    int c;
    //loop to keep running while input is invalid
    while(true)
	{
	    int flag=0;
        cout<<"Which package do you want?:"<<endl;
        cout<<"1. 10Mbps 125 GB for Rs.1500"<<endl;
        cout<<"2. 15Mbps 150 GB for Rs.1890"<<endl;
        cout<<"3. 20Mbps 175 GB for Rs.2499"<<endl;
	    cin>>c;
	    //checking if input is invalid
        if(c<1||c>3) 
            flag=1;
        //rerun loop if input is invalid
        if(flag==1)
        {
            cout<<"Enter valid input"<<endl;
            continue;
        }
        break;
    }
    //converting user choice into string and storing in map along with the key value
    global_map["Package"]= "Package "+to_string(c);
    string id;
    //loop to keep running while input is invalid
    while (true){
        cout << "Please enter the id you wish to have: ";
        cin >> id;
        //calling function to check if id entered by user already exists or not
        if(id_checker(id)){
        	//if id does not exist break the loop
            break;
        }
        cout << "ID already taken, please choose another id\n";

    }
    //saving key value pair in global map
    global_map["User ID"] = id;
    //adding user id to user id database
    add_id(id);
    cout << "Our manager will reach out to you in 5-7 working days\n Thank you choosing us!\n";
    //saving key value pair in global map
    global_map["Request Status"]="Forwarded to sales team";

}


vector<map<string,string>> get_data(string data){
	/*
		Function to convert string of all data into maps and store maps in vector and return that vector
	*/

	// splitting data string by delimiter and saving the results in vector of type string 
    vector<string> vec = string_splitter(data,"\n**********\n");

    // Declaring vector of type map(string,string)
    vector<map<string,string>> all_maps;
	// loop to iterate through each item in string vector
    for(int i = 0;i<vec.size();i++){
        // converting each string to map and appending to map vector
        all_maps.push_back(string_to_map(vec[i]));
    }
    // returning map vector
    return all_maps;
}
    

vector<map<string,string>> search_name(string id, vector<map<string,string>> map_vec){
     /*
       function to search all maps in a vector and return all maps that contain given id 
     */
     
    //declaring bool variable true
    bool flag = true; 
    //declaring a vector holding maps of string type
    vector<map<string,string>> name_maps; 
    // 
    for (int i = 0; i<map_vec.size();i++){
    	//if given id is found in the current map that map is stored in name_map vector
        if(map_vec[i]["User ID"]==id){
            name_maps.push_back(map_vec[i]);
            flag = false;
        }
    }
    //if bool variable is true following message is displayed
    if(flag){
        // Setting terminal color to red
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "User ID not found \n";
    }
    //if vector conatins more than 1 map 
    if(name_maps.size()>1){
        cout << "More than 1 request found under User ID " <<id<<".\n\n";
    }
    //returning vector of all maps that contain given id
    return name_maps;
}


bool id_checker(string id){
    /*
        Function to check whether a certain user id exists in the database
    */

    // Creating fstream object
    fstream file;
    // Opening user id database using fstream object
    file.open("User_IDs.txt");
    string temp_id;
    // Loop to keep reading a user id from database until the data ends
    while(file>>temp_id){
        // If given id exits in database then return false
        if(temp_id==id){
            file.close();
            return false;
        }
    }
    // If id doesn't exist in database return true
    file.close();
    return true;
}


void add_id(string id){
    /*
        Function to add a user id to database
    */

    // Creating fstream object
    fstream file;
    // Opening user id database in append mode using fstream object
    file.open("User_IDs.txt",fstream::app);
    // Writing the user id to database
    file<<"\n"+id;
    // Closing the file to conserve memory
    file.close();
}


    