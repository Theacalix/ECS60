#include "LongInt.h"

LongInt::LongInt()
{
}


LongInt::LongInt(int initialSize): Size(initialSize)
{
  for(int i = 0; i < Size; i++)
  {
    integer.insert(0,integer.zeroth());
  }
}


bool LongInt::getsize(int& ssize, int& dif, const LongInt& int_1, const LongInt& int_2)
{
  if(int_1.Size > int_2.Size)
  {
    ssize = int_2.Size;
    dif = int_1.Size - int_2.Size;
    return true;
  }
  else
  {
    ssize = int_1.Size;
    dif = int_2.Size - int_1.Size;
    return false;
  }
}


void LongInt::addExtra(ListNode<int>* ResultItr, ListNode<int>* int_extra, int dif)
{
   for(int i = 0; i < dif; i++)
  {
    ResultItr->element += int_extra->element;
    if(ResultItr->element > 9)
    {
      ResultItr->next->element += 1;
      ResultItr->element -= 10;
    }

    ResultItr = ResultItr->next;
    int_extra = int_extra->next;
  }
}


istream& operator>>(istream is, LongInt& LI)
{
  char first
  while(is.get(first))
  {
    LI.integer.insert(int(first), zeroth);
    Size++;
  }
}

LongInt operator+(const LongInt& left, const LongInt& right)
{
  int ssize, dif;
  bool Left = getsize(ssize, dif, left, right);
  if(Left)
  {
   LongInt result(left.Size + 1);
  }else
  {
    LongInt result(right.Size + 1);
  }
  
  ListNode<int> LeftItr* = left.integer->head, RightItr* = right.integer->head, ResultItr* = result.integer->head;

  for(int i = 0; i < ssize; i++)
  {
    ResultItr->element += LeftItr->element + RightItr->element;
    if(ResultItr->element > 9)
    {
      ResultItr->next->element += 1;
      ResultItr->element -= 10;
    }

    ResultItr = ResultItr->next;
    LeftItr = LeftItr->next;
    RightItr = RightItr->next;
  }

  if(Left)
    addExtra(ResultItr, LeftItr, dif);
  else
    addExtra(ResultItr, RightItr, dif);
}
