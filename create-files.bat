@echo off
setlocal

REM Check if a parameter is provided
if "%~1"=="" (
    echo Usage: create_files.bat <name>
    exit /b 1
)

REM Get the base name from the first parameter
set "base_name=%~1"

REM Call the Python script with the current directory and the base name
python create_files.py src/ "%base_name%"

endlocal
