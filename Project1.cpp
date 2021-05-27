/*
Dhruv Jaiswal
 
Problem: Find the resistance of a wire using the cross section in square centimeters,
the length of the wire in centimeters, and the resistivity of the wire composition in ohm meters.
The options for the wires are aluminum, copper, gold, platinum, zinc, and silver.
Allowing user to choose the materia they want to find the resistance of.
 
Input: The needed input for this program is the radius of the wire in centimeters,
       The length of the wire in centimeters,
	   The first letter of the type of the material.

Output: The expected output is the resistance of the wire in ohms.

Algorithm: To perform this calculation, used the formula:
            resistance = (length/cross section)*resistivity.
 
		   We'll check to see if the user puts in the correct material name and proper length and radius values,
           and if not ask them to input it in again.
           
           Using if and else if statements, ask the user for the first letter of material used to determine the resistivity.
           
           Then ask the user the for radius of the wire and mulitiply it by 2pi to find the cross section.
		   Divide this value by the length of the wire, which the user will also input. Mulitply this value by the
           resistivity to find the resistance of the wire.
 
           The output a message displaying the material name, cross section, length, and
           resistance of resistance of the wire.
*/

// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //PI used in calculating Area.
	const double PI = 3.14159;
    //Variablles
	float length, radius, resistivity, resistance, crossSection;
	char material;
	string elementName;
	
	cout << "What is the length of the wire in centimeters?" << endl;
	cin >> length;

	//Length check
	while (length <= 0)
	{
		cout << "That value is not valid, please input a length that is greater than 0." << endl;
		cin >> length;
	}

	cout << "What is the radius of your wire in centimeters?" << endl;
	cin >> radius;

	//Radius check
	while (radius <= 0)
	{
		cout << "That value is not valid, please input a radius that is greater than 0." << endl;
		cin >> radius;
	}

	cout << "What material is your wire made of: aluminum, copper, gold, platinum, silver, or zinc?" << endl 
		<< "Please input only the first letter of the material." << endl;
	cin >> material;

	//Material letter check for correct input
	if (material != 'A' && material != 'a' && material != 'C' && material != 'c' && material != 'G' && material != 'g'
		&& material != 'P' && material != 'p' && material != 'S' && material != 's' && material != 'Z' && material != 'z')
	{
		cout << "That letter is not valid, please input the first letter of the material that your wire is made of: aluminum, " << endl
			 << "copper, gold, platinum, silver, or zinc." << endl;
		cin >> material;
	}

    //sleceting the material's resistivity and name.
	if (material == 'A' || material == 'a')
	{
		resistivity = 2.8E-8;
		elementName = "aluminum";
	}
	else if (material == 'C' || material == 'c')
	{
		resistivity = 1.7E-8;
		elementName = "copper";
	}
	else if (material == 'G' || material == 'g')
	{
		resistivity = 2.4E-8;
		elementName = "gold";
	}
	else if (material == 'P' || material == 'p')
	{
		resistivity = 0.98E-7;
		elementName = "platinum";
	}
	else if (material == 'S' || material == 's')
	{
		resistivity = 1.59E-8;
		elementName = "silver";
	}
	else
	{
		resistivity = 5.5E-8;
		elementName = "zinc";
	}

	//Calculation of cross section of wire in centimeters
	crossSection = pow(radius,2.0) * PI;
    
	//Calculation of resisitance of wire. Must multiply by 100 because length and cross section are in cm and resistivity is in m and 100cm = 1m.
	resistance = (length / crossSection) * 100 * resistivity;

	//This if/else chain is just for proper grammar since aluminum starts with a vowel and the rest of the materials do not.
	if (material == 'A' || material == 'a')
	{
        //using setpricision for getting the righ tnumber of decimal places.
		cout << "An " << elementName << " wire with a cross section of " << setprecision(5) << showpoint << crossSection << " square centimeters and"  
			<< "a length of " << endl << length << " centimeters has a resistance of " << setprecision(3) << resistance << " ohms.";
	}
	else
	{
		cout << "A " << elementName << " wire with a cross section of " << setprecision(5) << showpoint << crossSection << " square centimeters and"
			 << " a length of " << endl << length << " centimeters has a resistance of " << setprecision(3) << resistance << " ohms.";
	}

	return (0);
}
