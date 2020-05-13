#include <iostream>
#include <string>

using namespace std;

#ifndef DIVSALES_h
#define DIVSALES_h

class divSales {
    
private:
    //Static Float Variable for corporate sales, holds the total amount
    // for all regions.
    static float totalCorporateSales;
    //String Variable for Region Name, holds the name of each region.
    string regionName;
    //Float array for region sales, holds the sales for each quarter of a
    // region.
    float regionalSales[4];
    
public:
    //Default Contructor
    divSales();
    //Default Destructor
    ~divSales();
    
    //Setter Function for setRegionInfo, takes a string and float array and
    // returns the value to the instance of class. It adds all values of
    // regionSales to totalCorporateSales.
    void setRegionInfo(string, float[]);
    
    //Getter Function for getRegionInfo, returns a string value for the
    // region name. Is constant to protect variable from editing.
    string getRegionName() const;
    //Getter Function for getQuarterlySales, takes an integer as parameter
    // and uses its value as an index to find a specific quarter's sale for
    // a region.
    float getQuarterlySales(int) const;
    //Getter Function for Division Sales, outputs the sales for each quarter
    // and returns the region total to the console.
    float getDivisionSales() const;
    //Getter Function for Regional Sales (Total), returns the total corporate
    // sales.
    float getRegionalSales() const;
    
    float extraCredit(int) const;
    
};

#endif/*  DIVSALES_h */
