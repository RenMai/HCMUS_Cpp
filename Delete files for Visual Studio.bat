REM Delete Debug, ipch folders and .sdf files in a Visual Studio solution's folder
REM ***IMPORTANT: Put this file in the solution's folder on which you want to work

@echo off
rem Enter into top level folder, process it and go back to original folder
pushd
call :processFolder
popd
goto :EOF

:processFolder
rem For each folder in this level
for /D %%a in (*) do (
   rem Enter into it, process it and go back to original
   cd %%a
   call :processFolder
   cd ..
   rem If is the target folder, delete it
   if /I "%%a" == "Debug" (
      rd /S /Q "%%a"
   )
)

@echo off
pushd
call :processFolder
popd
goto :EOF

:processFolder
for /D %%a in (*) do (
   cd %%a
   call :processFolder
   cd ..
   if /I "%%a" == "ipch" (
      rd /S /Q "%%a"
   )
)

del /s /f /q *.sdf
exit /B