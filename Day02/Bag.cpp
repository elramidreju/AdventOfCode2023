#include "Bag.h"

bool Bag::CanPick(int howManyRed, int howManyGreen, int howManyBlue)
{
	return redAmount >= howManyRed 
		&& greenAmount >= howManyGreen
		&& blueAmount >= howManyBlue;
}
