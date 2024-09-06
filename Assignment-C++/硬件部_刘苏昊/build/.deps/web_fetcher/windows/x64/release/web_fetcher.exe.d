{
    files = {
        [[build\.objs\web_fetcher\windows\x64\release\src\main.cpp.obj]]
    },
    values = {
        [[E:\VisualStudio\VS\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:C:\Users\Administrator.DESKTOP-A073ESA\AppData\Local\.xmake\packages\c\cpr\1.10.5\3c77f95842ff4659871a88c5207ae792\lib]],
            [[-libpath:C:\Users\Administrator.DESKTOP-A073ESA\AppData\Local\.xmake\packages\l\libcurl\8.7.1\5cd5aeb180e6462c970c81ac7924f2c6\lib]],
            "/opt:ref",
            "/opt:icf",
            "cpr.lib",
            "libcurl.lib",
            "advapi32.lib",
            "crypt32.lib",
            "wldap32.lib",
            "winmm.lib",
            "ws2_32.lib",
            "user32.lib"
        }
    }
}