#include "project.h"
#include "header.h"

char lecture_clavier()
{
	g_key_pressed = 0;
	
	while(1)
	{
		if (g_key_pressed)
		{

			// Debouncing
			CyDelay(100);

			pins_read();
			for (int i = 0; i < 4; i ++){
				for (int j = 0; j < 4; j++){
					if (!g_touches[i][j]){
						return CLAVIER[i][j];
					}
				}
			}
		}
	}
}