/**
 * is_ascii - checks if a character is a valid ascii
 * @c: character to check
 * Return: 0 if not and 1 if it is an ascii
 */

int is_ascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
