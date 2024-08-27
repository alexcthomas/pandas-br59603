
This repo is for recreating the pandas/pyarrow bug [59603](https://github.com/pandas-dev/pandas/issues/59603)

## Prerequisites


You'll need
  - Python 3.12 (assuming installed at C:\Python312 with c++ header files)
  - Visual Studio (tested on VS Community 2022 17.11.2) with C++ compiler

## Steps to recreate

  - Clone repo
  - `git submodule update --init --recursive`
  - Open TestModule.sln in VS2022
  - Hit compile
  - Confirm TestModule.pyd appears
  - `C:\python312\python -m virtualenv --symlinks venv`
  - `venv\Scripts\activate`
  - `pip install pandas pyarrow`
  - `python test_module.py`
  - Comment out the first line of test_module.py and try again

## Expected output
Creating mutex\
Mutex created\
Attempting to lock mutex\
Mutex locked and unlocked\
Exiting create_mutex\
Success

## Actual output
Creating mutex\
Mutex created\
Attempting to lock mutex

