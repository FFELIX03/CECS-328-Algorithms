#include <math.h>
#include <iostream>

using namespace std;
/* Class Findsquare used to find the square of a number by halfing it
 * recursively and checking if the products of the halfs equals original
 * number
 *
 * @param key  : original number
 * @param start: start at zero if overshoot go up by to half
 * @param end  : end of range
 *
 *
 *
 */
class FindSquare{
	public:
int square(double key,double start, double end)
{   
    double half=end+start;
    half=half/2;
    {
    if(ceil(half*half)>key)
        return square(key,start,half);
    if(ceil(half*half)<key)
        return square(key,half,end);
    }
    return half;

}
};
