#ifndef HEADER_9_15_H

#define HEADER_9_15_H

template <class T>
int binSearch(const T list[], int n, const T &key)
{
    int low = 0;
    int high = n - 1;
    while(low<=high){
        int mid = (low + high) / 2;
        if(key==list[mid])
            return mid;
            else if (ky<list[mid])
                high = mid - 1;
    }
    return -1;
}
#endif
