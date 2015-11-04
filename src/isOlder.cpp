/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isLegit(int d, int m, int y)
{
	if (d < 0 || d > 31 || m < 0 || m > 12 || y < 0 || y > 9999)
		return 0;

	int legitFlag = 0, leap = 0;
	int maxDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		leap = 1;

	if (leap == 1)
		maxDays[1]++;

	if (d <= maxDays[m - 1])
	{
		legitFlag = 1;
	}

	return legitFlag;
}
int isOlder(char *dob1, char *dob2) 
{
	int d1, m1, y1, d2, m2, y2;
	d1 = dob1[0] * 10 + dob1[1] - 11 * '0';
	d2 = dob2[0] * 10 + dob2[1] - 11 * '0';
	m1 = dob1[3] * 10 + dob1[4] - 11 * '0';
	m2 = dob2[3] * 10 + dob2[4] - 11 * '0';
	y1 = dob1[6] * 1000 + dob1[7] * 100 + dob1[8] * 10 + dob1[9] - 1111 * '0';
	y2 = dob2[6] * 1000 + dob2[7] * 100 + dob2[8] * 10 + dob2[9] - 1111 * '0';

	if (isLegit(d1, m1, y1) == 0 || isLegit(d2, m2, y2) == 0)
		return -1;

	if (y1 < y2)
		return 1;
	else if (y1 > y2)
		return 2;
	else
	{
		if (m1 < m2)
			return 1;
		else if (m1 > m2)
			return 2;
		else
		{
			if (d1 < d2)
				return 1;
			else if (d1 > d2)
				return 2;
			else
				return 0;
		}
	}
}
