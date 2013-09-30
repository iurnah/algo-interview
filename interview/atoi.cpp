#include <iostream>
#include <stdlib>

using namespace std;

int main()
{

}


int atoi (char* str)
{
assert(str);
assert(str[0]);
int result = 0;
	int newResult = 0;
				 if (str[0] == '+')
					  :x
					   if (str[0] == '-')
										return -1 * atoi(str + 1);

						   int i = 0;

								while (str[i])
											 {
															   assert(str[i] >= '0' && str[i] <= '9');
																		 newResult = (result << 1) + (result << 3) + str[i] - '0';
																				   assert(newResult >= result);
																							 result = newResult;
																									   i++;
																											}

									 return result;
}
