//The source code, follow the WTFPL license.
//Copyright ⓒ 2016 박재일 <b3496789@gmail.com>

#pragma warning(disable:4996)

//#define UNICODE
//#define _UNICODE
#define Last_ver "1.0"


#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
#include <atlstr.h>
#include <time.h>
#include <iomanip>

/*
#include <iomanip>
#include <time.h>
#include <cmath>
#include <string>
*/

using namespace std;

typedef BOOL(WINAPI *P_GDFSE)(LPCTSTR, PULARGE_INTEGER, PULARGE_INTEGER, PULARGE_INTEGER);
//void backup();

//language functions
void Lang_ENG();
void Lang_KOR();
void Lang_JPN();
void Lang_CHI();

//feature funtions
void func_logical_diskinfo();
void func_logical_diskinfo_KOR();
void func_logical_diskinfo_JPN();
void func_logical_diskinfo_CHI();

void func_physical_diskinfo();
void func_physical_diskinfo_KOR();
void func_physical_diskinfo_JPN();
void func_physical_diskinfo_CHI();

void func_physical_disk_overwrite();
void func_logical_disk_overwrite();


int lang_select = 1;   //1=ENG, 2=KOR, 3=JPN(not supported this time.)

int main(int argc, char* argv[])   //argc, argv exists for a later command argument, so do not delete this shit.
{
	//This is main function, do not add features here!
	//If u want to add a features, use the function!
	//If u wish to update ur code, then annotating the source code and change the date and time and what features have been added to the code in detail whether the record please!
	//And... just fuck it.
	//Developer: 박재일
	//Last update: 2016.08.02(yyyy.mm.dd) - if u updated this shit, edit here.
	//Last version: 1.0

	cout << "                    _                                      " << endl;
	cout << "                  -=\\`\\                                    " << endl;
	cout << "              |\\ ____\\_\\__                                 " << endl;
	cout << "            -=\\c`\"\"\"\"\"\"\" \"`)                               " << endl;
	cout << "               `~~~~~/ /~~`\                                " << endl;
	cout << "                 -==/ /                                    " << endl;
	cout << "                   '-'                                     " << endl;
	cout << "                  _  _                                     " << endl;
	cout << "                 ( `   )_                                  " << endl;
	cout << "                (    )    `)                               " << endl;
	cout << "              (_   (_ .  _) _)                             " << endl;
	cout << "                                             _             " << endl;
	cout << "                                            (  )           " << endl;
	cout << "             _ .                         ( `  ) . )        " << endl;
	cout << "           (  _ )_                      (_, _(  ,_)_)      " << endl;
	cout << "         (_  _(_ ,)                                        " << endl;

	cout << endl << endl;
	cout << "WELCOME TO ANTI FORENSIC WORLD!" << endl;

	for (int fcnt = 3; fcnt >= 1; fcnt--)
	{
		Sleep(1000);
		cout << "\r" << "Wait " << fcnt << " Sec" << endl << flush;
		cout.flush();
	}
	system("cls");

	cout << "ENG: Start the initial setting." << endl;
	cout << "KOR: 초기 설정을 시작 합니다." << endl;
	cout << "CHI: 初始化?始." << endl;
	cout << endl;
	cout << "** Default language is English" << endl << endl;
	cout << "     1. English" << endl;
	cout << "     2. Korean(한국어)" << endl;
	cout << "     3. Japanese(一本語)" << endl;
	cout << "     4. Chinese (中國語) " << endl;
	cout << endl;
	cout << "** If you enter anything it will be entered as the default setting." << endl << endl;
	cout << "put> ";

	cin >> lang_select;

	if (lang_select == 1)
	{
		Lang_ENG();
	}
	else if (lang_select == 2)
	{
		Lang_KOR();
	}
	else if (lang_select == 3)
	{
		Lang_JPN();
	}
	else if (lang_select == 4)
	{
		Lang_CHI();
	}
	else if (lang_select == 5)
	{
		cout << "Sorry dude, this is a not supported language :(" << endl;
	}

	else
	{
		cout << "What the fuck r u doing?" << endl;
		exit(0);
	}
}



//void backup()
//{
//   char orig[_MAX_PATH];
//   char back[_MAX_PATH];
//   
//   cout<<"Original Directory: ";
//   //scanf_s("%s",orig,sizeof(250));
//   cin>>orig;
//   cout<<"input data: "<<orig<<endl;
//   //fflush(stdin);
//   cout<<"Backup Directory: ";
//   cin>>back;
//   //scanf_s("%s",back,sizeof(250));
//   cout<<"input data: "<<back<<endl;
//


void Lang_ENG()
{
	system("cls");
	cout << "Welcome to AFSS Ver " << Last_ver << endl << endl;
	cout << "--MENU" << endl;
	cout << "  1. Get physical disk information" << endl;
	cout << "  2. Get logical disk information" << endl;
	cout << "  3. Disk all wiping" << endl;
	cout << "  4. Logical disk wping" << endl;

	cout << "put> ";

	int select_menu = NULL;
	cin >> select_menu;

	if (select_menu == 1)
	{
		func_physical_diskinfo();
	}
	else if (select_menu == 2)
	{
		cout << "You selected menu [2]" << endl;
		cout << "Getting logical disk information!" << endl;
		Sleep(1000);
		func_logical_diskinfo();
	}
	else if (select_menu == 3)
	{
		cout << "You selected menu [3]" << endl;
		cout << "Wiping hdd..." << endl;
		Sleep(1000);
		func_physical_disk_overwrite();
	}
	else if (select_menu == 4)
	{
		cout << "You selected menu [4]" << endl;
		Sleep(1000);
		func_logical_disk_overwrite();
	}
	else
	{
		cout << "ENTER" << endl;
	}
}

void Lang_KOR()
{
	system("cls");
	cout << "AFSS에 오신걸 환영합니다." << Last_ver << endl << endl;
	cout << "--메뉴" << endl;
	cout << "  1. 물리디스크 정보 불러오기" << endl;
	cout << "  2. 논리디스크 정보 불어오기" << endl;

	cout << "put> ";

	int select_menu = NULL;
	cin >> select_menu;

	if (select_menu == 1)
	{
		func_physical_diskinfo_KOR(); // 한글버전으로 함수 하나 복붙함
	}
	else if (select_menu == 2)
	{
		cout << "선택한 메뉴 [2]" << endl;
		cout << "논리디스크 정보를 불러왔습니다!" << endl;
		Sleep(1000);
		func_logical_diskinfo_KOR();  //새로 만든 지역디스크 함수 불러오기
	}
	else
	{
		cout << "ENTER" << endl;
	}
}
void Lang_JPN()
{
	system("cls");
	cout << "AFSSに?てたことを?迎します." << Last_ver << endl << endl;
	cout << "--メニュ?" << endl;
	cout << "  1. 物理ディスク情報呼ぶ" << endl;
	cout << "  2. 論理ディスク情報呼ぶ" << endl;

	cout << "put> ";

	int select_menu = NULL;
	cin >> select_menu;

	if (select_menu == 1)
	{
		func_physical_diskinfo_JPN();
		// 일본어버전으로 함수 하나 복붙함
	}
	else if (select_menu == 2)
	{
		cout << "選?したメニュ? [2]" << endl;
		cout << "論理ディスク情報を呼んできました!" << endl;
		Sleep(1000);
		func_logical_diskinfo_JPN();  //새로 만든 지역디스크 함수 불러오기
	}
	else
	{
		cout << "ENTER" << endl;
	}
}
void Lang_CHI()
{
	system("cls");
	cout << "?迎?到AFSS." << Last_ver << endl << endl;
	cout << "--??" << endl;
	cout << "  1. 物理磁?存取信息" << endl;
	cout << "  2. ??磁?存取信息" << endl;

	cout << "put> ";

	int select_menu = NULL;
	cin >> select_menu;

	if (select_menu == 1)
	{
		func_physical_diskinfo_CHI(); // 중국버전으로 함수 하나 복붙함
	}
	else if (select_menu == 2)
	{
		cout << "??的?? [4]" << endl;
		cout << "存取完了??磁?的信息" << endl;
		Sleep(1000);
		func_logical_diskinfo_CHI();  //새로 만든 지역디스크 함수 불러오기
	}
	else
	{
		cout << "ENTER" << endl;
	}
}

void func_logical_diskinfo()
{
	system("cls");
	//wcout << "Show disk information"<<endl;
	cout << endl;
	cout << "===============Logical Disk Info===============" << endl << endl;
	_TCHAR buffer[256] = { 0, };
	CString DrivePathName;
	int n = 0;
	_TCHAR DriveName[100];
	_TCHAR FileSystem[100];
	LPCTSTR    drivename;
	GetLogicalDriveStrings(256, buffer);
	DWORD lVolumnSerialNumber;

	while (buffer[n] != NULL)
	{
		for (int i = 0; i < sizeof(*(buffer + n)); i++)
		{
			DrivePathName = buffer + n;
			n += 4;

			ZeroMemory(DriveName, sizeof(DriveName));
			ZeroMemory(FileSystem, sizeof(FileSystem));
			ZeroMemory(&drivename, sizeof(drivename));

			GetVolumeInformation(DrivePathName, DriveName, 1024,
				&lVolumnSerialNumber, NULL, NULL, FileSystem, 1024);

			if (FileSystem[0] != NULL)
			{
				wcout << "Drive Path           : " << DrivePathName.GetBuffer() << endl;
				wcout << "Drive Name           : " << DriveName << endl;
				wcout << "File System          : " << FileSystem << endl;
				wcout << "Vol Serial Number    : ";
				printf("%X\n\n", lVolumnSerialNumber);
			}

			else
			{
				wcout << "Drive Path           : " << DrivePathName.GetBuffer() << endl;
				wcout << "Drive Name           : " << DriveName << endl;
				wcout << "File System          : " << "CD-ROM/Flopy" << endl;
				wcout << "Vol Serial Number    : " << "<Not Detected>" << endl << endl;
				//printf("%X\n\n", lVolumnSerialNumber);
			}
			lVolumnSerialNumber = '\0';                           //NULL
			cout << "-------------------------------------------" << endl;

		}
	}

	//2016.08.08 (yyyy.mm.dd) updated code ~
	/*cout << "Return to main screen..!" << endl;
	for (int rtm = 3; rtm > 0; rtm--)
	{
		Sleep(1000);
		cout << "wait" << rtm << " sec" << endl;
	}
	system("cls");
	Lang_ENG();*/
	//main(NULL,NULL);
	//~ End code

}
void func_logical_diskinfo_KOR()            //지역 디스크 한글 버젼
{
	system("cls");
	//wcout << "Show disk information"<<endl;
	cout << endl;
	cout << "===============논리 디스크 정보===============" << endl << endl;
	_TCHAR buffer[256] = { 0, };
	CString DrivePathName;
	int n = 0;
	_TCHAR DriveName[100];
	_TCHAR FileSystem[100];
	LPCTSTR    drivename;
	GetLogicalDriveStrings(256, buffer);
	DWORD lVolumnSerialNumber;

	while (buffer[n] != NULL)
	{
		for (int i = 0; i < sizeof(*(buffer + n)); i++)
		{
			DrivePathName = buffer + n;
			n += 4;

			ZeroMemory(DriveName, sizeof(DriveName));
			ZeroMemory(FileSystem, sizeof(FileSystem));
			ZeroMemory(&drivename, sizeof(drivename));

			GetVolumeInformation(DrivePathName, DriveName, 1024,
				&lVolumnSerialNumber, NULL, NULL, FileSystem, 1024);

			if (FileSystem[0] != NULL)
			{
				wcout << "디스크 경로    : " << DrivePathName.GetBuffer() << endl;
				wcout << "디스크 이름    : " << DriveName << endl;
				wcout << "파일 시스템    : " << FileSystem << endl;
				wcout << "시리얼 넘버    : ";
				printf("%X\n\n", lVolumnSerialNumber);
			}

			else
			{
				wcout << "디스크 경로    : " << DrivePathName.GetBuffer() << endl;
				wcout << "디스크 이름    : " << DriveName << endl;
				wcout << "파일 시스템    : " << "CD/플로피디스크" << endl;
				wcout << "시리얼 넘버    : " << "<Not Detected>" << endl << endl;
				//printf("%X\n\n", lVolumnSerialNumber);
			}
			lVolumnSerialNumber = '\0';                           //NULL
			cout << "-------------------------------------------" << endl;

		}
	}
}
void func_logical_diskinfo_JPN()
{
	system("cls");
	//wcout << "Show disk information"<<endl;
	cout << endl;
	cout << "===============論理ディスク情報===============" << endl << endl;
	_TCHAR buffer[256] = { 0, };
	CString DrivePathName;
	int n = 0;
	_TCHAR DriveName[100];
	_TCHAR FileSystem[100];
	LPCTSTR    drivename;
	GetLogicalDriveStrings(256, buffer);
	DWORD lVolumnSerialNumber;

	while (buffer[n] != NULL)
	{
		for (int i = 0; i < sizeof(*(buffer + n)); i++)
		{
			DrivePathName = buffer + n;
			n += 4;

			ZeroMemory(DriveName, sizeof(DriveName));
			ZeroMemory(FileSystem, sizeof(FileSystem));
			ZeroMemory(&drivename, sizeof(drivename));

			GetVolumeInformation(DrivePathName, DriveName, 1024,
				&lVolumnSerialNumber, NULL, NULL, FileSystem, 1024);

			if (FileSystem[0] != NULL)
			{
				wcout << "ディスク?路          : " << DrivePathName.GetBuffer() << endl;
				wcout << "ディスクの名前           : " << DriveName << endl;
				wcout << "ファイルシステム          : " << FileSystem << endl;
				wcout << "シリアルナンバ?    : ";
				printf("%X\n\n", lVolumnSerialNumber);
			}

			else
			{
				wcout << "ディスク?路           : " << DrivePathName.GetBuffer() << endl;
				wcout << "ディスクの名前         : " << DriveName << endl;
				wcout << "ファイルシステム         : " << "CD-ROM/フロッピ?ディスク" << endl;
				wcout << "シリアルナンバ?   : " << "<Not Detected>" << endl << endl;
				//printf("%X\n\n", lVolumnSerialNumber);
			}
			lVolumnSerialNumber = '\0';                           //NULL
			cout << "-------------------------------------------" << endl;

		}
	}
}
void func_logical_diskinfo_CHI()            //지역 디스크 중국 버젼
{
	system("cls");
	//wcout << "Show disk information"<<endl;
	cout << endl;
	cout << "===============??磁?信息===============" << endl << endl;
	_TCHAR buffer[256] = { 0, };
	CString DrivePathName;
	int n = 0;
	_TCHAR DriveName[100];
	_TCHAR FileSystem[100];
	LPCTSTR    drivename;
	GetLogicalDriveStrings(256, buffer);
	DWORD lVolumnSerialNumber;

	while (buffer[n] != NULL)
	{
		for (int i = 0; i < sizeof(*(buffer + n)); i++)
		{
			DrivePathName = buffer + n;
			n += 4;

			ZeroMemory(DriveName, sizeof(DriveName));
			ZeroMemory(FileSystem, sizeof(FileSystem));
			ZeroMemory(&drivename, sizeof(drivename));

			GetVolumeInformation(DrivePathName, DriveName, 1024,
				&lVolumnSerialNumber, NULL, NULL, FileSystem, 1024);

			if (FileSystem[0] != NULL)
			{
				wcout << "磁?通道    : " << DrivePathName.GetBuffer() << endl;
				wcout << "磁?名?    : " << DriveName << endl;
				wcout << "文件系?    : " << FileSystem << endl;
				wcout << "序?        : ";
				printf("%X\n\n", lVolumnSerialNumber);
			}

			else
			{
				wcout << "磁?通道    : " << DrivePathName.GetBuffer() << endl;
				wcout << "磁?名?    : " << DriveName << endl;
				wcout << "文件系?    : " << "CD/???" << endl;
				wcout << "序?        : " << "<Not Detected>" << endl << endl;
				//printf("%X\n\n", lVolumnSerialNumber);
			}
			lVolumnSerialNumber = '\0';                           //NULL
			cout << "-------------------------------------------" << endl;

		}
	}
}

void func_physical_diskinfo()
{
	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("Device IO Control failed..n");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - Total Sectors = " << uLBASize << endl;
		wcout << tchDriveName << " - Total Bytes   = " << uLBASize * 512 << endl;
		cout << endl;
	}
}

void func_physical_diskinfo_KOR()     //물리디스크 한글버젼
{
	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("디스크 IO 통제 실패");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - 총 섹터 수     = " << uLBASize << endl;
		wcout << tchDriveName << " - 총 바이트 수   = " << uLBASize * 512 << endl;
		cout << endl;
	}
}
void func_physical_diskinfo_JPN()
{
	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("ディスク IO 統制の失敗");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - ?セクタ?? = " << uLBASize << endl;
		wcout << tchDriveName << " - ?バイト?   = " << uLBASize * 512 << endl;
		cout << endl;
	}
}
void func_physical_diskinfo_CHI()     //물리디스크 중국 버젼
{
	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("失?磁? IO 控制");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - 扇???     = " << uLBASize << endl;
		wcout << tchDriveName << " - 字???     = " << uLBASize * 512 << endl;
		cout << endl;
	}
}

void func_physical_disk_overwrite()
{
	cout << fixed << setprecision(1);	//소숫점 첫째 자리까지 출력

	//int a, b;
	//int c;

	//srand(time(NULL));


	//for (a = 1; a < 100; a++) {
	//   for (c = 1; c<20; c++){
	//      b = rand() % 128;
	//      printf("%c", b);
	//   }
	//   printf("\n");
	//}

	//system("pause");

	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	char real_disk[MAX_PATH];
	char *DISK = real_disk;
	char OverW_Buffer[512];
	char *rtrn_Error;
	int Cnt = 0;
	int rtime;
	char tmp;


	/* CLOCK FUNCTIONS */
	time_t START_CLOCK, END_CLOCK;
	float TOTAL_TIME;
	int min;
	int sec;

	/*
	//diskpart 스크립트화 부분
	FILE *diskpart;
	diskpart = fopen("b.txt", "w");
	
	Sleep(1000);

	fprintf(diskpart, "list volume");
	fclose(diskpart);
	system("diskpart /s b.txt");

	cout << "input vol num: ";
	cin >> select_disk;

	diskpart = fopen("b.txt", "w");
	fprintf(diskpart, "select volume %d\n", select_disk);
	fprintf(diskpart, "delete volume");
	fclose(diskpart);
	//fprintf(diskpart, "");
	system("diskpart /s b.txt");
	*/
	

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("Device IO Control failed..n");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - Total Sectors = " << uLBASize << endl;
		wcout << tchDriveName << " - Total Bytes   = " << uLBASize * 512 << endl;
		cout << endl;
	}

	//system("pause");
	//clock_t begin, end;
	int select_disk;
	cout << "input num: ";
	cin >> select_disk;
	wsprintf(real_disk, _T("\\\\.\\PhysicalDrive%d"), select_disk);

	cout << "Wiping start!" << endl;
	Sleep(1000);

	DWORD dwWrite;

	HANDLE ANTI_DISK = CreateFile(               //ANTI_DISK 라는 HANDLE 을 생성하고 CreateFile 이라는 API 를 불러온다.
		TEXT(DISK),                           //DISK 포인터를 따라 이동하여 \\\\.\\PhysicalDrive%d 을 불러온다. (이때 앞에 TEXT 는 Unicode 로 불러온다는 뜻)
		GENERIC_READ | GENERIC_WRITE,            //읽고 쓰는 권한을 가져 온다.
		0, NULL, OPEN_EXISTING,                  //
		0,
		NULL
		);


	__int64 nxtptr = 0;
	__int64 startsec = 0;
	float percent = 0.0;
	float percent_b = 1.0;
	char prog[51] = { '\0' };

	//time_t start_time = 0, end_time = 0;
	//__int64 total_time = 0;

	for (Cnt = 0; Cnt < 50; Cnt++)
	{
		prog[Cnt] = ' ';
	}
	/*
	for (; startsec <= uLBASize; startsec++)
	{
	srand((unsigned)time(NULL));

	for (; Cnt < 512; Cnt++)
	{
	for (; inttmp<20; inttmp++)
	{
	tmp = rand() % 128;
	cout << tmp << " Rand char" << endl;
	OverW_Buffer[Cnt] = { tmp };
	}
	}

	//for (; Cnt < 512; Cnt++)
	//{
	//   tmp = rand() % 26 + 65;
	//   cout << tmp << " Rand alpha" << endl;
	//
	//}
	WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);   //WriteFile 함수를 불러와 ANTI_DISK HANDLE 을 탑제한다. OverW_Buffer 에 있는 데이터를 쓰고 512바이트 만큼 쓴다.
	SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_BEGIN);      //포인터를 이동시켜 다음 섹터를 읽을 수 있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
	nxtptr = nxtptr + 512;
	//WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);
	inttmp = 1;
	Cnt = 0;
	}
	*/

	

	for (; startsec <= uLBASize; startsec++)
	{
		//start_time = clock();
		//begin = clock();

		/* WARNING START CLOCK */
		START_CLOCK = clock();

		srand((unsigned)time(NULL));
		for (Cnt = 0; Cnt < 512; Cnt++)
		{
			tmp = rand() % 26 + 95;
			//cout << tmp << " Rand alpha" << endl;
			OverW_Buffer[Cnt] = { tmp };
		}
		WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);   //WriteFile 함수를 불러와 ANTI_DISK HANDLE 을 탑제한다. OverW_Buffer 에 있는 데이터를 쓰고 512바이트 만큼 쓴다.
																   //SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_BEGIN);      //포인터를 이동시켜 다음 섹터를 읽을 수  있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
		SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_CURRENT);     
		
		END_CLOCK = clock();
		/* WARNING END CLOCK */


		/* WARNING CALC TOTAL_TIME */
		if (END_CLOCK == START_CLOCK)
			continue;
		else
		{
			TOTAL_TIME = (((END_CLOCK - START_CLOCK)*(uLBASize - startsec)) / CLOCKS_PER_SEC);
			min = TOTAL_TIME / 60;
			sec = TOTAL_TIME - (min * 60);
			//cout << min<<"m "<<sec<<"s" << endl;

			/*cout << "END: " << end_time << endl;
			cout << "START: " << start_time << endl;
			cout << total_time << endl;
			//total_time = (int)(end_time - start_time)*(uLBASize-startsec)/CLOCKS_PER_SEC;
			//total_time = end_time - start_time;
			//cout << total_time << endl;
			//cout << "\r 예상 시간: "<<total_time;
			//포인터를 이동시켜 다음 섹터를 읽을 수 있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
			//cout << startsec << endl;
			//nxtptr=nxtptr+512;
			//startsec = startsec+512; //SetFilePointer 라는 부분에서 다음 영역을 가리키는 부분이 nxtptr 영역이고 1이니까 1바이트 뒤로 포인터를 옮기겠다 라는 뜻입니당
			//system("cls");// 이거 루프를 잘못계산한거같다
			*/

			//cout << "\r" << startsec;
			//Cnt = (int)percent/2;
			//cout << "IF u wan't STOP press Ctrl^c" << endl << endl;
			//cout << prgs << "% Complete!" << endl;
			//       Wiping... [=================================================>] [100%]
			//printf("\rWiping... [                                                  ] [%d]", prgs);
			//percent = 0;
			//WriteFile(ANTI_DISK, OverW_Buffer, 512,` &dwWrite, NULL);
			//end = clock();
			//cout <<"\r"<< "수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << " Percent: "<<percent<<endl;
			//total_time = (uLBASize / 10/10) / 60;
			//cout << "예상 시간: " << total_time << endl;
	

			Cnt = (int)percent / 2;
			percent = (startsec * 100.0) / uLBASize;
			
			if (percent != percent_b)
			{
				prog[Cnt] = '>';
				cout << "\r" << "Wiping... " << "[" << prog << "]" << " [" << percent << "%] " << min << "m " << sec << "s \0\0\0" << flush;
				//cout << total_time / 60 << endl;
			}
			else
			{
				percent = 100;
				cout << "\r" << "Wiping... " << "[" << prog << "]" << " [" << percent << "%]";
				cout << endl;
				break;
			}
			percent_b = percent;
		}
		
	}
	CloseHandle(ANTI_DISK);
}


void func_logical_disk_overwrite()
{
	cout << fixed << setprecision(1);	

	//소숫점 첫째 자리까지 출력
	//int a, b;
	//int c;
	//srand(time(NULL));
	//for (a = 1; a < 100; a++) {
	//   for (c = 1; c<20; c++){
	//      b = rand() % 128;
	//      printf("%c", b);
	//   }
	//   printf("\n");
	//}
	//system("pause");

	HANDLE   hDevice;            // handle to the drive to be examined
	BOOL   bResult = FALSE;      // results flag
	DWORD   dwjunk = 0;            // discard results

	UINT64   uLBASize = 0L;

	DISK_GEOMETRY_EX   stDiskGeometryEx;      // disk geometry structure
	TCHAR            tchDriveName[MAX_PATH];

	char real_disk[MAX_PATH];
	char *DISK = real_disk;
	char OverW_Buffer[512];
	char Analysis_MBR[3];
	char *rtrn_Error;
	int Cnt = 0;
	int rtime;
	char tmp;


	/* CLOCK FUNCTIONS */
	time_t START_CLOCK, END_CLOCK;
	float TOTAL_TIME;
	int min;
	int sec;

	/*
	//diskpart 스크립트화 부분
	FILE *diskpart;
	diskpart = fopen("b.txt", "w");

	Sleep(1000);

	fprintf(diskpart, "list volume");
	fclose(diskpart);
	system("diskpart /s b.txt");

	cout << "input vol num: ";
	cin >> select_disk;

	diskpart = fopen("b.txt", "w");
	fprintf(diskpart, "select volume %d\n", select_disk);
	fprintf(diskpart, "delete volume");
	fclose(diskpart);
	//fprintf(diskpart, "");
	system("diskpart /s b.txt");
	*/

	for (int i = 0; i < 24; i++)
	{
		wsprintf(tchDriveName, _T("\\\\.\\PhysicalDrive%d"), i);
		hDevice = CreateFile(tchDriveName,   // drive to open
			0,                  // no access to the drive
			FILE_SHARE_READ |      // share mode
			FILE_SHARE_WRITE,
			NULL,               // default security attributes
			OPEN_EXISTING,         // disposition
			0,                  // file attributes
			NULL);               // do not copy file attributes

		if (hDevice == INVALID_HANDLE_VALUE)   // cannot open the drive
		{
			break;
		}

		bResult = DeviceIoControl(hDevice,      // device to be queried
			IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,   // operation to perform
			NULL, 0, // no input buffer
			&stDiskGeometryEx, sizeof(DISK_GEOMETRY_EX),   // output buffer
			&dwjunk,                     // # bytes returned
			(LPOVERLAPPED)NULL);            // synchronous I/O

		if (!bResult)
		{
			printf("Device IO Control failed..n");
		}

		CloseHandle(hDevice);

		uLBASize = stDiskGeometryEx.DiskSize.QuadPart / 512;

		//wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize); Original code
		//wprintf(_T("%s - Total Sector = %I64d\n"), tchDriveName, uLBASize); Original code 2
		wcout << tchDriveName << " - Total Sectors = " << uLBASize << endl;
		wcout << tchDriveName << " - Total Bytes   = " << uLBASize * 512 << endl;
		cout << endl;
	}

	int select_disk;
	cout << "input num: ";
	cin >> select_disk;
	wsprintf(real_disk, _T("\\\\.\\PhysicalDrive%d"), select_disk);

	//cout << "Wiping start!" << endl;
	Sleep(1000);

	DWORD dwWrite;
	DWORD dwRead;

	/*
	HANDLE ANTI_DISK = CreateFile(               //ANTI_DISK 라는 HANDLE 을 생성하고 CreateFile 이라는 API 를 불러온다.
		TEXT(DISK),                           //DISK 포인터를 따라 이동하여 \\\\.\\PhysicalDrive%d 을 불러온다. (이때 앞에 TEXT 는 Unicode 로 불러온다는 뜻)
		GENERIC_READ | GENERIC_WRITE,            //읽고 쓰는 권한을 가져 온다.
		0, NULL, OPEN_EXISTING,                  //
		0,
		NULL
	);
	*/

	HANDLE READ_DISK = CreateFile(
		TEXT(DISK),
		GENERIC_READ,
		0, NULL, OPEN_EXISTING,
		0,
		NULL
	);


	__int64 nxtptr = 447;
	__int64 startsec = 0;
	float percent = 0.0;
	float percent_b = 1.0;
	char prog[51] = { '\0' };


	/* 수정해야 할 부분 */
	for (;;)	//임시로 무한반복 돌림
	{
		SetFilePointer(READ_DISK, nxtptr, NULL, FILE_BEGIN);
		ReadFile(READ_DISK, Analysis_MBR, 4, &dwRead, NULL);
		//WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);
		cout << "현재 읽혀진 바이트 수: " << dwRead << " 현재 포인터 위치: " << nxtptr << endl;
		cout << Analysis_MBR << endl;
		nxtptr += 4;
	}
	/* 여기 위까지 수정 해야한다 */


	//time_t start_time = 0, end_time = 0;
	//__int64 total_time = 0;

	for (Cnt = 0; Cnt < 50; Cnt++)
	{
		prog[Cnt] = ' ';
	}
	/*
	for (; startsec <= uLBASize; startsec++)
	{
	srand((unsigned)time(NULL));

	for (; Cnt < 512; Cnt++)
	{
	for (; inttmp<20; inttmp++)
	{
	tmp = rand() % 128;
	cout << tmp << " Rand char" << endl;
	OverW_Buffer[Cnt] = { tmp };
	}
	}

	//for (; Cnt < 512; Cnt++)
	//{
	//   tmp = rand() % 26 + 65;
	//   cout << tmp << " Rand alpha" << endl;
	//
	//}
	WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);   //WriteFile 함수를 불러와 ANTI_DISK HANDLE 을 탑제한다. OverW_Buffer 에 있는 데이터를 쓰고 512바이트 만큼 쓴다.
	SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_BEGIN);      //포인터를 이동시켜 다음 섹터를 읽을 수 있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
	nxtptr = nxtptr + 512;
	//WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);
	inttmp = 1;
	Cnt = 0;
	}
	*/

	//system("pause");

	//for (; startsec <= uLBASize; startsec++)
	//{
	//	//start_time = clock();
	//	//begin = clock();

	//	/* WARNING START CLOCK */
	//	START_CLOCK = clock();

	//	srand((unsigned)time(NULL));
	//	for (Cnt = 0; Cnt < 512; Cnt++)
	//	{
	//		tmp = rand() % 26 + 95;
	//		//cout << tmp << " Rand alpha" << endl;
	//		OverW_Buffer[Cnt] = { tmp };
	//	}
	//	WriteFile(ANTI_DISK, OverW_Buffer, 512, &dwWrite, NULL);   //WriteFile 함수를 불러와 ANTI_DISK HANDLE 을 탑제한다. OverW_Buffer 에 있는 데이터를 쓰고 512바이트 만큼 쓴다.
	//															   //SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_BEGIN);      //포인터를 이동시켜 다음 섹터를 읽을 수  있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
	//	SetFilePointer(ANTI_DISK, nxtptr, NULL, FILE_CURRENT);

	//	END_CLOCK = clock();
	//	/* WARNING END CLOCK */


	//	/* WARNING CALC TOTAL_TIME */
	//	if (END_CLOCK == START_CLOCK)
	//		continue;
	//	else
	//	{
	//		TOTAL_TIME = (((END_CLOCK - START_CLOCK)*(uLBASize - startsec)) / CLOCKS_PER_SEC);
	//		min = TOTAL_TIME / 60;
	//		sec = TOTAL_TIME - (min * 60);
	//		//cout << min<<"m "<<sec<<"s" << endl;

	//		/*cout << "END: " << end_time << endl;
	//		cout << "START: " << start_time << endl;
	//		cout << total_time << endl;
	//		//total_time = (int)(end_time - start_time)*(uLBASize-startsec)/CLOCKS_PER_SEC;
	//		//total_time = end_time - start_time;
	//		//cout << total_time << endl;
	//		//cout << "\r 예상 시간: "<<total_time;
	//		//포인터를 이동시켜 다음 섹터를 읽을 수 있도록 한다. 512바이트 = 1섹터, 513 = 다음 섹터의 시작 바이트
	//		//cout << startsec << endl;
	//		//nxtptr=nxtptr+512;
	//		//startsec = startsec+512; //SetFilePointer 라는 부분에서 다음 영역을 가리키는 부분이 nxtptr 영역이고 1이니까 1바이트 뒤로 포인터를 옮기겠다 라는 뜻입니당
	//		//system("cls");// 이거 루프를 잘못계산한거같다
	//		*/

	//		//cout << "\r" << startsec;
	//		//Cnt = (int)percent/2;
	//		//cout << "IF u wan't STOP press Ctrl^c" << endl << endl;
	//		//cout << prgs << "% Complete!" << endl;
	//		//       Wiping... [=================================================>] [100%]
	//		//printf("\rWiping... [                                                  ] [%d]", prgs);
	//		//percent = 0;
	//		//WriteFile(ANTI_DISK, OverW_Buffer, 512,` &dwWrite, NULL);
	//		//end = clock();
	//		//cout <<"\r"<< "수행시간 : " << ((end - begin) / CLOCKS_PER_SEC) << " Percent: "<<percent<<endl;
	//		//total_time = (uLBASize / 10/10) / 60;
	//		//cout << "예상 시간: " << total_time << endl;


	//		Cnt = (int)percent / 2;
	//		percent = (startsec * 100.0) / uLBASize;

	//		if (percent != percent_b)
	//		{
	//			prog[Cnt] = '>';
	//			cout << "\r" << "Wiping... " << "[" << prog << "]" << " [" << percent << "%] " << min << "m " << sec << "s \0\0\0" << flush;
	//			//cout << total_time / 60 << endl;
	//		}
	//		else
	//		{
	//			percent = 100;
	//			cout << "\r" << "Wiping... " << "[" << prog << "]" << " [" << percent << "%]";
	//			cout << endl;
	//			break;
	//		}
	//		percent_b = percent;
	//	}

	//}
	//CloseHandle(ANTI_DISK);
}

//{                           ****Original code****
//HANDLE   hDevice;                                       // handle to the drive to be examined
//BOOL   bResult = FALSE;                                 // results flag
//DWORD   dwjunk = 0;                                       // discard results
//UINT64   uLBASize = 0L;
//DISK_GEOMETRY   stDiskGeometry;                              // disk geometry structure
//TCHAR         tchDriveName[MAX_PATH];
//for (int i=0; i<24; i++)
//{
//   wsprintf(tchDriveName, _T("\\.\PhysicalDrive%d"), i);
//   hDevice = CreateFile(tchDriveName,                        // drive to open
//      0,                                             // no access to the drive
//      FILE_SHARE_READ |                                 // share mode
//      FILE_SHARE_WRITE,
//      NULL,                                          // default security attributes
//      OPEN_EXISTING,                                    // disposition
//      0,                                             // file attributes
//      NULL);                                          // do not copy file attributes
//   if (hDevice == INVALID_HANDLE_VALUE)                     // cannot open the drive
//   {
//      break;
//   }
//   bResult = DeviceIoControl(hDevice,                        // device to be queried
//      IOCTL_DISK_GET_DRIVE_GEOMETRY,                        // operation to perform
//      NULL, 0,                                       // no input buffer
//      &stDiskGeometry, sizeof(DISK_GEOMETRY),                  // output buffer
//      &dwjunk,                                       // # bytes returned
//      (LPOVERLAPPED) NULL);                              // synchronous I/O
//   if (!bResult)
//   {
//      wprintf(_T("Device IO Control failed..n"));
//   }
//   CloseHandle(hDevice);
//   //wprintf(_T("Cylinder = %lin"), stDiskGeometry.Cylinders.QuadPart);
//   //wprintf(_T("Media Type = %in"), stDiskGeometry.MediaType);
//   //wprintf(_T("Tracks Per Cylinder = %un"), stDiskGeometry.TracksPerCylinder);
//   //wprintf(_T("Sectors Per Track = %un"), stDiskGeometry.SectorsPerTrack);
//   //wprintf(_T("Bytes Per Sector = %un"), stDiskGeometry.BytesPerSector);
//   uLBASize = stDiskGeometry.Cylinders.QuadPart * (ULONG)stDiskGeometry.TracksPerCylinder *
//      (ULONG)stDiskGeometry.SectorsPerTrack * (ULONG)stDiskGeometry.BytesPerSector;
//   uLBASize /= 512;
//   wprintf(_T("%s - Total Sector = %I64dn"), tchDriveName, uLBASize);
//}