#include "divSales.h"
#include <iomanip>
#include <string>

//Initialization for totalCorporateSales
float divSales :: totalCorporateSales = 0.0;

//Default Construtor, initializes private member functions to null state
divSales :: divSales()
{
    regionName = " ";
    
    for (int i = 0; i < 4; i++) {
        regionalSales[i] = 0.0;
    }
}

//Default Destructor
divSales :: ~divSales()
{
    
}

//Setter function for setRegionInfo, this function asks the user to enter a
// region name (East, North, South, or West) and the values for each
// quarterly sales of that region. It also adds all quarterly sales to the
// static variable totalCorporateSales
void divSales :: setRegionInfo(string, float[])
{
    // This must only accept East, West, North, South
    cout << "Enter Region: "; getline(cin, regionName);

	while(regionName.compare("East") != 0 &&
		  regionName.compare("West") != 0 &&
		  regionName.compare("North") != 0 &&
		  regionName.compare("South") != 0) {
        
        cout << "Please Enter a Valid Region: "; getline(cin, regionName);
		}
    for (int i = 0; i < 4; i++) {
        
        cout << "\tQuarter " << i+1 << ": "; cin >> regionalSales[i];
        //Adds the totalCorporateSales
        totalCorporateSales += regionalSales[i];
    }
    cin.ignore();
}

//Getter function for getRegionName, this function returns the reigionName and
// the value is protected by a const.
string divSales :: getRegionName() const
{
    return regionName;
}

//Getter function for getQuarterlySales, this function takes an int as a
// parameter, then uses it to find a position in the array regionSales. It then
// returns the value. The value is protected by const.
float divSales :: getQuarterlySales(int j) const
{
	return regionalSales[j];
}

//Getter function for getDivisionSales, this function output to the console the
// quarterly sales for each region and adds the total quarterly sales for each
// region and returns its value. Protected by const.
float divSales :: getDivisionSales() const
{
	float total = 0.0;
    
    cout << fixed << showpoint << setprecision(2);
	
    for (int i = 0; i < 4; i++) {
        
        cout << "\tQuarter " << i+1 << ": " << regionalSales[i] << endl;
        total += regionalSales[i];
    }
    cout << "Region Total: ";
    
    return total;
}

//Getter function for getRegionalSales, returns the totalCorporateSales,
// protected by const
float divSales :: getRegionalSales() const
{
	return totalCorporateSales;
}

float divSales :: extraCredit(int i) const
{
    return regionalSales[i];
}

