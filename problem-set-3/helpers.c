// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    const char delim[2] = "/";
    int numerator = atoi(strtok(fraction, delim));
    int denominator = atoi(strtok(NULL, delim));

    int factor = 8 / denominator;
    numerator *= factor;

    return numerator;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    int length = strlen(note);
    char letter = note[0];
    int octave = note[length == 2 ? 1 : 2] - '0';

    double freq = 0;
    int semitones_diff = 0;

    switch(letter){
        case 'C':
            semitones_diff = -(length == 2 ? 9 : note[1] == '#' ? 8 : 10);
            break;
        case 'D':
            semitones_diff = -(length == 2 ? 7 : note[1] == '#' ? 6 : 8);
            break;
        case 'E':
            semitones_diff = -(length == 2 ? 5 : 6);
            break;
        case 'F':
            semitones_diff = -(length == 2 ? 4 : note[1] == '#' ? 3 : 5);
            break;
        case 'G':
            semitones_diff = -(length == 2 ? 2 : note[1] == '#' ? 1 : 3);
            break;
        case 'A':
            semitones_diff = (length == 2 ? 0 : note[1] == '#' ? 1 : -1);
            break;
        case 'B':
            semitones_diff = (length == 2 ? 2 : 1);
            break;
        default:
            break;
    }

    semitones_diff += 12 * (octave - 4);

    double exp = (semitones_diff)/12.0;
    freq = pow(2, exp);
    freq *= 440.0;

    return (int) round(freq);

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return !strcmp(s, "");
}
