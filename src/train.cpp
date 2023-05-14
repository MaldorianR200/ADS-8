// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool light) {
	if (first == nullptr) {
		first = new Cage();
		first -> light = light;
		first -> next = first;
		first -> prev = first;
   } else {
		Cage* nextCage = new Cage();
		nextCage -> light = light;
		nextCage -> prev = first -> prev;
		nextCage -> next = first;
		first -> prev -> next = nextCage;
		first -> prev = nextCage;
   }
}

int Train::getLength() {
	int count = 1;
	Cage* cur = first;
    cur -> light = true;
	while (cur) {
		cur = cur -> next;
        checkF(cur, count);
        if (cur -> light == true) {
            cur -> light = false;
            ++countOp;
            for (int i = count; i > 0; --i) {
                cur = cur -> prev;
                ++countOp;
            }
            if (cur -> light == false) {
                return count;
            } else {
                count = 1;
            }
        }
    }
	return 0;
}


int Train::getOpCount() {
    return countOp;
}


void Train::checkF(Cage* cur, int& count) {
	if (cur->light == false) {
		++count;
		++countOp;
	}
}
