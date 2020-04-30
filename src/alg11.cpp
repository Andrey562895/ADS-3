#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "iostream"
#include <cstdlib>
#include "string"
#include <stack> 
using namespace std;

int preori(char c)
{	 if (c == '*' || c == '/')
		return 3;
	else if (c == '+' || c == '-')
		return 2;
	else if (c == ')')
		return 1;
	else if (c == '(')
		return 0;
}

std::string infx2pstfx(std::string inf)
{
	std::stack<char> st;
	st.push('N');
	int l = inf.length();
	string ns;

	for (int i = 0; i < l; i++)
	{
		if ((inf[i] >= 'a' && inf[i] <= 'z') || (inf[i] >= 'A' && inf[i] <= 'Z'))
			ns += inf[i];

		else if (inf[i] == '(')
				st.push('(');
 
		else if (inf[i] == ')')
		{
			while (st.top() != 'N' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}
		else{
			while (st.top() != 'N' && preori(inf[i]) <= preori(st.top()))
			{
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(inf[i]);
		}

	}
	while (st.top() != 'N')
	{
		char c = st.top();
		st.pop();
		ns += c;
	}
	return ns;
}

int excute_calc(int k1, int k2, char pst)
{
	switch (pst)
	{
	case '+': return k1 + k2;
	case '-': return k1 - k2;
	case '*': return k1 * k2;
	case '/': return k1 / k2;
	default: return -1;
	}
}


int eval(string pst)
{
	TStack<int> stack2;
	for (int i = 0; i < pst.size(); i++)
	{
		char ch = pst[i];
		int priority = preori(ch);

		if (priority == -1)
			stack2.push(ch - 48);
		else
		{
			int  k1 = stack2.get();
			stack2.pop();

			int k2 = stack2.get();
			stack2.pop();

		}
		int res = excute_calc(k2, k1, ch);
		stack2.push(res);
	}
	return stack2.get();
}
