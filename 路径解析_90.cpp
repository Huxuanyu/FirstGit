#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int index;//指向数组下标
	string str_in,str_now;
	int p;
	cin>>p;
	cin>>str_now;
	for(int i=1; i<=p; i++)
	{
		cin>>str_in;
		if(str_in[0]!='/')
		{
			str_in = str_now + "/" + str_in + "/";
		}
		while((index = str_in.find("//")) != -1)
		{
			int count = 2;
			while(str_in[index + count] == '/')
				count++;
			str_in.erase(index, count-1);
		}
		if(str_in.size() > 1 && str_in[str_in.size() - 1] == '/')
		{
			str_in.erase(str_in.size() - 1);
		}
		while((index = str_in.find("/./"))!=-1)
		{
			str_in.erase(index+1,2);
		}
		
		while((index = str_in.find("/../")) != -1)
		{
			if(index == 0)	str_in.erase(index, 3);
			else
			{
				int index_temp;
				index_temp = str_in.rfind("/", index - 1);
				str_in.erase(index_temp, index - index_temp + 3);
			}

			if(str_in.size() == 0)	str_in = "/";
		}
		cout<<str_in<<endl;
	}
	return 0;
}
//	if(str_now.length()>=3) strfir = str_now.substr(str_now.length()-6,str_now.length()-4);
//	else strfir = "/";
//	Load no,input,yes;
//	string str_yes="";
//index = 0;
//		end = str_in.length();
//		while(index < end)
//		{
//			if(str_in[index] == '.')
//			{
//				if(str_in[index+1] == '.')
//				{
//				}
//
//			}
//			else if(str_in[index] == '/')
//			{
//
//			}
//		}
