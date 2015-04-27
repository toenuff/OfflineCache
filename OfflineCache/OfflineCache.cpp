#include "stdafx.h"
#include <cscobj.h>
#include <iostream>
int _tmain()
{
    IOfflineFilesCache *pCache;
    HRESULT hr;
    CoInitialize(nullptr);
    hr = CoCreateInstance(CLSID_OfflineFilesCache, NULL, CLSCTX_INPROC_SERVER, IID_IOfflineFilesCache, (void**)&pCache);
    if (FAILED(hr)) {
        std::cerr << "ERROR: " << hr << "\n";
        return 0;
    }
    ULONGLONG pcbVolumeTotal;
    ULONGLONG pcbLimit;
    ULONGLONG pcbUsed;
    ULONGLONG pcbUnpinnedLimit;
    ULONGLONG pcbUnpinnedUsed;
    hr = pCache->GetDiskSpaceInformation(&pcbVolumeTotal, &pcbLimit, &pcbUsed, &pcbUnpinnedLimit, &pcbUnpinnedUsed);
    if (FAILED(hr)) {
        std::cerr << "ERROR: " << hr << "\n";
        return 0;
    }
    std::cout << "VolumeTotal:\t"    << pcbVolumeTotal    << "\n";
    std::cout << "Limit:\t\t"        << pcbLimit            << "\n";
    std::cout << "Used:\t\t"        << pcbUsed            << "\n";
    std::cout << "UnpinnedLimit:\t" << pcbUnpinnedLimit << "\n";
    std::cout << "UnpinnedUsed:\t"    << pcbUnpinnedUsed    << "\n";
    return 1;
}