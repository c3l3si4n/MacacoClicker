// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <atlstr.h>
#include <intrin.h>       
#include <iphlpapi.h>
#include <cstdint>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <WinSock.h>
#include <functional>
#include <windows.h>
#include <boost/functional/hash.hpp>
#include <rpcdce.h>
#include <mysql.h>
#pragma comment(lib, "wsock32.lib")
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "Rpcrt4.lib")
#pragma comment(lib, "libmysql.lib")
std::string nigga;
std::string  hahaha;

// Fetches the MAC address and prints it

std::string ToStr(char c) {
	return std::string(1, c);
}

void toClipboard(const std::string &s) {
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size()+1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}

char
remap(int original)
{
	static char const remap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return original >= 0 && original < sizeof(remap) - 1
		? remap[original]
		: '?';   // or throw, or ...
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main()
{

	setlocale(LC_ALL, "Portuguese");
	UCHAR MACData[6];


	
	
	 DWORD DriveSerial;
	 long long nigga2;
	 
	 std::string username;
	 std::cout << ("username: " );
	 std::cin >> (username);
	 
	 long long hwidsemi2;
	 HW_PROFILE_INFO hwProfileInfo;
	 


	 long long hwidsemi;
	 std::string hwidfinal;
	 std::string queryhwid;
	

	nigga2 = atoi(nigga.c_str());
//CÓDIGO DO HWID ESTAVA AQUI
//CÓDIGO DO HWID ESTAVA AQUI
//CÓDIGO DO HWID ESTAVA AQUI
//CÓDIGO DO HWID ESTAVA AQUI
//CÓDIGO DO HWID ESTAVA AQUI


	queryhwid = std::to_string(hwidsemi2);
	
	
	//mysql

	MYSQL *mysql = NULL;

	mysql = mysql_init(mysql);

	if (!mysql) {
		puts("Init faild, out of memory?");
		return EXIT_FAILURE;
	}

	if (!mysql_real_connect(mysql,       /* MYSQL structure to use */
		"HOSTNAME",         /* server hostname or IP address */
		"USER",         /* mysql user */
		"PASS",          /* password */
		"DB",               /* default database to use, NULL for none */
		PORT,           /* port number, 0 for default */
		NULL,        /* socket file or named pipe name */
		CLIENT_FOUND_ROWS /* connection flags */)) {
		puts("Connect failed\n");
	}

	MYSQL_RES* res;
	int num_fields;
	std::string query = std::string("SELECT * FROM loader WHERE name='") + username + std::string("' AND hwid='") + queryhwid + ("';");
	char charquery[100];
	strcpy(charquery, query.c_str());


	if (mysql_query(mysql, charquery))
	{
		finish_with_error(mysql);
	}

	MYSQL_RES *result = mysql_store_result(mysql);

	if (result == NULL)
	{
		finish_with_error(mysql);
	}

	MYSQL_ROW row;
	MYSQL_FIELD *field;

	if (row = mysql_fetch_row(result))
	{
		
		std::cout << "bro tu pagou o cheat ai sim 777!"<< std::endl << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << std::endl << "Seu HWID é: " << queryhwid << std::endl;
		std::cout << "HWID copiado para o clipboard.";
		std::cout << "bro tu não comproou o xit" << std::endl;
		toClipboard(queryhwid);
	}

	mysql_close(mysql);
	
	system("pause");
}

