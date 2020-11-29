#include "Automata.h"
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


Automata::Automata ()
{
  cash = 0;
  state = OFF;
  chos = -1;
  count = 3;
  menu = new char *[3]
  {
  "COFFE", "TEA", "CACAO"};
  prices = new double[3]
  {
  29.99, 19.99, 49.99};
//cin>>count;
//menu= new char*(count);
//prices= new double(count);
//for (size_t i=0;i<count){cin>>menu[i]; cin>>prices[i];}
}

int
Automata::on ()
{
  if (state == OFF)
    {
      state = WAIT;
      return 0;
    }
  return -1;
}

int
Automata::off ()
{
  if (state == WAIT)
    {
      state = OFF;
      return 0;
    }
  return -1;
}




int
Automata::finish ()
{
  if (state == COOK)
    {
      state = WAIT;
      int ret = cash;
      cash = 0;
      chos = -1;
      return ret;
    }
  return -1;
}

STATES
Automata::getState () const
{
  return state;
}


int
Automata::getMenu (char **menu) const
{
  if (state == OFF)
    return -1;
  else
    {
      char **ret = new char *[count];
      char *a;
      for (size_t i = 0; i < count; i++)
	{
	  strcpy (a, menu[i]);
	  strcat (a, " ");
	  sprintf (a, "%g", prices[i]);
	  ret[i] = a;
	}
      menu = ret;
    }
}



bool
Automata::check () const
{
  if (state == CHECK)
    {
      if (cash >= prices[chos])
	return true;
      else
	return false;
    }
  return -1;
}

int
Automata::coin (double a)
{
  if ((state != OFF) && (state != COOK))
    {
      cash += a;
      chos = -1;
      state = ACCEPT;
      return 0;
    }
  return -1;
}


int
Automata::choice (int x)
{
  if (state == ACCEPT)
    {
      state = CHECK;
      chos = x;
      return 0;
    }
  return -1;
}

int
Automata::cook ()
{
  if ((state == CHECK) && check ())
    {
      state = COOK;
      return 0;
    }
  return -1;
}

int
Automata::cansel ()
{
  if ((state == ACCEPT) || (state == CHECK))
    {
      int ret = cash;
      cash = 0;
      chos = -1;
      state = WAIT;
      return ret;
    }
  return -1;
}

