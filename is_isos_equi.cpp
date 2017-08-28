#include <iostream>
using namespace std;

string is_isos_equi(int s1, int s2, int s3);

const string none = "None of these";
const string isos = "Isosceles";
const string equi = "Equilateral";

int main() {
    int num_input = 0;
    
    cin >> num_input;

    // Read in the side lengths of each sample and determine whether the triangle is
    // isosceles or equilateral
    for (int i = 0; i < num_input; i++) {
    	int side1, side2, side3;
    	cin >> side1 >> side2 >> side3;
    	cout << is_isos_equi(side1, side2, side3) << endl;
    }
    
    return 0;
}

// Function that takes in the side lengths of a triangle and determine whether 
//the triangle is isosceles or equilateral
string is_isos_equi(int s1, int s2, int s3) {
    // If not a valid triangle
    if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
        return none;
    }
    
	// If no pair of lengths are equal
	if (s1 != s2 && s1 != s3 && s2 != s3) {
		return none;
	}

	// If all 3 lengths are equal
	if (s1 == s2 && s2 == s3 && s3 == s1) {
		return equi;
	}

	// If both above conditions are false, the triangle must be isosceles 
	// but not equilateral
	return isos;
}