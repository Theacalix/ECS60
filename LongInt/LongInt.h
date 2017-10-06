#ifndef LONG_INT_H_
#define LONG_INT_H_

#include "LinkedList.h"

class LongInt
{
private:
  List<int> integer;
  int Size;
  LongInt(int initialSize);
  bool getsize(int& ssize,int& dif, const LongInt& int_1, const LongInt& int_2);
  void addExtra(ListNode<int>* result, ListNode<int>* int_extra, int dif);
public:
  LongInt();
  friend istream& operator>>(istream& is, const LongInt& LI);
  friend const LongInt operator+(const LongInt& left, const LongInt& right);
  friend ostream& operator<<(ostream& os, const LongInt& LI);


}; // Long Int



#endif
