#ifndef HELPERS_H
#define HELPERS_H

bool compareDoubles(double first, double second, double delta) {return (((first + delta) > second) && ((first - delta) < second));}

#endif // HELPERS_H
