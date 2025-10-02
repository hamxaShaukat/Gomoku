#include<iostream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<time.h>
using namespace std;

#define rows 80
#define cols 120
int Turn;

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}


void init(char Board[][cols], char Pname[][cols], int& turn, int& Dim, int& winCount)
{

	cout << "Enter the win count: ";
	cin >> winCount;
	cout << "Enter the Dimensions (0.......19): ";
	cin >> Dim;
	for (int r = 0; r < Dim; r++)
	{
		for (int c = 0; c < Dim; c++)
		{
			Board[r][c] = '-';
		}
		cout << endl;
	}

	for (int n = 0; n < 2; n++)
	{
		cout << "Enter (" << n + 1 << ")'s Name: ";
		cin >> Pname[n];
	}


	turn = rand() % 2;

}
void init1(char Board[][cols], int& turn, int& Dim, int& winCount)
{

	cout << "Enter the win count: ";
	cin >> winCount;
	cout << "Enter the Dimensions (0.......19): ";
	cin >> Dim;
	for (int r = 0; r < Dim; r++)
	{
		for (int c = 0; c < Dim; c++)
		{
			Board[r][c] = '-';
		}
		cout << endl;
	}
	turn = rand() % 2;
}

void print_Board(char Board[][cols], int Dim)
{
	for (int r = 0; r < Dim; r++)
	{
		for (int c = 0; c < Dim; c++)
		{
			cout << setw(3) << Board[r][c];
		}
		cout << endl;
	}
}

void Trn_msg(string name, char sym)
{

	cout << "\n character " << sym << "'s turn whose name is " << name << endl;
}

void select_Pos(int& pr, int& pc)
{
	cout << "Enter the choice (1......3)";
	cin >> pr >> pc;
	pr--;
	pc--;
}

bool is_valid(char Board[][cols], int pr, int pc, int dim)
{
	return (pr >= 0 && pc >= 0) && (pr < dim&& pc < dim) && (Board[pr][pc] == '-');
}

void place_move(char Board[][cols], int pr, int pc, char sym)
{
	Board[pr][pc] = sym;
}
void update(char Board[][cols], int pr, int pc, char sym)
{
	Board[pr][pc] = sym;
}

void T_C(int& Turn)
{
	Turn = (Turn + 1) % 2;

}

bool Search_hor(char B[][cols], int dim, char sym, int winCount)
{
	for (int r = 0; r < dim; r++)
	{
		int count = 0;
		for (int c = 0; c < dim; c++)
		{
			if (B[c][r] == sym)
			{
				count++;
			}
			if (count == winCount)
			{
				return true;
			}

		}
	}
	return false;
}
bool Search_ver(char B[][cols], int dim, char sym, int winCount)
{
	int count = 0;
	for (int c = 0; c < dim; c++)
	{
		count = 0;
		for (int r = 0; r < dim; r++)
		{
			if (B[c][r] == sym)
			{
				count++;
			}
			if (count == winCount)
			{
				return true;
			}

		}
	}
	return false;
}

bool Search_dia(char B[][cols], int dim, char sym, int winCount)
{
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			int count = 0;
			for (int i = 0; i < dim; i++)
			{
				if (B[r + i][c + i] == sym)
				{
					count++;
				}
			}
			if (count == winCount)
			{
				return true;
			}

		}
	}
	return false;
}

bool Search_Rdia(char B[][cols], int dim, char sym, int winCount)
{
	for (int r = 0; r < dim; r++)
	{
		for (int c = dim; c >= 0; c--)
		{
			int count = 0;
			for (int i = 0; i < dim; i++)
			{
				if (B[r + i][c - i] == sym)
				{
					count++;
				}
			}
			if (count == winCount)
			{
				return true;
			}

		}
	}
	return false;
}

bool is_win(char B[][cols], int dim, char sym, int winCount)
{
	if ((Search_hor(B, dim, sym, winCount) == true) || (Search_ver(B, dim, sym, winCount) == true) || (Search_dia(B, dim, sym, winCount) == true) || (Search_Rdia(B, dim, sym, winCount) == true))
	{
		return true;
	}
	return false;
}

bool is_draw(char B[][cols], int dim, char sym)
{
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			if (B[r][c] == '-')
			{
				return false;
			}
		}
	}
	return true;
}




int main1()
{
	srand(time(0));
	char B[cols][cols];
	int Dim, pr, pc, Turn, winCount;
	char sym[2] = { '/','X' }, pNam[2][cols];

	init(B, pNam, Turn, Dim, winCount);
	do
	{

		system("cls");
		print_Board(B, Dim);

		Trn_msg(pNam[Turn], sym[Turn]);
		do
		{
			select_Pos(pr, pc);
		} while (is_valid(B, pr, pc, Dim) == false);
		place_move(B, pr, pc, sym[Turn]);
		T_C(Turn);
		if ((is_win(B, Dim, sym[Turn], winCount) == true) || (is_draw(B, Dim, sym[Turn]) == true))
		{

			break;
		}
	} while (true);

	if (is_win(B, Dim, sym[Turn], winCount) == true)
	{
		cout << "Player......... " << pNam[Turn] << "   .......Has won the game.......";
	}
	else
	{
		cout << "Game is drwan";
	}
	return 0;
}


void comp_block(char B[][cols], char sym[],int &pr,int &pc, int dim, int Turn, int win)
{
	for (int W = win; W > 0; W--)
	{
		for (int r = 0; r < dim; r++)
		{
			for (int c = 0; c < dim; c++)
			{
				pr = r;
				pc = c;
				if (is_valid(B, pr, pc, dim) == true)
				{
					B[r][c] = sym[Turn];

					if (is_win(B, dim, sym[Turn], W) == true)
					{
						B[r][c] = '-';
						return;
					}
					B[r][c] = '-';
				}
			}
		}
		for (int r = 0; r < dim; r++)
		{
			for (int c = 0; c < dim; c++)
			{
				pr = r;
				pc = c;
				if (is_valid(B, pr, pc, dim) == true)
				{
					B[r][c] = sym[Turn + 1];

					if (is_win(B, dim, sym[Turn + 1], W) == true)
					{
						B[r][c] = '-';
						return;
					}
					B[r][c] = '-';
				}
			}
		}
	}
	do
	{
		pr = rand() % dim;
		pc = rand() % dim;
	} while (is_valid(B,pr,pc,dim)==false);
}




int main2()
{

	srand(time(0));
	char B[cols][cols];
	int Dim, pr, pc, Turn, winCount;
	char sym[2] = { '/','X' };
	string pNam[2] = { "User","Bot"};

	init1(B, Turn, Dim, winCount);
	do
	{
		if (Turn == 1)
		{
			system("cls");
			print_Board(B, Dim);

			Trn_msg(pNam[Turn], sym[Turn]);
			comp_block(B, sym,pr,pc, Dim, Turn, winCount);

			place_move(B, pr, pc, sym[Turn]);
			T_C(Turn);
		}
		else
		{


			system("cls");
			print_Board(B, Dim);

			Trn_msg(pNam[Turn], sym[Turn]);
			do
			{
				select_Pos(pr, pc);
			} while (is_valid(B, pr, pc, Dim) == false);
			place_move(B, pr, pc, sym[Turn]);
			T_C(Turn);
		}
		if ((is_win(B, Dim, sym[Turn], winCount) == true) || (is_draw(B, Dim, sym[Turn]) == true))
		{

			break;
		}
	} while (true);

	if (is_win(B, Dim, sym[Turn], winCount) == true)
	{
		cout << "Player......... " << pNam[Turn] << "   .......Has won the game.......";
	}
	else
	{
		cout << "Game is drwan";
	}

}




int main()
{
	int Q;
	cout << "Enter 1 to check Human vs Human: "<<endl<<endl;
	cout << "Enter 2 to check Bot vs Human: " << endl << endl;

	cout << "Enter the Question number: ";
	cin >> Q;

	switch (Q)
	{
	case(1):
		main1();
		break;
	case(2):
		main2();
		break;
	default:
		cout << "Wrong input............";
		break;
	}

}
