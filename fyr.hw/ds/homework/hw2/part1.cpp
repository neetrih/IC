#include"../../Vector/stack.h"
#include<cctype>
#include<string>
#include<cstdlib>
#include<cstring>
#define N_OPTR 9 
typedef enum
{
	AD,
	SB,
	ML,
	DV,
	PW,
	FC,
	LP,
	RP,
	EE
} Operator;
Operator optr2rank(char op)
{ 
	switch (op)
{
case '+':

	return AD; // 加
case '-':
	return SB; // 减
case '*':
	return ML; // 乘
case '/':
	return DV; // 除
case '^':
	return PW; // 乘幂
case '!':
	return FC; // 阶乘
case '(':
	return LP; // 左括号
case ')':
	return RP; // 右括号
case '\0':
	return EE; // 起始符与终止符
default:
	exit(-1); // 未知运算符
}
}
char orderBetween(char a, char b)
{
	const char pri[N_OPTR][N_OPTR] = {
		// 运算符优先等级 [栈顶] [弼前]
		/* |-------------------- 当 前 运 算 符 --------------------| */
		/* + - * / ^    !     (     )   \0 */
		/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/* | - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
		/* 栈 * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 顶 / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
		/* 运 ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
		/* 算 ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
		/* 符 ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
		/* | ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		/* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='};
	return pri[optr2rank(a)][optr2rank(b)];
}

void ap(char *&rpn, float opnd)
{
	int n = strlen(rpn);
	char buf[64];
	if (opnd != (float)(int)opnd)
		sprintf(buf, "%.2f \0", opnd);
			else
				sprintf(buf, "%d \0", (int)opnd);
					rpn = (char *)realloc(rpn, sizeof(char) * (n + strlen(buf) + 1));
					strcat(rpn, buf);
}

void ap(char *&rpn, char optr)
{
	int n = strlen(rpn);
	rpn = (char *)realloc(rpn, sizeof(char) * (n + 3));
	sprintf(rpn + n, "%c ", optr);
	rpn[n + 2] = '\0';
}

void readNumber(char *&p, Stack<float> &stk)
{
	stk.push((float)(*p - '0'));
	while (isdigit(*(++p)))
		stk.push(stk.pop() * 10 + (*p - '0'));
	if ('.' != *p)
		return;
	float fraction = 1;
	while (isdigit(*(++p)))
		stk.push(stk.pop() + (*p - '0') * (fraction /= 10));
}
float calculate(char op, float a)
{
	if (floor(a) == a)
		if (a == 0)
			return 1.0;
	else
	{
		float b = 1.0;
		for (float i = 1.0; i <= a; i++)
		{
			b *= i;
		}
		return b;
	}
	else
	{
		cout << "非整数无法阶乘" << endl;
		exit(-1);
	}
}

float calculate(float a, char op, float b)
{
	switch (op)
{
case '+':
	return a + b;
case '-':
	return a - b;
case '*':
	return a * b;
case '/':
	if (b == 0)
	{
		cout << "ERROR:除数为0" << endl;
		exit(-1);
	}
	return a / b;
case '%':
	if ((int)b == 0)
	{
		cout << "ERROR:除数为0" << endl;
		exit(-1);
	}
	return (int)a % (int)b;
case '^':
	return pow(a, b);
case'=':
	cout<<"不要在末尾加="<<endl;
default:
	cout << "未知运算符" << endl;
	exit(-1);
}
}

float evaluate(char *S, char *&RPN)//4.7原码
{
	Stack<float> opnd;
	Stack<char> optr;
	optr.push('\0');
	while (!optr.empty())
	{
		if (isdigit(*S))
		{
			readNumber(S, opnd);
			ap(RPN, opnd.top());
		}
		else
			switch (orderBetween(optr.top(), *S))
		{
		case '<':
			optr.push(*S);
			S++;
			break;
		case '=':
			optr.pop();
			S++;
			break;
		case '>':
{
	char op = optr.pop();
	ap(RPN, op);
	if (op == '!')
	{
		float pOpnd = opnd.pop();
		opnd.push(calculate(op, pOpnd));
	}
	else
	{
		float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop();
		opnd.push(calculate(pOpnd1, op, pOpnd2));
	}
	break;
}
		default:
			exit(-1);
		}
	}
	return opnd.pop();
}

int main()
{
	int i=1;
	while(i!=0)
	{
	cout << "输入表达式[不用输入=]" << endl;
	char input[64]	
	,*RPN = new char[64];
	cin >> input;
	cout << "表达式的结果是"<<evaluate(input, RPN) << endl;
		cout<<"是否需要再次计算,是输入1，不是输入0"<<endl;
		cin>>i;
		
		
	
	delete[] RPN;
	}
	return 0;
}
