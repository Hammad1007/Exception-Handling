// Header Files
#include <iostream>
#include <string>
using namespace std;

//const int days_in_months[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//const char* months[12][12] = {"January", "Feb", "March", "April", "May", "June", "July", "August", 
//"September", "October", "November", "December" };
//const char* days[12][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

//-----------------------------------------------------------------------------------------------------------

// Menu Function
void Menu() {
	cout << "\t---------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t*********************Assignment 6*********************\n";
	cout << "\t---------------------------------------------------------------------------------------------\n";
}

//-----------------------------------------------------------------------------------------------------------
//------------------------------------------Month class------------------------------------------------------

// Month class
class Month {
private:
	string Name_of_Month;    // name of the month
	int days;               // no of days
public:
	// Default Constructor
	Month() {
		Name_of_Month = '\0';
		days = 0;
	}

	// Parameterised Constructor
	Month(string m, int d) {
		this->Name_of_Month = m;
		this->days = d;
	}

	// Copy Constructor
	Month(const Month& obj) {
		this->Name_of_Month = obj.Name_of_Month;
		this->days = obj.days;
	}

	// Assignment Operator
	Month operator=(Month& obj) {
		this->Name_of_Month = obj.Name_of_Month;
		this->days = obj.days;
		return *this;
	}

	// Getters
	string getName() {
		return this->Name_of_Month;
	}

	int getDays() {
		return this->days;
	}

	// Setters
	void setName(string n) {
		this->Name_of_Month = n;
	}

	void setDays(int d) {
		this->days = d;
	}

	// Destructor
	~Month() {
		cout << "~Month() called." << endl;
	}

};// class ends

//-----------------------------------------------------------------------------------------------------------
//----------------------------------------Exception Class MonthError-----------------------------------------

// Exception class number 1
class MonthError {
private:
	string Name;          // Name of the month
	Month* arr;          //  Month class array 
	int size;           //   size of the array
public:
	// Default Constructor
	MonthError() {
		Name = '\0';
		size = 12;
		arr = new Month[size];
		arr[0].setName("January");
		arr[1].setName("February");
		arr[2].setName("March");
		arr[3].setName("April");
		arr[4].setName("May");
		arr[5].setName("June");
		arr[6].setName("July");
		arr[7].setName("August");
		arr[8].setName("September");
		arr[9].setName("October");
		arr[10].setName("November");
		arr[11].setName("December");
		arr[0].setDays(31);
		arr[1].setDays(29);
		arr[2].setDays(31);
		arr[3].setDays(30);
		arr[4].setDays(31);
		arr[5].setDays(30);
		arr[6].setDays(31);
		arr[7].setDays(31);
		arr[8].setDays(30);
		arr[9].setDays(31);
		arr[10].setDays(30);
		arr[11].setDays(31);
	}

	// Input the month
	// Exception function
	void InputMonth(int monthnum) {
		try {
			if (monthnum > 0 && monthnum <= 12) {
				this->Name = arr[monthnum - 1].getName();
			}
			else {
				throw monthnum;
			}
		}
		catch (int mymon) {
			cout << "The month " << mymon << " you entered, is incorrect.\n";
			exit(1);
		}

	}

	// Stream Insertion Operator
	friend ostream& operator << (ostream& out, MonthError& obj) {
		out << obj.Name;
		return out;
	}

	// Destructor
	~MonthError() {
		if (arr != nullptr) {
			delete[]arr;
			arr = nullptr;
		}
	}

};// class ends

//-----------------------------------------------------------------------------------------------------------
//----------------------------------------Exception Class DayError-------------------------------------------

// Exception class number 2
class DayError {
private:
	int Date;
	Month* arr;
	int size;
public:
	// Default Constructor
	DayError() {
		Date = 0;
		size = 12;
		arr = new Month[size];
		arr[0].setName("January");
		arr[1].setName("February");
		arr[2].setName("March");
		arr[3].setName("April");
		arr[4].setName("May");
		arr[5].setName("June");
		arr[6].setName("July");
		arr[7].setName("August");
		arr[8].setName("September");
		arr[9].setName("October");
		arr[10].setName("November");
		arr[11].setName("December");
		arr[0].setDays(31);
		arr[1].setDays(29);
		arr[2].setDays(31);
		arr[3].setDays(30);
		arr[4].setDays(31);
		arr[5].setDays(30);
		arr[6].setDays(31);
		arr[7].setDays(31);
		arr[8].setDays(30);
		arr[9].setDays(31);
		arr[10].setDays(30);
		arr[11].setDays(31);
	}

	// Input the day from the user
	// Exception function
	void InputDay(int m, int d) {
		try {
			if (d > 0 && d < arr[d].getDays()) {
				this->Date = d;
			}
			else {
				throw d;
			}
		}
		catch (int myday) {
			cout << "The day " << myday << " you entered is incorrect.\n";
			exit(1);
		}
	}
	
	// Stream Insertion
	friend ostream& operator << (ostream& out, DayError& obj) {
		out << obj.Date;
		return out;
	}

	// Destructor
	~DayError() {
		if (arr != nullptr) {
			delete[]arr;
			arr = nullptr;
		}
	}

};// class ends

//-----------------------------------------------------------------------------------------------------------


// Main Driver
int main() {

	system("Color E0");

	Menu();
	
	MonthError m;
	
	DayError d;
	
	int day = 0; 
	int month = 0;
	int year = 0;    
	
	cout << "Enter the Day: ";
	cin >> day;
	cout << "Enter the Month: ";
	cin >> month;
	cout << "Enter the Year: ";
	cin >> year;
	
	m.InputMonth(month);
	d.InputDay(month, day);
	
	cout << "The date you entered is:\n";
	cout <<  m << " " << d << "," << year << endl;    // eg. February 18, 2001

	cout << "\t\t\t\t\t     ------------Thank You------------\n\n";

	system("Pause");
	return 0;

}// main driver ends here


//-----------------------------------------------------------------------------------------------------------
