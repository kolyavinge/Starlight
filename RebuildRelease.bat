rmdir x64\Release /s /q
"C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin"\MSBuild /p:configuration=release
del x64\Release\res\main.ico/q
del x64\Release\res\Starlight.aps/q
del x64\Release\res\Starlight.rc/q
del x64\Release\*.obj /q
del x64\Release\*.pdb /q
del x64\Release\*.iobj /q
del x64\Release\*.ipdb /q
del x64\Release\Starlight.exe.recipe /q
del x64\Release\Starlight.vcxproj.FileListAbsolute.txt /q
rmdir x64\Release\Starlight.tlog /s /q