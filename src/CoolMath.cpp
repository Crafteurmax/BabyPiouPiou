#include "CoolMath.h"

// cool qake III code, with original comment for historic reasons
// explanation https://youtu.be/p8u_k2LIZyo?si=5TRdNeXY83aOT3qO
// as explained here https://en.wikipedia.org/wiki/Fast_inverse_square_root#Avoiding_undefined_behavior
// in C++, it would be better not to use this type of cast but a bit_cast
// however 
// it's cooler like that
float CoolMath::Q_rsqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;                       // evil floating point bit level hacking
	i = 0x5f3759df - (i >> 1);               // what the fuck?
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));   // 1st iteration
	// y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

sf::Vector2f CoolMath::normalize(sf::Vector2f vect)
{
	return vect * Q_rsqrt(vect.x * vect.x + vect.y * vect.y);
}

float CoolMath::norme(sf::Vector2f vect)
{
	return 1/ Q_rsqrt(vect.x * vect.x + vect.y * vect.y);
}

