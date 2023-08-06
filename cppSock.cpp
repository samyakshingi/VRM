#include<iostream>
#include<stdio.h>
#include<WinSock2.h>
#include<Windows.h>
#include<sstream>
#include<string>
#include<mmsystem.h>

//#define SCK_VERSION 0x0202

using namespace std;

void Navigation();
void Fuel();
void Fire();
void Alarm();
void Code_Red();
void General();
void Radar();
void Eject(); 
void Radio(); 
void Land();

int main()
{
	SOCKET sock;
    SOCKADDR_IN address;
	
	long ok;
	char MESSAGE[200];
	int r=-1;
	WSAData WSD;
	WORD DllVersion;
	DllVersion = MAKEWORD(2,1);
	ok = WSAStartup(DllVersion,&WSD);
	
	while(r!=0)
	{
		sock = socket(AF_INET, SOCK_STREAM,0);
		
		address.sin_addr.s_addr = inet_addr("127.0.0.1");
		address.sin_family = AF_INET;
		address.sin_port = htons(9999);
		
		r = connect(sock, (SOCKADDR*)&address, sizeof(address));
		cout<<"Connection Successful";
	}	
		while (true)
		{
			ok = recv(sock, MESSAGE, sizeof(MESSAGE),0);
			string reply;
			reply = MESSAGE;
			string fin = reply.substr(0,ok);
			cout<<fin<<endl;

			if(fin=="navigation")
			{
				Navigation();
			}
			else if(fin=="fuel")
			{
				Fuel();
			}
			else if(fin=="fire")
			{
				Fire();
			}
			else if(fin=="alarm")
			{
				Alarm();
			}
			// else if(fin=="code red")
			// {
			// 	Code_Red();
				
			// }
			else if(fin=="general")
			{
				General();
			}
			else if(fin=="radar")
			{
				Radar();
			}
			else if(fin=="eject")
			{
				Eject();
			}
			else if(fin=="radio")
			{
				Radio();
			}
			else if(fin=="land")
			{
				Land();
			}
			else
			{
				cout<<"Function not Available\n";
			}
		}
	return 0;
}

void Navigation()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Navigation\\for_testing\\Navigation.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Fuel()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\FUEL\\for_testing\\FUEL.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Fire()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Fire\\Fire\\for_testing\\Fire.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Alarm()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Alarm\\for_testing\\Alarm.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
// void Code_Red()
// {
// 	STARTUPINFO startInfo={0};
// 	PROCESS_INFORMATION processInfo={0};
// 	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Matlab\\Navigation\\Navigation for_redistribution_files_only\\Navigation.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
// }
void General()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\General\\for_testing\\General.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);

}
void Radar()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Radar\\for_testing\\Radar.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Eject()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Eject\\for_testing\\Eject.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Radio()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Radio\\for_testing\\Radio.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}
void Land()
{
	STARTUPINFO startInfo={0};
	PROCESS_INFORMATION processInfo={0};
	CreateProcess(TEXT("C:\\Users\\samya\\Documents\\HALProject\\Working_files\\MatApp\\Landing\\for_testing\\Landing.exe"),NULL,NULL,NULL,FALSE,NORMAL_PRIORITY_CLASS,NULL,NULL,&startInfo,&processInfo);
}