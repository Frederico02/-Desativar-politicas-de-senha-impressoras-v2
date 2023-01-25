#include <windows.h>

int main() {
    HKEY hKey;
    DWORD dwValue = 0;
    LONG lError = RegCreateKeyEx(HKEY_LOCAL_MACHINE,
        "SOFTWARE\\Policies\\Microsoft\\Windows NT\\printers\\PointAndPrint",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL);
    if (lError == ERROR_SUCCESS) {
        lError = RegSetValueEx(hKey,
            "RestrictDriverInstallationToAdministrators",
            0,
            REG_DWORD,
            (BYTE*)&dwValue,
            sizeof(dwValue));
        if (lError != ERROR_SUCCESS) {
            // handle error
        }
        RegCloseKey(hKey);
    }
    else {
        // handle error
    }
    return 0;
}
