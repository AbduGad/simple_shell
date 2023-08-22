#include "main.h"
/**
 * signal_handler - handels when the input is ^C doesnt exit
 * @signum: singnal number
 */
void signal_handler(int signum)
{
	(void)signum;

	if (signum == SIGINT)
	{
		write(1, "\n$ ", 3);
	}
}
