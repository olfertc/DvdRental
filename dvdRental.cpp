#include <iostream>
#include <string> // to use strings
using namespace std;

string getTitle(); // string function: asks user for a movie title, returns the title
int getHours(); // int function: asks user for hours, returns the hours
char getType(); // char function: asks user for type of movie, returns type
double calculateCost(int hours, char type); // function for calculating the cost of movie rental: returns cost
void printResults(string title, int hours, double cost); // function to print the cost of movie rental



int main() {
	
	string title;
	int hours;
	char type;
	double cost; 
	char again = ' ';

	/* loop to call functions and get user input for title, hours and type, 
	calculates the cost and then returns the cost of movie rental, 
	until user does not want to calculate again*/
	while (again != 'N') {
		title = getTitle();
		hours = getHours();
		type = getType();
		cost = calculateCost(hours, type);
		printResults(title, hours, cost);
		cout << "Would you like to calculate another movie? (Y or N): ";
		cin >> again;
		cin.ignore(256, '\n'); 
	}
	return 0;
}

// function to get the title from user
string getTitle() {
	string title;
	cout << "Enter a movie title: ";
	getline(cin, title);
	return title;
}

// function to get the hours from user
int getHours() {
	int hours;
	cout << "Enter the hours: ";
	cin >> hours;
	return hours;
}

// function to get the type from user
char getType() {
	char type;
	cout << "Enter the type of movie (R, N, or O): ";
	cin >> type;
	return type;
}

// function to calculate cost
double calculateCost(int hours, char type) {
	double cost;

	if (hours <= 3) {
		cost = 5.0;
	}
	else {
		cost = 5.0 + (1 * (hours - 3));
	}
	if (type == 'N') {
		cost = cost + (cost * 0.25);
	}
	if (type == 'O') {
		cost = cost + (cost * (- 0.3));
	}
	if (cost > 10.0) {
		cost = 10.0;
	}	
	return cost;
}

// function to print the title, the hours and the calculated cost
void printResults(string title, int hours, double cost) {
	cout << title << " " << hours << " " << cost << endl;
	return;
}