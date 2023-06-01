#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers
 * @size: number of elements in array
 * @direction: direction to slide and merge
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, used;

    if (direction == SLIDE_LEFT)
        i = 1;
    else
        i = size - 2;
    while (1)
    {
        if (line[i] == line[i + direction] && line[i] != 0)
        {
            line[i + direction] += line[i];
            line[i] = 0;
            used = i + direction;
        }
        else if (line[i] != 0 && line[i + direction] == 0)
        {
            j = i;
            while ((j != 0 && j != size) && line[j + direction] == 0)
                j += direction;
            if ((j != 0 && j != size && (j + direction != used)) && line[j + direction] == line[i])
            {
                line[j + direction] *= 2;
                used = j + direction;
            }
            else
                line[j] = line[i];
            line[i] = 0;
        }
        i += (direction * (-1));
        if (i == 0 || i == size - 1)
            break;
    }
    return (1);
}