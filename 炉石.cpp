#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Card
{
	int position;
	int health;
	int attack;
	//Card(int _position,int _health,int _attack):position(_position),health(_health),attack(_attack){}
	bool operator < (const Card &other) const
	{
		if (position < other.position) return true;
		else return false;
	}
};

void print(vector<Card>& lt) {  
    for(vector<Card>::iterator it = lt.begin(); it != lt.end(); it++) {  
        if(it == lt.begin()) {  
            cout << it->health << endl;  
            cout << lt.size() - 1;  
        } else cout << " " << it->health;  
    }  
}  

int main()
{
	string str[] = { "summon","attack","end" };
	string input;
	Card card_temp;
	vector<Card> play1;
	vector<Card> play2;
	Card cardt;
	cardt.position = cardt.attack = 0;
	cardt.health = 30;
	play1.push_back(cardt);
	play2.push_back(cardt);
	bool task; //ÅÐ¶ÏÊÇ·ñ²åÈëÖÐ¼ä
	int n, jud = 0, player = 1; // judÅÐ¶ÏÊ¤¸º
	int att, def; //¹¥»÷¡¢±»¹¥»÷
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		task = false;
		cin >> input;
		if(jud == 0)
		{
			if (input == str[0])
			{
				cin >> card_temp.position >> card_temp.attack >> card_temp.health;
				if (player == 1)
				{
					for (int k = 0; k<play1.size(); k++)
					{
						if (card_temp.position == play1[k].position)
						{
							play1.insert(play1.begin() + k, card_temp);
							for (int j = k; j<play1.size(); j++)
								play1[j].position++;
							task = true;
							break;
						}
					}
					if (!task)	play1.push_back(card_temp);
				}
				else if (player == 2)
				{
					for (int k = 0; k<play2.size(); k++)
					{
						if (card_temp.position == play2[k].position)
						{
							play2.insert(play2.begin() + k, card_temp);
							for (int j = k; j<play2.size(); j++)
								play2[j].position++;
							task = true;
							break;
						}
					}
					if (!task)	play2.push_back(card_temp);
				}
			}
			else if (input == str[1])
			{
				cin >> att >> def;
				if (player == 1)
				{
					play2[def].health = play2[def].health - play1[att].attack;
					play1[att].health = play1[att].health - play2[def].attack;
					if (play2[def].health <= 0)
					{
						if (def == 0 && jud == 0) jud = 1;
						else
						{
							vector<Card>::iterator it = play2.begin() + def;
							play2.erase(it);
							for (int i = def; i<play2.size(); i++)
							{
								play2[i].position--;
							}
						}
					}
					if (play1[att].health <= 0)
					{
						if (def == 0 && jud == 0) jud = -1;
						else
						{
							vector<Card>::iterator it = play1.begin() + att;
							play1.erase(it);
							for (int k = att; k<play1.size(); k++)
							{
								play1[k].position--;
							}
						}
					}
				}
				else if (player == 2)
				{
					play1[def].health = play1[def].health - play2[att].attack;
					play2[att].health = play2[att].health - play1[def].attack;
					if (play1[def].health <= 0)
					{
						if (def == 0)
						{
							if (jud == 0)	jud = -1;
						}
						else
						{
							vector<Card>::iterator it = play1.begin() + def;
							play1.erase(it);
							for (int k = def; k<play1.size(); k++)
							{
								play1[k].position--;
							}
						}
					}
					if (play2[att].health <= 0)
					{
						if (att == 0)
						{
							if (jud == 0)	jud = 1;
						}
						else
						{
							vector<Card>::iterator it = play2.begin() + att;
							play2.erase(it);
							for (int i = att; i<play2.size(); i++)
							{
								play2[i].position--;
							}
						}
					}
				}
			}
			else if (input == str[2])
			{
				if (player == 1)	player = 2;
				else if (player == 2) player = 1;
			}
		}
		else break;
	}
	cout << jud << endl;
	print(play1);  
    cout << endl;  
    print(play2);	
	return 0;
}
	/*
	cout << play1[0].health << endl;
	cout << play1.size() - 1;
	for (int j = 1; j<play1.size(); j++)
	{
		cout << " " << play1[j].health;
	}
	cout << endl;
	cout << play2[0].health << endl;
	cout << play2.size() - 1;
	for (int j = 1; j<play2.size(); j++)
	{
		cout << " " << play2[j].health;
	}*/

