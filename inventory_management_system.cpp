#include <bits/stdc++.h>
using namespace std;
vector<int> v;      // Declared a vector to store the desired serial numbers
map<string, int> m; // Used ordered map to store a key once adding values of duplicate values

bool IsLoggedIn() // Function checks whether there is a text file with user entered username and password
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username; // Asking user to enter his username
    cout << "password: ";
    cin >> password;                      // Asking user to enter his password
    ifstream read(username + ".txt");     // Reading a text file names username.txt
    getline(read, un);                    // Reading username from the file
    getline(read, pw);                    // Reading Password from the file
    if (un == username && pw == password) // Checking whether user has entered correct username and password or not
    {
        return true; // If entered correct return true
    }
    return false; // If entered incorrect return false
}
// Used class for data hiding
class item // Declared a class for performing operation and storing some data using class functions
{
    string name;
    string unit;
    float price;
    int stock;

public:                                                       // Declared functions  for performing operations
    void SetAllValues(item *s);                               // To set all initial values of items
    void StringCaseChangedToUpperCase(string &x);             // To change the case of a string ti uppercase
    int word_belong_to_string(string &, string &, int, int);  // To check whether the subsequence entered by the user is present in a word of list or not
    void PrintWordsWithSubsequenceX(item *, string &, int &); // To print all words that contains subsequence
    void InStock(item *, int, int &);                         // To check wheather a particular item is in stock or not
    int GSTCalculation(item *, int, int);                     // To calculate amount with GST
    void SerialAndQuantityChoiceEnter(item *, int, int &);    // To check wheather user have entered correct choice of serial number and quantity and if not is askes user to entyer value again
    bool ShowItems(string);                                   // To show all items in the Mall
};

void item ::SetAllValues(item *s) // Function that sets all initial values of items
{
s[0].name = "ELECTRIC KETTLE";
s[0].unit = "UNIT";
s[0].price = 350;
s[0].stock = 120;
s[1].name = "HTC MOBILE PHONE";
s[1].unit = "UNIT";
s[1].price = 500;
s[1].stock = 50;
s[2].name = "COCONUT SHAMPOO";
s[2].unit = "BOTTLE";
s[2].price = 100;
s[2].stock = 200;
s[3].name = "AYURVEDIC HAIR OIL";
s[3].unit = "BOTTLE";
s[3].price = 100;
s[3].stock = 150;
s[4].name = "DELL LAPTOP";
s[4].unit = "UNIT";
s[4].price = 800;
s[4].stock = 30;
s[5].name = "COLGATE TOOTHPASTE";
s[5].unit = "TUBE";
s[5].price = 500;
s[5].stock = 300;
s[6].name = "COFFEE MAKER";
s[6].unit = "UNIT";
s[6].price = 500;
s[6].stock = 80;
s[7].name = "BOAT HEADPHONES";
s[7].unit = "UNIT";
s[7].price = 300;
s[7].stock = 100;
s[8].name = "FROZZEN SICILIAN PIZZA";
s[8].unit = "PACK";
s[8].price = 100;
s[8].stock = 50;
s[9].name = "SCOTT TOILET PAPER";
s[9].unit = "PACK";
s[9].price = 300;
s[9].stock = 500;
s[10].name = "AIRWICK AIR FRESHENER";
s[10].unit = "CAN";
s[10].price = 600;
s[10].stock = 150;
s[11].name = "OPPO POWER BANK";
s[11].unit = "UNIT";
s[11].price = 200;
s[11].stock = 80;
s[12].name = "OLIVE COOKING OIL";
s[12].unit = "BOTTLE";
s[12].price = 102;
s[12].stock = 250;
s[13].name = "HP WIRELESS MOUSE";
s[13].unit = "UNIT";
s[13].price = 105;
s[13].stock = 120;
s[14].name = "FACIAL TISSUES";
s[14].unit = "PACK";
s[14].price = 400;
s[14].stock = 200;
s[15].name = "BOAT BLUETOOTH SPEAKER";
s[15].unit = "UNIT";
s[15].price = 400;
s[15].stock = 60;
s[16].name = "CEREAL BOX";
s[16].unit = "BOX";
s[16].price = 600;
s[16].stock = 100;
s[17].name = "CELLO WATER BOTTLE";
s[17].unit = "BOTTLE";
s[17].price = 200;
s[17].stock = 400;
s[18].name = "CENDOL BEVERAGE";
s[18].unit = "BOTTLE";
s[18].price = 300;
s[18].stock = 250;
s[19].name = "SURF EXCEL DETERGENT";
s[19].unit = "BOX";
s[19].price = 845;
s[19].stock = 100;
s[20].name = "HITACHI AIR CONDITIONER";
s[20].unit = "UNIT";
s[20].price = 900;
s[20].stock = 25;
s[21].name = "HAIER HCC FREEZER";
s[21].unit = "UNIT";
s[21].price = 700;
s[21].stock = 15;
s[22].name = "WEIGHT SCALE";
s[22].unit = "UNIT";
s[22].price = 300;
s[22].stock = 50;
s[23].name = "SLEEPYCAT BEDSHEET";
s[23].unit = "SET";
s[23].price = 200;
s[23].stock = 100;
s[24].name = "ELECTRIC FAN";
s[24].unit = "UNIT";
s[24].price = 405;
s[24].stock = 60;
s[25].name = "EXERCISE MAT";
s[25].unit = "UNIT";
s[25].price = 151;
s[25].stock = 80;
s[26].name = "CHEESE CAKE DESSERT";
s[26].unit = "PLATE";
s[26].price = 545;
s[26].stock = 200;
s[27].name = "STEPPER WORKOUT MACHINE";
s[27].unit = "UNIT";
s[27].price = 502;
s[27].stock = 30;
s[28].name = "IPHONE";
s[28].unit = "UNIT";
s[28].price = 500;
s[28].stock = 50;
s[29].name = "DELL WIRELESS MOUSE";
s[29].unit = "UNIT";
s[29].price = 156;
s[29].stock = 120;
}

void item ::StringCaseChangedToUpperCase(string &x) // Function to change case of a complete string to upper
{
    for (int i = 0; i < x.size(); i++) // for loop to traverse the string
    {
        if (x[i] >= 'a' && x[i] <= 'z') // if charactrer of a string id not in uppercase
        {
            x[i] = x[i] - 'a' + 'A'; // change to upper case
        }
    }
}

int item ::word_belong_to_string(string &s, string &x, int k, int t) // Function using dynamic programming (for optimization) to check whether the subsequence enered by te user is present in the word of a list ore not
{                                                                    // Using Recursion
    int dp[k + 1][t + 1];                                            // Declaring DP
    memset(dp, -1, sizeof(dp));                                      // all values of dp are set to 0
    if (k == 0 || t == 0)                                            // Base condition of recursion
        return 0;
    if (dp[k][t] != -1) // If already estimated a value return it
        return dp[k][t];
    if (s[k - 1] == x[t - 1]) // if last charactrers of the two strings (s and x) are equal add 1
    {
        return dp[k][t] = 1 + word_belong_to_string(s, x, k - 1, t - 1);
    }
    // if last chracters of the two strings are not equal then take max of (k-1,t)and (k,t-1) so as to obtain longest common subsequence
    return dp[k][t] = max(word_belong_to_string(s, x, k - 1, t), word_belong_to_string(s, x, k, t - 1));
}

void item ::PrintWordsWithSubsequenceX(item *s, string &x, int &z) // For printing all words that contains user entered subsequence
{
    for (int i = 0; i < 38; i++) // For loop to travese the list
    {
        int k = word_belong_to_string((s[i].name), x, (s[i].name).size(), x.size()); // calling the function to check whether the subsequence lies in the word or not
        if (k == x.size())                                                           // if it lies in the word
        {
            z++;        // increment z (z gives the assending serial order number)
            if (z < 10) // for printing in an ordered way if z<10 start from ahead
            {
                cout << " " << z << " : " << s[i].name;             // printing serial serial number and item name
                v.push_back(i);                                     // pushing index in vector
                for (int d = 0; d < 28 - ((s[i].name).size()); d++) // for loop to put spaces to formate the output
                {
                    cout << " "; // Printing the spaces
                }
                cout << "--- Rs." << s[i].price << ".00 per " << s[i].unit << endl; // printing ---rs. and .00 per
            }
            else
            {                                                     // for printing in an ordered way if z>10 start
                cout << z << " : " << s[i].name;                  // printing serial serial number and item name
                v.push_back(i);                                   // pushing index in vector
                for (int d = 0; d < 28 - (s[i].name).size(); d++) // for loop to put spaces to formate the output
                {
                    cout << " "; // Printing the spaces
                }
                cout << "--- Rs." << s[i].price << ".00 per " << s[i].unit << endl; // printing ---rs. and .00 per
            }
        }
    }
    if (z == 0) // if no word contains the user enterd subsequence
    {
        cout << "Sorry, no such item is found..." << endl;
    }
}

void item ::InStock(item *s, int a, int &c) // Function the checks wheather the quantity entered by the user is there in the list or not
{

    while (s[v[a - 1]].stock < c) // while list has less quantity
    {
        if (s[v[a - 1]].stock == 0)
        {
            cout << s[v[a - 1]].name << " is currently running out of stock" << endl;
            return;
        }
        cout << "\nWe are really Sorry To inform that we dont have that much stock" << endl;
        cout << "We have " << s[v[a - 1]].stock << " Stocks of " << s[v[a - 1]].name << endl;
        cout << "We can Provide you that amount" << endl;
        cout << "\nDo You Want to have the item ?";
        cout << "\nEnter Yes/No : ";
        string userentered = "";
        item ob;
        cin >> userentered;
        cin.ignore(); // To remove '\n'
        ob.StringCaseChangedToUpperCase(userentered);
        if (userentered[0] == 'Y')
        {
            cout << "Enter the new Quantity You want to have: ";
            cin >> c;
        }
        else
        {
            return;
        }
    }
    s[v[a - 1]].stock -= c;
}

int item ::GSTCalculation(item *s, int a, int c) // Function to clculate the amount with GST
{
    m[s[v[a - 1]].name] += c;                  // for duplicate enteries
    float r = c * (s[v[a - 1]].price) * (1.1); // calculation of gst
    int k = r * 10;                            // for round of
    if (((k) % 10) >= 5)
        r = r + 1;
    return r; // return final amount
}

void item ::SerialAndQuantityChoiceEnter(item *s, int z, int &ans) // Function to check wheather user have entered correct choice of serial number and quantity and if not is askes user to entyer value again
{
    item ob;
    if (z > 0) // if some items are showed to user
    {
        int a, c;
        cout << "Enter a Choice from above Serial numbers: ";
        cin >> a;
        while (a > z) // while user enteres wrong serial number ask again
        {
            cout << "Warning !!!\n***You have entred an invalid choice***\nRenter your Choice : ";
            cin >> a;
        }
        cout << "Enter the Quantity you need to have: ";
        cin >> c;
        ob.InStock(s, a, c);               // calling function to check if quantity c is in stock or not
        ans += ob.GSTCalculation(s, a, c); // storing total amount in ans
    }
}

bool item ::ShowItems(string c) // function to show all items
{
    if (c[0] == 'Y')
        return true;
    return false;
}

int main()
{
    system("cls"); // to make the terminal clear
    // Login system
    // user can only order if he has login
    cout << "Welcome to Our Mall's login System\n";
    cout << "Resister if New Customer\nLogin if Existing Cusomer\n";
    cout << "1. Register\n2. Login\nYour Choice: ";
    int choice;
    cin >> choice;                     // taking input from user
    while (choice != 2 && choice != 1) // while user enters wrong choice ask user to enter corect choice again
    {
        cout << "Invalid Choice!!!\nPlease Enter a valid choice : ";
        cin >> choice; // Enter choice again
    }
    if (choice == 1) // if choice == 1
    {
        string username, password;

        cout << "select a username: ";
        cin >> username; // Enter username
        fflush(stdin);   // for removing '\n'
        cout << "select a password: ";
        cin >> password; // Enter password

        ofstream file;
        file.open(username + ".txt"); // Saving a text file named username.txt
        file << username << "\n"
             << password; // adding content to file
        file.close();     // closing file after edit

        main(); // call again returned to main
    }

    else if (choice == 2) // if choice == 2
    {
        bool status = IsLoggedIn();

        if (!status) // if incorrect usename or password
        {
            cout << "False Login" << endl; // print false login
            system("PAUSE");               // to make user enter any key to continue
            exit(0);                       // exit the program
        }

        else // if correct usename and password
        {
            cout << "Succesfully logged in" << endl; // print sucessfully logged in
            system("PAUSE");                         // to make user enter any key to continue
        }
    }

    item ob, s[51]; // decaring class variable
    int ans = 0;    // variable that stores total amount
    int once = 0;
    ob.SetAllValues(s);           // function calles to set all values of items
    string userentered = "Yes";   //,show;
    while (userentered[0] == 'Y') // if user want to have more item
    {
        cout << "\n***Welcome to Our Mall***" << endl;
        int z = 0; // to print accending serial number order
        if (once == 0)
        {
            cout << "\nDo You want to see all items ? (Enter yes/no): ";
            string show = "";
            cin >> show;
            ob.StringCaseChangedToUpperCase(show);
            if (ob.ShowItems(show))
            {
                show = "E";
                ob.PrintWordsWithSubsequenceX(s, show, z);
                show.clear();
            }
            once++;
            cin.ignore();
            v.clear();
            cout<<"\n";
        }
        z=0;
        cout << "We have different varities of 'Phone, Laptop, Oil, Speaker' at our mall" << endl;
        cout << "Enter any subsequence (in any case) of the above names you will get their details" << endl;
        cout << "What Do you want to have: ";
        string x;
        fflush(stdin);                      // To remove '\n'
        getline(cin, x);                    // Enter a subsequence
        ob.StringCaseChangedToUpperCase(x); // function called to change case of string to upper case

        cout << "Items found matching with your keyword:" << endl;
        ob.PrintWordsWithSubsequenceX(s, x, z);     // Printing all words with user enterd subsequence
        ob.SerialAndQuantityChoiceEnter(s, z, ans); // Function called to check wheather user have entered correct choice of serial number and quantity and if not is askes user to entyer value again
        cout << "\nDo You Want to have More item ?";
        cout << "\nEnter Yes/No : ";
        cin >> userentered;
        cin.ignore();                                 // To remove '\n'
        ob.StringCaseChangedToUpperCase(userentered); // Function called to change case of string to upper case
        v.clear();
    }
    cout << "\nYou Have ordered : " << endl; // Printing all items entered by user
    cout << "Product Name      Quantity" << endl;
    for (auto it : m) // for loop to traverse map
    {
        cout << it.first;                                // printing product name
        for (int d = 0; d < 20 - (it.first).size(); d++) // for loop to print spaces for spaces for optput formatting
        {
            cout << " "; // print space
        }
        cout << it.second << endl; // printing quantity
    }
    cout << "Total cost to be paid (with GST) = Rs. " << ans << "." << endl; // Printing final total amount that user needs to pay for the items
    cout << "\nThanks For Placing Order" << endl;
    cout << "\nProvide a Minor detais " << endl;
    string name, address, pincode, phonenumber; // Variable that stores minor details about user
    cout << "Enter Your full Name : ";
    getline(cin, name); // Enter full name
    cout << "Enter Shipping Address : ";
    getline(cin, address); // Enter Addredss
    cout << "Enter Pincode of Your area : ";
    cin >> pincode; // Enter pincode
    cout << "Enter Your Phone number : ";
    cin >> phonenumber; // Enter pincode
    cout << "\nYour Order Is placed Succesfully" << endl;
    cout << "Details of the order \n";
    cout << "Placed By : " << name << "\nShipping Address : " << address << "\nPincode : " << pincode << "\nPhone Number : " << phonenumber << endl;
    cout << "\nYou Have ordered : " << endl;
    cout << "Product Name      Quantity" << endl;
    for (auto it : m) // for loop to traverse map
    {
        cout << it.first;                                // printing product name
        for (int d = 0; d < 20 - (it.first).size(); d++) // for loop to print spaces for spaces for optput formatting
        {
            cout << " "; // printing spaces
        }
        cout << it.second << endl; // printing quantity
    }
    cout << "Total cost to be paid (with GST) = Rs. " << ans << "." << endl; // Printing Final amount
    cout << "\nYour will have your order in 1 hour" << endl;
    cout << "Do Rate us in the scale of 1-5 (Where 5 means Excellent and 1 means Poor) : " << endl;
    int feedbackpoint;
    cin >> feedbackpoint; // taking feedbackfrom user
    cout << "Thanks For Your valuable Feedback, We are happy to serve you" << endl;

    if (feedbackpoint < 3)
    {
        cout << "We would like to hear that how could we improve our service : ";
        string improvementSuggestion;
        cin.ignore();
        getline(cin, improvementSuggestion);
        exit(0);
    }
    else if (feedbackpoint == 5)
    {
        cout << "We will be greatfull to maintain rating at this stage and improve upto more extent in future";
        exit(0);
    }
    else
    {
        cout << "We would work hard to take the rating up to 5";
        exit(0);
    }
    return 0;
}