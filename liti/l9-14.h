#ifndef HEADER_9_14_H

#define HEADER_9_14_H

template <class T>
int seqSearch(const T list[], int n, const T &key)
{
    for (int i = 0; i < n; i++)
        if (list[i] == key)
            return i;
    return -1;
}
#endif
