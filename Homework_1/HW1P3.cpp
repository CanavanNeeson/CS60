//Canavan Neeson. CSCI 60-03. HW 1 Problem 3.
#include <iostream>
#include <string>
using namespace std;

class Movie {
public:
	Movie(); //default constructor
	Movie(string, string, double);//constructor to initialize all fields

	string getName() {return name;}
	string getRating() {return rating;}
	double getEarnings() {return earnings;}
	void setName(string); //Setters is necessary for Movies created with the default constructor
	void setRating(string);
	void setEarnings(double);
	double movieShowing(int);
	//Increases earnings by 12 times the argument
private:
	string name;
	string rating;
	double earnings;
};

	Movie mergeMovie(Movie m, Movie n);

int main() {
	Movie m1("Star Wars", "PG", 1000), m2("Star Wars", "PG-13", 1000), m3("Avalanche Sharks", "PG-13", 1);
	
	cout << m1.getName() << " " << m1.getRating() << " "<< m1.getEarnings() << endl;
	Movie m4;
	m4.setName("Megashark vs. Crocosaur");
	m4.setRating("PG-13");
	m4.setEarnings(2);
	
	cout << m4.getName() << " " << m4.getRating() << " " << m4.getEarnings() << endl;
	
	Movie m5 = mergeMovie(m1, m2);
	cout << m5.getName() << " " << m5.getRating() << " "<< m5.getEarnings() << endl;
	
	m5.movieShowing(12);
	cout << m5.getName() << " " << m5.getRating() << " "<< m5.getEarnings() << endl;
	
	m4.movieShowing(12);
	cout << m4.getName() << " " << m4.getRating() << " " << m4.getEarnings() << endl;
	
	return 0;
}






//Movie mutators
void Movie::setName(string s) {
	name = s;
}

void Movie::setEarnings(double e) {
	if (earnings >= 0)
		earnings = e;
}

void Movie::setRating(string s) 
//Precondition: string that is a valid rating
//Postcondition: rating is set to argument
{
	if (s == "G" || s == "PG" || s == "PG-13" || s == "R")
		rating = s;
	else
		cout << "Error in setRating. " << s << " is not a valid rating!\n";
}


//Other Movie member functions
double Movie::movieShowing(int n) 
//Precondition: earnings is set. Int argument
//Postcondition: earnings is increased by 12 times the argument. Returns new earnings
{
	double ticketPrice = 12;
	earnings += n * ticketPrice;
	return earnings; //Unclear what function should return
}

Movie mergeMovie(Movie m, Movie n) 
//Precondition: two Movie arguments
//Postcondition: Returns Movie with most restrictive of argument ratings, earnings equal to sum of two arguments' earnings. If the arguments have the same names, the returned Movie will have that name; if not, the name will be "Could not combine."
{
	Movie newMovie;
	if (m.getName() == n.getName()) 
		newMovie.setName(m.getName());
	else {
		newMovie.setName("Could not combine.");
		return newMovie;
	}
	
	if (m.getRating() == "R" || n.getRating() == "R")
		newMovie.setRating("R");
	else if (m.getRating() == "PG-13" || n.getRating() == "PG-13")
		newMovie.setRating("PG-13");
	else if (m.getRating() == "PG" || n.getRating() == "PG")
		newMovie.setRating("PG");
	else if (m.getRating() == "G" || n.getRating() == "G")
		newMovie.setRating("G");
	else
		cout << "Error in mergeMovie. Could not combine ratings.\n";
	
	newMovie.setEarnings(m.getEarnings() + n.getEarnings());
	
	return newMovie;
}

//Movie constructors
Movie::Movie() 
//Sets all fields to dummy values
{
	name = "";
	rating = "G";
	earnings = 0;
}

Movie::Movie(string n, string s, double e) {
	name = n;
	
	if (s == "G" || s == "PG" || s == "PG-13" || s == "R")
		rating = s;
	else
		cout << "Error in Movie constructor. " << s << " is not a valid rating!\n";
	
	earnings = e;
}





