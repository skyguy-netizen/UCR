#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private:
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;
    // create list of strings to check if given name is valid name or not
    vector<string> monthList = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

public:
    // creates the date January 1st, 2000.
    Date();

    /* parameterized constructor: month number, day, year
        - e.g. (3, 1, 2010) will construct the date March 1st, 2010

        If any of the arguments are invalid (e.g. 15 for month or 32 for day)
        then the constructor will construct instead a valid Date as close
        as possible to the arguments provided - e.g. in above example,
        Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
        In case of such invalid input, the constructor will issue a console error message:

        Invalid date values: Date corrected to 12/31/2010.
        (with a newline at the end).
    */
    Date(unsigned m, unsigned d, unsigned y); // done

    /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

        If the constructor is unable to recognize the string argument as a valid month name,
        then it will issue a console error message:

        Invalid month name: the Date was set to 1/1/2000.
        (with a newline at the end).

        If the day argument is invalid for the given month (but the month name was valid),
        then the constructor will handle this error in the same manner as the other
        parameterized constructor.

        This constructor will recognize both "december" and "December"
        as month name.
    */
    Date(const string &mn, unsigned d, unsigned y);

    /* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
       Does not output a newline at the end.
    */
    void printNumeric() const;

    /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
       The first letter of the month name is upper case, and the month name is
       printed in full - January, not Jan, jan, or january.
       Does not output a newline at the end.
    */
    void printAlpha() const;

private:
    /* Returns true if the year passed in is a leap year, otherwise returns false.
     */
    bool isLeap(unsigned y) const; // done

    /* Returns number of days allowed in a given month
       -  e.g. daysPerMonth(9, 2000) returns 30.
       Calculates February's days for leap and non-leap years,
       thus, the reason year is also a parameter.
    */
    unsigned daysPerMonth(unsigned m, unsigned y) const; // done

    /* Returns the name of a given month
       - e.g. name(12) returns the string "December"
    */
    string name(unsigned m) const; // done

    /* Returns the number of a given named month
       - e.g. number("March") returns 3
    */
    unsigned number(const string &mn) const; // done
};

// Implement the Date member functions here

// default constructor
Date::Date()
{
    this->day = 1;
    this->month = 1;
    this->year = 2000;
    this->monthName = "January";
}

// defining constructor of format (month number, date, year)
Date::Date(unsigned m, unsigned d, unsigned y)
{
    bool error1 = false; // to check for invalid entries
    bool error2 = false; // to check for invalid entries

    if (m > 12)
    {                     // check if month number is more than 12, if yes, then entry is invalid
        this->month = 12; // set month number to 12 as that is the closest month number
        error1 = true;    // since invalid input, set error to true
    }
    else if (m <= 0)
    {                    // check if month number is less than 0
        this->month = 1; // set month number to 1 if true, as that is the closest
        error1 = true;   // since invalid input, set error to true
    }
    else
    {
        this->month = m; // if none of the above cases are true, set month number to input
    }

    this->monthName = name(month); // get monthName based on given month
    this->year = y;                // get year
    // cout << month << endl;          //this was for a test
    m = month; // change value of m

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    { // these month numbers have 31 days
        // cout << "Test" << endl;
        if (d > 31)
        { // to check for invalid date
            this->day = daysPerMonth(month, y);
            error2 = true;
        }
        else if (d < 1)
        { // check for invalid date
            this->day = 1;
            // cout << "Test 2 " << endl;
            error2 = true;
        }
        else
        { // if entry is not invalid, assign date to input date
            this->day = d;
        }
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    { // these month numbers have 30 days
        if (d > 30)
        { // check for invalid date
            this->day = daysPerMonth(month, y);
            error2 = true;
        }
        else if (d < 1)
        { // check for invalid date
            this->day = 1;
            error2 = true;
        }
        else
        { // if input is not invalid, then assign date to user inputted date
            this->day = d;
        }
    }
    else if (d > 28 && !isLeap(y))
    { // if month is 2 and value of day is 29 more but year is not a leap year
        this->day = 28;
        error2 = true; // since invalid input, set error to true
    }
    else if (d > 29 && isLeap(y))
    { // if month is 2 and value of day is 28 or more but year is not a leap year
        this->day = 29;
        error2 = true; // since invalid input, set error to true
    }
    else
    {
        this->day = d; // if no other cases are true, then set day to
    }

    if (error1 || error2)
    { // to handle exceptions
        cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
        // exception case, if either one of the errors was detected
        // exit(1);
    }
}

// defining a constructor of type (month name, date, year)
Date::Date(const string &mn, unsigned d, unsigned y)
{
    bool isinlist = false; // if input is invalid
    bool error1 = false;   // for error checking
    bool error2 = false;   // for error checking

    for (unsigned i = 0; i < monthList.size(); i++)
    {
        if (monthList.at(i) == mn)
        {
            isinlist = true; // if input valid...set to true
        }
    }

    if (isinlist)
    {
        this->month = number(mn);
        this->monthName = name(month);
        this->year = y;
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (d > 31)
            {
                this->day = daysPerMonth(month, y);
                error2 = true;
            }
            else if (d < 1)
            {
                this->day = 1;
                error2 = true;
            }
            else
            {
                this->day = d;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (d > 30)
            {
                this->day = daysPerMonth(month, y);
                error2 = true;
            }
            else if (d < 1)
            {
                this->day = 1;
                error2 = true;
            }
            else
            {
                this->day = d;
            }
        }
        else if (d > 28 && !isLeap(y))
        {
            this->day = 28;
            error2 = true;
        }
        else if (d > 29 && isLeap(y))
        {
            this->day = 29;
            error2 = true;
        }
        else
        {
            this->day = d;
        }

        if (error1 || error2)
        { // to handle exceptions where date is invalid but month name is valid
            cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
            // exit(1);
        }
    }
    else
    { // again for handling exception where month name is invalid
        this->day = 1;
        this->month = 1;
        this->year = 2000;
        this->monthName = "January";
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
    }
}

void Date::printNumeric() const
{ // print numeric
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{ // print in alphabets
    cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const
{ // to check if given year is leap year
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    { // only if these two conditions are true, then year is leap year
        return true;
    }

    return false;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{ // to calculate days in given month
    unsigned days;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        days = 31;
    }
    else if (m == 2)
    {
        if (isLeap(y))
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }
    else
    {
        days = 30;
    }

    return days;
}

string Date::name(unsigned m) const
{ // to return month name from given month number
    string name;
    if (m == 1)
    {
        name = "January";
    }
    else if (m == 2)
    {
        name = "February";
    }
    else if (m == 3)
    {
        name = "March";
    }
    else if (m == 4)
    {
        name = "April";
    }
    else if (m == 5)
    {
        name = "May";
    }
    else if (m == 6)
    {
        name = "June";
    }
    else if (m == 7)
    {
        name = "July";
    }
    else if (m == 8)
    {
        name = "August";
    }
    else if (m == 9)
    {
        name = "September";
    }
    else if (m == 10)
    {
        name = "October";
    }
    else if (m == 11)
    {
        name = "November";
    }
    else
    {
        name = "December";
    }

    return name;
}

unsigned Date::number(const string &mn) const
{ // to get month number from given month name
    unsigned month;
    if (mn == "January" || mn == "Jan" || mn == "january" || mn == "jan")
    {
        month = 1;
    }
    else if (mn == "February" || mn == "Feb" || mn == "february" || mn == "feb")
    {
        month = 2;
    }
    else if (mn == "March" || mn == "march" || mn == "Mar" || mn == "mar")
    {
        month = 3;
    }
    else if (mn == "April" || mn == "april" || mn == "Apr" || mn == "apr")
    {
        month = 4;
    }
    else if (mn == "May" || mn == "may")
    {
        month = 5;
    }
    else if (mn == "June" || mn == "june" || mn == "Jun" || mn == "jun")
    {
        month = 6;
    }
    else if (mn == "July" || mn == "july" || mn == "Jul" || mn == "jul")
    {
        month = 7;
    }
    else if (mn == "August" || mn == "august" || mn == "Aug" || mn == "aug")
    {
        month = 8;
    }
    else if (mn == "September" || mn == "september" || mn == "Sep" || mn == "sep")
    {
        month = 9;
    }
    else if (mn == "October" || mn == "october" || mn == "Oct" || mn == "oct")
    {
        month = 10;
    }
    else if (mn == "November" || mn == "november" || mn == "Nov" || mn == "nov")
    {
        month = 11;
    }
    else
    {
        month = 12;
    }

    return month;
}

// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main()
{

    Date testDate;
    testDate = getDate();
    cout << endl;
    cout << "Numeric: ";
    testDate.printNumeric();
    cout << endl;
    cout << "Alpha:   ";
    testDate.printAlpha();
    cout << endl;

    return 0;
}

Date getDate()
{
    int choice;
    unsigned monthNumber, day, year;
    string monthName;

    cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
         << "1 - Month Number" << endl
         << "2 - Month Name" << endl
         << "3 - default" << endl;
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        cout << "month number? ";
        cin >> monthNumber;
        cout << endl;
        cout << "day? ";
        cin >> day;
        cout << endl;
        cout << "year? ";
        cin >> year;
        cout << endl;
        return Date(monthNumber, day, year);
    }
    else if (choice == 2)
    {
        cout << "month name? ";
        cin >> monthName;
        cout << endl;
        cout << "day? ";
        cin >> day;
        cout << endl;
        cout << "year? ";
        cin >> year;
        cout << endl;
        return Date(monthName, day, year);
    }
    else
    {
        return Date();
    }
}