#include "project.h"
#include "header.h"

void enable()
{
	uint8_t touche_E = 0;

	while (!touche_E)
	{
		char key = lecture_clavier();
		if (key == 'E')
		{
			touche_E = 1;
		}
	}
}