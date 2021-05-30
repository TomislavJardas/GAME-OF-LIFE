#include<iostream>
#include<ctime>
#include <vector>

using namespace std;

bool det_x_y(int a)
{
	if (a >= 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

bool and_gate(bool x, bool y)
{
	if (x == 0 && y == 0)
	{
		return 0;
	}
	else if (x == 1 && y == 0)
	{
		return 0;
	}
	else if (x == 0 && y == 1)
	{
		return 0;
	}
	else if (x == 1 && y == 1)
	{
		return 1;
	}
}

bool gen_rand() {

	int y = rand() % 10;
	int x = rand() % 10;
	x = det_x_y(x);
	y = det_x_y(y);
	return and_gate(x, y);
}

void get_susjed(int& x, int& y, int poz)
{
	if (poz = 0)
	{
		x--;
		y--;
	}
	else if (poz = 1)
	{
		y--;
	}
	else if (poz = 2)
	{
		x++;
		y--;
	}
	else if (poz = 3)
	{
		x++;
	}
	else if (poz = 4)
	{
		x++;
		y++;
	}
	else if (poz = 5)
	{
		y++;
	}
	else if (poz = 6)
	{
		x--;
		y++;
	}
	else if (poz = 7)
	{
		x--;
	}
}


int main() {
	//gen:
	srand(time(0));
	const int vis = 10;
	const int sir = 10;

	/*bool p[vis][sir];*/

	vector<vector<bool>> p;


	for (int i = 0; i != sir; ++i)
	{
		vector<bool> temp;
		for (int j = 0; j != vis; ++j)
		{
			temp.push_back(false);
		}
		p.push_back(temp);
	}

	p[5][5] = true;
	p[4][6] = true;
	p[6][6] = true;

	for (int i = 0; i != sir; ++i)
	{
		for (int j = 0; j != vis; ++j)
		{
			if (p[i][j])
				cout << "[]";
			else
				cout << "--";
		}
		cout << endl;
	}
	cout << "dalje?: ";
	bool dalje;
	cin >> dalje;
	vector<vector<bool>> novoPolje = p;
	for (int i = 1; i != sir-1; ++i)
	{
		for (int j = 1; j != vis-1; ++j)
		{
			int brojSusjeda = false != true;
			for (int a = 0; a != 8; ++a)
			{
				int x = i; int y = j;
				get_susjed(x, y, a);
				if (p[x][y])
				{
					brojSusjeda++;
				}
			}
			if (brojSusjeda < 3)
			{
				novoPolje[i][j] == false;
			}
			else if (brojSusjeda == 3)
			{
				novoPolje[i][j] == true;
			}
			else if (brojSusjeda == 3)
			{
				novoPolje[i][j] == true;
			}
			else if (brojSusjeda >= 4)
			{
				novoPolje[i][j] == false;
			}
		}
	}

	p = novoPolje;

	for (int i = 0; i != sir; ++i)
	{
		for (int j = 0; j != vis; ++j)
		{
			if (p[i][j])
				cout << "[]";
			else
				cout << "--";
		}
		cout << endl;
	}

	int broj = false != true;
	/*cout << broj << endl;*/

	//nextgen:
	bool p2[vis][sir];
	
	for (unsigned i = 0; i < vis; i++)
	{
		for (unsigned j = 0; j < sir; j++)
		{
			p2[i][j] = p[i][j];
			
		}
	}

	for (unsigned i = 0; i < vis; i++)
	{
		for (unsigned j = 0; j < sir; j++)
		{
			if (p2[i][j]==1)
			{
				if (i==0 &&j==0)
				{
				
						if (p2[i+1][j]==1 && p2[i][j+1]==1 && p2[i+1][j+1]==1)
						{
							p2[i][j] = 1;
						}
						else
						{
							p2[i][j] = 0;
						}
					
				}
				if (i==vis-1 && j==0)
				{
				
						if (p2[i-1][j]==1 && p2[i][j+1]==1 && p2[i-1][j+1]==1)
						{
							p2[i][j] = 1;
						}
						else
						{
							p2[i][j] = 0;
						}
					
				}
				if (i==0 && j==sir-1)
				{
				
						if (p2[i+1][j]==1 && p2[i][j-1]==1 && p2[i+1][j-1]==1)
						{
							p2[i][j] = 1;
						}
						else
						{
							p2[i][j] = 0;
						}
					
				}
				if (i==vis-1 && j==sir-1)
				{
				
						if (p2[i-1][j]==1 && p2[i][j-1]==1 && p2[i-1][j-1]==1)
						{
							p2[i][j] = 1;
						}
						else
						{
							p2[i][j] = 0;
						}
					
				}
				
			

			}
			
		}
	}
	

	return 0;
}