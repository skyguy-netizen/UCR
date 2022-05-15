#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Distance.h"

/* Constructs a default Distance of 0 (0 feet and 0.0 inches)
 */
Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}

/* Constructs a distance of ft feet and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(unsigned ft, double in)
{

    this->feet = ft;
    this->inches = in;

    init();

    // while (this->inches >= 12)
    // {
    //     this->feet++;
    //     this->inches -= 12;
    // }
}

/* Constructs a distance of 0 ft and in inches,
     unless in >= 12, in which case the values of feet and inches
     are adjusted accordingly. A Distance will always be positive.
     Just convert negative inches to positive. Don't subtract from feet.
*/
Distance::Distance(double in)
{
    // if (in < 0)
    // {
    //     in = -in;
    // }

    this->feet = 0;
    this->inches = in;

    init();

    // while (this->inches >= 12)
    // {
    //     this->feet++;
    //     this->inches -= 12;
    // }
}

/* Returns just the feet portion of the Distance
 */
unsigned Distance::getFeet() const
{
    return feet;
}

/* Returns just the inches portion of the Distance
 */
double Distance::getInches() const
{
    return inches;
}

/* Returns the entire distance as the equivalent amount of inches.
     (e.g., 4 feet 3.5 inches would be returned as 51.5 inches)
*/
double Distance::distanceInInches() const
{
    Distance total;
    total.feet = this->feet;
    total.inches = this->inches;

    while (total.feet > 0)
    {
        total.feet--;
        total.inches += 12;
    }

    return total.inches;
}

/* Returns the entire distance as the equivalent amount of feet.
     (e.g., 3 feet 6 inches would be returned as 3.5 feet)
*/
double Distance::distanceInFeet() const
{
    double total = feet;
    double inches = this->inches;
    while (inches >= 12)
    {
        total++;
        inches -= 12;
    }

    if (inches > 0)
    {
        total += inches / 12.0;
    }

    return total;
}

/* Returns the entire distance as the equivalent amount of meters.
     1 inch equals 0.0254 meters.
     (e.g., 2 feet 8.12 inches would be returned as 0.815848 meters)
*/
double Distance::distanceInMeters() const
{
    double totInches = distanceInInches();
    return totInches * 0.0254;
}

/* Returns the sum of 2 Distances.
 */
Distance Distance::operator+(const Distance &rhs) const
{
    Distance total;
    total.feet = feet + rhs.feet;
    total.inches = inches + rhs.inches;

    while (total.inches >= 12)
    {
        total.feet++;
        total.inches -= 12;
    }

    return total;
}

/* Returns the difference between 2 Distances.
 */
Distance Distance::operator-(const Distance &rhs) const
{
    Distance diff;
    if (this->feet > rhs.feet)
    {
        diff.feet = feet - rhs.feet;
        diff.inches = inches - rhs.inches;
    }
    else
    {
        diff.feet = rhs.feet - feet;
        diff.inches = rhs.inches - inches;
    }

    if (diff.feet > 0)
    {
        while (diff.inches < 0)
        {
            diff.feet--;
            diff.inches += 12;
        }
    }
    else
    {
        if (this->inches > rhs.inches)
        {
            diff.inches = this->inches - rhs.inches;
        }
        else
        {
            diff.inches = rhs.inches - this->inches;
        }
    }

    while (diff.inches >= 12)
    {
        diff.feet++;
        diff.inches -= 12;
    }
    return diff;
}

/* Outputs to the stream out the Distance in the format:
     feet' inches'' (i.e. 3' 3.41'')
*/
ostream &operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet << "' " << rhs.inches << "\"";
    return out;
}

void Distance::init()
{
    if (inches < 0)
    {
        inches = -1 * inches;
    }

    while (this->inches >= 12)
    {
        this->feet++;
        this->inches -= 12;
    }
}