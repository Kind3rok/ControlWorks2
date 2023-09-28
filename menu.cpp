#include "input.h"
#include "start.h"
#include <iostream>

void StartProgram(void)
{
	ShowAuthor();
	for (;;) 
	{
		ShowMainMenu();
		switch (int user_choice = GetKey(CW1, CW4))
		{
			case CW1:
				InfoCW1();
				StartCW1();
				break;

			case CW2:
				InfoCW2();
				StartCW2();
				break;

			case CW3:
				InfoCW3();
				StartCW3();
				break;

			case CW4:
				InfoCW4();
				StartCW4();
				break;

			case QUIT:
				exit(EXIT_SUCCESS);
		}
	}
}
