#include <windows.h>
#include <stdio.h>
#include <iostream>

using namespace std;
short ReadSect
	(const char *_dsk,    // disk to access
	char *&_buff,         // buffer where sector will be stored
	unsigned int _nsect   // sector number, starting with 0
	)

{
	DWORD dwRead;
	HANDLE hDisk = CreateFile(_dsk, GENERIC_READ, NULL, 0, OPEN_EXISTING, 0, 0);
	if (hDisk == INVALID_HANDLE_VALUE) // this may happen if another program is already reading from disk
	{
		CloseHandle(hDisk);
		return 1;
	}
	SetFilePointer(
		hDisk,
		_nsect * 512, //512를 변수로 준다.
		0,
		FILE_BEGIN); // which sector to read

	ReadFile(
		hDisk,
		_buff,
		512,
		&dwRead,
		0);  // read sector

	CloseHandle(hDisk);
	return 0;
}


int main()
{
	//char * drv = "\\\\.\\C:";
	char *dsk = "\\\\.\\PhysicalDrive0";
	int sector = 0;
	int cnt;
	int a=0;

	char *buff = new char[512];
	ReadSect(dsk, buff, sector);

	//if ((unsigned char)buff[510] == 0x55 && (unsigned char)buff[511] == 0xaa) cout << "Disk is bootable!" << endl;

	int infor_cnt=0;
	for (cnt = 446; cnt < 510; cnt++) //partition table start bytes
	{

		if(cnt==454||cnt==470||cnt==486||cnt==502)
		{
			printf("LBA: ");
			for(int lba=0;lba<4;lba++)
			{
				printf( " %x ", (unsigned char)buff[cnt]);
				cnt++;
			}
			printf("\n");
			printf("SIS: ");
			for(int sis=0;sis<4;sis++)
			{
				printf( " %x ", (unsigned char)buff[cnt]);
				cnt++;
			}
			printf("\n");

		}
		
		//if (a == 16) 
		//{ //그냥 16개씩 끊어서 줄바꿈 해주는 칸
		//	printf("\n");
		//	a = 0;
		//}
		//a++;

	}


	//cout << "\n\n " << buff[454] << "\n\n";

	//system("pause");

}

