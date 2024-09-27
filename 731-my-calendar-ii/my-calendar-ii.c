#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOOKINGS 1000

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval bookings[MAX_BOOKINGS];
    int bookingsCount;
    Interval overlaps[MAX_BOOKINGS];
    int overlapsCount;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = (MyCalendarTwo*)malloc(sizeof(MyCalendarTwo));
    obj->bookingsCount = 0;
    obj->overlapsCount = 0;
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    for (int i = 0; i < obj->overlapsCount; i++) {
        if (start < obj->overlaps[i].end && end > obj->overlaps[i].start) {
            return false;
        }
    }
    
    for (int i = 0; i < obj->bookingsCount; i++) {
        if (start < obj->bookings[i].end && end > obj->bookings[i].start) {
            obj->overlaps[obj->overlapsCount].start = (start > obj->bookings[i].start) ? start : obj->bookings[i].start;
            obj->overlaps[obj->overlapsCount].end = (end < obj->bookings[i].end) ? end : obj->bookings[i].end;
            obj->overlapsCount++;
        }
    }
    
    obj->bookings[obj->bookingsCount].start = start;
    obj->bookings[obj->bookingsCount].end = end;
    obj->bookingsCount++;
    
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj);
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 * myCalendarTwoFree(obj);
 */