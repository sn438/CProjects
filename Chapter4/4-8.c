#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define SIN '@'
#define POW '$'
#define EXP '#'
#define LETTER '^'
#define VARIABLE '('
#define ANS ')'
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void printpop(void);
void duplicatetop(void);
void swaptop(void);
void clearstack(void);
void unget(char []);

int variablelist[27]; //holds all variable values
/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {	
			case NUMBER:
				push(atof(s));
				break;
			case LETTER:
				if(s[0] >= 'A' && s[0] <= 'Z')
					push(variablelist[s[0] - 'A']);
				else
					printf("error: variable not found\n");
				break;
			case VARIABLE:
				if(s[0] >= 'A' && s[0] <= 'Z')
					variablelist[s[0] - 'A'] = pop();
				else
					printf("error: variable not found\n");
				break;
			case ANS:
				push(variablelist[27]);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push((int) pop() % (int) op2);
				else
					printf("error: mod 0 error\n");
				break;
			case SIN:
				push(sin(pop()));
				break;
			case POW:
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case '\n':
				op2 = pop(); //op2 is only being used to hold temporary value
				printf("\t%.8g\n", op2);
				variablelist[27] = op2;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can’t push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
/* printpop: prints the top value of the stack without popping*/
void printpop(void) {
	if(sp > 0)
		printf("%s: %f", "Top element of stack", val[sp - 1]);
	else
		printf("There is nothing in the stack");
}
/* duplicatetop: duplicates the top element of the stack*/
void duplicatetop(void) {
	push(val[sp - 1]);
}
/*swaptop: swap the top two elements of the stack*/
void swaptop(void) {
	int first = val[sp - 1];
	int second = val[sp - 2];
	push(first);
	push(second);
}
/*clearstack: clears the stack*/
void clearstack(void){
	sp = 0;
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c, temp;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	// variable
	if (c >= 'A' && c <= 'Z'){	
		if ((temp = getch()) == ' '){	
			while((temp = getch()) == ' ' || temp == '\t')
				;
			if (temp == '='){
				while((c = getch()) != '\n'); // need to do this because otherwise the \n command while cause the program to try to print the stack	
				return VARIABLE;
			}
			else {
				ungetch(temp);
				return LETTER;
			}
		} else {
			ungetch(temp);
		}
	}

	// SIN
	if (c == 's'){
		if ((c = getch()) == 'i'){
			if((c = getch()) == 'n'){
				return SIN;
			}
			else {
				ungetch(c);
				ungetch('i');
				c = 's';
			}	
		}
		else {
			ungetch(c);
			c = 's';
		}
	}
	//POW	
	if (c == 'p'){
		if ((c = getch()) == 'o'){
			if((c = getch()) == 'w'){
				return POW;
			}
			else {
				ungetch(c);
				ungetch('o');
				c = 'p';
			}	
		}
		else {
			ungetch(c);
			c = 'p';
		}
	}

	//EX
	if (c == 'e'){
		if ((c = getch()) == 'x'){
			if((c = getch()) == 'p'){
				return EXP;
			}
			else {
				ungetch(c);
				ungetch('x');
				c = 'e';
			}	
		}
		else {
			ungetch(c);
			c = 'e';
		}
	}

	//ANS
	if (c == 'A'){
		if ((c = getch()) == 'N'){
			if((c = getch()) == 'S'){
				return ANS;
			}
			else {
				ungetch(c);
				ungetch('N');
				c = 'A';
			}	
		}
		else {
			ungetch(c);
			c = 'A';
		}
	}

	//negative number
	if (c == '-'){
		if (isdigit(c = getch())){
			ungetch(c);
			s[0] = '-';
			i = 0;
			if (isdigit(c)) /* collect integer part */
				while (isdigit(s[++i] = c = getch()))
					;
			if (c == '.') /* collect fraction part */
				while (isdigit(s[++i] = c = getch()))
					;
			s[i] = '\0';
			if (c != EOF)
				ungetch(c);
			return NUMBER;
		}
		else{
			ungetch(c);
			c = '-';
		}
	}
	if (!isdigit(c) && c != '.')
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

char buffer = 0; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	if (buffer >  0) {
    		int temp = buffer;
    		buffer = 0;
		return temp;
  	} else {
    		return  getchar();
  	}
}
void ungetch(int c) /* push character back on input */
{
	buffer = (char) c;
}

void unget(char s[]){
	int i = 0;
	while(bufp < BUFSIZE && s[i] != '\0'){
		ungetch(s[i++]);
	}
	if (bufp < BUFSIZE)
		ungetch('\0');
}
